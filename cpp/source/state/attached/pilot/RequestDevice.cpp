#include "state/attached/pilot/RequestDevice.hpp"

#include "state/attached/pilot/Ready.hpp"

#include "event/bridge/DeviceList.hpp"
#include "event/bridge/Error.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::pilot;

RequestDevice::RequestDevice(ILiveCycleState::Listener& listener, const RefId _requestedRefId):
    IAttachedState(listener),
    requestedRefId(_requestedRefId)
{
}

void RequestDevice::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::REQUEST_DEVICE);
    message.mutable_requestdeviceparams()->set_refid(requestedRefId);
    send(message);
}

IAttachedState* RequestDevice::handleEvent(const sl::event::endpoint::Event& event)
{
    switch (event.getType())
    {
    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

IAttachedState* RequestDevice::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    if (message->base().command() == skylync::Message::ACCEPT &&
            message->base().responsefor() == skylync::Message::REQUEST_DEVICE)
    {
        trace("====================== device!!!! ==========");
    }
    else
    {
        exceptUnexpected(message);
        return nullptr;
    }
    return nullptr;
}

std::string RequestDevice::toString() const noexcept
{
    return "Attached::Pilot::REQUEST_DEVICE";
}
