#ifndef EVENT_BRIDGE_ATTACHED_HPP
#define EVENT_BRIDGE_ATTACHED_HPP

#include "Event.hpp"

namespace sl
{

namespace event
{

namespace bridge
{

class Attach : public Event
{
public:
    Attach();

    ~Attach();

    std::string toString() noexcept;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_ATTACHED_HPP
