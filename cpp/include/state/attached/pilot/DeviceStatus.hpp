#ifndef STATE_ATTACHED_PILOT_DEVICESTATUS_HPP
#define STATE_ATTACHED_PILOT_DEVICESTATUS_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached
{

namespace pilot
{

class DeviceStatus : public IAttachedState
{
public:
    DeviceStatus(ILiveCycleState::Listener& listener);

    void start() noexcept override;

    IAttachedState* handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;
};

} // pilot

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_PILOT_DEVICESTATUS_HPP
