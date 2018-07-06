#include "state/attached/device/Operation.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::device;

Operation::Operation(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Operation::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_responsefor(skylync::Message::OPERATION_STARTED);
    message.mutable_base()->set_command(skylync::Message::ACCEPT);
    send(message);
}

IAttachedState* Operation::handleEvent(const sl::event::endpoint::Event& event)
{
    switch (event.getType())
    {
    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

IAttachedState* Operation::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    switch (message->base().command())
    {
    case skylync::Message::CHANNEL_OPEN:
        openChannel(message->channelparams());
        return nullptr;

    default:
        exceptUnexpected(message);
        return nullptr;
    }
}

std::string Operation::toString() const noexcept
{
    return "Attached::Pilot::Operation";
}

void Operation::openChannel(const skylync::ChannelParams&)
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_responsefor(skylync::Message::CHANNEL_OPEN);
    message.mutable_base()->set_command(skylync::Message::ACCEPT);
    send(message);
}
