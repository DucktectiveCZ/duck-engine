#ifndef DUCK_ENGINE_SERIALIZATION_JSON_H
#define DUCK_ENGINE_SERIALIZATION_JSON_H

#include "core/core.h"
#include <string>
#include <nlohmann/json.hpp>

namespace DUCK_SERIALIZATION_NAMESPACE_NAME {

class Json final {
public:
    Json(std::string filepath);
    ~Json();

    void saveToFile(const std::string& filepath);

    template<typename T>
    T get(const std::string& key);

    template<typename T>
    void set(const std::string& key, const T& value);

private:
    nlohmann::json data;
};

} 

#endif // DUCK_ENGINE_SERIALIZATION_JSON_H
