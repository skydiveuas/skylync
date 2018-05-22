#include "state/Connecting.hpp"

#include "state/Attaching.hpp"

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

sl::state::IState* Connecting::notifyConnected()
{
    listener.notifyBridgeEvent(new sl::event::bridge::Event(sl::event::bridge::Event::CONNECTED));
    return nullptr;
}

std::string Connecting::toString() const noexcept
{
    return "Connecting";
}
