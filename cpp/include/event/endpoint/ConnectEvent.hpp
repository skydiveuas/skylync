#ifndef ENDPOINT_CONNECTEVENT_HPP
#define ENDPOINT_CONNECTEVENT_HPP

#include "Event.hpp"

#include <string>

namespace sl
{

namespace event
{

namespace endpoint
{

class ConnectEvent : public Event
{
public:
    ConnectEvent(const std::string& _ip, const int _port):
        Event(Event::CONNECT),
        ip (_ip),
        port(_port)
    {
    }

private:
    const std::string ip;
    const int port;
};

} // endpoint

} // event

} // sl

#endif // ENDPOINT_CONNECTEVENT_HPP
