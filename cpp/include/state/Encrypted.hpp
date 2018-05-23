#ifndef STATE_ENCRYPTED_HPP
#define STATE_ENCRYPTED_HPP

#include "ILiveCycleState.hpp"

namespace sl
{

namespace state
{

class Encrypted : public ILiveCycleState
{
public:
    Encrypted(Listener& listener);

    void start(const EndpointEvent* const event) noexcept override;

    void handleEvent(const EndpointEvent& event);

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_ENCRYPTED_HPP
