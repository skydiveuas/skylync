#include "event/bridge/Channel.hpp"

using namespace sl::event::bridge;

Channel::Channel():
    Event(Event::CHANNEL)
{
}

std::string Channel::toString() const noexcept
{
    return "CHANNEL";
}
