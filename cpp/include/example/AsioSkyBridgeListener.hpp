#ifndef EXAMPLE_ASIOSKYBRIDGELISTENER_HPP
#define EXAMPLE_ASIOSKYBRIDGELISTENER_HPP

#include "SkyBridgeListener.hpp"

#include "event/bridge/Event.hpp"

#include "AsioTcpClient.hpp"
#include "AsioUdpClient.hpp"

#include "TimerThread.hpp"

#include "asio.hpp"

#include <memory>

namespace sl
{

namespace example
{

class AsioSkyBridgeListener : public SkyBridgeListener
{
public:
    asio::io_context& ioContext;

    AsioSkyBridgeListener(asio::io_context& _ioContext, const sl::SkyBridgeListener::Side side);

    virtual ~AsioSkyBridgeListener();

    void notifyBridgeEvent(const BridgeEvent* event) noexcept override;

    virtual void notifyBridgeEvent(const BridgeEvent& event) noexcept;

    std::shared_ptr<sl::ICommInterface> createCommInterface(const sl::ICommInterface::TransportProtocol protocol,
                                                            sl::ICommInterface::Listener& listener) noexcept;

    std::shared_ptr<ITimer> createTimer() noexcept override;

    void trace(const std::string& message) noexcept override;

private:
    TimerThread timerThread;
};


} // example

} // sl

#endif // EXAMPLE_ASIOSKYBRIDGELISTENER_HPP
