#ifndef SKYBRIDGELISTENER_HPP
#define SKYBRIDGELISTENER_HPP

#include "ICommInterface.hpp"
#include "ITimer.hpp"

#include "event/endpoint/Event.hpp"
#include "event/bridge/Event.hpp"

#include "Types.hpp"

#include <memory>

namespace sl
{

class SkyBridgeListener
{
public:
    const EndpointType side;

    SkyBridgeListener(const EndpointType side);

    virtual ~SkyBridgeListener();

    virtual void notifyBridgeEvent(std::unique_ptr<const event::bridge::Event>) noexcept = 0;

    virtual std::shared_ptr<ICommInterface> createCommInterface(const TransportProtocol,
                                                                ICommInterface::Listener&) noexcept = 0;

    virtual std::shared_ptr<ITimer> createTimer() noexcept = 0;

    virtual void trace(const std::string&) noexcept = 0;
};

} // sl

#endif // SKYBRIDGELISTENER_HPP
