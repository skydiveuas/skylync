#include "state/Disconnecting.hpp"

#include "state/Released.hpp"

using sl::state::Disconnecting;
using sl::event::endpoint::Event;

Disconnecting::Disconnecting(Listener& listener):
    IState(DISCONNECTING, listener)
{
}

sl::state::IState* Disconnecting::handleEvent(const Event& event)
{
    return nullptr;
}

sl::state::IState* Disconnecting::handleMessage()
{
    return nullptr;
}

sl::state::IState* Disconnecting::notifyDisconnected()
{
    return newState<sl::state::Released>();
}

std::string Disconnecting::toString() const noexcept
{
    return "Disconnecting";
}
