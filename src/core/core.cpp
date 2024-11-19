#include "core/core.h"
#include <string>
#include <sstream>

std::string DUCK_ENGINE_CORE_NAMESPACE_NAME::Object::toString() const {
    std::stringstream ss;
    ss << (void*)this;
    return ss.str();
}