// TODO implement logger to terminal module
#include "modules/logger_module.hpp"
#include "modules/module.hpp"

String LoggerModule::moduleTypeName = String("LoggerModule");

LoggerModule::LoggerModule(String& moduleName)
: Module(moduleName, MODULE_TYPE_LOGGER) {}

LoggerModule::~LoggerModule() {}
void LoggerModule::init() {}
void LoggerModule::update() {}