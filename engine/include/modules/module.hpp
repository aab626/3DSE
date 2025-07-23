#pragma once
#include "engine_common.hpp"

class Module {
// Default constructors
public:
    Module() = delete;

// Fields
private:
    const String name;

// Virtual methods
public:
    virtual ~Module() = 0;
    
    virtual void init() = 0;
    virtual void update() = 0;

// Methods
protected:
    // Constructor should only be called from derived modules
    Module(String& name);
    
    public:
    // Getters
    const String& GetName() const;
    void RegisterModule();
};