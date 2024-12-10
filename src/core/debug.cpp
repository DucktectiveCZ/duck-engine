/*
#include "core/debug.h"
#include "exceptions/exceptions.h"
#include <spdlog/spdlog.h>

namespace DUCK_ENGINE_DEBUG_NAMESPACE_NAME {

std::size_t getCurrentlyAllocatedMemory() {
    return MemoryManager::getInstance().getCurrentlyAllocatedMemory();
}

MemoryManager::MemoryManager() 
    : m_allocatedMemory(0), m_deallocatedMemory(0) { }

MemoryManager::~MemoryManager() {
    if (m_allocatedMemory != m_deallocatedMemory) {
        spdlog::critical("Memory leak detected! Memory leak size: {}", m_allocatedMemory - m_deallocatedMemory);
        std::exit(1);
    }
}

void* MemoryManager::allocate(std::size_t size) {
    void* ptr = ::malloc(size);
    if (!ptr) {
        throw DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME::MemoryAllocationException("Failed to allocate memory");
    }
    m_allocatedMemory += size;
    m_memorySizes[ptr] = size;
    return ptr;
}

void MemoryManager::deallocate(void* ptr) {
    if (ptr) {
        auto it = m_memorySizes.find(ptr);
        if (it == m_memorySizes.end()) {
            spdlog::warn("Attempting to deallocate memory that was not allocated");
        }
        m_deallocatedMemory += it->second;
        m_memorySizes.erase(it);
        ::free(ptr);
    }
}

long MemoryManager::getAllocatedMemory() const {
    return m_allocatedMemory;
}

long MemoryManager::getCurrentlyAllocatedMemory() const {
    return m_allocatedMemory - m_deallocatedMemory;
}

long MemoryManager::getDeallocatedMemory() const {
    return m_deallocatedMemory;
}

std::size_t MemoryManager::getMemorySize(void* ptr) const {
    auto it = m_memorySizes.find(ptr);
    if (it != m_memorySizes.end()) {
        return it->second;
    }
    return 0;
}

const std::map<void*, std::size_t>& MemoryManager::getMemorySizes() const {
    return m_memorySizes;
}


MemoryManager& MemoryManager::getInstance() {
    static MemoryManager instance;
    return instance;
}

}

void* operator new(std::size_t size) {
    return DUCK_ENGINE_DEBUG_NAMESPACE_NAME::MemoryManager::getInstance().allocate(size);
}

void operator delete(void* ptr) noexcept {
    DUCK_ENGINE_DEBUG_NAMESPACE_NAME::MemoryManager::getInstance().deallocate(ptr);
}
*/
