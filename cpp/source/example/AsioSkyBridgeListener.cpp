#include "example/AsioSkyBridgeListener.hpp"

#include "example/Timer.hpp"

#include <iostream>

using sl::example::AsioSkyBridgeListener;

AsioSkyBridgeListener::AsioSkyBridgeListener(asio::io_context& _ioContext, const sl::SkyBridgeListener::Side side):
    sl::SkyBridgeListener(side),
    ioContext(_ioContext)
{
}

AsioSkyBridgeListener::~AsioSkyBridgeListener()
{
    timerThread.clear();
}

void AsioSkyBridgeListener::notifyBridgeEvent(const BridgeEvent* event) noexcept
{
    std::unique_ptr<const BridgeEvent> guard(event);
    notifyBridgeEvent(*guard.get());
}

void AsioSkyBridgeListener::notifyBridgeEvent(const BridgeEvent& event) noexcept
{
    trace("Received: " + event.toString());
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

std::shared_ptr<sl::ITimer> AsioSkyBridgeListener::createTimer() noexcept
{
    return std::make_shared<Timer>(timerThread);
}

void AsioSkyBridgeListener::trace(const std::string& message) noexcept
{
    std::cout << "Bridge trace: [" << message << "]" << std::endl;
}
