#include "core/core.h"
#include "core/debug.h"
#include <string>
#include <sstream>

DUCK_ENGINE_CORE_NAMESPACE_NAME::Object::Object() { }

DUCK_ENGINE_CORE_NAMESPACE_NAME::Object::~Object() { }

std::string DUCK_ENGINE_CORE_NAMESPACE_NAME::Object::toString() const {
    std::stringstream ss;
    ss << (void*)this;
    return ss.str();
}

