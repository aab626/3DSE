#pragma once
#include "engine_common.hpp"

class Module {
    // Virtual methods
    public:
        virtual ~Module() = 0;

    // Fields
    private:
        const String name;

    // Methods
    protected:
        static void RegisterModule(Module* module);

    public:
        Module() = delete;
        Module(String& name);

        // Getters
        const String& GetName() const;
};