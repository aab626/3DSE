#include "modules/module.hpp"
#include "engine.hpp"

// Constructor
Module::Module(String& name)
: name(name) {}

// Virtual destructor
Module::~Module() {}

// Registers a module in the engine
void Module::RegisterModule() {
    Engine* engine = Engine::GetInstance();
    engine->RegisterModule(this);
}

const String& Module::GetName() const {
    const String& nameRef = name;
    return nameRef;
}