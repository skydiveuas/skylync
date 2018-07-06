#include "event/endpoint/OperationRequest.hpp"

using namespace sl::event::endpoint;

OperationRequest::OperationRequest(const RefId _refId):
    Event(Event::OPERATION_REQUEST),
    refId(_refId)
{
}

std::string OperationRequest::toString() const noexcept
{
    return "OPERATION_REQUEST[refId:" + std::to_string(refId) + "]";
}

sl::RefId OperationRequest::getRefId() const noexcept
{
    return refId;
}
