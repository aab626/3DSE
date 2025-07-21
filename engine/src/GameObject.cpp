#include "../include/GameObject.hpp"

#include "../include/Engine.hpp"
#include "../include/Module.hpp"

#include <memory>

// Constructor for GameObject
GameObject::GameObject(Engine& e, id_t id) 
    : engine(e), id(id) {
        // Populate module mapping array
        for (const auto &moduleName : this->engine.getRegisteredModules()) {
            this->moduleMap[moduleName] = std::vector<ModulePtr>();
        }
    }

id_t GameObject::get_id() {
    return this->id;
}

void GameObject::addModule(ModulePtr module) {
    this->moduleMap[module.getName()].push_back(module);
}

// void GameObject::add_module(std::shared_ptr<Module> module) {
//     modules.push_back(module);
// }

// const std::vector<std::shared_ptr<Module>>& GameObject::get_modules() const {
//     return modules;
// }
