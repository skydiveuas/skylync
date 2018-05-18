#include "event/endpoint/Event.hpp"

using namespace sl::event::endpoint;

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
