#ifndef EXAMPLE_ASIOUDPCLIENT_HPP
#define EXAMPLE_ASIOUDPCLIENT_HPP

#include "ICommInterface.hpp"

#include "asio.hpp"

#include <array>

namespace sl
{

namespace example
{

class AsioUdpClient : public sl::ICommInterface
{
public:
    AsioUdpClient(sl::ICommInterface::Listener& _listener, asio::io_context& _ioContext);

    void connect(const std::string&, const int) override;

    void disconnect() override;

    void send(const DataPacket dataPacket) override;

private:
    static constexpr size_t READ_BUFFER_SIZE = 1024;
    std::array<uint8_t, READ_BUFFER_SIZE> readBuffer;

    asio::io_context& ioContext;
    asio::ip::udp::endpoint endpoint;

    void doRead();
};

} // example

} // sl

#endif // EXAMPLE_ASIOUDPCLIENT_HPP
