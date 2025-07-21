#include "../../include/modules/TestModule.hpp"
#include <iostream>

TestModule::TestModule(Engine &e, const std::string &s) 
    : Module(e, s) {}

void TestModule::update() {
    std::cout << "Testmodule update!" << std::endl;
}