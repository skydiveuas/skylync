#include "state/Disconnection.hpp"

#include "state/Disconnected.hpp"

using sl::state::Disconnection;

Disconnection::Disconnection(Listener& listener):
    ILiveCycleState(Type::DISCONNECTION, listener)
{
}

void Disconnection::start(const EndpointEvent* const) noexcept
{
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::RELEASED));
    controlCommInterface.disconnect();
}

void Disconnection::onDisconnected()
{
    trace("Disconnection::onDisconnected");
    switchState<sl::state::Disconnected>();
}

std::string Disconnection::toString() const noexcept
{
    return "DISCONNECTION";
}
