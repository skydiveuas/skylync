#ifndef BRIDGE_EVENT_HPP
#define BRIDGE_EVENT_HPP

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
        CONNECTED,
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

#endif // BRIDGE_EVENT_HPP
