#ifndef SKYBRIDGE_HPP
#define SKYBRIDGE_HPP

#include "SkyBridgeListener.hpp"

#include "ICommInterface.hpp"
#include "ProtobufParser.hpp"

#include "event/endpoint/Event.hpp"
#include "event/bridge/Event.hpp"

#include "state/ILiveCycleState.hpp"

#include <memory>
#include <mutex>

namespace sl
{

class SkyBridge : public state::ILiveCycleState::Listener
{
public:
    typedef state::ILiveCycleState State;

    typedef event::bridge::Event BridgeEvent;
    typedef event::endpoint::Event EndpointEvent;

    SkyBridge(SkyBridgeListener& listener);

    void notifyEndpointEvent(const EndpointEvent* event) noexcept;

    State::Type getState() const noexcept;

private:
    SkyBridgeListener& listener;

    std::shared_ptr<ICommInterface> commInterface;
    std::shared_ptr<ProtobufParser<skylync::BridgeMessage>> parser;

    std::shared_ptr<state::ILiveCycleState> state;
    std::mutex stateLock;

    void switchState(std::shared_ptr<State> newState, const EndpointEvent* const event) override;

    ICommInterface& getControlCommInterface() override;

    SkyBridgeListener& getBridgeListener() override;

    ProtobufParser<skylync::BridgeMessage>& getParser() override;

    void handleMessage(std::shared_ptr<skylync::BridgeMessage> message);
};

} // sl

#endif // SKYBRIDGE_HPP
