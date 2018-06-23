#include "state/Encrypted.hpp"

#include "state/Authentication.hpp"

using namespace sl::event;
using namespace sl::state;

Encrypted::Encrypted(Listener& listener):
    ILiveCycleState(Type::ENCRYPTED, listener)
{
}

void Encrypted::start(const endpoint::Event* const) noexcept
{
    notifyBridgeEvent(new bridge::Event(bridge::Event::ENCRYPTED));
}

void Encrypted::handleEvent(const endpoint::Event& event)
{
    switch (event.getType())
    {
    case endpoint::Event::ATTACH:
        switchState<Authentication>(event);
        break;

    default:
        exceptUnexpected(event);
    }
}

std::string Encrypted::toString() const noexcept
{
    return "ENCRYPTED";
}
