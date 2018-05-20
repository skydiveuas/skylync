#ifndef EVENT_ENDPOINT_CONNECT_HPP
#define EVENT_ENDPOINT_CONNECT_HPP

#include <string>

#include "Event.hpp"

namespace sl
{

namespace event
{

namespace endpoint
{

class Connect : public Event
{
public:
    Connect(const std::string& _ip, const int _port);

    std::string toString() const noexcept override;

private:
    const std::string ip;
    const int port;
};

} // endpoint

} // event

} // sl

#endif // EVENT_ENDPOINT_CONNECT_HPP
