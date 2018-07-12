#include "example/AsioUdpClient.hpp"

#include <iostream>

using namespace sl::example;

AsioUdpClient::AsioUdpClient(sl::ICommInterface::Listener* _listener, asio::io_context& _ioContext):
    sl::ICommInterface(_listener),
    ioContext(_ioContext),
    socket(ioContext)
{
}

void AsioUdpClient::connect(const std::string& host, const int port)
{
    std::cout << "AsioUdpClient::connect" << std::endl;
    asio::ip::udp::resolver resolver(ioContext);
    asio::ip::udp::resolver::results_type endpoints =
            resolver.resolve(asio::ip::udp::v4(), host, std::to_string(port));
    endpoint = *endpoints.begin();
    socket.async_connect(endpoint, [this] (std::error_code ec)
    {
        if (!ec)
        {
            doRead();
            listener.load()->onConnected();
        }
        else
        {
            std::cout << "ERROR!!!!!!!!" << std::endl;
        }
    });
}

void AsioUdpClient::disconnect()
{
    std::cout << "AsioUdpClient::disconnect" << std::endl;
    listener.load()->onDisconnected();
}

void AsioUdpClient::send(const DataPacket dataPacket)
{
    std::cout << "AsioUdpClient::send" << std::endl;
    socket.async_send(asio::buffer(dataPacket.first, dataPacket.second),
                         [this] (std::error_code ec, std::size_t /*length*/)
    {
        if (ec)
        {
            socket.close();
        }
    });
}

void AsioUdpClient::doRead()
{
    std::cout << "AsioUdpClient::doRead - MISSING IMPLEMENTATION" << std::endl;
}
