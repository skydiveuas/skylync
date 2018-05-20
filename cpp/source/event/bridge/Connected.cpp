#include "event/bridge/Connected.hpp"

using sl::event::bridge::Connected;

Connected::Connected():
    Event(Event::CONNECTED)
{
}
