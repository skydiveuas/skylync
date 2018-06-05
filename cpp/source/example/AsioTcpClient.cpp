#include "example/AsioTcpClient.hpp"

#include <iostream>

using sl::example::AsioTcpClient;

AsioTcpClient::AsioTcpClient(sl::ICommInterface::Listener& _listener,
                                   asio::io_context& _ioContext):
    sl::ICommInterface(_listener),
    ioContext(_ioContext),
    socket(ioContext)
{
}

void AsioTcpClient::connect(const std::string& host, const int port)
{
    std::cout << "TcpCommInterface::connect" << std::endl;
    asio::ip::tcp::resolver resolver(ioContext);
    auto endpoint = resolver.resolve(host, std::to_string(port));
    asio::async_connect(socket, endpoint, [this] (std::error_code ec, asio::ip::tcp::endpoint)
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

void AsioTcpClient::disconnect()
{
    std::cout << "AsioTcpClient::disconnect" << std::endl;
    listener.load()->onDisconnected();
}

void AsioTcpClient::send(const DataPacket dataPacket)
{
    std::cout << "AsioTcpClient::send" << std::endl;
    asio::async_write(socket, asio::buffer(dataPacket.first, dataPacket.second),
                      [this](std::error_code ec, std::size_t /*length*/)
    {
        if (ec)
        {
            socket.close();
        }
    });
}

void AsioTcpClient::doRead()
{
    std::cout << "AsioTcpClient::doRead" << std::endl;
    socket.async_read_some(asio::buffer(readBuffer.data(), READ_BUFFER_SIZE),
                           [this](std::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            listener.load()->onReceived(DataPacket(readBuffer.data(), length));
            doRead();
        }
        else
        {
            socket.close();
        }
    });
}
