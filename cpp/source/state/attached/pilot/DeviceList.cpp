#include "state/attached/pilot/DeviceList.hpp"

#include "state/attached/pilot/Ready.hpp"

#include "event/bridge/DeviceList.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::pilot;

DeviceList::DeviceList(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void DeviceList::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::DEVICE_LIST);
    send(message);
}

IAttachedState* DeviceList::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    if (message->base().command() == skylync::Message::ACCEPT &&
            message->base().responsefor() == skylync::Message::DEVICE_LIST &&
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

std::string DeviceList::toString() const noexcept
{
    return "Attached::Pilot::DeviceList";
}
