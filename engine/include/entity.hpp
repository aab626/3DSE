#pragma once
#include "engine_common.hpp"

#include "modules/module.hpp"

#include <vector>

class Entity {
    // Fields
    protected:
        t_id id;
        std::vector<Module*> modules;

    // Methods
    public:
        // Constructor
        Entity();
        void AddModule(Module* module);
        void RemoveModule(const String& moduleName);
};
