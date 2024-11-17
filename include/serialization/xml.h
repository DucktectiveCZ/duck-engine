#ifndef DUCK_ENGINE_SERIALIZATION_XML_H
#define DUCK_ENGINE_SERIALIZATION_XML_H

#include "core/core.h"
#include <string>
#include <tinyxml2.h>

namespace DUCK_SERIALIZATION_NAMESPACE_NAME {

class XmlDocument final {
public:
    XmlDocument() = default;
    ~XmlDocument() = default;

    bool LoadFromFile(const std::string& filename);
    bool LoadFromString(const std::string& content);
    bool SaveToFile(const std::string& filename) const;
    std::string ToString() const;

    tinyxml2::XMLNode* GetRootNode() const;
    void SetRootNode(tinyxml2::XMLNode* node);

    tinyxml2::XMLNode* CreateNode(const std::string& name);
    void DeleteNode(tinyxml2::XMLNode* node);

private:
    tinyxml2::XMLNode* m_RootNode;
};

}

#endif // DUCK_ENGINE_SERIALIZATION_XML_H