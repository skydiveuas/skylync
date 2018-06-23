#ifndef STATE_ATTACHED_DEVICE_READY_HPP
#define STATE_ATTACHED_DEVICE_READY_HPP

#include "state/attached/IAttachedState.hpp"

#include "event/bridge/Event.hpp"

namespace sl
{

namespace state
{

namespace attached
{

namespace device
{

class Ready : public IAttachedState
{
public:
    Ready(ILiveCycleState::Listener& listener, const event::bridge::Event* const _event);

    void start() noexcept override;

    IAttachedState* handleEvent(const event::endpoint::Event& event) override;

    std::string toString() const noexcept override;

private:
    const event::bridge::Event* event;
};

} // device

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_DEVICE_READY_HPP
