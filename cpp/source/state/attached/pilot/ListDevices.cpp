#include "state/attached/pilot/ListDevices.hpp"

#include "state/attached/pilot/Ready.hpp"

using sl::state::attached::pilot::ListDevices;

ListDevices::ListDevices(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void ListDevices::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_command(skylync::Message::LIST_DEVICE);
    // TODO set device refId
    send(message);
}

sl::state::attached::IAttachedState* ListDevices::handleEvent(const EndpointEvent& event)
{
    switch (event.getType())
    {
    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

sl::state::attached::IAttachedState* ListDevices::handleMessage(std::shared_ptr<skylync::BridgeMessage>)
{
    // TODO handle bridge response
    return nullptr;
}

std::string ListDevices::toString() const noexcept
{
    return "Attached::Pilot::LIST_DEVICES";
}
