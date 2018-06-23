#ifndef EVENT_BRIDGE_HPP
#define EVENT_BRIDGE_HPP

#include "Types.hpp"

#include <string>

namespace sl
{

namespace event
{

namespace bridge
{

class Event
{
public:
    enum Type
    {
        MESSAGE,
        ERROR,
        CONNECTED,
        ENCRYPTED,
        ATTACHED,
        RELEASED,
        DISCONNECTED,
        DEVICE_LIST,
        CHANNEL,
    };

    Event(const Type _type);

    Type getType() const noexcept;

    virtual ~Event();

    virtual std::string toString() const noexcept;

private:
    const Type type;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_HPP
