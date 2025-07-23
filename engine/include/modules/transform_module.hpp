#pragma once
#include "modules/module.hpp"
#include "engine_common.hpp"
#include <array>

class TransformModule : public Module {
// Static fields
public:
    static String moduleTypeName;
    
// Fields
private:
    std::array<double, 3> position{};
    std::array<double, 3> rotation{};
    std::array<double, 3> scale{};

// Constructors and Destructors
public:
    TransformModule(String& moduleName);
    TransformModule(String &moduleName, const std::array<double, 3> &pos, const std::array<double, 3> &rot, const std::array<double, 3> &sca);
    ~TransformModule() override;

// Override methods
public:
    void init() override;
    void update() override;

// Methods
public:
    const std::array<double, 3>& GetPosition() const;
};
