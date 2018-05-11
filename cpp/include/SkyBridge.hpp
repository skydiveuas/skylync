#ifndef SKYBRIDGE_HPP
#define SKYBRIDGE_HPP

#include "ITimer.hpp"

#include "state/IState.hpp"

#include "event/endpoint/EndpointEvent.hpp"
#include "event/bridge/BridgeEvent.hpp"

#include <memory>
#include <mutex>

namespace sl
{

class SkyBridge
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

        virtual void notifyBridgeEvent(const event::bridge::BridgeEvent& event) = 0;

        virtual std::shared_ptr<ITimer> createTimer() = 0;

        virtual void trace(const std::string& message) = 0;
    };

    SkyBridge(const Listener& _listener);

    void notifyEndpointEvent(const event::endpoint::EndpointEvent& event);

private:
    const Listener& listener;

    state::IState& state;
    std::mutex stateLock;
};

} // sl

#endif // SKYBRIDGE_HPP
