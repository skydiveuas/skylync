#include "state/attached/device/Ready.hpp"

using sl::state::attached::device::Ready;

Ready::Ready(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Ready::start(const sl::event::endpoint::Event* const) noexcept
{
}

sl::state::attached::IAttachedState* Ready::handleEvent(const sl::event::endpoint::Event&)
{
    return nullptr;
}

sl::state::attached::IAttachedState* Ready::handleMessage(std::shared_ptr<skylync::BridgeMessage>)
{
    return nullptr;
}

std::string Ready::toString() const noexcept
{
    return "Attached::Device::READY";
}
