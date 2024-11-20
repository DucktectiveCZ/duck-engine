#include "core/core.h"
#include <exception>
#include <string>

namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {

class Exception : public std::exception,
                  DUCK_ENGINE_CORE_NAMESPACE_NAME::Object
{
public:
    Exception(const std::string& message);
    virtual ~Exception() noexcept;
    const char* what() const noexcept;
    
    std::string getMessage() const;

    std::string toString() const override;
protected:
    std::string m_message;
};

class InvalidAccessException : public Exception {
public:
    InvalidAccessException(const std::string& message);
    virtual ~InvalidAccessException() override;
};

}