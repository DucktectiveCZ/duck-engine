#ifndef DUCK_ENGINE_CORE_CORE_H
#define DUCK_ENGINE_CORE_CORE_H

#define DUCK_NAMESPACE_NAME duck::engine
#define DUCK_ENGINE_CORE_NAMESPACE_NAME duck::engine::core
#define DUCK_GRAPHICS_NAMESPACE_NAME duck::engine::graphics
#define DUCK_MATH_NAMESPACE_NAME duck::engine::math
#define DUCK_PHYSICS_NAMESPACE_NAME duck::engine::physics
#define DUCK_UTILITY_NAMESPACE_NAME duck::engine::utility
#define DUCK_LOGGING_NAMESPACE_NAME duck::engine::logging
#define DUCK_EXCEPTIONS_NAMESPACE_NAME duck::engine::exceptions
#define DUCK_ENGINE_SERIALIZATION_NAMESPACE_NAME duck::engine::serialization
#define DUCK_ENGINE_IO_NAMESPACE_NAME duck::engine::io
#define DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME duck::engine::exceptions
#define DUCK_ENGINE_SCRIPTS_NAMESPACE_NAME duck::engine::scripts    
namespace DUCK_ENGINE_CORE_NAMESPACE_NAME {

class Object {
public:
    Object();
    virtual ~Object();
};

}

#endif // DUCK_ENGINE_CORE_CORE_H