#ifndef STATE_ISTATE_HPP
#define STATE_ISTATE_HPP

#include "ITimer.hpp"

#include "event/bridge/Event.hpp"
#include "event/endpoint/Event.hpp"

#include <memory>

namespace sl
{

namespace state
{

class IState
{
public:
    enum Type
    {
        IDLE,
        CONNECTING,
        ATTACHING,
        ATTACHED,
    };

    class Listener
    {
    public:
        virtual void notifyBridgeEvent(const event::bridge::Event* event) noexcept = 0;

        virtual std::shared_ptr<ITimer> createTimer() noexcept = 0;

        virtual void trace(const std::string& message) noexcept = 0;
    };

    IState(const Type _type, Listener& _listener);

    virtual ~IState();

    Type getType() const noexcept;

    virtual IState* handleEvent(const event::endpoint::Event& event) = 0;

    virtual IState* handleMessage() = 0;

    virtual std::string toString() const noexcept = 0;

protected:
    const Type type;

    Listener& listener;

    template <typename _State>
    IState* newState() const;

    void except(const event::endpoint::Event& event) const;
};

template <typename _State>
IState* IState::newState() const
{
    return new _State(listener);
}

} // state

} // sl

#endif // STATE_ISTATE_HPP
