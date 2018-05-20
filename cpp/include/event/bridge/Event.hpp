#ifndef EVENT_BRIDGE_HPP
#define EVENT_BRIDGE_HPP

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
        ATTACHED,
    };

    Event(const Type _type);

    virtual ~Event();

    virtual const char* toString() const noexcept;

private:
    const Type type;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_HPP
