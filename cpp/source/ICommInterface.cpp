#include "ICommInterface.hpp"

using sl::ICommInterface;


ICommInterface::ICommInterface(Listener& _listener)
{
    setListener(_listener);
}

void ICommInterface::setListener(Listener& _listener)
{
    listener.store(&_listener);
}

ICommInterface::~ICommInterface()
{
}
