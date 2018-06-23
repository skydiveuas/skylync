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
    char* data = new char[SIZE];
    std::memset(data, 'a', SIZE);
    controlCommInterface.send(ICommInterface::DataPacket(data, SIZE));
}

void Encryption::onReceived(const ICommInterface::DataPacket dataPacket)
{
    trace("Received " + std::to_string(dataPacket.second) + " bytes, encrypted");
    delete[] dataPacket.first;
    switchState<Encrypted>();
}

std::string Encryption::toString() const noexcept
{
    return "ENCRYPTION";
}
