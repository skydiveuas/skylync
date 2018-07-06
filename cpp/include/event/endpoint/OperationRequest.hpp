#ifndef EVENT_ENDPOINT_OPERATIONREQUEST_HPP
#define EVENT_ENDPOINT_OPERATIONREQUEST_HPP

#include "Event.hpp"

namespace sl
{

namespace event
{

namespace endpoint
{

class OperationRequest : public Event
{
public:
    OperationRequest(const RefId refId);

    std::string toString() const noexcept override;

    RefId getRefId() const noexcept;

private:
    const RefId refId;
};

} // endpoint

} // event

} // sl

#endif // EVENT_ENDPOINT_OPERATIONREQUEST_HPP
