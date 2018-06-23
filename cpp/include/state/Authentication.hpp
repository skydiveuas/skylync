#ifndef STATE_AUTHENTICATION_HPP
#define STATE_AUTHENTICATION_HPP

#include "ILiveCycleState.hpp"

namespace sl
{

namespace state
{

class Authentication : public ILiveCycleState
{
public:
    Authentication(Listener& listener);

    void start(const event::endpoint::Event* const event) noexcept override;

    void handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_AUTHENTICATION_HPP
