#include "state/Disconnected.hpp"

#include "state/Connection.hpp"

using namespace sl::event;
using namespace sl::state;

Disconnected::Disconnected(Listener& listener):
    ILiveCycleState(Type::DISCONNECTED, listener)
{
}

void Disconnected::start() noexcept
{
    notifyBridgeEvent(new bridge::Event(bridge::Event::DISCONNECTED));
}

void Disconnected::handleEvent(const endpoint::Event& event)
{
    switch (event.getType())
    {
    case endpoint::Event::CONNECT:
        switchState<Connection>();
        break;

    default:
        exceptUnexpected(event);
    }
}

std::string Disconnected::toString() const noexcept
{
    return "DISCONNECTED";
}
