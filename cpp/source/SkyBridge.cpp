#include "SkyBridge.hpp"

#include "event/bridge/Message.hpp"

using sl::SkyBridge;

SkyBridge::Listener::Listener(const Side _side):
    side(_side)
{
}

SkyBridge::Listener::~Listener()
{
}

SkyBridge::SkyBridge(Listener& _listener):
    listener(_listener),
    state(std::make_shared<sl::state::IState>(new sl::state::Idle(*this)))
{
}

void SkyBridge::notifyEndpointEvent(const sl::event::endpoint::Event& event) noexcept
{
    listener.trace(std::string("Handling: ") + event.toString());
    try
    {
        sl::state::IState* newState = state->handleEvent(event);
        if (nullptr != newState)
        {
            state.swap(std::shared_ptr<sl::state::IState>(newState));
            //std::shared_ptr<sl::state::IState> stateGuard();
        }
    }
    catch (const std::runtime_error& e)
    {
        using sl::event::bridge::Message;
        notifyBridgeEvent(*(new Message(e.what())));
    }
}

sl::state::IState::Type SkyBridge::getState() const noexcept
{
    return state->getType();
}

void SkyBridge::notifyBridgeEvent(const sl::event::bridge::Event& event) noexcept
{
    listener.trace(std::string("Emitting: ") + event.toString());
    listener.notifyBridgeEvent(event);
}

std::shared_ptr<sl::ITimer> SkyBridge::createTimer() noexcept
{
    return listener.createTimer();
}

void SkyBridge::trace(const std::string& message) noexcept
{
    listener.trace(message);
}
