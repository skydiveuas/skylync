#include "example/AsioSkyBridgeListener.hpp"

#include "example/Timer.hpp"

#include <iostream>

using namespace sl;
using namespace sl::example;
using namespace sl::event;

AsioSkyBridgeListener::AsioSkyBridgeListener(asio::io_context& _ioContext, const sl::EndpointType side):
    SkyBridgeListener(side),
    ioContext(_ioContext)
{
}

AsioSkyBridgeListener::~AsioSkyBridgeListener()
{
    timerThread.clear();
}

void AsioSkyBridgeListener::notifyBridgeEvent(std::unique_ptr<const event::bridge::Event> event) noexcept
{
    notifyBridgeEvent(*event.get());
}

void AsioSkyBridgeListener::notifyBridgeEvent(const bridge::Event& event) noexcept
{
    trace("Received: " + event.toString());
}

std::shared_ptr<sl::ICommInterface> AsioSkyBridgeListener::createCommInterface(const ICommInterface::TransportProtocol protocol,
                                                        ICommInterface::Listener& listener) noexcept
{
    std::cout << "SkyBridgeListener::createCommInterface" << std::endl;
    switch (protocol)
    {
    case ICommInterface::TCP:
        return std::make_shared<AsioTcpClient>(listener, ioContext);

    case ICommInterface::UDP:
        return std::make_shared<AsioUdpClient>(listener, ioContext);

    default:
        // error
        return nullptr;
    }
}

std::shared_ptr<ITimer> AsioSkyBridgeListener::createTimer() noexcept
{
    return std::make_shared<Timer>(timerThread);
}

void AsioSkyBridgeListener::trace(const std::string& message) noexcept
{
    std::cout << "Bridge trace: [" << message << "]" << std::endl;
}
