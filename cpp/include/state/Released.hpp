#ifndef STATE_RELEASED_HPP
#define STATE_RELEASED_HPP

#include "IState.hpp"

namespace sl
{

namespace state
{

class Released : public IState
{
public:
    Released(Listener& listener);

    IState* handleEvent(const event::endpoint::Event& event) override;

    IState* handleMessage() override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_RELEASED_HPP
