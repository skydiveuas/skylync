#include "state/attached/IAttachedState.hpp"

using sl::state::attached::IAttachedState;

IAttachedState::IAttachedState(sl::state::ILiveCycleState::Listener& _listener):
    listener(_listener),
    controlCommInterface(listener.getControlCommInterface())
{
}

void IAttachedState::start() noexcept
{
}

sl::state::attached::IAttachedState* IAttachedState::handleEvent(const EndpointEvent& event)
{
    exceptUnexpected(event);
    return nullptr;
}

sl::state::attached::IAttachedState* IAttachedState::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    exceptUnexpected(message);
    return nullptr;
}

void IAttachedState::send(const skylync::EndpointMessage& message)
{
    trace("Sending message: [" + message.DebugString() + "]");
    controlCommInterface.send(listener.getParser().serialize(message));
}

void IAttachedState::notifyBridgeEvent(const BridgeEvent* const event)
{
    listener.getBridgeListener().notifyBridgeEvent(event);
}

void IAttachedState::trace(const std::string& message)
{
    listener.getBridgeListener().trace(message);
}

void IAttachedState::except(const std::string& cause) const
{
    throw std::runtime_error(cause + " @ " + toString());
}

void IAttachedState::exceptUnexpected(const std::shared_ptr<skylync::BridgeMessage> message) const
{
    exceptUnexpected(message->DebugString());
}

void IAttachedState::exceptUnexpected(const EndpointEvent& event) const
{
    exceptUnexpected(event.toString());
}

void IAttachedState::exceptUnexpected(const std::string& cause) const
{
    except("Unexpected: [" + cause + "]");
}

