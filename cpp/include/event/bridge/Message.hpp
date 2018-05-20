#ifndef EVENT_BRIDGE_MESSAGE_HPP
#define EVENT_BRIDGE_MESSAGE_HPP

#include "Event.hpp"

#include <string>

namespace sl
{

namespace event
{

namespace bridge
{

class Message : public Event
{
public:
    Message(const std::string& _message);

    virtual ~Message();

    virtual std::string toString() noexcept;

private:
    std::string message;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_MESSAGE_HPP
