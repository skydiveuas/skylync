#include "state/Release.hpp"

#include "state/Disconnection.hpp"

using sl::state::Release;

Release::Release(Listener& listener):
    ILiveCycleState(Type::RELEASE, listener)
{
}

void Release::start(const EndpointEvent* const) noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::RELEASE);
    send(message);
}

void Release::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    trace("Received: [" + message->DebugString() + "]");
    if (message->has_base() &&
            message->base().command() == skylync::Message::ACCEPT)
    {
        notifyBridgeEvent(new sl::event::bridge::Event(sl::event::bridge::Event::RELEASED));
        switchState<sl::state::Disconnection>();
    }
}

std::string Release::toString() const noexcept
{
    return "RELEASE";
}
