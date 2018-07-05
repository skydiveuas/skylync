#ifndef SKYBRIDGE_HPP
#define SKYBRIDGE_HPP

#include "SkyBridgeListener.hpp"

#include "ICommInterface.hpp"
#include "ProtobufParser.hpp"

#include "Context.hpp"

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
    SkyBridge(SkyBridgeListener& listener);

    void notifyEndpointEvent(const event::endpoint::Event* event) noexcept;

    state::ILiveCycleState::Type getState() const noexcept;

private:
    SkyBridgeListener& listener;
    ProtobufParser<skylync::BridgeMessage> parser;

    std::shared_ptr<ICommInterface> commInterface;

    std::shared_ptr<state::ILiveCycleState> state;
    std::mutex stateLock;

    Context context;

    void switchState(std::shared_ptr<state::ILiveCycleState> newState) override;

    ICommInterface& getControlCommInterface() override;

    SkyBridgeListener& getBridgeListener() override;

    ProtobufParser<skylync::BridgeMessage>& getParser() override;

    void updateContext(const skylync::Context* _context) override;

    void handleMessage(std::shared_ptr<skylync::BridgeMessage> message);
};

} // sl

#endif // SKYBRIDGE_HPP
