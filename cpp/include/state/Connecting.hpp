#ifndef STATE_CONNECTING_HPP
#define STATE_CONNECTING_HPP

#include "IState.hpp"

namespace sl
{

namespace state
{

class Connecting : public IState
{
public:
    Connecting(Listener& listener);

    IState* handleEvent(const event::endpoint::Event& event) override;

    IState* handleMessage() override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_CONNECTING_HPP
