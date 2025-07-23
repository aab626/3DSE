#include "engine_common.hpp"

#include "engine.hpp"
#include "entity.hpp"
#include "modules/module.hpp"

#include "modules/test_module.hpp"

// #include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <iostream>


int main() {
    fmt::println("ENGINE TESTBED");

    // Engine
    Engine* engine = Engine::GetInstance();
    fmt::println("Engine: {0} | maxId: {1}", fmt::ptr(engine), Engine::maxInstanceId);

    // Module registration
    String tModuleName = "testModule";
    int tInt = 12;
    String tString = "asdf";
    TestModule* testModule = new TestModule(tModuleName, tInt, tString);
    testModule->RegisterModule();

    // Entity creation
    Entity* ent1 = new Entity();
    ent1->AddModule(testModule);

    Entity* ent2 = new Entity();
    ent2->AddModule(testModule);

    fmt::println("Engine id: {}", engine->GetNextId());

    return 0;
}