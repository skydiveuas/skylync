#include "state/Attached.hpp"

#include "state/Release.hpp"

using sl::state::Attached;

Attached::Attached(Listener& listener):
    ILiveCycleState(Type::ATTACHED, listener)
{
}

void Attached::start(const EndpointEvent* const) noexcept
{
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::ATTACHED));
}

void Attached::handleEvent(const EndpointEvent& event)
{
    switch (event.getType())
    {
    case EndpointEvent::RELEASE:
        switchState<sl::state::Release>();
        break;

    default:
        exceptUnexpected(event);
        break;
    }
}

void Attached::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    trace("Received: [" + message->DebugString() + "]");
}

std::string Attached::toString() const noexcept
{
    return "ATTACHED";
}
