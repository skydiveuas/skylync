#ifndef STATE_ATTACHED_PILOT_READY_HPP
#define STATE_ATTACHED_PILOT_READY_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached {

namespace pilot {

class Ready : public IAttachedState
{
public:
    Ready(ILiveCycleState::Listener& listener);

    void start() noexcept override;

    State* handleEvent(const EndpointEvent& event) override;

    std::string toString() const noexcept override;
};

} // pilot

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_PILOT_READY_HPP