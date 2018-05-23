#include "state/Disconnected.hpp"

#include "state/Connection.hpp"

using sl::state::Disconnected;

Disconnected::Disconnected(Listener& listener):
    ILiveCycleState(Type::DISCONNECTED, listener)
{
}

void Disconnected::start(const EndpointEvent* const) noexcept
{
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::DISCONNECTED));
}

void Disconnected::handleEvent(const EndpointEvent& event)
{
    switch (event.getType())
    {
    case sl::event::endpoint::Event::CONNECT:
        switchState<sl::state::Connection>();
        break;

    default:
        exceptUnexpected(event);
    }
}

std::string Disconnected::toString() const noexcept
{
    return "DISCONNECTED";
}
