#include "state/Released.hpp"

#include "state/Connecting.hpp"

using sl::state::Released;
using sl::event::endpoint::Event;

Released::Released(Listener& listener):
    IState(RELEASED, listener)
{
}

sl::state::IState* Released::handleEvent(const Event& event)
{
    switch (event.getType())
    {
    case Event::CONNECT:
        listener.connect();
        return newState<sl::state::Connecting>();

    default:
        except(event);
    }
    return nullptr;
}

sl::state::IState* Released::handleMessage()
{
    return nullptr;
}

std::string Released::toString() const noexcept
{
    return "Released";
}
