#include "state/Release.hpp"

#include "state/Disconnection.hpp"

using sl::state::Release;

Release::Release(Listener& listener):
    ILiveCycleState(Type::RELEASE, listener)
{
}

void Release::start(const EndpointEvent* const) noexcept
{
    send("MESSAGE:RELEASE");
}

void Release::handleMessage(const Message& message)
{
    trace("Received: [" + message + "] - released");
    switchState<sl::state::Disconnection>();
}

std::string Release::toString() const noexcept
{
    return "RELEASE";
}
