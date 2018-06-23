#ifndef EVENT_ENDPOINT_REQUESTDEVICE_HPP
#define EVENT_ENDPOINT_REQUESTDEVICE_HPP

#include "Event.hpp"

namespace sl
{

namespace event
{

namespace endpoint
{

class RequestDevice : public Event
{
public:
    RequestDevice(const sl::RefId refId);

    std::string toString() const noexcept override;

private:
    const sl::RefId refId;
};

} // endpoint

} // event

} // sl

#endif // EVENT_ENDPOINT_REQUESTDEVICE_HPP
