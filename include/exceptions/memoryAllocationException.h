#ifndef DUCK_ENGINE_EXCEPTIONS_MEMORY_ALLOCATION_EXCEPTION_H
#define DUCK_ENGINE_EXCEPTIONS_MEMORY_ALLOCATION_EXCEPTION_H

#include "core/core.h"
#include "exceptions/memoryException.h"

namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {

class MemoryAllocationException : public MemoryException {
public:
    MemoryAllocationException(const std::string& message);
};

}

#endif // DUCK_ENGINE_EXCEPTIONS_MEMORY_ALLOCATION_EXCEPTION_H
