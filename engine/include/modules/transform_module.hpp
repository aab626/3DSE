#include "modules/module.hpp"
#include "engine_common.hpp"
#include <array>

class TransformModule : public Module {
// Fields
private:
    std::array<double, 3> position{};
    std::array<double, 3> rotation{};
    std::array<double, 3> scale{};

// Constructors and Destructors
public:
    TransformModule(String& moduleName);
    TransformModule(String &moduleName, double position[3], double rotation[3], double scale[3]);
    ~TransformModule() override;

// Override methods
public:
    void init() override;
    void update() override;
};
