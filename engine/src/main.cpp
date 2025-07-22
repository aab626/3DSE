#include "engine_common.hpp"

#include "engine.hpp"
#include "entity.hpp"

// #include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <iostream>


int main() {
    fmt::println("ENGINE TESTBED");
    Engine* engine = Engine::GetInstance();

    fmt::println("Engine: {0} | maxId: {1}", fmt::ptr(engine), Engine::maxInstanceId);

    Entity* ent1 = new Entity();
    try {
        ent1->RemoveModule(String("cat"));
    } catch (const std::exception& e) {
        fmt::print(fmt::emphasis::bold | fg(fmt::color::red), "Error: {}\n", e.what());
    }

    return 0;
}