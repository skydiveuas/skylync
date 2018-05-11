#ifndef BRIDGEEVENT_HPP
#define BRIDGEEVENT_HPP

#include <string>

namespace sl
{

namespace event
{

namespace bridge
{

class BridgeEvent
{
public:
    enum Type
    {
        CONNECTED,
    };

    BridgeEvent(const Type _type);

    virtual ~BridgeEvent();

    virtual std::string toString() noexcept;

private:
    const Type type;
};

} // endpoint

} // event

} // sl

#endif // BRIDGEEVENT_HPP
