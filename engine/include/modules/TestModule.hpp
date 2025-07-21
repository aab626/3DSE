#pragma once
#include "../Module.hpp"

class TestModule: public Module {
    public:
        TestModule(Engine &engine, const std::string &moduleName);
        void update() override;
};
