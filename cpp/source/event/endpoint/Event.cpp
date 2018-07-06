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
    case DEVICE_LIST: return "DEVICE_LIST";
    case DEVICE_STATUS: return "DEVICE_STATUS";
    case OPERATION_REQUEST: return "OPERATION_REQUEST";
    case OPERATION_ACCEPTED: return "OPERATION_ACCEPTED";
    case OPERATION_REJECTED: return "OPERATION_REJECTED";
    default:
        return "Unknown event name";
    }
}
