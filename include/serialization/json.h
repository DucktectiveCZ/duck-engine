#ifndef DUCK_ENGINE_SERIALIZATION_JSON_H
#define DUCK_ENGINE_SERIALIZATION_JSON_H

#include "core/core.h"
#include <map>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>

namespace DUCK_SERIALIZATION_NAMESPACE_NAME {

class Json final {
public:
    Json();
    ~Json();

    bool load_from_file(const std::string& filepath);
    bool save_to_file(const std::string& filepath);

    template<typename T>
    T get(const std::string& key);

    template<typename T>
    void set(const std::string& key, const T& value);

private:
    nlohmann::json data;
};

} 

#endif // DUCK_ENGINE_SERIALIZATION_JSON_H
