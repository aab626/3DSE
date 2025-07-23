#include "modules/test_module.hpp"
#include "modules/module.hpp"

TestModule::TestModule(String& name, int a, String b)
: Module(name), testInt(a), testString(b) {

}

void TestModule::init() {}
void TestModule::update() {}
TestModule::~TestModule() {}