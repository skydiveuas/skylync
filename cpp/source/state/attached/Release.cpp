#include "state/attached/Release.hpp"

#include "state/Release.hpp"

using namespace sl::event;
using namespace sl::state::attached;

Release::Release(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Release::start() noexcept
{
    listener.switchState(std::make_shared<state::Release>(listener));
}

std::string Release::toString() const noexcept
{
    return "Attached::Release";
}
