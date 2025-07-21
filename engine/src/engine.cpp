// ...existing code...
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <pybind11/pybind11.h>
#include <gl/GL.h>

#include "../include/Engine.hpp"

#include "../include/GameObject.hpp"
#include "../include/Module.hpp"
#include "../include/modules/TestModule.hpp"

// #include "../include/modules/RenderModule.hpp"


namespace py = pybind11;


void Engine::init() {
    // Initialize engine vars
    this->nextGameObjectId = 0;

    // Register modules
    TestModule testMod(*this, "Test Module");
}

void Engine::render() {
    // Rendering logic here
}

GameObject Engine::createGameObject() {
    GameObject gameObject = GameObject(*this, nextGameObjectId);
    nextGameObjectId++;
    return gameObject;
}

void Engine::registerModule(std::string moduleName) {
    for (const auto& registeredModuleName : this->registeredModules) {
        if (moduleName == registeredModuleName) {
            throw std::runtime_error("Module already registered: " + moduleName);
        }
    }

    this->registeredModules.push_back(moduleName);
}

// Getters
std::vector<std::string>& Engine::getRegisteredModules() {
    return this->registeredModules;
}

// Bind C++ engine classes to Python using pybind11 for scripting support.
PYBIND11_MODULE(engine, m) {
    py::class_<Engine>(m, "Engine")
        .def(py::init<>())
        .def("init", &Engine::init)
        .def("render", &Engine::render)
        .def("createGameObject", &Engine::createGameObject);
    
    py::class_<GameObject>(m, "GameObject")
        .def("get_id", &GameObject::get_id);
        
    py::class_<Module, std::shared_ptr<Module>>(m, "Module")
        .def("getName", &Module::getName)
        .def("update", &Module::update);

    py::class_<TestModule, Module, std::shared_ptr<TestModule>>(m, "TestModule")
        .def(py::init<Engine&, std::string&>())
        .def("update", &TestModule::update);
}