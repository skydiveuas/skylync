#ifndef ENDPOINT_EVENT_HPP
#define ENDPOINT_EVENT_HPP

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
    };

    Event(const Type _type);

    virtual ~Event();

    virtual std::string toString() noexcept;

private:
    const Type type;
};

} // endpoint

} // event

} // sl

#endif // ENDPOINT_EVENT_HPP
