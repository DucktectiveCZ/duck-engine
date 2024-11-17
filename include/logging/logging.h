#ifndef DUCK_ENGINE_LOGGING_LOGGING_H
#define DUCK_ENGINE_LOGGING_LOGGING_H

#include "core/core.h"
#include <spdlog/common.h>
#include <string>

namespace DUCK_LOGGING_NAMESPACE_NAME {
    enum class LoggingLevel { trace= spdlog::level::level_enum::trace,
                              debug= spdlog::level::level_enum::debug,
                              info= spdlog::level::level_enum::info,
                              warn= spdlog::level::level_enum::warn,
                              error= spdlog::level::level_enum::err,
                              critical= spdlog::level::level_enum::critical,
                              off= spdlog::level::level_enum::off };
    
    void trace(const std::string& msg);
    void debug(const std::string& msg);
    void info(const std::string& msg);
    void warn(const std::string& msg);
    void error(const std::string& msg);
    void critical(const std::string& msg);

    template<typename... Args>
    static void trace(const std::string& fmt, Args&&... args);
    template<typename... Args>
    static void debug(const std::string& fmt, Args&&... args);
    template<typename... Args>
    static void info(const std::string& fmt, Args&&... args);
    template<typename... Args>
    static void warn(const std::string& fmt, Args&&... args);
    template<typename... Args>
    static void error(const std::string& fmt, Args&&... args);
    template<typename... Args>
    static void critical(const std::string& fmt, Args&&... args);

    void setLevel(LoggingLevel level);
}

#endif // DUCK_ENGINE_LOGGING_LOGGING_H