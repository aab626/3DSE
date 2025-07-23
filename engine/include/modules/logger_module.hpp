#include "modules/module.hpp"
#include "engine_common.hpp"

// Module that logs information about its entity
class LoggerModule : public Module {
// Fields
// private:

// Constructors and Destructors
public:
    LoggerModule(String& name);
    ~LoggerModule() override;

    // Override methods
  public:
    void init() override;
    void update() override;
};
