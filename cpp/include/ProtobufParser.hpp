#ifndef PROTOBUFPARSER_HPP
#define PROTOBUFPARSER_HPP

#include "ICommInterface.hpp"

#include "skylync.pb.h"

#include "memory"

namespace sl
{

template <typename _ExpectedMessage>
class ProtobufParser
{
public:
    typedef std::function<void(std::shared_ptr<_ExpectedMessage>)> Callback;
    typedef std::function<void(const char* const)> ErrorHandler;

    ProtobufParser(Callback _callback);

    void deserialize(const char* const buf, const size_t length) const;

    ICommInterface::DataPacket serialize(const ::google::protobuf::Message& message);

private:
    static constexpr size_t OUT_BUFFER_SIZE = 1024;
    std::array<char, OUT_BUFFER_SIZE> outBuffer;
    size_t outBufferPosition = { 0 };

    const Callback callback;

    bool serialize(const ::google::protobuf::Message& message, char* buf, const size_t length) const;
};

template <typename _ExpectedMessage>
ProtobufParser<_ExpectedMessage>::ProtobufParser(Callback _callback):
    callback(_callback)
{
}

template <typename _ExpectedMessage>
void ProtobufParser<_ExpectedMessage>::deserialize(const char* const buf, const size_t length) const
{
    size_t size = length;
    while (size >= sizeof(uint32_t))
    {
        size_t messageSize;
        memcpy(&messageSize, buf, sizeof(uint32_t));
        if (messageSize + sizeof(uint32_t) < length)
        {
            throw std::runtime_error("Not enough data received for parsing.");
        }

        std::shared_ptr<_ExpectedMessage> result = std::make_shared<_ExpectedMessage>();
        if (result->ParseFromArray(buf, messageSize))
        {
            callback(result);
        }
        else
        {
            throw std::runtime_error("Could not parse message.");
        }

        size -= (messageSize + sizeof(uint32_t));
    }
}

template <typename _ExpectedMessage>
sl::ICommInterface::DataPacket ProtobufParser<_ExpectedMessage>::serialize(const ::google::protobuf::Message& message)
{
    size_t size = message.ByteSizeLong() + sizeof(uint32_t);
    if (OUT_BUFFER_SIZE - outBufferPosition < size)
    {
        outBufferPosition = 0;
    }
    if (serialize(message, outBuffer.data() + outBufferPosition, size))
    {
        throw std::runtime_error("Could not serialize message");
    }
    ICommInterface::DataPacket result(outBuffer.data() + outBufferPosition, size);
    outBufferPosition += size;
    return result;
}

template <typename _ExpectedMessage>
bool ProtobufParser<_ExpectedMessage>::serialize(const ::google::protobuf::Message& message, char* buf, const size_t length) const
{
    const size_t messageSize = message.ByteSizeLong();
    if (length < messageSize + sizeof(uint32_t))
    {
        throw std::runtime_error("Too small buffer for message to be serialized.");
    }
    memcpy(buf, &messageSize, sizeof(uint32_t));
    return message.SerializeToArray(buf + sizeof(uint32_t), length);
}

} // sl

#endif // PROTOBUFPARSER_HPP
