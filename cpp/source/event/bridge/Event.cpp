#include "event/bridge/Event.hpp"

using namespace sl::event::bridge;

Event::Event(const Type _type):
    type(_type)
{
}

Event::~Event()
{
}

Event::Type Event::getType() const noexcept
{
    return type;
}

std::string Event::toString() const noexcept
{
    switch (type)
    {
    case MESSAGE: return "MESSAGE";
    case ERROR: return "ERROR";
    case CONNECTED: return "CONNECTED";
    case ENCRYPTED: return "ENCRYPTED";
    case ATTACHED: return "ATTACHED";
    case RELEASED: return "RELEASED";
    case DISCONNECTED: return "DISCONNECTED";
    case DEVICE_LIST: return "DEVICE_LIST";
    case CHANNEL: return "CHANNEL";
    default:
        return "Unknown event name";
    }
}
