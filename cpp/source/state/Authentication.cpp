#include "state/Authentication.hpp"

#include "state/Attached.hpp"
#include "state/Disconnected.hpp"

#include "event/endpoint/Attach.hpp"

using sl::state::Authentication;

Authentication::Authentication(Listener& listener):
    ILiveCycleState(Type::AUTHENTICATION, listener)
{
}

void Authentication::start(const EndpointEvent* const event) noexcept
{
    const sl::event::endpoint::Attach& attach =
            *reinterpret_cast<const sl::event::endpoint::Attach* const>(event);
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::ATTACH);
    message.mutable_attachparams()->set_id(attach.getId());
    message.mutable_attachparams()->set_pwd(attach.getPwd());
    send(message);
}

void Authentication::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    trace("Received: [" + message->DebugString() + "]");
    if (message->has_base() &&
            message->base().command() == skylync::Message::ACCEPT)
    {
        switchState<sl::state::Attached>();
    }
    else
    {
        switchState<sl::state::Disconnected>();
    }
}

std::string Authentication::toString() const noexcept
{
    return "AUTHENTICATION";
}
