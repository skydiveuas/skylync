#include "example/AsioSkyBridgeListener.hpp"

#include <iostream>

using sl::example::AsioSkyBridgeListener;

AsioSkyBridgeListener::AsioSkyBridgeListener(asio::io_context& _ioContext, const sl::SkyBridgeListener::Side side):
    sl::SkyBridgeListener(side),
    ioContext(_ioContext)
{
}

void AsioSkyBridgeListener::notifyBridgeEvent(const sl::event::bridge::Event* event) noexcept
{
    std::unique_ptr<const sl::event::bridge::Event> guard(event);
    std::cout << "Received event: " << event->toString() << std::endl;
}

std::shared_ptr<sl::ICommInterface> AsioSkyBridgeListener::createCommInterface(const sl::ICommInterface::TransportProtocol protocol,
                                                        sl::ICommInterface::Listener& listener) noexcept
{
    std::cout << "SkyBridgeListener::createCommInterface" << std::endl;
    switch (protocol)
    {
    case sl::ICommInterface::TCP:
        return std::make_shared<AsioTcpClient>(listener, ioContext);

    case sl::ICommInterface::UDP:
        return std::make_shared<AsioUdpClient>(listener, ioContext);

    default:
        // error
        return nullptr;
    }
}

void AsioSkyBridgeListener::trace(const std::string& message) noexcept
{
    std::cout << "Bridge trace: [" << message << "]" << std::endl;
}
