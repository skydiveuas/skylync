#ifndef EVENT_BRIDGE_CHANNEL_HPP
#define EVENT_BRIDGE_CHANNEL_HPP

#include "Event.hpp"

#include <string>

namespace sl
{

namespace event
{

namespace bridge
{

class Channel : public Event
{
public:
    Channel();

    std::string toString() const noexcept override;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_CHANNEL_HPP
