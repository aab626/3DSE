#include "modules/transform_module.hpp"
#include "modules/module.hpp"
#include <algorithm>
#include <array>

constexpr int SPATIAL_DIMENSIONS = 3;
String TransformModule::moduleTypeName = String("TransformModule");

TransformModule::TransformModule(String& moduleName)
: Module(moduleName, MODULE_TYPE_TRANSFORM), 
  position{0.0, 0.0, 0.0}, rotation{0.0, 0.0, 0.0}, scale{0.0, 0.0, 0.0} {}

TransformModule::TransformModule(
    String &moduleName,
    const std::array<double, 3> &pos, const std::array<double, 3> &rot, const std::array<double, 3> &sca)
    : Module(moduleName, MODULE_TYPE_TRANSFORM), 
      position{pos[0], pos[1], pos[2]},
      rotation{rot[0], rot[1], rot[2]}, 
      scale{sca[0], sca[1], sca[2]} {}

TransformModule::~TransformModule() {}

void TransformModule::init() {}
void TransformModule::update() {}

// Getters
const std::array<double, 3>& TransformModule::GetPosition() const {
  return position;
}

// TODO add move/rotate/etc operations
