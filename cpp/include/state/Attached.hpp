#ifndef STATE_ATTACHED_HPP
#define STATE_ATTACHED_HPP

#include "ILiveCycleState.hpp"

#include "attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

class Attached : public ILiveCycleState
{
public:
    Attached(Listener& listener);

    void start(const EndpointEvent* const) noexcept override;

    void handleEvent(const EndpointEvent& event) override;

    void handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;

private:
    std::unique_ptr<attached::IAttachedState> subState;

    void switchSubState(attached::IAttachedState* newState);
};

} // state

} // sl

#endif // STATE_ATTACHED_HPP
