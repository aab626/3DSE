#include "engine.hpp"
#include "engine_common.hpp"

#include <fmt/core.h>

#include <limits>
#include <stdexcept>
#include <algorithm>


// Initialize Engine class variables
Engine* Engine::instance = nullptr;
t_id Engine::maxInstanceId = std::numeric_limits<t_id>::max();

// Engine constructor, just sets the instance fields for now
Engine::Engine()
: nextEntityId(ENGINE_START_ID) {

}

// Constructor and instance retrieval method for the Engine singleton
Engine* Engine::GetInstance() {
    if (!Engine::instance) {
        Engine::instance = new Engine();
    }

    return Engine::instance;
}

// Used to retrieve a Entity ID during creation
// Also increments the next ID and checks for overflows
t_id Engine::GetNextId() {
    if (nextEntityId < Engine::maxInstanceId) {
        t_id entityId = nextEntityId++;
        return entityId;
    } else {
        String msg = fmt::format("Maximum entity ID reached: {} of {}.", nextEntityId, Engine::maxInstanceId);
        throw std::runtime_error(msg);
    }
}

// Attemps to register a module into the engine
void Engine::RegisterModule(Module* module) {
    // Check if duplicate
    if (std::find(registeredModules.begin(), registeredModules.end(), module->GetName()) != registeredModules.end()) {
        String msg = fmt::format("Duplicate module registered: {}.", module->GetName());
        throw std::runtime_error(msg);
    }

    registeredModules.push_back(module->GetName());
}



// Python binding stuff, commented until usable
// #include <pybind11/pybind11.h>
// namespace py = pybind11;

// // Bind C++ engine classes to Python using pybind11 for scripting support.
// PYBIND11_MODULE(engine, m) {
//     py::class_<Engine>(m, "Engine")
//         .def(py::init<>())
//         .def("init", &Engine::init)
//         .def("render", &Engine::render)
//         .def("createGameObject", &Engine::createGameObject);
    
//     py::class_<GameObject>(m, "GameObject")
//         .def("get_id", &GameObject::get_id);
        
//     py::class_<Module, std::shared_ptr<Module>>(m, "Module")
//         .def("getName", &Module::getName)
//         .def("update", &Module::update);

//     py::class_<TestModule, Module, std::shared_ptr<TestModule>>(m, "TestModule")
//         .def(py::init<Engine&, std::string&>())
//         .def("update", &TestModule::update);
// }