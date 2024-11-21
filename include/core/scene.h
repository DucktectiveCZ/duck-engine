#ifndef DUCK_ENGINE_CORE_SCENE_H
#define DUCK_ENGINE_CORE_SCENE_H

#include "core/core.h"
#include <functional>
#include <vector>
#include <memory>

namespace DUCK_ENGINE_CORE_NAMESPACE_NAME {

struct EventArgs { };
struct EventResult { };
struct UpdateEventArgs : EventArgs   { };
struct UpdateResult    : EventResult { };
struct LoadEeventArgs  : EventArgs   { };
struct LoadResult      : EventResult { };
struct UnloadEventArgs : EventArgs   { };
struct UnloadResult    : EventResult { };

struct CollissionEventArgs : EventArgs { };
struct CollisionResult : EventResult { };

using EventHandler = std::function<EventResult(EventArgs)>;

class IGameObject { };

class Entity : IGameObject { };

class Scene : public IGameObject {
public:
    virtual ~Scene();

    static Scene loadFromFile(std::string path);

    void addGameObject(std::shared_ptr<IGameObject> gameObject);
    void removeGameObject(std::shared_ptr<IGameObject> gameObject);

    EventHandler onLoad;
    EventHandler onUnload;
    EventHandler onUpdate;
    
    void update();
    void render();

protected:
    std::vector<EventHandler> m_scripts;
    std::vector<std::shared_ptr<IGameObject>> m_gameObjects;
};

}

#endif // DUCK_ENGINE_CORE_SCENE_H
