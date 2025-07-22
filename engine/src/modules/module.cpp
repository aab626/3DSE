#include "modules/module.hpp"
#include "engine.hpp"

// Constructor
Module::Module(String& name)
: name(name) {
}

// Registers a module in the engine
void Module::RegisterModule(Module* module) {
    Engine* engine = Engine::GetInstance();
    engine->RegisterModule(module);
}

const String& Module::GetName() const {
    const String& nameRef = name;
    return nameRef;
}