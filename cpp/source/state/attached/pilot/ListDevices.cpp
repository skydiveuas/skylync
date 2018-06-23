#include "state/attached/pilot/ListDevices.hpp"

#include "state/attached/pilot/Ready.hpp"

#include "event/bridge/DeviceList.hpp"
#include "event/bridge/Error.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::pilot;

ListDevices::ListDevices(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void ListDevices::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::LIST_DEVICE);
    send(message);
}

IAttachedState* ListDevices::handleEvent(const sl::event::endpoint::Event& event)
{
    switch (event.getType())
    {
    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

IAttachedState* ListDevices::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    if (message->base().command() == skylync::Message::ACCEPT &&
            message->base().responsefor() == skylync::Message::LIST_DEVICE &&
            message->has_devicelist())
    {
        return new Ready(listener, new bridge::DeviceList(message->devicelist()));
    }
    else
    {
        exceptUnexpected(message);
        return nullptr;
    }
}

std::string ListDevices::toString() const noexcept
{
    return "Attached::Pilot::LIST_DEVICES";
}
