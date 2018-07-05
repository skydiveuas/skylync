#ifndef STATE_AUTHENTICATION_HPP
#define STATE_AUTHENTICATION_HPP

#include "ILiveCycleState.hpp"

#include "event/endpoint/Attach.hpp"

namespace sl
{

namespace state
{

class Authentication : public ILiveCycleState
{
public:
    Authentication(Listener& listener, const event::endpoint::Attach* _attach);

    void start() noexcept override;

    void handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;

private:
    std::unique_ptr<const event::endpoint::Attach> attach;
};

} // state

} // sl

#endif // STATE_AUTHENTICATION_HPP
