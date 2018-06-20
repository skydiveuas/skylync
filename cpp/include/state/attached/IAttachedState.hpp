#ifndef STATE_ATTACHED_IATTACHEDSTATE_HPP
#define STATE_ATTACHED_IATTACHEDSTATE_HPP

#include "state/ILiveCycleState.hpp"

namespace sl
{

namespace state
{

namespace attached {

class IAttachedState
{
public:
    typedef event::endpoint::Event EndpointEvent;
    typedef event::bridge::Event BridgeEvent;
    typedef IAttachedState State;

    IAttachedState(ILiveCycleState::Listener& _listener);

    virtual void start() noexcept;

    virtual State* handleEvent(const EndpointEvent& event);

    virtual State* handleMessage(std::shared_ptr<skylync::BridgeMessage> message);

    virtual std::string toString() const noexcept = 0;

protected:
    ILiveCycleState::Listener& listener;

    ICommInterface& controlCommInterface;

    void send(const skylync::EndpointMessage& message);

    void notifyBridgeEvent(const BridgeEvent* const event);
    void trace(const std::string& message);

    void except(const std::string& cause) const;
    void exceptUnexpected(const std::shared_ptr<skylync::BridgeMessage> message) const;
    void exceptUnexpected(const EndpointEvent& event) const;
    void exceptUnexpected(const std::string& cause) const;
};

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_IATTACHEDSTATE_HPP
