#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "skylync.pb.h"

namespace sl
{

class Context
{
public:
    Context();

    bool update(const skylync::Context* _protoContext);

    unsigned long getRefId() const;

private:
    std::unique_ptr<const skylync::Context> protoContext;

    bool validateProto(const skylync::Context* _protoContext) const;
};

} // sl

#endif // CONTEXT_HPP
