#include "state/Attaching.hpp"

using sl::state::Attaching;
using sl::event::endpoint::Event;

Attaching::Attaching(Listener& listener):
    IState(ATTACHING, listener)
{
}

void Attaching::handleEvent(const Event& event)
{

}

void Attaching::handleMessage()
{

}

std::string Attaching::toString() const noexcept
{
    return "Attaching";
}
