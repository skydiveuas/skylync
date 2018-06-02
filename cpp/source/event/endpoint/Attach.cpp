#include "event/endpoint/Attach.hpp"

using sl::event::endpoint::Attach;

Attach::Attach(const std::string _id, const std::string _pwd):
    Event(Event::ATTACH),
    id(_id),
    pwd(_pwd)
{
}

Attach::~Attach()
{
    pwd.assign(pwd.size(), '*');
}

std::string Attach::toString() const noexcept
{
    return "Attach[" + id + "]";
}

std::string Attach::getMessage() const noexcept
{
    return "Attach[id:" + id + ", pwd:" + pwd + "]";
}
