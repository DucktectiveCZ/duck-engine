#ifndef DUCK_ENGINE_CORE_SCENE_H
#define DUCK_ENGINE_CORE_SCENE_H

#include "core/core.h"
#include <vector>
#include <memory>

namespace DUCK_ENGINE_CORE_NAMESPACE_NAME {

class IGameObject { };

class Scene : public IGameObject {
public:
    Scene();
    virtual ~Scene();

    void addGameObject(std::shared_ptr<IGameObject> gameObject);
    void removeGameObject(std::shared_ptr<IGameObject> gameObject);
    
    void update();
    void render();

protected:
    std::vector<std::shared_ptr<IGameObject>> m_gameObjects;
};

}

#endif // DUCK_ENGINE_CORE_SCENE_H
