#pragma once

#include "Module.hpp"
#include "Engine.hpp"

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

class GameObject {
    friend class Engine; // Allow Engine to access private members

private:
    Engine& engine;
    id_t id;
    std::unordered_map<std::string, std::vector<ModulePtr>> moduleMap;
    GameObject(Engine& e, id_t id);
    
public:
    id_t get_id();
    void addModule(ModulePtr module);
};
