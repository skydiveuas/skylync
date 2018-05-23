#include "state/Encryption.hpp"

#include "state/Encrypted.hpp"

using sl::state::Encryption;

Encryption::Encryption(Listener& listener):
    ILiveCycleState(Type::ENCRYPTION, listener)
{
}

void Encryption::start(const EndpointEvent* const) noexcept
{
    notifyBridgeEvent(new BridgeEvent(BridgeEvent::CONNECTED));
    trace("Starting encryption procedure");
    unsigned char* data = new unsigned char[10];
    controlCommInterface.send(sl::ICommInterface::DataPacket(data, 10));
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
