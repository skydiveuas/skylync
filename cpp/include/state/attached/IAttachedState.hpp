#ifndef STATE_ATTACHED_IATTACHEDSTATE_HPP
#define STATE_ATTACHED_IATTACHEDSTATE_HPP

#include "state/ILiveCycleState.hpp"

#include "event/bridge/Event.hpp"

namespace sl
{

namespace state
{

namespace attached {

class IAttachedState
{
public:
    typedef IAttachedState State;

    IAttachedState(ILiveCycleState::Listener& _listener);

    virtual void start(const ILiveCycleState::EndpointEvent* const event) noexcept;

    virtual State* handleEvent(const event::endpoint::Event& event);

    virtual State* handleMessage(std::shared_ptr<skylync::BridgeMessage> message);

    virtual std::string toString() const noexcept = 0;

private:
    ILiveCycleState::Listener& listener;

    ICommInterface& controlCommInterface;
};

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_IATTACHEDSTATE_HPP
