#include "engine_common.hpp"
#include "engine.hpp"
#include "entity.hpp"
#include "modules/module.hpp"
#include "modules/test_module.hpp"
#include "modules/logger_module.hpp"
#include "modules/transform_module.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


namespace py = pybind11;
using namespace pybind11::literals;

// Bind C++ engine classes to Python using pybind11 for scripting support.
PYBIND11_MODULE(engine_lib, m) {
    m.doc() = "3D Space Game Engine library";

    py::enum_<ModuleType>(m, "ModuleType")
        .value("MODULE_TYPE_BASE", MODULE_TYPE_BASE)
        .value("MODULE_TYPE_TEST", MODULE_TYPE_TEST)
        .value("MODULE_TYPE_LOGGER", MODULE_TYPE_LOGGER)
        .value("MODULE_TYPE_TRANSFORM", MODULE_TYPE_TRANSFORM);

    // Expose Engine class 
    py::class_<Engine, py::smart_holder>(m, "Engine")
        // Static methods
        .def_static("GetInstance", 
            &Engine::GetInstance, py::return_value_policy::reference, 
            "Get the singleton Engine instance")

        // Instance methods
        .def("RegisterModuleType", 
            &Engine::RegisterModuleType, "type"_a, "typeName"_a,
            "Register a module type in the engine");

    // Expose Entity class
    py::class_<Entity>(m, "Entity")
        // Constructor
        .def(py::init<>(), 
            "Create a new Entity")

        // Instance methods
        .def("AddModule", 
            &Entity::AddModule, "module"_a,
            "Add a module to this entity")

        .def("RemoveModule", 
            &Entity::RemoveModule, "moduleName"_a
            "Remove a module from this entity by name");

    // Modules
    py::class_<Module>(m, "Module")
        .def("GetName", 
            &Module::GetName, 
            "Returns the name of the module");

    // Test module
    py::class_<TestModule, Module>(m, "TestModule")
        .def(py::init<String&, int, String>(),
            "name"_a, "testInt"_a, "testString"_a
        )

        .def_readonly_static("moduleTypeName", &TestModule::moduleTypeName)

        .def("init", &TestModule::init)
        .def("update", &TestModule::update);

    // Logger module
    py::class_<LoggerModule, Module>(m, "LoggerModule")
        .def(py::init<String &>(),
            "name"_a)

        .def_readonly_static("moduleTypeName", &LoggerModule::moduleTypeName)
        
        .def("init", &LoggerModule::init)
        .def("update", &LoggerModule::update);

    // Transform module
    py::class_<TransformModule, Module>(m, "TransformModule")
        .def(py::init<String&>(),
            "name"_a)

        .def(py::init<String&, std::array<double, 3>, std::array<double, 3>, std::array<double, 3>>(),
            "name"_a, "position"_a, "rotation"_a, "scale"_a)

        .def_readonly_static("moduleTypeName", &TransformModule::moduleTypeName)

        .def("init", &TransformModule::init)
        .def("update", &TransformModule::update)

        .def("GetPosition", &TransformModule::GetPosition)
        ;
}
