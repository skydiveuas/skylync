#ifndef STATE_ATTACHED_PILOT_OPERATIONESTABLISHMENT_HPP
#define STATE_ATTACHED_PILOT_OPERATIONESTABLISHMENT_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached
{

namespace pilot
{

class OperationEstablishment : public IAttachedState
{
public:
    OperationEstablishment(ILiveCycleState::Listener& listener, const RefId _requestedRefId);

    void start() noexcept override;

    IAttachedState* handleEvent(const sl::event::endpoint::Event& event) override;

    IAttachedState* handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;

private:
    const RefId requestedRefId;

    IAttachedState* sendFlightTunnelReqest() noexcept;
};

} // pilot

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_PILOT_OPERATIONESTABLISHMENT_HPP
