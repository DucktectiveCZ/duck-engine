#include "logging/logging.h"
#include "core/core.h"
#include <spdlog/spdlog.h>

namespace DUCK_LOGGING_NAMESPACE_NAME {

static void trace(const std::string& msg) {
    spdlog::trace(msg);
}
static void debug(const std::string& msg) {
    spdlog::debug(msg);
}
static void info(const std::string& msg) {
    spdlog::info(msg);
}
static void warn(const std::string& msg) {
    spdlog::warn(msg);
}
static void error(const std::string& msg) {
    spdlog::error(msg);
}
static void critical(const std::string& msg) {
    spdlog::critical(msg);
}

template<typename... Args>
static void trace(const std::string& fmt, Args&&... args) {
    spdlog::trace(fmt, args...);
}
template<typename... Args>
static void debug(const std::string& fmt, Args&&... args);
template<typename... Args>
static void info(const std::string& fmt, Args&&... args) {
    spdlog::info(fmt, args...);
}
template<typename... Args>
static void warn(const std::string& fmt, Args&&... args);
template<typename... Args>
static void error(const std::string& fmt, Args&&... args);
template<typename... Args>
static void critical(const std::string& fmt, Args&&... args);

void setLevel(LoggingLevel level);

}