#include "state/Encrypted.hpp"

#include "state/Authentication.hpp"

using sl::state::Encrypted;

Encrypted::Encrypted(Listener& listener):
    ILiveCycleState(Type::ENCRYPTED, listener)
{
}

void Encrypted::start(const EndpointEvent* const) noexcept
{
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::ENCRYPTED));
}

void Encrypted::handleEvent(const EndpointEvent& event)
{
    switch (event.getType())
    {
    case EndpointEvent::ATTACH:
        switchState<sl::state::Authentication>(event);
        break;

    default:
        exceptUnexpected(event);
    }
}

std::string Encrypted::toString() const noexcept
{
    return "ENCRYPTED";
}
