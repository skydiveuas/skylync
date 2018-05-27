#include "state/Encryption.hpp"

#include "state/Encrypted.hpp"

#include <cstring>

using sl::state::Encryption;

Encryption::Encryption(Listener& listener):
    ILiveCycleState(Type::ENCRYPTION, listener)
{
}

void Encryption::start(const EndpointEvent* const) noexcept
{
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::CONNECTED));
    trace("Starting encryption procedure");
    const size_t SIZE = 64;
    unsigned char* data = new unsigned char[SIZE];
    std::memset(data, 'a', SIZE);
    controlCommInterface.send(sl::ICommInterface::DataPacket(data, SIZE));
}

void Encryption::onReceived(const sl::ICommInterface::DataPacket dataPacket)
{
    trace("Received " + std::to_string(dataPacket.second) + " bytes, encrypted");
    delete[] dataPacket.first;
    switchState<sl::state::Encrypted>();
}

std::string Encryption::toString() const noexcept
{
    return "ENCRYPTION";
}
