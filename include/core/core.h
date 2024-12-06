#ifndef DUCK_ENGINE_CORE_CORE_H
#define DUCK_ENGINE_CORE_CORE_H

#include <string>
#define DUCK_ENGINE_NAMESPACE_NAME duck::engine

#define DUCK_ENGINE_CORE_NAMESPACE_NAME       DUCK_ENGINE_NAMESPACE_NAME::core
#define DUCK_ENGINE_GRAPHICS_NAMESPACE_NAME   DUCK_ENGINE_NAMESPACE_NAME::graphics
#define DUCK_ENGINE_PHYSICS_NAMESPACE_NAME    DUCK_ENGINE_NAMESPACE_NAME::physics
#define DUCK_ENGINE_UTILITY_NAMESPACE_NAME    DUCK_ENGINE_NAMESPACE_NAME::utility
#define DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME DUCK_ENGINE_NAMESPACE_NAME::exceptions
#define DUCK_ENGINE_DEBUG_NAMESPACE_NAME      DUCK_ENGINE_NAMESPACE_NAME::debug
#define DUCK_ENGINE_SCRIPTS_NAMESPACE_NAME    DUCK_ENGINE_NAMESPACE_NAME::scripts

namespace DUCK_ENGINE_CORE_NAMESPACE_NAME {

class Object {
public: 
    Object();
    virtual ~Object();

    virtual std::string toString() const;
};

class IInterface {
public:
  virtual ~IInterface();

  virtual std::string toString() const;
};

}

#endif // DUCK_ENGINE_CORE_CORE_H
