#include <string>
#include "core/core.h"
#include "exceptions/exceptions.h"

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::Exception(const std::string& message)
    : std::exception(), m_message(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::~Exception() { }

const char* DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::what() const noexcept {
    return m_message.c_str();
}

std::string DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::toString() const {
    return m_message;
}
