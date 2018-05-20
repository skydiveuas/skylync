#include "state/Idle.hpp"

using sl::state::Idle;
using sl::event::endpoint::Event;

Idle::Idle(Listener& listener):
    IState(IDLE, listener)
{
}

void Idle::handleEvent(const Event& event)
{
    switch (event.getType())
    {
    case Event::CONNECT:

        return;

    default:
        except(event);
    }
}

void Idle::handleMessage()
{

}

std::string Idle::toString() const noexcept
{
    return "Idle";
}
