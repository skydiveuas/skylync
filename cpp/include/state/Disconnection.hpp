#ifndef STATE_DISCONNECTION_HPP
#define STATE_DISCONNECTION_HPP

#include "ILiveCycleState.hpp"

namespace sl
{

namespace state
{

class Disconnection : public ILiveCycleState
{
public:
    Disconnection(Listener& listener);

    void start(const event::endpoint::Event* const event) noexcept override;

    void onDisconnected() override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_DISCONNECTION_HPP
