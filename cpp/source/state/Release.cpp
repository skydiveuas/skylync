#include "state/Release.hpp"

#include "state/Disconnection.hpp"

using sl::state::Release;

Release::Release(Listener& listener):
    ILiveCycleState(Type::RELEASE, listener)
{
}

void Release::start(const EndpointEvent* const event) noexcept
{
    //send("MESSAGE:RELEASE");
}

void Release::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    trace("Received: [" + message->DebugString() + "]");
}

std::string Release::toString() const noexcept
{
    return "RELEASE";
}
