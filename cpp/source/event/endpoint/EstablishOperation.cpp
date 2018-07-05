#include "event/endpoint/EstablishOperation.hpp"

using namespace sl::event::endpoint;

EstablishOperation::EstablishOperation(const RefId _refId):
    Event(Event::REQUEST_DEVICE),
    refId(_refId)
{
}

std::string EstablishOperation::toString() const noexcept
{
    return "REQUEST_DEVICE[refId:" + std::to_string(refId) + "]";
}

sl::RefId EstablishOperation::getRefId() const noexcept
{
    return refId;
}
