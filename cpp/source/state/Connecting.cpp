#include "state/Connecting.hpp"

using sl::state::Connecting;
using sl::event::endpoint::Event;

Connecting::Connecting(Listener& listener):
    IState(CONNECTING, listener)
{
}

void Connecting::handleEvent(const Event& event)
{

}

void Connecting::handleMessage()
{

}

std::string Connecting::toString() const noexcept
{
    return "Connecting";
}
