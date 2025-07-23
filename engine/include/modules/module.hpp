#pragma once
#include "engine_common.hpp"

// Module identifiers, each module type should have one unique module type identifier
enum ModuleType {
    MODULE_TYPE_BASE = 0, // Should not be used, safe to remove
    MODULE_TYPE_TEST,
    MODULE_TYPE_LOGGER,
    MODULE_TYPE_TRANSFORM
};

class Module {
// Instance fields
private:
    const String name;
    const ModuleType type;

// Virtual methods
public:
    virtual ~Module() = 0;
    virtual void init() = 0;
    virtual void update() = 0;

// Instance methods
protected:
    // Constructor should only be called from derived modules
    Module(String &name, ModuleType type);

public:
    Module() = delete;
    
    // Getters
    const String &GetName() const;
};