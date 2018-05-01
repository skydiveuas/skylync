#ifndef ICOMMINTERFACE_HPP
#define ICOMMINTERFACE_HPP

#include <cstddef>
#include <functional>

namespace sl
{

class ICommInterface
{
public:
    typedef std::function<void(const unsigned char*, const size_t) noexcept> Receiver;

    virtual ~ICommInterface()
    {
    }

    virtual void send(const unsigned char* data, const size_t length) = 0;

    void setReceiver(Receiver _receiver) noexcept
    {
        receiver = _receiver;
    }

protected:
    Receiver receiver;
};

} // sl

#endif // ICOMMINTERFACE_HPP
