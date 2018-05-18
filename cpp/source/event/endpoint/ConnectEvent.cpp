#include "event/endpoint/ConnectEvent.hpp"

using namespace sl::event::endpoint;

ConnectEvent::ConnectEvent(const std::string& _ip, const int _port):
    Event(Event::CONNECT),
    ip (_ip),
    port(_port)
{
}
