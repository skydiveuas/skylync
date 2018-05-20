#include "state/Attached.hpp"

using sl::state::Attached;
using sl::event::endpoint::Event;

Attached::Attached(Listener& listener):
    IState(ATTACHED, listener)
{
}

IState* Attached::handleEvent(const Event& event)
{

}

IState* Attached::handleMessage()
{

}

std::string Attached::toString() const noexcept
{
    return "Attached";
}
