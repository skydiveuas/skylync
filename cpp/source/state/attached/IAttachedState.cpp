#include "state/attached/IAttachedState.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;

IAttachedState::IAttachedState(ILiveCycleState::Listener& _listener):
    listener(_listener),
    controlCommInterface(listener.getControlCommInterface())
{
}

void IAttachedState::start() noexcept
{
}

IAttachedState* IAttachedState::handleEvent(const sl::event::endpoint::Event& event)
{
    exceptUnexpected(event);
    return nullptr;
}

IAttachedState* IAttachedState::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    exceptUnexpected(message);
    return nullptr;
}

void IAttachedState::send(const skylync::EndpointMessage& message)
{
    trace("Sending message: [" + message.DebugString() + "]");
    controlCommInterface.send(listener.getParser().serialize(message));
}

void IAttachedState::notifyBridgeEvent(const event::bridge::Event* const event)
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

void IAttachedState::exceptUnexpected(const endpoint::Event& event) const
{
    exceptUnexpected(event.toString());
}

void IAttachedState::exceptUnexpected(const std::string& cause) const
{
    except("Unexpected: [" + cause + "]");
}

