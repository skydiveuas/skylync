#ifndef EVENT_BRIDGE_MESSAGE_HPP
#define EVENT_BRIDGE_MESSAGE_HPP

#include "Event.hpp"

#include "skylync.pb.h"

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
    Message(const Type type, const std::string& _message);

    virtual ~Message();

    virtual std::string toString() const noexcept override;

protected:
    std::string message;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_MESSAGE_HPP
