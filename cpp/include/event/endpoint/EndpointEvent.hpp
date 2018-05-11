#ifndef ENDPOINTEVENT_HPP
#define ENDPOINTEVENT_HPP

namespace sl
{

namespace event
{

namespace endpoint
{

class EndpointEvent
{
public:
    enum Type
    {
        CONNECT,
    };

    EndpointEvent(const Type _type):
        type(_type)
    {
    }

    virtual ~EndpointEvent()
    {
    }

private:
    const Type type;
};

} // endpoint

} // event

} // sl

#endif // ENDPOINTEVENT_HPP
