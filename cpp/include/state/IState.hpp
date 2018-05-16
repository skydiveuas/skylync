#ifndef ISTATE_HPP
#define ISTATE_HPP

#include "event/bridge/Event.hpp"

#include <memory>

namespace sl
{

namespace state
{

class IState
{
public:
    class Listener
    {
    public:
        virtual void notifyBridgeEvent(const event::bridge::Event& event) = 0;

        virtual std::shared_ptr<ITimer> createTimer() = 0;

        virtual void trace(const std::string& message) = 0;
    };

    IState(Listener& _listener):
        listener(_listener)
    {

    }

    virtual ~IState()
    {
    }

protected:
    Listener& listener;
};

} // state

} // sl

#endif // ISTATE_HPP
