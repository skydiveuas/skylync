#ifndef SKYBRIDGELISTENER_HPP
#define SKYBRIDGELISTENER_HPP

#include "ITimer.hpp"
#include "ICommInterface.hpp"

#include "event/endpoint/Event.hpp"
#include "event/bridge/Event.hpp"

#include <memory>

namespace sl
{

class SkyBridgeListener
{
public:
    typedef event::bridge::Event BridgeEvent;
    typedef event::endpoint::Event EndpointEvent;

    enum Side
    {
        DEVICE,
        PILOT,
    } side;

    SkyBridgeListener(const Side side);

    virtual ~SkyBridgeListener();

    virtual void notifyBridgeEvent(const BridgeEvent* const) noexcept = 0;

    virtual std::shared_ptr<ICommInterface> createCommInterface(const ICommInterface::TransportProtocol,
                                                                ICommInterface::Listener&) noexcept = 0;

    virtual std::shared_ptr<ITimer> createTimer() noexcept = 0;

    virtual void trace(const std::string&) noexcept = 0;
};

} // sl

#endif // SKYBRIDGELISTENER_HPP
