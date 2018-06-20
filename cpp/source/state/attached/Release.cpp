#include "state/attached/Release.hpp"

#include "state/Release.hpp"

using sl::state::attached::Release;

Release::Release(sl::state::ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Release::start() noexcept
{
    listener.switchState(std::make_shared<sl::state::Release>(listener), nullptr);
}

std::string Release::toString() const noexcept
{
    return "Attached::RELEASE";
}
