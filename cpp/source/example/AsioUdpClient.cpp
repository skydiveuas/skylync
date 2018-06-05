#include "example/AsioUdpClient.hpp"

#include <iostream>

using sl::example::AsioUdpClient;

AsioUdpClient::AsioUdpClient(sl::ICommInterface::Listener& _listener, asio::io_context&):
    sl::ICommInterface(_listener)
{
}

void AsioUdpClient::connect(const std::string&, const int)
{
    std::cout << "AsioUdpClient::connect" << std::endl;
    listener.load()->onConnected();
}

void AsioUdpClient::disconnect()
{
    std::cout << "AsioUdpClient::disconnect" << std::endl;
    listener.load()->onDisconnected();
}

void AsioUdpClient::send(const DataPacket dataPacket)
{
    listener.load()->onReceived(dataPacket);
}
