#ifndef DUCK_ENGINE_CORE_GAMEOBJECT_H
#define DUCK_ENGINE_CORE_GAMEOBJECT_H

#include "core/core.h"
#include "graphics/types.h"
#include <functional>
#include <memory>
#include <tinyxml2.h>

#define STR_XMLELEMENT_SCENE        "Scene"
#define STR_XMLELEMENT_ENTITY       "Entity"
#define STR_XMLELEMENT_BOXCOLLISION "BoxCollision"
#define STR_XMLELEMENT_SPRITE       "Sprite"

namespace DUCK_ENGINE_CORE_NAMESPACE_NAME {

class IGameObject : public IInterface {
public:
  virtual ~IGameObject();
  virtual void update() = 0;
  virtual void render() = 0;
};

class Entity : public IGameObject {
public:
  Entity();
  virtual ~Entity();
  
  void pushChild(std::shared_ptr<IGameObject> child);
  void removeChild(std::shared_ptr<IGameObject> child);

  void update() override;
  void render() override;
};
class IAttribute : public IGameObject { };

class ICollission : public IAttribute { };

class BoxCollission : public IAttribute {
public:
  BoxCollission(graphics::Rectangle rect);
  BoxCollission(graphics::Size x, graphics::Size y, graphics::Size w, graphics::Size h);
  BoxCollission();
};

class GameObjectFactory {
public:
  using Factory = std::function<std::shared_ptr<IGameObject>(tinyxml2::XMLElement *)>;
  static std::shared_ptr<IGameObject> fromXmlElement(tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> fromEntityXmlElement(tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> fromSceneXmlElement(tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> fromBoxCollissionXmlElement(tinyxml2::XMLElement *element);
  static std::shared_ptr<IGameObject> fromSpriteXmlElement(tinyxml2::XMLElement *element);
  
  static std::shared_ptr<IGameObject> h_throwSceneInsideSceneException(tinyxml2::XMLElement *);
  static std::shared_ptr<IGameObject> h_throwUnknownElementException(tinyxml2::XMLElement *);
private:
  GameObjectFactory() = delete;
};

}

#endif // !DUCK_ENGINE_CORE_GAMEOBJECT_H
