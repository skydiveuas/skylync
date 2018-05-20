#ifndef EVENT_ENDPOINT_ATTACH_HPP
#define EVENT_ENDPOINT_ATTACH_HPP

#include <string>

#include "Event.hpp"

namespace sl
{

namespace event
{

namespace endpoint
{

class Attach
{
public:
    Attach(const std::string _id, const std::string _pwd);

    ~Attach();

    std::string toString() noexcept;

private:
    const std::string id;
    const std::string pwd;
};

} // endpoint

} // event

} // sl

#endif // EVENT_ENDPOINT_ATTACH_HPP
