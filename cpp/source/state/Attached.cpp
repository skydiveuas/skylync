#include "state/Attached.hpp"

#include "state/Release.hpp"

#include "state/attached/device/Ready.hpp"
#include "state/attached/pilot/Ready.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;

Attached::Attached(Listener& listener):
    ILiveCycleState(Type::ATTACHED, listener)
{
}

void Attached::start(const endpoint::Event* const) noexcept
{
    switch (listener.getBridgeListener().side)
    {
    case sl::EndpointType::DEVICE:
        switchSubState(new device::Ready(listener, new bridge::Event(bridge::Event::ATTACHED)));
        break;

    case sl::EndpointType::PILOT:
        switchSubState(new pilot::Ready(listener, new bridge::Event(bridge::Event::ATTACHED)));
        break;

    default:
        exceptUnexpected("Endpoint side type");
    }
}

void Attached::handleEvent(const endpoint::Event& event)
{
    IAttachedState* newState(subState->handleEvent(event));
    if (nullptr != newState)
    {
        switchSubState(newState);
    }
}

void Attached::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    IAttachedState* newState(subState->handleMessage(message));
    if (nullptr != newState)
    {
        switchSubState(newState);
    }
}

std::string Attached::toString() const noexcept
{
    return subState != nullptr ? subState->toString() : "ATTACHED";
}

void Attached::switchSubState(IAttachedState* newState)
{
    std::unique_ptr<IAttachedState> guard(newState);
    subState.swap(guard);
    subState->start();
}
