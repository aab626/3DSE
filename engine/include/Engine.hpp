#pragma once
#include "../include/GameObject.hpp"

#include <vector>
#include <string>
// #include <unordered_map>
// #include <memory>

// GameObject id type shorthand
typedef signed int id_t;

// Engine class
class Engine {
private:
    id_t nextGameObjectId;                  // ID for the next game object
    std::vector<std::string> registeredModules;
    
    // std::vector<GameObject> gameObjects;    // Vector of active game objects

public:
    Engine() = default;

    void init();
    void render();

    GameObject createGameObject();
    void registerModule(std::string moduleName);
    std::vector<std::string>& getRegisteredModules();
};