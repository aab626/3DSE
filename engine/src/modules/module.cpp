#include "modules/module.hpp"
#include "engine_common.hpp"
#include "engine.hpp"

// Constructor
Module::Module(String& name, ModuleType type)
: name(name), type(type) {}

// Virtual destructor
Module::~Module() {}

const String& Module::GetName() const {
    return name;
}