#include "state/Release.hpp"

#include "state/Disconnection.hpp"

using namespace sl::event;
using namespace sl::state;

Release::Release(Listener& listener):
    ILiveCycleState(Type::RELEASE, listener)
{
}

void Release::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::RELEASE);
    send(message);
}

void Release::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    if (message->has_base() &&
            message->base().command() == skylync::Message::ACCEPT)
    {
        notifyBridgeEvent(new bridge::Event(bridge::Event::RELEASED));
        switchState<Disconnection>();
    }
}

std::string Release::toString() const noexcept
{
    return "Release";
}
