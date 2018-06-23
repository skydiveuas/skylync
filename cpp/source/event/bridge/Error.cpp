#include "event/bridge/Error.hpp"

using namespace sl::event::bridge;

Error::Error(const std::string& message):
    Message(Event::ERROR, message)
{
}

std::string Error::toString() const noexcept
{
    return "ERROR![" + message + "]";
}
