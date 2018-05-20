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

    void handleEvent(const event::endpoint::Event& event) override;

    void handleMessage() override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // IDLE_HPP
