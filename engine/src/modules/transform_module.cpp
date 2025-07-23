#include "modules/transform_module.hpp"
#include "modules/module.hpp"
#include <algorithm>

constexpr int SPATIAL_DIMENSIONS = 3;

TransformModule::TransformModule(String& moduleName)
: Module(moduleName), position{0.0, 0.0, 0.0}, rotation{0.0, 0.0, 0.0}, scale{0.0, 0.0, 0.0} {}

TransformModule::TransformModule(String &moduleName, double pos[3], double rot[3], double sca[3])
:   Module(moduleName), position{pos[0], pos[1], pos[2]}, rotation{rot[0], rot[1], rot[2]}, scale{sca[0], sca[1], sca[2]} {}

TransformModule::~TransformModule() {}

void TransformModule::init() {}
void TransformModule::update() {}

// TODO add move/rotate/etc operations
