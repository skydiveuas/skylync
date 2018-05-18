#include "state/Idle.hpp"

using namespace sl::state;

Idle::Idle(Listener& listener):
    IState(CONNECT, listener)
{
}

void Idle::handleEvent(const event::endpoint::Event& event)
{

}

void Idle::handleMessage()
{

}

const char* Idle::toString() const noexcept
{
    return NAME;
}
