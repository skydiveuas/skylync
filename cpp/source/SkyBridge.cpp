#include "SkyBridge.hpp"

using namespace sl;

SkyBridge::Listener::Listener(const Side _side):
    side(_side)
{
}

SkyBridge::Listener::~Listener()
{
}

SkyBridge::SkyBridge(Listener& _listener):
    listener(_listener),
    state(*(new state::Idle(*this)))
{
}

void SkyBridge::notifyEndpointEvent(const event::endpoint::Event& event)
{
    listener.trace(std::string("Handling: ") + event.toString());
}

void SkyBridge::notifyBridgeEvent(const event::bridge::Event& event)
{
    listener.notifyBridgeEvent(event);
}

std::shared_ptr<ITimer> SkyBridge::createTimer()
{
    return listener.createTimer();
}

void SkyBridge::trace(const std::string& message)
{
    listener.trace(message);
}
