#include "state/Attached.hpp"

using sl::state::Attached;
using sl::event::endpoint::Event;

Attached::Attached(Listener& listener):
    IState(ATTACHED, listener)
{
}

void Attached::handleEvent(const Event& event)
{

}

void Attached::handleMessage()
{

}

std::string Attached::toString() const noexcept
{
    return "Attached";
}
