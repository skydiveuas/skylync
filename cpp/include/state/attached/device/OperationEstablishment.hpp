#ifndef STATE_ATTACHED_DEVICE_OPERATIONESTABLISHMENT_HPP
#define STATE_ATTACHED_DEVICE_OPERATIONESTABLISHMENT_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached
{

namespace device
{

class OperationEstablishment : public IAttachedState
{
public:
    OperationEstablishment(ILiveCycleState::Listener& listener);

    void start() noexcept override;

    IAttachedState* handleEvent(const event::endpoint::Event& event) override;

    IAttachedState* handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;

private:
    const event::bridge::Event* event;
};

} // device

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_DEVICE_OPERATIONESTABLISHMENT_HPP
