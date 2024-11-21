#ifndef DUCK_ENGINE_EXCEPTIONS_MEMORY_LEAK_EXCEPTION_H
#define DUCK_ENGINE_EXCEPTIONS_MEMORY_LEAK_EXCEPTION_H

#include "core/core.h"
#include "exceptions/memoryException.h"

namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {


class MemoryLeakException : public MemoryException {
public:
    MemoryLeakException(const std::string& message);
    virtual ~MemoryLeakException();
};

}

#endif // DUCK_ENGINE_EXCEPTIONS_MEMORY_LEAK_EXCEPTION_H
