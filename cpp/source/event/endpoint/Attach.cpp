#include "event/endpoint/Attach.hpp"

using namespace sl::event::endpoint;

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

const std::string& Attach::getId() const noexcept
{
    return id;
}

const std::string& Attach::getPwd() const noexcept
{
    return pwd;
}
