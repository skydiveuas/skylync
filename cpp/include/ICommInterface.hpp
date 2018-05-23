#ifndef ICOMMINTERFACE_HPP
#define ICOMMINTERFACE_HPP

#include <cstddef>
#include <atomic>
#include <utility>
#include <string>

namespace sl
{

class ICommInterface
{
public:
    typedef std::pair<const unsigned char* const, const size_t> DataPacket;

    enum TransportProtocol
    {
        TCP,
        UDP,
    };

    class Listener
    {
    public:
        virtual void onConnected() = 0;

        virtual void onDisconnected() = 0;

        virtual void onReceived(const DataPacket) = 0;
    };

    ICommInterface(Listener& listener);

    void setListener(Listener& listener);

    virtual ~ICommInterface();

    virtual void connect(const std::string& host, const int port) = 0;

    virtual void disconnect() = 0;

    virtual void send(const DataPacket) = 0;

protected:
    std::atomic<Listener*> listener;
};

} // sl

#endif // ICOMMINTERFACE_HPP
