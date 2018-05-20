#include "event/endpoint/Attach.hpp"

using sl::event::endpoint::Attach;

Attach::Attach(const std::string _id, const std::string _pwd):
    Event(Event::ATTACH),
    ip(_ip),
    pwd(_pwd)
{
}

Attach::~Attach()
{

}

std::string toString() noexcept;
