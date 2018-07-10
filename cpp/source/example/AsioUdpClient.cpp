#include "example/AsioUdpClient.hpp"

#include <iostream>

using sl::example::AsioUdpClient;

AsioUdpClient::AsioUdpClient(sl::ICommInterface::Listener& _listener, asio::io_context& _ioContext):
    sl::ICommInterface(_listener),
    ioContext(_ioContext)
{
}

void AsioUdpClient::connect(const std::string&, const int)
{
    std::cout << "AsioUdpClient::connect" << std::endl;
    listener.load()->onConnected();
    doRead();
}

void AsioUdpClient::disconnect()
{
    std::cout << "AsioUdpClient::disconnect" << std::endl;
    listener.load()->onDisconnected();
}

void AsioUdpClient::send(const DataPacket)
{
    std::cout << "AsioUdpClient::send - MISSING IMPLEMENTATION" << std::endl;
}

void AsioUdpClient::doRead()
{
    std::cout << "AsioUdpClient::doRead - MISSING IMPLEMENTATION" << std::endl;
}
