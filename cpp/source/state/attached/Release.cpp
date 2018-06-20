#include "state/attached/Release.hpp"

using sl::state::attached::Release;

Release::Release(sl::state::ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Release::start(const sl::event::endpoint::Event* const) noexcept
{
}

sl::state::attached::IAttachedState* Release::handleEvent(const sl::event::endpoint::Event&)
{
    return nullptr;
}

sl::state::attached::IAttachedState* Release::handleMessage(std::shared_ptr<skylync::BridgeMessage>)
{
    return nullptr;
}

std::string Release::toString() const noexcept
{
    return "Attached::RELEASE";
}
