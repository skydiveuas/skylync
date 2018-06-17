#include "ProtobufParser.hpp"

using sl::ProtobufParser;

ProtobufParser::ProtobufParser(Callback _callback):
    callback(_callback)
{
}

void ProtobufParser::deserialize(const void* const buf, const size_t length)
{

}

void ProtobufParser::serialize(const ::google::protobuf::Message& message, const void* const buf, const size_t length)
{
    const size_t messageSize = message.ByteSizeLong();
    if (length < messageSize + sizeof(uint32_t))
    {
        std::runtime_error("Too small buffer provided for message serialization");
    }
    memcpy(buf, &messageSize, sizeof(uint32_t));
    if (!message.SerializeToArray(buf + sizeof(uint32_t), length))
    {
        std::runtime_error("Serialization error, message corruped");
    }
}
