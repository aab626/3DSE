#include "engine.hpp"
#include "engine_common.hpp"

#include <fmt/core.h>

#include <limits>
#include <stdexcept>
#include <algorithm>


// Initialize Engine class variables
Engine* Engine::instance = nullptr;
t_id Engine::maxInstanceId = std::numeric_limits<t_id>::max();

// Engine constructor, just sets the instance fields for now
Engine::Engine()
: nextEntityId(ENGINE_START_ID) {

}

// Constructor and instance retrieval method for the Engine singleton
Engine* Engine::GetInstance() {
    if (!Engine::instance) {
        Engine::instance = new Engine();
    }

    return Engine::instance;
}

// Used to retrieve a Entity ID during creation
// Also increments the next ID and checks for overflows
t_id Engine::GetNextId() {
    if (nextEntityId < Engine::maxInstanceId) {
        t_id entityId = nextEntityId++;
        return entityId;
    } else {
        String msg = fmt::format("Maximum entity ID reached: {} of {}.", nextEntityId, Engine::maxInstanceId);
        throw std::runtime_error(msg);
    }
}

// Attemps to register a module into the engine
void Engine::RegisterModuleType(ModuleType type, String& typeName) {
    // Check if duplicate
    auto it = std::find_if(
        registeredModuleTypes.begin(), registeredModuleTypes.end(),
        [type](const std::tuple<ModuleType, String>& tuple) {
            return std::get<0>(tuple) == type;
        }
    );

    // Found duplicate
    if (it != registeredModuleTypes.end()) {
        String msg = fmt::format("Duplicate module type registered: {}.", std::get<1>(*it));
        throw std::runtime_error(msg);
    }

    // Register module type
    registeredModuleTypes.emplace_back(type, typeName);
}



