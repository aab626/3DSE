#pragma once
#include "engine_common.hpp"
#include "modules/module.hpp"
#include <vector>


constexpr t_id ENGINE_START_ID = 0;

class Engine {
    // Fields
    private:
        t_id nextEntityId;
        std::vector<String> registeredModules;

    // Methods
    private:
        Engine();

    public:
        t_id GetNextId();
        void RegisterModule(Module* module);
    
    // Static Methods
    public:
        // Singleton constructor and instance retrieval method
        static Engine* instance;
        static Engine* GetInstance();

        static t_id maxInstanceId;
};
