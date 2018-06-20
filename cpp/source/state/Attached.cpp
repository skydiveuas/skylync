#include "state/Attached.hpp"

#include "state/Release.hpp"

#include "state/attached/device/Ready.hpp"
#include "state/attached/pilot/Ready.hpp"

using sl::state::Attached;

Attached::Attached(Listener& listener):
    ILiveCycleState(Type::ATTACHED, listener)
{
}

void Attached::start(const EndpointEvent* const) noexcept
{
    switch (listener.getBridgeListener().side)
    {
    case sl::SkyBridgeListener::DEVICE:
        switchSubState(new sl::state::attached::device::Ready(listener));
        break;

    case sl::SkyBridgeListener::PILOT:
        switchSubState(new sl::state::attached::pilot::Ready(listener));
        break;

    default:
        exceptUnexpected("Endpoint side type");
    }
}

void Attached::handleEvent(const EndpointEvent& event)
{
    trace("Handlinig: [" + event.toString() + "] @ " + toString());
    sl::state::attached::IAttachedState* newState(subState->handleEvent(event));
    if (nullptr != newState)
    {
        switchSubState(newState);
    }
}

void Attached::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    trace("Received: [" + message->DebugString() + "] @ " + toString());
    sl::state::attached::IAttachedState* newState(subState->handleMessage(message));
    if (nullptr != newState)
    {
        switchSubState(newState);
    }
}

std::string Attached::toString() const noexcept
{
    return subState != nullptr ? subState->toString() : "ATTACHED";
}

void Attached::switchSubState(sl::state::attached::IAttachedState* newState)
{
    std::unique_ptr<sl::state::attached::IAttachedState> guard(newState);
    subState.swap(guard);
    subState->start();
}
