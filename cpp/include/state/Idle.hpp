#ifndef STATE_IDLE_HPP
#define STATE_IDLE_HPP

#include "IState.hpp"

namespace sl
{

namespace state
{

class Idle : public IState
{
public:
    Idle(Listener& listener);

    IState* handleEvent(const event::endpoint::Event& event) override;

    IState* handleMessage() override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // IDLE_HPP
