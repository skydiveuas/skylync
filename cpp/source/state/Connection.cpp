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
    //connectionTimer = listener.getBridgeListener().createTimer();
    //connectionTimer->callAfter(CONNECTION_TIMEOUT, std::bind(&Connection::onTimeout, this));
    controlCommInterface.connect("localhost", 16385);
}

void Connection::onConnected()
{
    trace("Connection::onConnected");
    //connectionTimer->kill();
    switchState<sl::state::Encryption>();
}

std::string Connection::toString() const noexcept
{
    return "CONNECTION";
}

void Connection::onTimeout() noexcept
{
    controlCommInterface.disconnect();
    notifyBridgeEvent(new sl::event::bridge::Error("Timeout waiting for connection, disconnected."));
    switchState<sl::state::Disconnected>();
}
