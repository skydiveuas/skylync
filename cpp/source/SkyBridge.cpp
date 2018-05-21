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
    state(new sl::state::Idle(*this))
{
}

void SkyBridge::notifyEndpointEvent(const sl::event::endpoint::Event* event) noexcept
{
    handleEvent(event);
}

sl::state::IState::Type SkyBridge::getState() const noexcept
{
    return state->getType();
}

void SkyBridge::handleEvent(const sl::event::endpoint::Event* event) noexcept
{
    std::unique_ptr<const sl::event::endpoint::Event> eventLock(event);
    listener.trace(std::string("Handling: ") + event->toString());
    try
    {
        std::unique_lock<std::mutex> lockGuard(stateLock);
        std::unique_ptr<sl::state::IState> newState(state->handleEvent(*event));
        if (nullptr != newState.get())
        {
            listener.trace("State transition: [" + state->toString() +
                           " -> " + newState->toString() + "]");
            state.swap(newState);
        }
    }
    catch (const std::runtime_error& e)
    {
        using sl::event::bridge::Message;
        notifyBridgeEvent(new Message(e.what()));
    }
}

void SkyBridge::handleMessage() noexcept
{
    listener.trace(std::string("Handling: "));
    try
    {
        std::unique_lock<std::mutex> lockGuard(stateLock);
        std::unique_ptr<sl::state::IState> newState(state->handleMessage());
        if (nullptr != newState.get())
        {
            listener.trace("State transition: [" + state->toString() +
                           " -> " + newState->toString() + "]");
            state.swap(newState);
        }
    }
    catch (const std::runtime_error& e)
    {
        using sl::event::bridge::Message;
        notifyBridgeEvent(new Message(e.what()));
    }
}

void SkyBridge::onConnected()
{

}

void SkyBridge::onDisconnected()
{

}

void SkyBridge::onReceived(const unsigned char* data, const size_t length)
{

}

void SkyBridge::connect()
{
    listener.trace("SkyBridge::connect");
    commInterface = listener.createCommInterface(sl::ICommInterface::TCP, *this);
    commInterface->connect();
}

void SkyBridge::disconnect()
{
    listener.trace("SkyBridge::disconnect");

}

void SkyBridge::notifyBridgeEvent(const sl::event::bridge::Event* event) noexcept
{
    listener.trace("Emitting: " + event->toString());
    listener.notifyBridgeEvent(event);
}


std::shared_ptr<sl::ICommInterface>
SkyBridge::createCommInterface(const sl::ICommInterface::TransportProtocol protocol,
                               const sl::ICommInterface::Listener& _listener) noexcept
{
    listener.trace("SkyBridge::disconnect");
    return listener.createCommInterface(protocol, _listener);
}

std::shared_ptr<sl::ITimer> SkyBridge::createTimer() noexcept
{
    listener.trace("SkyBridge::createTimer");
    return listener.createTimer();
}

void SkyBridge::trace(const std::string& message) noexcept
{
    listener.trace(message);
}
