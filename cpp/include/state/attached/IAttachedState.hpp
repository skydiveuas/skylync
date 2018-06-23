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
    IAttachedState(ILiveCycleState::Listener& _listener);

    virtual void start() noexcept;

    virtual IAttachedState* handleEvent(const event::endpoint::Event& event);

    virtual IAttachedState* handleMessage(std::shared_ptr<skylync::BridgeMessage> message);

    virtual std::string toString() const noexcept = 0;

protected:
    ILiveCycleState::Listener& listener;

    ICommInterface& controlCommInterface;

    void send(const skylync::EndpointMessage& message);

    void notifyBridgeEvent(const event::bridge::Event* const event);
    void trace(const std::string& message);

    void except(const std::string& cause) const;
    void exceptUnexpected(const std::shared_ptr<skylync::BridgeMessage> message) const;
    void exceptUnexpected(const event::endpoint::Event& event) const;
    void exceptUnexpected(const std::string& cause) const;

    template <typename _State>
    void switchState()
    {
        listener.switchState(std::make_shared<_State>(listener), nullptr);
    }

    template <typename _State>
    void switchState(const sl::event::endpoint::Event& event)
    {
        listener.switchState(std::make_shared<_State>(listener), &event);
    }
};

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_IATTACHEDSTATE_HPP
