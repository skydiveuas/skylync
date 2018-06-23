#include "state/attached/pilot/Ready.hpp"

#include "state/attached/Release.hpp"

#include "state/attached/pilot/ListDevices.hpp"
#include "state/attached/pilot/RequestDevice.hpp"

#include "event/endpoint/RequestDevice.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::pilot;

Ready::Ready(ILiveCycleState::Listener& listener, const bridge::Event* const _event):
    IAttachedState(listener),
    event(_event)
{
}

void Ready::start() noexcept
{
    if (event)
    {
        notifyBridgeEvent(event);
        event = nullptr;
    }
}

IAttachedState* Ready::handleEvent(const endpoint::Event& event)
{
    switch (event.getType())
    {
    case endpoint::Event::RELEASE:
        return new Release(listener);

    case endpoint::Event::LIST_DEVICES:
        return new ListDevices(listener);

    case endpoint::Event::REQUEST_DEVICE:
        return new pilot::RequestDevice(listener,
                                        reinterpret_cast<const endpoint::RequestDevice&>(event).getRefId());

    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

std::string Ready::toString() const noexcept
{
    return "Attached::Pilot::READY";
}
