#ifndef PROTOBUFPARSER_HPP
#define PROTOBUFPARSER_HPP

#include "skylync.pb.h"

namespace sl
{

class ProtobufParser
{
public:
    typedef std::function<void(const skylync::BridgeMessage* const)> Callback;

    ProtobufParser(Callback _callback);

    void deserialize(const char* const buf, const size_t length);

    static bool serialize(const ::google::protobuf::Message& message, char* buf, const size_t length);

private:
    Callback callback;
};

} // sl

#endif // PROTOBUFPARSER_HPP
