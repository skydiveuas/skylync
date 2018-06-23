#ifndef STATE_ATTACHED_PILOT_REQUESTDEVICE_HPP
#define STATE_ATTACHED_PILOT_REQUESTDEVICE_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached
{

namespace pilot
{

class RequestDevice : public IAttachedState
{
public:
    RequestDevice(ILiveCycleState::Listener& listener, const RefId _requestedRefId);

    void start() noexcept override;

    IAttachedState* handleEvent(const sl::event::endpoint::Event& event) override;

    IAttachedState* handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;

private:
    const RefId requestedRefId;
};

} // pilot

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_PILOT_REQUESTDEVICE_HPP
