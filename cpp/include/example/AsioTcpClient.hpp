#ifndef EXAMPLE_ASIOTCPCLIENT_HPP
#define EXAMPLE_ASIOTCPCLIENT_HPP

#include "ICommInterface.hpp"

#include "asio.hpp"

#include <array>

namespace sl
{

namespace example
{

class AsioTcpClient : public sl::ICommInterface
{
public:
    AsioTcpClient(sl::ICommInterface::Listener& _listener, asio::io_context& _ioContext);

    void connect(const std::string& host, const int port) override;

    void disconnect() override;

    void send(const DataPacket dataPacket) override;

private:
    static constexpr size_t READ_BUFFER_SIZE = 1024;
    std::array<char, READ_BUFFER_SIZE> readBuffer;

    asio::io_context& ioContext;
    asio::ip::tcp::socket socket;

    void doRead();
};

} // example

} // sl

#endif // EXAMPLE_ASIOTCPCLIENT_HPP
