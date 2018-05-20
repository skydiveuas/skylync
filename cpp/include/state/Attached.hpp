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

    void handleEvent(const event::endpoint::Event& event) override;

    void handleMessage() override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_ATTACHED_HPP
