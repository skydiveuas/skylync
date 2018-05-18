#ifndef ICOMMINTERFACE_HPP
#define ICOMMINTERFACE_HPP

#include <cstddef>
#include <functional>

namespace sl
{

class ICommInterface
{
public:
    class Listener
    {
    public:
        virtual void onReceived(const unsigned char* data, const size_t length) = 0;
    };

    ICommInterface(const Listener& _listener);

    virtual ~ICommInterface();

    virtual void send(const unsigned char* data, const size_t length) = 0;

protected:
    const Listener& listener;
};

} // sl

#endif // ICOMMINTERFACE_HPP
