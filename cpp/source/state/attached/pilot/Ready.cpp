#include "state/attached/pilot/Ready.hpp"

#include "state/attached/pilot/ListDevices.hpp"

#include "state/attached/Release.hpp"

using sl::state::attached::pilot::Ready;

Ready::Ready(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Ready::start() noexcept
{
    std::cout << "aasdasdasdasdasdas" << std::endl;
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::ATTACHED));
}

sl::state::attached::IAttachedState* Ready::handleEvent(const EndpointEvent& event)
{
    switch (event.getType())
    {
    case sl::event::endpoint::Event::RELEASE:
        return new sl::state::attached::Release(listener);

    case sl::event::endpoint::Event::LIST_DEVICES:
        return new sl::state::attached::pilot::ListDevices(listener);

    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

std::string Ready::toString() const noexcept
{
    return "Attached::Pilot::READY";
}
