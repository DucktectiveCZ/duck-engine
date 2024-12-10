#ifndef DUCK_ENGINE_CORE_SCENE_H
#define DUCK_ENGINE_CORE_SCENE_H

#include "core/gameObject.h"
#include <string>
#include <vector>
#include <memory>

namespace duck::engine::core {

class Scene : public IParentGameObject {
public:
  Scene();
  virtual ~Scene();

  static Scene loadFromFile(std::string path);

  void pushGameObject(std::shared_ptr<IGameObject> gameObject);
  void removeGameObject(std::shared_ptr<IGameObject> gameObject);
    
  void update() override;
  void render() override;
  
  std::string toString() const override;

  const std::vector<std::shared_ptr<IGameObject>>& getChildren() const override;
protected:
  std::vector<std::shared_ptr<IGameObject>> m_gameObjects;
};

}

#endif // DUCK_ENGINE_CORE_SCENE_H
