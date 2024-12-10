/*
#ifndef DUCK_ENGINE_CORE_DEBUG_H
#define DUCK_ENGINE_CORE_DEBUG_H

#include "core/core.h"
#include <map>

namespace DUCK_ENGINE_DEBUG_NAMESPACE_NAME {

std::size_t getCurrentlyAllocatedMemory();

class MemoryManager : DUCK_ENGINE_CORE_NAMESPACE_NAME::Object {
public:
    MemoryManager();
    virtual ~MemoryManager();

    void* allocate(std::size_t size);
    void deallocate(void* ptr);

    long getAllocatedMemory() const;
    long getCurrentlyAllocatedMemory() const;
    long getDeallocatedMemory() const;
    std::size_t getMemorySize(void* ptr) const;
    const std::map<void*, std::size_t>& getMemorySizes() const;

    static MemoryManager& getInstance();
private:
    long m_allocatedMemory;
    long m_deallocatedMemory;
    std::map<void*, std::size_t> m_memorySizes;
};

}

void* operator new(std::size_t size);
void operator delete(void* ptr) noexcept;

#endif // DUCK_ENGINE_CORE_DEBUG_H
*/
