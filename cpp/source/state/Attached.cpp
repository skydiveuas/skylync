#include "state/Attached.hpp"

using sl::state::Attached;
using sl::event::endpoint::Event;

Attached::Attached(Listener& listener):
    IState(ATTACHED, listener)
{
}

sl::state::IState* Attached::handleEvent(const Event& event)
{
    return nullptr;
}

sl::state::IState* Attached::handleMessage()
{
    return nullptr;
}

std::string Attached::toString() const noexcept
{
    return "Attached";
}
