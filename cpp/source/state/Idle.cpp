#include "state/Idle.hpp"

#include "state/Connecting.hpp"

using sl::state::Idle;
using sl::event::endpoint::Event;

Idle::Idle(Listener& listener):
    IState(IDLE, listener)
{
}

sl::state::IState& Idle::handleEvent(const Event& event)
{
    switch (event.getType())
    {
    case Event::CONNECT:
        // TODO send CONNECT message
        return newState<sl::state::Connecting>();

    default:
        except(event);
    }
    return nullptr;
}

void Idle::handleMessage()
{

}

std::string Idle::toString() const noexcept
{
    return "Idle";
}
