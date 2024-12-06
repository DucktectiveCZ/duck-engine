#ifndef DUCK_ENGINE_EXCEPTIONS_INVALIDARGUMENTEXCEPTION_H
#define DUCK_ENGINE_EXCEPTIONS_INVALIDARGUMENTEXCEPTION_H

#include "core/core.h"
#include "exceptions/exception.h"
namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {
    
class InvalidArgumentException : public Exception {
public:
    InvalidArgumentException(const std::string& message);
};

}

#endif // DUCK_ENGINE_EXCEPTIONS_INVALIDARGUMENTEXCEPTION_H