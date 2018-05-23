#ifndef STATE_CONNECTION_HPP
#define STATE_CONNECTION_HPP

#include "ILiveCycleState.hpp"

namespace sl
{

namespace state
{

class Connection : public ILiveCycleState
{
public:
    Connection(Listener& listener);

    void start(const EndpointEvent* const event) noexcept override;

    void onConnected() override;

    std::string toString() const noexcept override;

private:
    static constexpr size_t CONNECTION_TIMEOUT = 2000; // ms

    std::shared_ptr<ITimer> connectionTimer;

    void onTimeout() noexcept;
};

} // state

} // sl

#endif // STATE_CONNECTION_HPP
