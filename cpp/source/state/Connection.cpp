#include "state/Connection.hpp"

#include "state/Encryption.hpp"
#include "state/Disconnected.hpp"

#include "event/bridge/Error.hpp"

#include <functional>

using namespace sl::event;
using namespace sl::state;

Connection::Connection(Listener& listener):
    ILiveCycleState(Type::CONNECTION, listener)
{
}

void Connection::start(const endpoint::Event* const) noexcept
{
    connectionTimer = listener.getBridgeListener().createTimer();
    connectionTimer->callAfter(CONNECTION_TIMEOUT, std::bind(&Connection::onTimeout, this));
    controlCommInterface.connect("localhost", 16385);
}

void Connection::onConnected()
{
    connectionTimer->kill();
    trace("Connection::onConnected");
    switchState<state::Encryption>();
}

void Connection::onDisconnected()
{
    connectionTimer->kill();
    trace("Connection::onDisconnected");
    switchState<state::Disconnected>();
}

std::string Connection::toString() const noexcept
{
    return "CONNECTION";
}

void Connection::onTimeout() noexcept
{
    notifyBridgeEvent(new bridge::Error("Timeout waiting for connection, disconnected."));
    controlCommInterface.disconnect();
}
