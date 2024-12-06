#include "core/scene.h"
#include "core/gameObject.h"
#include "exceptions/invalidArgumentException.h"
#include "exceptions/xmlParseException.h"
#include <memory>
#include <string>
#include <tinyxml2.h>
#include <algorithm>

namespace DUCK_ENGINE_CORE_NAMESPACE_NAME {

Scene::Scene() = default;

Scene::~Scene() = default;

Scene Scene::loadFromFile(std::string path) {
  tinyxml2::XMLDocument doc;
  if (doc.LoadFile(path.c_str()) != tinyxml2::XML_SUCCESS)
      throw exceptions::InvalidArgumentException("Failed to load scene file: " + path);
  tinyxml2::XMLElement *element = doc.FirstChildElement();
  if (std::string(element->Name()) != STR_XMLELEMENT_SCENE)
    throw exceptions::InvalidArgumentException("The file is not a scene definition file");
  return *(Scene *)GameObjectFactory::fromSceneXmlElement(element).get();
}

void Scene::pushGameObject(std::shared_ptr<IGameObject> gameObject) {
    m_gameObjects.push_back(gameObject);
}

void Scene::removeGameObject(std::shared_ptr<IGameObject> gameObject) {
    auto it = std::find(m_gameObjects.begin(), m_gameObjects.end(), gameObject);
    if (it != m_gameObjects.end()) {
        m_gameObjects.erase(it);
    }
}

void Scene::update() {
  for (auto& gameObject : m_gameObjects) {
    gameObject->update();
  }
}

void Scene::render() {
  for (auto& gameObject : m_gameObjects) {
    gameObject->update();
  }
}

}
