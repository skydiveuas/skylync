#include "SkyBridge.hpp"

#include "state/Released.hpp"
#include "state/Connecting.hpp"
#include "state/Disconnecting.hpp"

#include "event/bridge/Message.hpp"
#include "event/bridge/Error.hpp"

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
    state(new sl::state::Released(*this))
{
}

void SkyBridge::notifyEndpointEvent(const EndpointEvent* event) noexcept
{
    handleEvent(event);
}

sl::state::IState::Type SkyBridge::getState() const noexcept
{
    return state->getType();
}

void SkyBridge::handleEvent(const EndpointEvent* event) noexcept
{
    std::unique_ptr<const EndpointEvent> eventLock(event);
    listener.trace(std::string("Handling: ") + event->toString());
    try
    {
        std::unique_lock<std::mutex> lockGuard(stateLock);
        std::unique_ptr<State> newState(state->handleEvent(*event));
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
        std::unique_ptr<State> newState(state->handleMessage());
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
    listener.trace("SkyBridge::onConnected");
    try
    {
        std::unique_lock<std::mutex> lockGuard(stateLock);
        if (State::CONNECTING == getState())
        {
            std::unique_ptr<State> newState(
                        reinterpret_cast<sl::state::Connecting*>(state.get())->notifyConnected());
            if (nullptr != newState.get())
            {
                listener.trace("State transition: [" + state->toString() +
                               " -> " + newState->toString() + "]");
                state.swap(newState);
            }
        }
    }
    catch (const std::runtime_error& e)
    {
        using sl::event::bridge::Message;
        notifyBridgeEvent(new Message(e.what()));
    }
}

void SkyBridge::onDisconnected()
{
    listener.trace("SkyBridge::onDisconnected");
    try
    {
        std::unique_lock<std::mutex> lockGuard(stateLock);
        if (State::DISCONNECTING == getState())
        {
            std::unique_ptr<State> newState(
                        reinterpret_cast<sl::state::Disconnecting*>(state.get())->notifyDisconnected());
            if (nullptr != newState.get())
            {
                listener.trace("State transition: [" + state->toString() +
                               " -> " + newState->toString() + "]");
                state.swap(newState);
            }
        }
    }
    catch (const std::runtime_error& e)
    {
        using sl::event::bridge::Message;
        notifyBridgeEvent(new Message(e.what()));
    }
}

void SkyBridge::onReceived(const unsigned char*, const size_t)
{
    // TODO encode Google Protocol message
    state->handleMessage();
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
    commInterface->disconnect();
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
