#include "ICommInterface.hpp"

using namespace sl;

ICommInterface::ICommInterface(const Listener& _listener):
    listener(_listener)
{
}

ICommInterface::~ICommInterface()
{
}

