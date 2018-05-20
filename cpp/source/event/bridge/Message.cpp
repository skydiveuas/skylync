#include "event/bridge/Message.hpp"

using sl::event::bridge::Message;

Message::Message(const std::string& _message):
    Event(Event::MESSAGE),
    message(_message)
{
}

Message::Message(const Type type, const std::string& _message):
    Event(type),
    message(_message)
{
}

Message::~Message()
{
}

std::string Message::toString() const noexcept
{
    return "Message[" + message + "]";
}

