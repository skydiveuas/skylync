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

    void start(const EndpointEvent* const event) noexcept override;

    void handleMessage(const Message& message) override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_AUTHENTICATION_HPP
