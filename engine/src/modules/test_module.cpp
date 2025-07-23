#include "modules/test_module.hpp"
#include "modules/module.hpp"
#include "engine_common.hpp"

String TestModule::moduleTypeName = String("TestModule");

TestModule::TestModule(String& name, int a, String b)
: Module(name, MODULE_TYPE_TEST), testInt(a), testString(b) {}

void TestModule::init() {}
void TestModule::update() {}
TestModule::~TestModule() {}