#include "state/attached/device/Ready.hpp"

#include "state/attached/Release.hpp"

using sl::state::attached::device::Ready;

Ready::Ready(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Ready::start() noexcept
{
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::ATTACHED));
}

sl::state::attached::IAttachedState* Ready::handleEvent(const EndpointEvent& event)
{
    switch (event.getType())
    {
    case sl::event::endpoint::Event::RELEASE:
        return new sl::state::attached::Release(listener);

    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

std::string Ready::toString() const noexcept
{
    return "Attached::Device::READY";
}
