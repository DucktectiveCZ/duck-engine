#ifndef DUCK_ENGINE_EXCEPTIONS_EXCEPTION_H
#define DUCK_ENGINE_EXCEPTIONS_EXCEPTION_H

#include "core/core.h"
#include <boost/stacktrace/stacktrace.hpp>
#include <string>

namespace duck::engine::exceptions {

class Exception : public std::exception,
                  duck::engine::core::Object
{
public:
  Exception(const std::string& message);
  virtual ~Exception() noexcept;
  const char* what() const noexcept override;
  
  const std::string& getMessage() const;
  const boost::stacktrace::stacktrace& getStacktrace() const;

  std::string toString() const override;
protected:
  std::string m_message;
  boost::stacktrace::stacktrace m_stacktrace;
};

}

#endif // DUCK_ENGINE_EXCEPTIONS_EXCEPTION_H
