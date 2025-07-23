#pragma once
#include "engine_common.hpp"
#include "modules/module.hpp"
#include <vector>
#include <tuple>


constexpr t_id ENGINE_START_ID = 0;

class Engine {
// Static attributes
public:
    static Engine *instance;
    static t_id maxInstanceId;

// Static methods
public:
    static Engine* GetInstance();

// Instance fields
private:
    t_id nextEntityId;
    std::vector<std::tuple<ModuleType, String>> registeredModuleTypes;

// Instance methods
private:
    Engine();

public:
    t_id GetNextId();
    void RegisterModuleType(ModuleType type, String& typeName);
};
