#include "state/Connection.hpp"

#include "state/Encryption.hpp"
#include "state/Disconnected.hpp"

#include "event/bridge/Error.hpp"

#include <functional>

using sl::state::Connection;

Connection::Connection(Listener& listener):
    ILiveCycleState(Type::CONNECTION, listener)
{
}

void Connection::start(const EndpointEvent* const) noexcept
{
    connectionTimer = listener.getBridgeListener().createTimer();
    connectionTimer->callAfter(CONNECTION_TIMEOUT, std::bind(&Connection::onTimeout, this));
    controlCommInterface.connect("localhost", 16385);
}

void Connection::onConnected()
{
    connectionTimer->kill();
    trace("Connection::onConnected");
    switchState<sl::state::Encryption>();
}

void Connection::onDisconnected()
{
    connectionTimer->kill();
    trace("Connection::onDisconnected");
    switchState<sl::state::Disconnected>();
}

std::string Connection::toString() const noexcept
{
    return "CONNECTION";
}

void Connection::onTimeout() noexcept
{
    notifyBridgeEvent(new sl::event::bridge::Error("Timeout waiting for connection, disconnected."));
    controlCommInterface.disconnect();
}
