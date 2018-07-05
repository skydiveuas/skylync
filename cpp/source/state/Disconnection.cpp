#include "state/Disconnection.hpp"

#include "state/Disconnected.hpp"

using namespace sl::event;
using namespace sl::state;

Disconnection::Disconnection(Listener& listener):
    ILiveCycleState(Type::DISCONNECTION, listener)
{
}

void Disconnection::start() noexcept
{
    notifyBridgeEvent(new bridge::Event(bridge::Event::RELEASED));
    controlCommInterface.disconnect();
}

void Disconnection::onDisconnected()
{
    trace("Disconnection::onDisconnected");
    switchState<Disconnected>();
}

std::string Disconnection::toString() const noexcept
{
    return "Disconnection";
}
