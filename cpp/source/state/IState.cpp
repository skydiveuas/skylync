#include "state/IState.hpp"

using sl::state::IState;
using sl::event::endpoint::Event;

IState::IState(const Type _type, Listener& _listener):
    type(_type),
    listener(_listener)
{
}

IState::Type IState::getType() const noexcept
{
    return type;
}

IState::~IState()
{
}

void IState::except(const Event& event) const
{
    throw std::runtime_error("Unexpected:[" + event.toString() + "] @ [" + toString() + "]");
}
