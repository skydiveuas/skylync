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
    AsioUdpClient(sl::ICommInterface::Listener& _listener, asio::io_context&);

    void connect(const std::string&, const int) override;

    void disconnect() override;

    void send(const DataPacket dataPacket) override;
};

} // example

} // sl

#endif // EXAMPLE_ASIOUDPCLIENT_HPP
