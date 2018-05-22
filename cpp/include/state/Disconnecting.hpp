#ifndef STATE_DISCONNECTING_HPP
#define STATE_DISCONNECTING_HPP

#include "IState.hpp"

namespace sl
{

namespace state
{

class Disconnecting : public IState
{
public:
    Disconnecting(Listener& listener);

    IState* handleEvent(const event::endpoint::Event& event) override;

    IState* handleMessage() override;

    IState* notifyDisconnected();

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_DISCONNECTING_HPP
