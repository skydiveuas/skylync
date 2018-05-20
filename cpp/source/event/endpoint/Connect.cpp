#include "event/endpoint/Connect.hpp"

using sl::event::endpoint::Connect;

Connect::Connect(const std::string& _ip, const int _port):
    Event(Event::CONNECT),
    ip (_ip),
    port(_port)
{
}

std::string Connect::toString() const noexcept
{
    return "Connect[" + ip + "@" + std::to_string(port) + "]";
}