#include "state/Encryption.hpp"

#include "state/Encrypted.hpp"

#include <cstring>

using namespace sl::event;
using namespace sl::state;

Encryption::Encryption(Listener& listener):
    ILiveCycleState(Type::ENCRYPTION, listener)
{
}

void Encryption::start(const endpoint::Event* const) noexcept
{
    notifyBridgeEvent(new bridge::Event(event::bridge::Event::CONNECTED));
    trace("Starting encryption procedure");
    const size_t SIZE = 64;
    uint8_t* data = new uint8_t[SIZE];
    std::memset(data, 'a', SIZE);
    controlCommInterface.send(DataPacket(data, SIZE));
    delete[] data;
}

void Encryption::onReceived(const DataPacket dataPacket)
{
    trace("Received " + std::to_string(dataPacket.second) + " bytes, encrypted");
    switchState<Encrypted>();
}

std::string Encryption::toString() const noexcept
{
    return "ENCRYPTION";
}
