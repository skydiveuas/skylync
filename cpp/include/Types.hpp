#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>
#include <string>

namespace sl
{
typedef std::pair<const uint8_t* const, const size_t> DataPacket;

enum TransportProtocol
{
    TCP,
    UDP,
};

enum EndpointType
{
    DEVICE,
    PILOT,
};

typedef unsigned long RefId;
typedef std::pair<RefId, std::string> RefName;

typedef std::vector<RefName> DeviceList;

} // types

#endif // TYPES_HPP
