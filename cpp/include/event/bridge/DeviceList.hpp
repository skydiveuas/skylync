#ifndef EVENT_BRIDGE_DEVICELIST_HPP
#define EVENT_BRIDGE_DEVICELIST_HPP

#include "Event.hpp"

#include "skylync.pb.h"

namespace sl
{

namespace event
{

namespace bridge
{

class DeviceList : public Event
{
public:
    DeviceList(const skylync::DeviceList& _deviceList);

    std::string toString() const noexcept override;

    const sl::DeviceList& getDeviceList() const;

private:
    sl::DeviceList deviceList;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_DEVICELIST_HPP
