#include "exceptions/exceptions.h"
#include "core/core.h"
#include "exceptions/exception.h"
#include <boost/stacktrace/stacktrace.hpp>
#include <string>

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::Exception(const std::string& message)
  : std::exception(), m_message(message), m_stacktrace(boost::stacktrace::stacktrace()) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::~Exception() noexcept { }

const char* DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::what() const noexcept {
  return m_message.c_str();
}

const std::string& DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::getMessage() const {
  return m_message;
}

const boost::stacktrace::stacktrace& DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::getStacktrace() const {
  return m_stacktrace;
}

std::string DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception::toString() const {
  return getMessage();
}

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::InvalidArgumentException::InvalidArgumentException(const std::string& message)
  : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::InvalidAccessException::InvalidAccessException(const std::string& message)
  : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::XmlParseException::XmlParseException(const std::string& message)
  : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::MemoryException::MemoryException(const std::string& message)
  : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::MemoryLeakException::MemoryLeakException(const std::string& message)
  : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::MemoryException(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::MemoryAllocationException::MemoryAllocationException(const std::string& message)
  : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::MemoryException(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::NotImplementedException::NotImplementedException(const std::string& message)
  : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::Exception(message) { }

DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::NotImplementedException::NotImplementedException()
  : DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::NotImplementedException("Feature not implemented") { }
