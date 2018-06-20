#ifndef STATE_ATTACHED_PILOT_READY_HPP
#define STATE_ATTACHED_PILOT_READY_HPP

#include "state/attached/IAttachedState.hpp"

#include "event/bridge/Event.hpp"

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

    void start(const ILiveCycleState::EndpointEvent* const event) noexcept override;

    State* handleEvent(const event::endpoint::Event& event) override;

    State* handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;
};

} // pilot

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_PILOT_READY_HPP
