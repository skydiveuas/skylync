#include "state/attached/IAttachedState.hpp"

using sl::state::attached::IAttachedState;

IAttachedState::IAttachedState(sl::state::ILiveCycleState::Listener& _listener):
    listener(_listener),
    controlCommInterface(listener.getControlCommInterface())
{
}

void IAttachedState::start(const sl::event::endpoint::Event* const) noexcept
{
}

sl::state::attached::IAttachedState* IAttachedState::handleEvent(const sl::event::endpoint::Event&)
{
    return nullptr;
}

sl::state::attached::IAttachedState* IAttachedState::handleMessage(std::shared_ptr<skylync::BridgeMessage>)
{
    return nullptr;
}
