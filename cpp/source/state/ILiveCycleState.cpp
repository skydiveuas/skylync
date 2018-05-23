#include "state/ILiveCycleState.hpp"

using sl::state::ILiveCycleState;

ILiveCycleState::Listener::~Listener()
{
}

ILiveCycleState::ILiveCycleState(const Type _type, Listener& _listener):
    type(_type),
    listener(_listener),
    controlCommInterface(listener.getControlCommInterface())
{
    listener.getBridgeListener().trace("ctor ILiveCycleState");
    controlCommInterface.setListener(*this);
}

ILiveCycleState::~ILiveCycleState()
{
    listener.getBridgeListener().trace("dtor ILiveCycleState");
}

sl::state::ILiveCycleState::Type ILiveCycleState::getType() const noexcept
{
    return type;
}

void ILiveCycleState::start(const EndpointEvent* const event) noexcept
{
    exceptUnexpected("Start method with event: [" + event->toString() + "]");
}

void ILiveCycleState::handleEvent(const EndpointEvent& event)
{
    exceptUnexpected(event);
}

void ILiveCycleState::handleMessage(const Message& message)
{
    exceptUnexpected(message);
}

void ILiveCycleState::onConnected()
{
    exceptUnexpected("onConnected");
}

void ILiveCycleState::onDisconnected()
{
    exceptUnexpected("onDisconnected");
}

void ILiveCycleState::onReceived(const sl::ICommInterface::DataPacket dataPacket)
{
    handleMessage(Message(reinterpret_cast<const char* const>(dataPacket.first), dataPacket.second));
}

void ILiveCycleState::send(const Message& message)
{
    trace("Sending message: [" + message + "]");
    controlCommInterface.send(sl::ICommInterface::DataPacket(reinterpret_cast<const unsigned char* const>(message.c_str()), message.size()));
}

void ILiveCycleState::notifyBridgeEvent(const BridgeEvent* const event)
{
    listener.getBridgeListener().notifyBridgeEvent(event);
}

void ILiveCycleState::trace(const std::string& message)
{
    listener.getBridgeListener().trace(message);
}

void ILiveCycleState::except(const std::string& message) const
{
    throw std::runtime_error(message + " @ " + toString());
}

void ILiveCycleState::exceptUnexpected(const std::string& message) const
{
    except("Unexpected: [" + message + "]");
}

void ILiveCycleState::exceptUnexpected(const EndpointEvent& event) const
{
    exceptUnexpected(event.toString());
}
