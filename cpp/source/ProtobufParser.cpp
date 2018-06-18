#include "ProtobufParser.hpp"

using sl::ProtobufParser;

ProtobufParser::ProtobufParser(Callback _callback):
    callback(_callback)
{
}

void ProtobufParser::deserialize(const char* const buf, const size_t length)
{

}

bool ProtobufParser::serialize(const ::google::protobuf::Message& message, char* buf, const size_t length)
{
    const size_t messageSize = message.ByteSizeLong();
    if (length < messageSize + sizeof(uint32_t))
    {
        return false;
    }
    memcpy(buf, &messageSize, sizeof(uint32_t));
    return message.SerializeToArray(buf + sizeof(uint32_t), length);
}
