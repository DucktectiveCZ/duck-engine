#include "exceptions/exceptions.h"
#include "core/core.h"
#include <string>

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::Exception(const std::string& message)
    : std::exception(), m_message(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::~Exception() { }

const char* DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::what() const noexcept {
    return m_message.c_str();
}

const std::string& DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::getMessage() const {
    return m_message;
}

std::string DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::toString() const {
    return getMessage();
}

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::InvalidAccessException::InvalidAccessException(const std::string& message)
    : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::InvalidAccessException::~InvalidAccessException() { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::XmlParseException::XmlParseException(const std::string& message)
    : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::XmlParseException::~XmlParseException() { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::MemoryLeakException::MemoryLeakException(const std::string& message)
    : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::MemoryLeakException::~MemoryLeakException() { }
