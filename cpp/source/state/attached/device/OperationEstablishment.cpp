#include "state/attached/device/OperationEstablishment.hpp"

#include "state/attached/device/Ready.hpp"
#include "state/attached/device/Operation.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::device;

OperationEstablishment::OperationEstablishment(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void OperationEstablishment::start() noexcept
{
    notifyBridgeEvent(new bridge::Event(bridge::Event::OPERATION_REQUESTED));
}

sl::state::attached::IAttachedState* OperationEstablishment::handleEvent(const endpoint::Event& event)
{
    switch (event.getType())
    {
    case endpoint::Event::OPERATION_ACCEPTED:
        return new Operation(listener);

    case endpoint::Event::OPERATION_REJECTED:
        sendReject();
        return new Ready(listener);

    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

IAttachedState* OperationEstablishment::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    switch (message->base().command())
    {

    default:
        exceptUnexpected(message);
        return nullptr;
    }
}

std::string OperationEstablishment::toString() const noexcept
{
    return "Attached::Device::OperationEstablishment";
}

void OperationEstablishment::sendReject() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_responsefor(skylync::Message::OPERATION_STARTED);
    message.mutable_base()->set_command(skylync::Message::REJECT);
    send(message);
}
