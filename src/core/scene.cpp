#include "core/scene.h"
#include "core/gameObject.h"
#include "exceptions/invalidArgumentException.h"
#include <fmt/format.h>
#include <memory>
#include <spdlog/spdlog.h>
#include <sstream>
#include <string>
#include <tinyxml2.h>
#include <algorithm>
#include <vector>

duck::engine::core::Scene::Scene() = default;

duck::engine::core::Scene::~Scene() = default;

duck::engine::core::Scene duck::engine::core::Scene::loadFromFile(std::string path) {
  tinyxml2::XMLDocument doc;
  if (doc.LoadFile(path.c_str()) != tinyxml2::XML_SUCCESS)
      throw exceptions::InvalidArgumentException(fmt::format("Failed to load scene file '{}': {}", path, doc.ErrorName()));
  tinyxml2::XMLElement *element = doc.FirstChildElement();
  if (std::string(element->Name()) != STR_XMLELEMENT_SCENE)
    throw exceptions::InvalidArgumentException("The file is not a scene definition file");
  spdlog::debug("Loaded XML document, parsing");
  return *(Scene *)GameObjectFactory::fromSceneXmlElement(element).get();
}

void duck::engine::core::Scene::pushGameObject(std::shared_ptr<core::IGameObject> gameObject) {
    m_gameObjects.push_back(gameObject);
}

void duck::engine::core::Scene::removeGameObject(std::shared_ptr<duck::engine::core::IGameObject> gameObject) {
    auto it = std::find(m_gameObjects.begin(), m_gameObjects.end(), gameObject);
    if (it != m_gameObjects.end()) {
        m_gameObjects.erase(it);
    }
}

void duck::engine::core::Scene::update() {
  for (auto& gameObject : m_gameObjects) {
    gameObject->update();
  }
}

void duck::engine::core::Scene::render() {
  for (auto& gameObject : m_gameObjects) {
    gameObject->update();
  }
}

std::string duck::engine::core::Scene::toString() const {
  std::stringstream ss;
  ss << "Scene [";
  for (auto child : this->getChildren()) {
    ss << child->toString() << " ";
  }
  ss << "]";
  return ss.str();
}

const std::vector<std::shared_ptr<duck::engine::core::IGameObject>>& duck::engine::core::Scene::getChildren() const {
  return this->m_gameObjects;
}

