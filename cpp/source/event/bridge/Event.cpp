#include "event/bridge/Event.hpp"

using sl::event::bridge::Event;

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
    default:
        return "Unknown event name";
    }
}
