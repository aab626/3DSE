#pragma once
#include "modules/module.hpp"
#include "engine_common.hpp"

// Module for testing implementation
class TestModule : public Module {
// Static fields
public:
    static String moduleTypeName;

// Fields
private:
    int testInt;
    String testString;

// Constructors and Destructors
public:
    // TestModule(String& name) = delete;
    ~TestModule() override;
    
    TestModule(String& name, int a, String b);

// Override methods
public:
    void init() override;
    void update() override;
};
