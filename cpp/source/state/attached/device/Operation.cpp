#include "state/attached/device/Operation.hpp"

#include "event/bridge/Channel.hpp"

using namespace sl::event;
using namespace sl::state;
using namespace sl::state::attached;
using namespace sl::state::attached::device;

Operation::Operation(ILiveCycleState::Listener& listener):
    IAttachedState(listener)
{
}

void Operation::start() noexcept
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_responsefor(skylync::Message::OPERATION_STARTED);
    message.mutable_base()->set_command(skylync::Message::ACCEPT);
    send(message);
}

IAttachedState* Operation::handleEvent(const sl::event::endpoint::Event& event)
{
    switch (event.getType())
    {
    default:
        exceptUnexpected(event);
        return nullptr;
    }
}

IAttachedState* Operation::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    switch (message->base().command())
    {
    case skylync::Message::CHANNEL_OPEN:
        openChannel(message->channelparams());
        return nullptr;

    case skylync::Message::CHANNEL_VALIDATE:
        validateChannel(message->channelvalidationparams());
        return nullptr;

    default:
        exceptUnexpected(message);
        return nullptr;
    }
}

std::string Operation::toString() const noexcept
{
    return "Attached::Pilot::Operation";
}

void Operation::openChannel(const skylync::ChannelParams& params)
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_responsefor(skylync::Message::CHANNEL_OPEN);
    if (true)//listener.isChannelSupported(params.channelid()))
    {
        message.mutable_base()->set_command(skylync::Message::ACCEPT);
    }
    else
    {
        message.mutable_base()->set_command(skylync::Message::REJECT);
    }
    send(message);
}

void Operation::validateChannel(const skylync::ChannelValidationParams& params)
{
    if (true)//listener.isChannelSupported(params.channelid()))
    {
        TransportProtocol tp = UDP;//evaluateTransportProtocol(params.channelid());
        key = std::vector<uint8_t>(params.key().data(), params.key().data() + params.key().size());
        interface = listener.getBridgeListener().createCommInterface(tp, *this);
        interface->connect("localhost", params.port());
    }
    else
    {
        skylync::EndpointMessage message;
        message.mutable_base()->set_responsefor(skylync::Message::CHANNEL_VALIDATE);
        message.mutable_base()->set_command(skylync::Message::REJECT);
        send(message);
    }
}

void Operation::onConnected()
{
    trace("Operation::onConnected");
    interface->send(DataPacket(key.data(), key.size()));
    key.clear();
}

void Operation::onDisconnected()
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_responsefor(skylync::Message::CHANNEL_VALIDATE);
    message.mutable_base()->set_command(skylync::Message::REJECT);
    send(message);
    interface.reset();
}

void Operation::onReceived(const DataPacket dataPacket)
{
    skylync::EndpointMessage message;
    message.mutable_base()->set_responsefor(skylync::Message::CHANNEL_VALIDATE);
    if (validateKey(dataPacket))
    {
        interface->setListener(nullptr);
        notifyBridgeEvent(new bridge::Channel(interface));
        message.mutable_base()->set_command(skylync::Message::ACCEPT);
    }
    else
    {
        message.mutable_base()->set_command(skylync::Message::REJECT);
    }
    interface.reset();
    send(message);
}

bool Operation::validateKey(const DataPacket dataPacket) const
{
    if (dataPacket.second == key.size())
    {
        for (size_t i = 0; i < dataPacket.second; ++i)
        {
            if (key.at(i) != dataPacket.first[i])
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}
