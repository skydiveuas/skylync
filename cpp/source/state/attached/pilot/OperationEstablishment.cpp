#include "state/attached/pilot/OperationEstablishment.hpp"

#include "state/attached/pilot/Ready.hpp"
#include "state/attached/pilot/Operation.hpp"

#include "event/bridge/DeviceList.hpp"
#include "event/bridge/Error.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::pilot;

OperationEstablishment::OperationEstablishment(ILiveCycleState::Listener& listener, const RefId _requestedRefId):
    IAttachedState(listener),
    requestedRefId(_requestedRefId)
{
}

void OperationEstablishment::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::OPERATION_REQUEST);
    message.mutable_operationparams()->set_refid(requestedRefId);
    send(message);
}

IAttachedState* OperationEstablishment::handleEvent(const sl::event::endpoint::Event& event)
{
    switch (event.getType())
    {
    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

IAttachedState* OperationEstablishment::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    if (skylync::Message::OPERATION_REQUEST == message->base().responsefor())
    {
        switch (message->base().command())
        {
        case skylync::Message::ACCEPT:
            return sendFlightTunnelReqest();

        case skylync::Message::REJECT:
            return new Ready(listener, new bridge::Error("Request device failed: " +
                                                         skylync::Message_Cause_Name(message->base().cause())));

        default:
            exceptUnexpected(message);
        }
    }
    else
    {
        exceptUnexpected(message);
    }
    return nullptr;
}

std::string OperationEstablishment::toString() const noexcept
{
    return "Attached::Pilot::OperationEstablishment";
}

IAttachedState* OperationEstablishment::sendFlightTunnelReqest() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::TUNNEL_REQUEST);
    message.mutable_channelparams()->set_channelid(sl::FLIGHT_UDP);
    send(message);
    return new Operation(listener);
}
