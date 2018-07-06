#ifndef EVENT_BRIDGE_DEVICESTATUS_HPP
#define EVENT_BRIDGE_DEVICESTATUS_HPP

#include "Event.hpp"

#include "skylync.pb.h"

namespace sl
{

namespace event
{

namespace bridge
{

class DeviceStatus : public Event
{
public:
    DeviceStatus();

    std::string toString() const noexcept override;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_DEVICELIST_HPP
