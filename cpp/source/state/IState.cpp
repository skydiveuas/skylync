#include "state/IState.hpp"

using namespace sl::state;

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
