#include "state/attached/device/Ready.hpp"

#include "state/attached/Release.hpp"
#include "state/attached/device/Operation.hpp"
#include "state/attached/device/OperationEstablishment.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::device;

Ready::Ready(ILiveCycleState::Listener& listener):
    IAttachedState(listener),
    event(nullptr)
{
}

Ready::Ready(ILiveCycleState::Listener& listener, const bridge::Event* const _event):
    IAttachedState(listener),
    event(_event)
{
}

void Ready::start() noexcept
{
    if (event)
    {
        notifyBridgeEvent(event);
        event = nullptr;
    }
}

sl::state::attached::IAttachedState* Ready::handleEvent(const endpoint::Event& event)
{
    switch (event.getType())
    {
    case endpoint::Event::RELEASE:
        return new Release(listener);

    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

IAttachedState* Ready::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    switch (message->base().command())
    {
    case skylync::Message::OPERATION_STARTED:
        return new OperationEstablishment(listener);

    default:
        exceptUnexpected(message);
        return nullptr;
    }
}

std::string Ready::toString() const noexcept
{
    return "Attached::Device::Ready";
}
