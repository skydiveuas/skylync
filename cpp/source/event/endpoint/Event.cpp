#include "event/endpoint/Event.hpp"

using sl::event::endpoint::Event;

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
    default:
        return "Unknown event name";
    }
}
