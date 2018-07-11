#ifndef EVENT_BRIDGE_CHANNEL_HPP
#define EVENT_BRIDGE_CHANNEL_HPP

#include "Event.hpp"

#include "ICommInterface.hpp"

#include <string>
#include "memory"

namespace sl
{

namespace event
{

namespace bridge
{

class Channel : public Event
{
public:
    Channel(std::shared_ptr<ICommInterface> _interface);

    std::string toString() const noexcept override;

private:
    std::shared_ptr<ICommInterface> interface;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_CHANNEL_HPP
