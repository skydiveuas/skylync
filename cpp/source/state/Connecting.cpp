#include "state/Connecting.hpp"

using sl::state::Connecting;
using sl::event::endpoint::Event;

Connecting::Connecting(Listener& listener):
    IState(CONNECTING, listener)
{
}

sl::state::IState* Connecting::handleEvent(const Event& event)
{
    return nullptr;
}

sl::state::IState* Connecting::handleMessage()
{
    return nullptr;
}

std::string Connecting::toString() const noexcept
{
    return "Connecting";
}
