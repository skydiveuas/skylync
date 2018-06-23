#ifndef STATE_ATTACHED_PILOT_READY_HPP
#define STATE_ATTACHED_PILOT_READY_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached
{

namespace pilot
{

class Ready : public IAttachedState
{
public:
    Ready(ILiveCycleState::Listener& listener, const event::bridge::Event* const _event);

    void start() noexcept override;

    IAttachedState* handleEvent(const sl::event::endpoint::Event& event) override;

    std::string toString() const noexcept override;

private:
    const event::bridge::Event* event;
};

} // pilot

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_PILOT_READY_HPP
