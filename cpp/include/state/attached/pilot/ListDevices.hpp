#ifndef STATE_ATTACHED_PILOT_LISTDEVICES_HPP
#define STATE_ATTACHED_PILOT_LISTDEVICES_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached {

namespace pilot {

class ListDevices : public IAttachedState
{
public:
    ListDevices(ILiveCycleState::Listener& listener);

    void start() noexcept override;

    IAttachedState* handleEvent(const sl::event::endpoint::Event& event) override;

    IAttachedState* handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;
};

} // pilot

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_PILOT_LISTDEVICES_HPP
