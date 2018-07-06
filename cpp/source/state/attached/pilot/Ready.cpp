#include "state/attached/pilot/Ready.hpp"

#include "state/attached/Release.hpp"

#include "state/attached/pilot/DeviceList.hpp"
#include "state/attached/pilot/OperationEstablishment.hpp"

#include "event/endpoint/OperationRequest.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::pilot;

Ready::Ready(ILiveCycleState::Listener& listener):
    IAttachedState(listener),
    event(nullptr)
{
}

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

    case endpoint::Event::DEVICE_LIST:
        return new DeviceList(listener);

    case endpoint::Event::DEVICE_STATUS:
        return new DeviceList(listener);

    case endpoint::Event::OPERATION_REQUEST:
        return new pilot::OperationEstablishment(listener,
                                        reinterpret_cast<const endpoint::OperationRequest&>(event).getRefId());

    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

std::string Ready::toString() const noexcept
{
    return "Attached::Pilot::Ready";
}
