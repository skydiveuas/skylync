#include "event/bridge/DeviceList.hpp"

using namespace sl::event::bridge;

DeviceList::DeviceList(const skylync::DeviceList& _deviceList):
    Event(Event::DEVICE_LIST)
{
    deviceList.resize(_deviceList.devices_size());
    for (size_t i = 0; i < _deviceList.devices_size(); ++i)
    {
        const skylync::DeviceId& device = _deviceList.devices(i);
        deviceList.push_back(RefName(device.ref(), device.name()));
    }
}

std::string DeviceList::toString() const noexcept
{
    return "DEVICELIST[" + std::to_string(deviceList.size()) + "]";
}

const sl::DeviceList& DeviceList::getDeviceList() const
{
    return deviceList;
}
