#include "core/gameObject.h"
#include "core/scene.h"
#include "exceptions/invalidArgumentException.h"
#include <fmt/format.h>
#include <memory>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>

std::shared_ptr<duck::engine::core::IGameObject> duck::engine::core::GameObjectFactory::fromXmlElement(tinyxml2::XMLElement *element) {
  static std::unordered_map<std::string, GameObjectFactory::Factory> factories = {
    { STR_XMLELEMENT_ENTITY,       GameObjectFactory::fromEntityXmlElement },
    { STR_XMLELEMENT_BOXCOLLISION, GameObjectFactory::fromBoxCollissionXmlElement },
    { STR_XMLELEMENT_SPRITE,       GameObjectFactory::fromSpriteXmlElement },
    { STR_XMLELEMENT_SCENE,        GameObjectFactory::fromSceneXmlElement },
  };
  
  std::string name = element->Name();
  auto object = factories[name](element);
  return object;
}

std::shared_ptr<duck::engine::core::IGameObject> duck::engine::core::GameObjectFactory::fromEntityXmlElement(tinyxml2::XMLElement *element) {
  if (std::string(element->Name()) == STR_XMLELEMENT_ENTITY)
    throw exceptions::InvalidArgumentException("The provided xml element is not an entity.");
  Entity entity;
  tinyxml2::XMLElement *childElement = element->FirstChildElement();
  while (childElement) {
    auto newChild = GameObjectFactory::fromXmlElement(childElement);
    entity.pushChild(newChild);
    childElement = childElement->NextSiblingElement();
  }
  return std::make_shared<IGameObject>(entity);
}

std::shared_ptr<duck::engine::core::IGameObject> duck::engine::core::GameObjectFactory::fromSceneXmlElement(tinyxml2::XMLElement *element) {
  if (std::string(element->Name()) == STR_XMLELEMENT_SCENE)
    throw exceptions::InvalidArgumentException("The provided xml element is not a scene.");
  Scene scene;
  tinyxml2::XMLElement *childElement = element->FirstChildElement();
  while (childElement) {
    auto newGameObject = fromXmlElement(childElement);
    scene.pushGameObject(newGameObject);
    childElement = childElement->NextSiblingElement();
  }
  return std::make_shared<IGameObject>(scene);
}

