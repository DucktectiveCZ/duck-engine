#ifndef DUCK_ENGINE_EXCEPTIONS_INVALID_ACCESS_EXCEPTION_H
#define DUCK_ENGINE_EXCEPTIONS_INVALID_ACCESS_EXCEPTION_H

#include "core/core.h"
#include "exceptions/exception.h"

namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {

class InvalidAccessException : public Exception {
public:
    InvalidAccessException(const std::string& message);
    virtual ~InvalidAccessException() override;
};

}

#endif // DUCK_ENGINE_EXCEPTIONS_INVALID_ACCESS_EXCEPTION_H
