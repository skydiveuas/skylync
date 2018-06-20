#ifndef STATE_ATTACHED_RELEASE_HPP
#define STATE_ATTACHED_RELEASE_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached {

class Release : public IAttachedState
{
public:
    Release(ILiveCycleState::Listener& listener);

    void start() noexcept override;

    std::string toString() const noexcept override;
};

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_RELEASE_HPP
