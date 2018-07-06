#include "event/bridge/DeviceStatus.hpp"

using namespace sl::event::bridge;

DeviceStatus::DeviceStatus():
    Event(Event::DEVICE_STATUS)
{
}

std::string DeviceStatus::toString() const noexcept
{
    return "DEVICESTATUS[]";
}
