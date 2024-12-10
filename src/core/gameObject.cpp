#include "core/gameObject.h"
#include "core/scene.h"
#include "exceptions/exception.h"
#include "exceptions/invalidArgumentException.h"
#include "exceptions/notImplementedException.h"
#include "exceptions/xmlParseException.h"
#include "graphics/types.h"
#include <algorithm>
#include <cstring>
#include <fmt/format.h>
#include <memory>
#include <spdlog/spdlog.h>
#include <sstream>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>
#include <vector>

duck::engine::core::BoxCollision::BoxCollision(duck::engine::graphics::Size x, duck::engine::graphics::Size y, duck::engine::graphics::Size width, duck::engine::graphics::Size height)
  : m_x(x), m_y(y), m_width(width), m_height(height) { }
duck::engine::core::BoxCollision::BoxCollision(const duck::engine::graphics::Rectangle& dimensions)
  : m_x(dimensions.getX()), m_y(dimensions.getY()), m_width(dimensions.getWidth()), m_height(dimensions.getHeight()) { }
duck::engine::core::BoxCollision::BoxCollision()
  : duck::engine::core::BoxCollision(0, 0, 0, 0) { }

void duck::engine::core::BoxCollision::render() { }
void duck::engine::core::BoxCollision::update() { }

std::string duck::engine::core::BoxCollision::toString() const {
  return fmt::format("BoxCollision(x: {}, y: {}, width: {}, height: {})", m_x, m_y, m_width, m_height);
}

void duck::engine::core::BoxCollision::setX(duck::engine::graphics::Size x) {
  m_x = x;
}
void duck::engine::core::BoxCollision::setY(duck::engine::graphics::Size y) {
  m_y = y;
}
void duck::engine::core::BoxCollision::setWidth(duck::engine::graphics::Size width) {
  m_width = width;
}
void duck::engine::core::BoxCollision::setHeight(duck::engine::graphics::Size height) {
  m_height = height;
}

duck::engine::graphics::Size duck::engine::core::BoxCollision::getX() const {
  return m_x;
}
duck::engine::graphics::Size duck::engine::core::BoxCollision::getY() const {
  return m_y;
}
duck::engine::graphics::Size duck::engine::core::BoxCollision::getWidth() const {
  return m_width;
}
duck::engine::graphics::Size duck::engine::core::BoxCollision::getHeight() const {
  return m_height;
}

duck::engine::core::Entity::Entity()
  : m_children() { }
duck::engine::core::Entity::~Entity()
{ }

void duck::engine::core::Entity::pushChild(std::shared_ptr<duck::engine::core::IGameObject> child) {
  this->m_children.push_back(child);
}

void duck::engine::core::Entity::removeChild(std::shared_ptr<duck::engine::core::IGameObject> child) {
  auto it = std::find(this->m_children.begin(), this->m_children.end(), child);
  if (it == this->m_children.end())
    throw exceptions::InvalidArgumentException("Child not found");
  this->m_children.erase(it);
}

void duck::engine::core::Entity::update() {
  for (auto child : this->m_children)
    child->update();
}

void duck::engine::core::Entity::render() {
  for (auto child : this->m_children)
    child->update();
}

std::string duck::engine::core::Entity::toString() const {
  std::stringstream ss;
  ss << "Entity [";
  for (auto child : this->getChildren())
    ss << " " << child->toString();
  ss << "]";
  return ss.str();
}

const std::vector<std::shared_ptr<duck::engine::core::IGameObject>>& duck::engine::core::Entity::getChildren() const {
  return m_children;
}

std::shared_ptr<duck::engine::core::IGameObject> duck::engine::core::GameObjectFactory::fromXmlElement(tinyxml2::XMLElement *element) {
  static std::unordered_map<std::string, GameObjectFactory::Factory> factories = {
    { STR_XMLELEMENT_ENTITY,       GameObjectFactory::fromEntityXmlElement },
    { STR_XMLELEMENT_BOXCOLLISION, GameObjectFactory::fromBoxCollissionXmlElement },
    { STR_XMLELEMENT_SPRITE,       GameObjectFactory::fromSpriteXmlElement },
    { STR_XMLELEMENT_SCENE,        GameObjectFactory::fromSceneXmlElement },
  };
  
  std::string name(element->Name());

  if (factories.find(name) == factories.end())
    throw exceptions::XmlParseException(fmt::format("Element doesn't exist: {}", name));
  auto object = factories[name](element);
  return object;
}

std::shared_ptr<duck::engine::core::IGameObject> duck::engine::core::GameObjectFactory::fromEntityXmlElement(tinyxml2::XMLElement *element) {
  spdlog::debug("Parsing entity");
  std::string elementName(element->Name());
  std::string expectedName(STR_XMLELEMENT_ENTITY);

  if (expectedName != expectedName)
    throw exceptions::InvalidArgumentException("The provided xml element is not an entity.");
  Entity entity;
  tinyxml2::XMLElement *childElement = element->FirstChildElement();
  while (childElement) {
    spdlog::debug("Creating an xml element from @{}", (void *)childElement);
    auto newChild = GameObjectFactory::fromXmlElement(childElement);
    spdlog::debug("Element created successfully, pushing child to the vector");
    entity.pushChild(newChild);
    spdlog::debug("Next child");
    childElement = childElement->NextSiblingElement();
  }
  return std::make_shared<Entity>(entity);
}

std::shared_ptr<duck::engine::core::IGameObject> duck::engine::core::GameObjectFactory::fromSceneXmlElement(tinyxml2::XMLElement *element) {
  spdlog::debug("Loading scene element");
  std::string elementName(element->Name());
  std::string expectedName(STR_XMLELEMENT_SCENE);

  if (elementName != expectedName) {
    throw exceptions::InvalidArgumentException(fmt::format("The provided xml element is not a scene: '{}'", elementName));
  }
  Scene scene;
  tinyxml2::XMLElement *childElement = element->FirstChildElement();
  while (childElement) {
    spdlog::debug("Parsing object @{} {}", (void *)childElement, childElement->Name());
    auto newGameObject = fromXmlElement(childElement);
    spdlog::debug("Element parsed");
    scene.pushGameObject(newGameObject);
    spdlog::debug("Pushing element");
    childElement = childElement->NextSiblingElement();
  }
  return std::make_shared<Scene>(scene);
}

std::shared_ptr<duck::engine::core::IGameObject> duck::engine::core::GameObjectFactory::fromBoxCollissionXmlElement(tinyxml2::XMLElement *element) {
  BoxCollision boxCollision;
  boxCollision.setWidth(std::stoll(h_getAttribute(element, "Width")));
  boxCollision.setHeight(std::stoll(h_getAttribute(element, "Height")));
  try {
    boxCollision.setX(std::stoll(h_getAttribute(element, "X")));
    boxCollision.setY(std::stoll(h_getAttribute(element, "Y")));
  } catch (exceptions::XmlParseException ex) { }
  catch (exceptions::Exception ex) {
    throw ex;
  }
  return std::make_shared<BoxCollision>(boxCollision);
}

std::shared_ptr<duck::engine::core::IGameObject> duck::engine::core::GameObjectFactory::fromSpriteXmlElement(tinyxml2::XMLElement *element) {
  throw exceptions::NotImplementedException();
}

std::string duck::engine::core::GameObjectFactory::h_fromAttributeXmlElement(const std::string& objectName, tinyxml2::XMLElement *element) {
  std::string elementName(element->Name());
  std::string expectedNamePrefix = std::string(objectName) + ".";
  
  if (!elementName.starts_with(expectedNamePrefix))
    throw exceptions::XmlParseException("Element is not an attribute");

  std::string attributeName = elementName.substr(expectedNamePrefix.length());
  const char *value = element->Attribute(attributeName.c_str());
  if (value == nullptr)
    throw exceptions::XmlParseException("Attribute has no value");
  return value;
}

std::string duck::engine::core::GameObjectFactory::h_getAttribute(tinyxml2::XMLElement *element, const std::string &attributeName) {
  tinyxml2::XMLElement *childElement = element->FirstChildElement();
  while (childElement) {
    if (attributeName == childElement->Name()) {
      const char *value = childElement->Attribute(attributeName.c_str());
      if (value != nullptr)
        return value;
      return h_fromAttributeXmlElement(element->Name(), childElement);
    }
    childElement = childElement->NextSiblingElement();
  }
  throw exceptions::InvalidArgumentException("The provided element is not an attribute");
}
