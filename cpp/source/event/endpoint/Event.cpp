#include "event/endpoint/Event.hpp"

using namespace sl::event::endpoint;

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
    case CONNECT: return "CONNECT";
    case ATTACH: return "ATTACH";
    case RELEASE: return "RELEASE";
    case LIST_DEVICES: return "LIST_DEVICES";
    case REQUEST_DEVICE: return "REQUEST_DEVICE";
    default:
        return "Unknown event name";
    }
}
