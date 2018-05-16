#ifndef IDLE_HPP
#define IDLE_HPP

#include "IState.hpp"

namespace sl
{

namespace state
{

class Idle : public IState
{
public:
    Idle(Listener& listener):
        IState(listener)
    {

    }
};

} // state

} // sl

#endif // IDLE_HPP
