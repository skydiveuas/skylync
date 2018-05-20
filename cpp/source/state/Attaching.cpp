#include "state/Attaching.hpp"

using sl::state::Attaching;
using sl::event::endpoint::Event;

Attaching::Attaching(Listener& listener):
    IState(ATTACHING, listener)
{
}

IState* Attaching::handleEvent(const Event& event)
{

}

IState* Attaching::handleMessage()
{

}

std::string Attaching::toString() const noexcept
{
    return "Attaching";
}
