#include "event/endpoint/RequestDevice.hpp"

using namespace sl::event::endpoint;

RequestDevice::RequestDevice(const sl::RefId _refId):
    Event(Event::REQUEST_DEVICE),
    refId(_refId)
{
}

std::string RequestDevice::toString() const noexcept
{
    return "REQUEST_DEVICE[refId:" + std::to_string(refId) + "]";
}
