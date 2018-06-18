#include "state/Authentication.hpp"

#include "state/Attached.hpp"

#include "event/endpoint/Attach.hpp"

using sl::state::Authentication;

Authentication::Authentication(Listener& listener):
    ILiveCycleState(Type::AUTHENTICATION, listener)
{
}

void Authentication::start(const EndpointEvent* const event) noexcept
{
    //send(reinterpret_cast<const sl::event::endpoint::Attach* const>(event)->getMessage());
}

void Authentication::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    trace("Received: [" + message->DebugString() + "]");
}

std::string Authentication::toString() const noexcept
{
    return "AUTHENTICATION";
}
