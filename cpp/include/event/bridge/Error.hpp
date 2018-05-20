#ifndef EVENT_BRIDGE_ERROR_HPP
#define EVENT_BRIDGE_ERROR_HPP

#include "Message.hpp"

#include <string>

namespace sl
{

namespace event
{

namespace bridge
{

class Error : public Message
{
public:
    Error(const std::string message);

    ~Error();

    std::string toString() noexcept;
};

} // bridge

} // event

} // sl

#endif // EVENT_BRIDGE_ERROR_HPP
