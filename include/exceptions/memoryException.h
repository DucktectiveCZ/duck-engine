#ifndef DUCK_ENGINE_EXCEPTIONS_MEMORY_EXCEPTION_H
#define DUCK_ENGINE_EXCEPTIONS_MEMORY_EXCEPTION_H

#include "core/core.h"
#include "exceptions/exception.h"

namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {

class MemoryException : public Exception {
public:
    MemoryException(const std::string& message);
};

}

#endif // DUCK_ENGINE_EXCEPTIONS_MEMORY_EXCEPTION_H
