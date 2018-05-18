#ifndef SKYBRIDGE_HPP
#define SKYBRIDGE_HPP

#include "ITimer.hpp"

#include "event/endpoint/Event.hpp"
#include "event/bridge/Event.hpp"

#include "state/IState.hpp"
#include "state/Idle.hpp"

#include <memory>
#include <mutex>

namespace sl
{

class SkyBridge : public state::IState::Listener
{
public:
    class Listener
    {
    public:
        enum Side
        {
            DEVICE,
            PILOT,
        } side;

        Listener(const Side _side);

        virtual ~Listener();

        virtual void notifyBridgeEvent(const event::bridge::Event& event) = 0;

        virtual std::shared_ptr<ITimer> createTimer() = 0;

        virtual void trace(const std::string& message) = 0;
    };

    SkyBridge(Listener& _listener);

    void notifyEndpointEvent(const event::endpoint::Event& event);

private:
    Listener& listener;

    state::IState& state;
    std::mutex stateLock;

    void notifyBridgeEvent(const event::bridge::Event& event) override;

    std::shared_ptr<ITimer> createTimer() override;

    void trace(const std::string& message) override;
};

} // sl

#endif // SKYBRIDGE_HPP
