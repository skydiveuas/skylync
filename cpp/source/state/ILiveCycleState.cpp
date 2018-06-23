#include "state/ILiveCycleState.hpp"

using namespace sl::event;
using namespace sl::state;

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

void ILiveCycleState::start(const endpoint::Event* const event) noexcept
{
    exceptUnexpected("Start method with event: [" + event->toString() + "]");
}

void ILiveCycleState::handleEvent(const endpoint::Event& event)
{
    exceptUnexpected(event);
}

void ILiveCycleState::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
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

void ILiveCycleState::onReceived(const ICommInterface::DataPacket dataPacket)
{
    listener.getParser().parse(dataPacket);
}

void ILiveCycleState::send(const skylync::EndpointMessage& message)
{
    trace("Sending message: [" + message.DebugString() + "]");
    controlCommInterface.send(listener.getParser().serialize(message));
}

void ILiveCycleState::notifyBridgeEvent(const bridge::Event* const event)
{
    listener.getBridgeListener().notifyBridgeEvent(event);
}

void ILiveCycleState::trace(const std::string& message)
{
    listener.getBridgeListener().trace(message);
}

void ILiveCycleState::except(const std::string& cause) const
{
    throw std::runtime_error(cause + " @ " + toString());
}

void ILiveCycleState::exceptUnexpected(const std::shared_ptr<skylync::BridgeMessage> message) const
{
    exceptUnexpected(message->DebugString());
}

void ILiveCycleState::exceptUnexpected(const endpoint::Event& event) const
{
    exceptUnexpected(event.toString());
}

void ILiveCycleState::exceptUnexpected(const std::string& cause) const
{
    except("Unexpected: [" + cause + "]");
}
