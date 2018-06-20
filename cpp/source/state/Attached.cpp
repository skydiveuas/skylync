#include "state/Attached.hpp"

#include "state/Release.hpp"

#include "state/attached/device/Ready.hpp"
#include "state/attached/pilot/Ready.hpp"

using sl::state::Attached;

Attached::Attached(Listener& listener):
    ILiveCycleState(Type::ATTACHED, listener)
{
}

void Attached::start(const EndpointEvent* const event) noexcept
{
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::ATTACHED));
    switch (listener.getBridgeListener().side)
    {
    case sl::SkyBridgeListener::DEVICE:
        switchSubState(new sl::state::attached::device::Ready(listener), event);
        break;

    case sl::SkyBridgeListener::PILOT:
        switchSubState(new sl::state::attached::pilot::Ready(listener), event);
        break;

    default:
        break;
    }
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

void Attached::switchSubState(sl::state::attached::IAttachedState* newState, const EndpointEvent* const event)
{
    std::unique_ptr<sl::state::attached::IAttachedState> guard(newState);
    subState.swap(guard);
    subState->start(event);
}
