#ifndef DUCK_ENGINE_CORE_GAMEOBJECT_H
#define DUCK_ENGINE_CORE_GAMEOBJECT_H

#include "core/core.h"
#include "graphics/types.h"
#include <cstddef>
#include <functional>
#include <iterator>
#include <memory>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>
#include <vector>

#define STR_XMLELEMENT_SCENE        "Scene"
#define STR_XMLELEMENT_ENTITY       "Entity"
#define STR_XMLELEMENT_BOXCOLLISION "BoxCollision"
#define STR_XMLELEMENT_SPRITE       "Sprite"

namespace DUCK_ENGINE_CORE_NAMESPACE_NAME {

class IGameObject : public IInterface {
public:
  virtual ~IGameObject() = default;
  virtual void update() = 0;
  virtual void render() = 0;
};

class IParentGameObject : public IGameObject {
public:
  virtual ~IParentGameObject() = default;
  
  virtual const std::vector<std::shared_ptr<duck::engine::core::IGameObject>>& getChildren() const = 0;
};

class Entity : public IParentGameObject {
public:
  Entity();
  virtual ~Entity();
  
  void pushChild(std::shared_ptr<IGameObject> child);
  void removeChild(std::shared_ptr<IGameObject> child);

  const std::vector<std::shared_ptr<IGameObject>>& getChildren() const override;
  void update() override;
  void render() override;

  std::string toString() const override;
private:
  std::vector<std::shared_ptr<IGameObject>> m_children;
};
class IAttribute : public IGameObject { };

class ICollission : public IAttribute { };

class BoxCollision : public IAttribute {
public:
  BoxCollision(const graphics::Rectangle& rect);
  BoxCollision(graphics::Size x, graphics::Size y, graphics::Size width, graphics::Size height);
  BoxCollision();
  
  void setX(graphics::Size x);
  void setY(graphics::Size y);
  void setWidth(graphics::Size w);
  void setHeight(graphics::Size h);
  
  graphics::Size getX() const;
  graphics::Size getY() const;
  graphics::Size getWidth() const;
  graphics::Size getHeight() const;
  
  void render() override;
  void update() override;
  
  std::string toString() const override;
protected:
  graphics::Size m_x;
  graphics::Size m_y;
  graphics::Size m_width;
  graphics::Size m_height;
};

class GameObjectFactory {
public:
  using Factory = std::function<std::shared_ptr<IGameObject>(tinyxml2::XMLElement *)>;

  static std::shared_ptr<IGameObject> fromXmlElement(tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> fromEntityXmlElement(tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> fromSceneXmlElement(tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> fromBoxCollissionXmlElement(tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> fromSpriteXmlElement(tinyxml2::XMLElement *element);
  
  static std::string h_getAttribute(tinyxml2::XMLElement *element, const std::string& attributeName);
  static std::string h_fromAttributeXmlElement(const std::string& objectName, tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> h_throwUnknownElementException(tinyxml2::XMLElement *);
private:
  GameObjectFactory() = delete;
};

}

#endif // !DUCK_ENGINE_CORE_GAMEOBJECT_H
