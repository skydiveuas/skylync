#ifndef STATE_ATTACHING_HPP
#define STATE_ATTACHING_HPP

#include "IState.hpp"

namespace sl
{

namespace state
{

class Attaching : public IState
{
public:
    Attaching(Listener& listener);

    void handleEvent(const event::endpoint::Event& event) override;

    void handleMessage() override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_ATTACHING_HPP
