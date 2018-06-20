#ifndef STATE_ATTACHED_RELEASE_HPP
#define STATE_ATTACHED_RELEASE_HPP

#include "state/attached/IAttachedState.hpp"

#include "event/bridge/Event.hpp"

namespace sl
{

namespace state
{

namespace attached {

class Release : public IAttachedState
{
public:
    Release(ILiveCycleState::Listener& listener);

    void start(const ILiveCycleState::EndpointEvent* const event) noexcept override;

    State* handleEvent(const event::endpoint::Event& event) override;

    State* handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;
};

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_RELEASE_HPP
