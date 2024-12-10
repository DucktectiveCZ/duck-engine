#include "core/core.h"
#include <string>
#include <sstream>

duck::engine::core::Object::Object() { }
duck::engine::core::Object::~Object() { }

duck::engine::core::IInterface::~IInterface() = default;

std::string duck::engine::core::Object::toString() const {
  std::stringstream ss;
  ss << "Object @";
  ss << (void*)this;
  return ss.str();
}

