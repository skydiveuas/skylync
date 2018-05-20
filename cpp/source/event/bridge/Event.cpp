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
    default:
        return "Unknown event name";
    }
}
