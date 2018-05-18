#ifndef IDLE_HPP
#define IDLE_HPP

#include "IState.hpp"

namespace sl
{

namespace state
{

class Idle : public IState
{
public:
    Idle(Listener& listener);

    void handleEvent(const event::endpoint::Event& event) override;

    void handleMessage() override;

    const char* toString() const noexcept override;

private:
    static constexpr auto NAME = "Idle";
};

} // state

} // sl

#endif // IDLE_HPP
