#include "core/core.h"
#include <exception>
#include <string>

namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {

class Exception : public std::exception {
public:
    Exception(const std::string& message);
    virtual ~Exception() noexcept;
    const char* what() const noexcept;

    std::string getMessage() const;
    
};

}