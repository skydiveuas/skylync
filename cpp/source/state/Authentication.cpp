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
    send(reinterpret_cast<const sl::event::endpoint::Attach* const>(event)->getMessage());
}

void Authentication::handleMessage(const Message& message)
{
    trace("Received: [" + message + "] - authenticated");
    switchState<sl::state::Attached>();
}

std::string Authentication::toString() const noexcept
{
    return "AUTHENTICATION";
}
