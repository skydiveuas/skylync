#include "state/Encryption.hpp"

#include "state/Encrypted.hpp"

#include <cstring>

using namespace sl::event;
using namespace sl::state;

Encryption::Encryption(Listener& listener):
    ILiveCycleState(Type::ENCRYPTION, listener)
{
}

void Encryption::start() noexcept
{
    notifyBridgeEvent(new bridge::Event(event::bridge::Event::CONNECTED));
    trace("Starting encryption procedure");
    std::vector<uint8_t> data(static_cast<uint8_t>('a'), 64);
    controlCommInterface.send(DataPacket(data.data(), 64));
}

void Encryption::onReceived(const DataPacket dataPacket)
{
    trace("Received " + std::to_string(dataPacket.second) + " bytes, encrypted");
    switchState<Encrypted>();
}

std::string Encryption::toString() const noexcept
{
    return "Encryption";
}
