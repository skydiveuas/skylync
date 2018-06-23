#include "SkyBridge.hpp"

#include "state/Disconnected.hpp"

#include "event/bridge/Message.hpp"

#include <functional>

using namespace sl;

SkyBridge::SkyBridge(SkyBridgeListener& _listener):
    listener(_listener),
    parser(std::bind(&SkyBridge::handleMessage, this, std::placeholders::_1)),
    commInterface(listener.createCommInterface(ICommInterface::TCP, *state.get())),
    state(std::make_shared<state::Disconnected>(*this))
{
    commInterface->setListener(*state.get());
}

void SkyBridge::notifyEndpointEvent(const event::endpoint::Event* event) noexcept
{
    listener.trace("Handling: " + event->toString() + " @ " + state->toString());
    std::unique_ptr<const event::endpoint::Event> eventLock(event);
    state->handleEvent(*event);
}

state::ILiveCycleState::Type SkyBridge::getState() const noexcept
{
    return state->getType();
}

void SkyBridge::switchState(std::shared_ptr<state::ILiveCycleState> newState, const event::endpoint::Event* const event)
{
    listener.trace("Transition: " + state->toString() + " -> " + newState->toString());
    state.swap(newState);
    state->start(event);
}

ICommInterface& SkyBridge::getControlCommInterface()
{
    return *commInterface;
}

SkyBridgeListener& SkyBridge::getBridgeListener()
{
    return listener;
}

ProtobufParser<skylync::BridgeMessage>& SkyBridge::getParser()
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
    listener.trace("Received: " + message->DebugString() + " @ " + state->toString());
    state->handleMessage(message);
}
