#ifndef STATE_ATTACHED_HPP
#define STATE_ATTACHED_HPP

#include "IState.hpp"

namespace sl
{

namespace state
{

class Attached : public IState
{
public:
    Attached(Listener& listener);

    IState* handleEvent(const event::endpoint::Event& event) override;

    IState* handleMessage() override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_ATTACHED_HPP
