#ifndef SKYDEVICE_HPP
#define SKYDEVICE_HPP

#include <memory>

#include "ITimer.hpp"

#include "event/endpoint/EndpointEvent.hpp"
#include "event/bridge/BridgeEvent.hpp"

namespace sl
{

namespace device
{

class SkyDevice
{
public:
    class Listener
    {
        virtual void notifyBridgeEvent(const event::bridge::BridgeEvent& event) = 0;

        virtual std::shared_ptr<ITimer> createTimer() = 0;
    };

    SkyDevice(const Listener& _listener);

    void notifyEndpointEvent(const event::endpoint::EndpointEvent& event);

private:
    const Listener& listener;
};

} // device

} // sl

#endif // SKYDEVICE_HPP
