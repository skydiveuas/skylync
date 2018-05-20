#include "event/bridge/Error.hpp"

using sl::event::bridge::Error;

Error::Error(const std::string message):
    Message(Event::ERROR, message)
{
}

std::string Error::toString() const noexcept
{
    return "Error![" + message + "]";
}
