#include "logging/logging.h"
#include "core/core.h"
#include <spdlog/spdlog.h>

namespace DUCK_LOGGING_NAMESPACE_NAME {

void trace(const std::string& msg) {
    spdlog::trace(msg);
}
void debug(const std::string& msg) {
    spdlog::debug(msg);
}
void info(const std::string& msg) {
    spdlog::info(msg);
}
void warn(const std::string& msg) {
    spdlog::warn(msg);
}
void error(const std::string& msg) {
    spdlog::error(msg);
}
void critical(const std::string& msg) {
    spdlog::critical(msg);
}

template<typename... Args>
void trace(const std::string& fmt, Args&&... args) {
    spdlog::trace(fmt, args...);
}
template<typename... Args>
void debug(const std::string& fmt, Args&&... args);
template<typename... Args>
void info(const std::string& fmt, Args&&... args) {
    spdlog::info(fmt, args...);
}
template<typename... Args>
void warn(const std::string& fmt, Args&&... args);
template<typename... Args>
void error(const std::string& fmt, Args&&... args);
template<typename... Args>
void critical(const std::string& fmt, Args&&... args);

void setLevel(LoggingLevel level);

}