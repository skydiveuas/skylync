#include "state/Attaching.hpp"

using sl::state::Attaching;
using sl::event::endpoint::Event;

Attaching::Attaching(Listener& listener):
    IState(ATTACHING, listener)
{
}

sl::state::IState* Attaching::handleEvent(const Event& event)
{
    return nullptr;
}

sl::state::IState* Attaching::handleMessage()
{
    return nullptr;
}

std::string Attaching::toString() const noexcept
{
    return "Attaching";
}
