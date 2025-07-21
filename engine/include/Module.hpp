#pragma once

#include <string>
#include <memory>

class Engine;
using ModulePtr = std::shared_ptr<Module>;

class Module {
    friend class Engine;

    private:
        Engine& engine;
        std::string moduleName;

    public:
        Module(Engine &engine, const std::string& moduleName);
        
        const std::string getName();
        virtual void update() = 0;
};
