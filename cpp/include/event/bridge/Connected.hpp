#ifndef EVENT_BRIDGE_CONNECTED_HPP
#define EVENT_BRIDGE_CONNECTED_HPP

#include "Event.hpp"

namespace sl
{

namespace event
{

namespace bridge
{

class Connected : public Event
{
public:
    Connected();

    ~Connected();

    std::string toString() noexcept;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_CONNECTED_HPP
