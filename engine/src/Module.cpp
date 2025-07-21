
#include "../include/Module.hpp"
#include "../include/Engine.hpp"

#include <string>

// Module constructor
// Sets fields and registers the module to the engine
Module::Module(Engine &e, const std::string &s)
    : engine(e), moduleName(s) {
        this->engine.registerModule(s);
    }

// Getter for read only module name
const std::string Module::getName() {
    return this->moduleName;
}