#include "SkyBridge.hpp"

#include "state/Disconnected.hpp"

#include "event/bridge/Message.hpp"

#include <functional>

using sl::SkyBridge;

SkyBridge::SkyBridge(sl::SkyBridgeListener& _listener):
    listener(_listener),
    parser(std::bind(&SkyBridge::handleMessage, this, std::placeholders::_1)),
    commInterface(listener.createCommInterface(sl::ICommInterface::TCP, *state.get())),
    state(std::make_shared<sl::state::Disconnected>(*this))
{
    commInterface->setListener(*state.get());
}

void SkyBridge::notifyEndpointEvent(const EndpointEvent* event) noexcept
{
    listener.trace("Handling: " + event->toString() + " @ " + state->toString());
    std::unique_ptr<const EndpointEvent> eventLock(event);
    state->handleEvent(*event);
}

sl::state::ILiveCycleState::Type SkyBridge::getState() const noexcept
{
    return state->getType();
}

void SkyBridge::switchState(std::shared_ptr<State> newState, const EndpointEvent* const event)
{
    listener.trace("Transition: " + state->toString() + " -> " + newState->toString());
    state.swap(newState);
    state->start(event);
}

sl::ICommInterface& SkyBridge::getControlCommInterface()
{
    return *commInterface;
}

sl::SkyBridgeListener& SkyBridge::getBridgeListener()
{
    return listener;
}

sl::ProtobufParser<skylync::BridgeMessage>& SkyBridge::getParser()
{
    return parser;
}

void SkyBridge::updateContext(const skylync::Context* _context)
{
    listener.trace("Updating context");
    if (context.update(_context))
    {
        listener.trace("ERR! Context update failed");
    }
}

void SkyBridge::handleMessage(std::shared_ptr<skylync::BridgeMessage> message)
{
    state->handleMessage(message);
}
