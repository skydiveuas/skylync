#ifndef STATE_RELEASE_HPP
#define STATE_RELEASE_HPP

#include "ILiveCycleState.hpp"

namespace sl
{

namespace state
{

class Release : public ILiveCycleState
{
public:
    Release(Listener& listener);

    void start(const event::endpoint::Event* const event) noexcept override;

    void handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_RELEASED_HPP
