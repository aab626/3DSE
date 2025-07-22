#include "entity.hpp"
#include "engine.hpp"

#include <fmt/core.h>
#include <stdexcept>


// Constructor
Entity::Entity() {
    Engine *engine = Engine::GetInstance();
    this->id = engine->GetNextId();
}

// Add a module to the entity
void Entity::AddModule(Module* module) {
    modules.push_back(module);
}

void Entity::RemoveModule(const String& moduleName) {
    auto moduleIterator = std::find_if(modules.begin(), modules.end(), [&moduleName](Module* m) { return m->GetName() == moduleName; });
    if (moduleIterator != modules.end()) {
        modules.erase(moduleIterator);
    } else {
        String msg = fmt::format("Module \"{}\" not found in entity ID: {}", moduleName, id);
        throw std::runtime_error(msg);
    }
}
