#ifndef EXAMPLE_ASIOSKYBRIDGELISTENER_HPP
#define EXAMPLE_ASIOSKYBRIDGELISTENER_HPP

#include "SkyBridgeListener.hpp"

#include "AsioTcpClient.hpp"
#include "AsioUdpClient.hpp"

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

    void notifyBridgeEvent(const sl::event::bridge::Event* event) noexcept override;

    std::shared_ptr<sl::ICommInterface> createCommInterface(const sl::ICommInterface::TransportProtocol protocol,
                                                            sl::ICommInterface::Listener& listener) noexcept;

    void trace(const std::string& message) noexcept override;
};


} // example

} // sl

#endif // EXAMPLE_ASIOSKYBRIDGELISTENER_HPP
