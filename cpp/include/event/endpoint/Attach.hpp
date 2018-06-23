#ifndef EVENT_ENDPOINT_ATTACH_HPP
#define EVENT_ENDPOINT_ATTACH_HPP

#include "Event.hpp"

#include <string>

namespace sl
{

namespace event
{

namespace endpoint
{

class Attach : public Event
{
public:
    Attach(const std::string _id, const std::string _pwd);

    ~Attach();

    std::string toString() const noexcept override;

    const std::string& getId() const noexcept;
    const std::string& getPwd() const noexcept;

private:
    const std::string id;
    std::string pwd;
};

} // endpoint

} // event

} // sl

#endif // EVENT_ENDPOINT_ATTACH_HPP
