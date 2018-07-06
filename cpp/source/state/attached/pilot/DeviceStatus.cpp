#include "state/attached/pilot/DeviceStatus.hpp"

#include "state/attached/pilot/Ready.hpp"

#include "event/bridge/DeviceStatus.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::pilot;

DeviceStatus::DeviceStatus(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void DeviceStatus::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::DEVICE_STATUS);
    send(message);
}

IAttachedState* DeviceStatus::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    if (message->base().command() == skylync::Message::ACCEPT &&
            message->base().responsefor() == skylync::Message::DEVICE_STATUS &&
            message->has_devicelist())
    {
        return new Ready(listener, new bridge::DeviceStatus());
    }
    else
    {
        exceptUnexpected(message);
        return nullptr;
    }
}

std::string DeviceStatus::toString() const noexcept
{
    return "Attached::Pilot::DeviceStatus";
}
