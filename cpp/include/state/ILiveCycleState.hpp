#ifndef STATE_ILIVECYCLESTATE_HPP
#define STATE_ILIVECYCLESTATE_HPP

#include "SkyBridgeListener.hpp"

#include "ICommInterface.hpp"
#include "ProtobufParser.hpp"

#include "skylync.pb.h"

#include "event/bridge/Event.hpp"
#include "event/endpoint/Event.hpp"

#include <memory>

namespace sl
{

namespace state
{

class ILiveCycleState : public ICommInterface::Listener
{
public:
    typedef event::endpoint::Event EndpointEvent;
    typedef event::bridge::Event BridgeEvent;

    enum Type
    {
        DISCONNECTED,
        CONNECTION,
        ENCRYPTION,
        ENCRYPTED,
        AUTHENTICATION,
        ATTACHED,
        RELEASE,
        DISCONNECTION,
    };

    class Listener
    {
    public:
        virtual ~Listener();

        virtual void switchState(std::shared_ptr<ILiveCycleState>, const EndpointEvent* const) = 0;

        virtual ICommInterface& getControlCommInterface() = 0;

        virtual SkyBridgeListener& getBridgeListener() = 0;

        virtual ProtobufParser<skylync::BridgeMessage>& getParser() = 0;
    };

    ILiveCycleState(const Type type, Listener& listener);

    virtual ~ILiveCycleState();

    Type getType() const noexcept;

    virtual void start(const EndpointEvent* const event) noexcept;

    virtual void handleEvent(const EndpointEvent& event);

    virtual void handleMessage(std::shared_ptr<skylync::BridgeMessage> message);

    virtual void onConnected();

    virtual void onDisconnected();

    virtual void onReceived(const ICommInterface::DataPacket dataPacket);

    virtual std::string toString() const noexcept = 0;

protected:
    const Type type;

    Listener& listener;

    ICommInterface& controlCommInterface;

    void send(const skylync::EndpointMessage& message);

    void notifyBridgeEvent(const BridgeEvent* const event);
    void trace(const std::string& message);   

    void except(const std::string& cause) const;
    void exceptUnexpected(const std::shared_ptr<skylync::BridgeMessage> message) const;
    void exceptUnexpected(const EndpointEvent& event) const;
    void exceptUnexpected(const std::string& cause) const;

    template <typename _State>
    void switchState()
    {
        listener.switchState(std::make_shared<_State>(listener), nullptr);
    }

    template <typename _State>
    void switchState(const EndpointEvent& event)
    {
        listener.switchState(std::make_shared<_State>(listener), &event);
    }
};

} // state

} // sl

#endif // STATE_ILIVECYCLESTATE_HPP
