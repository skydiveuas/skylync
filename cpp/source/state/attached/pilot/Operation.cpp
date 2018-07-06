#include "state/attached/pilot/Operation.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::pilot;

Operation::Operation(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Operation::start() noexcept
{
}

IAttachedState* Operation::handleEvent(const sl::event::endpoint::Event& event)
{
    switch (event.getType())
    {
    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

IAttachedState* Operation::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    exceptUnexpected(message);
    return nullptr;
}

std::string Operation::toString() const noexcept
{
    return "Attached::Device::Operation";
}
