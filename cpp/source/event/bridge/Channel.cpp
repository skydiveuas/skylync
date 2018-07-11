#include "event/bridge/Channel.hpp"

using namespace sl::event::bridge;

Channel::Channel(std::shared_ptr<ICommInterface> _interface):
    Event(Event::CHANNEL),
    interface(_interface)
{
}

std::string Channel::toString() const noexcept
{
    return "CHANNEL";
}
