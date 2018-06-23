#ifndef STATE_DISCONNECTED_HPP
#define STATE_DISCONNECTED_HPP

#include "ILiveCycleState.hpp"

namespace sl
{

namespace state
{

class Disconnected : public ILiveCycleState
{
public:
    Disconnected(Listener& listener);

    void start(const event::endpoint::Event* const event) noexcept override;

    void handleEvent(const event::endpoint::Event& event) override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_DISCONNECTED_HPP
