#include "state/Authentication.hpp"

#include "state/Attached.hpp"
#include "state/Disconnected.hpp"

#include "event/endpoint/Attach.hpp"

using namespace sl::event;
using namespace sl::state;

Authentication::Authentication(Listener& listener, const endpoint::Attach& _attach):
    ILiveCycleState(Type::AUTHENTICATION, listener),
    attach(_attach)
{
}

void Authentication::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::ATTACH);
    message.mutable_attachparams()->set_id(attach.getId());
    message.mutable_attachparams()->set_pwd(attach.getPwd());
    send(message);
}

void Authentication::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    if (message->has_base() &&
            message->base().command() == skylync::Message::ACCEPT &&
            message->has_context())
    {
        listener.updateContext(message->release_context());
        switchState<sl::state::Attached>();
    }
    else
    {
        switchState<sl::state::Disconnected>();
    }
}

std::string Authentication::toString() const noexcept
{
    return "Authentication";
}
