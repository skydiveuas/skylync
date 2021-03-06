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

    void start() noexcept override;

    void handleEvent(const event::endpoint::Event& event);

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_ENCRYPTED_HPP
