#ifndef EVENT_ENDPOINT_HPP
#define EVENT_ENDPOINT_HPP

#include <string>

namespace sl
{

namespace event
{

namespace endpoint
{

class Event
{
public:
    enum Type
    {
        CONNECT,
        ATTACH,
        RELEASE,
    };

    Event(const Type _type);

    virtual ~Event();

    Type getType() const noexcept;

    virtual std::string toString() const noexcept;

private:
    const Type type;
};

} // endpoint

} // event

} // sl

#endif // EVENT_ENDPOINT_HPP
