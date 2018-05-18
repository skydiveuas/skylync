#include "event/bridge/Event.hpp"

using namespace sl::event::bridge;

Event::Event(const Type _type):
    type(_type)
{
}

Event::~Event()
{
}

const char* Event::toString() const noexcept
{
    return "test";
}
