#ifndef DUCK_ENGINE_CORE_WINDOW_H
#define DUCK_ENGINE_CORE_WINDOW_H

#include "core/core.h"
#include <SDL_render.h>
#include <cstdint>
#include <string>

namespace DUCK_CORE_NAMESPACE_NAME {

class Window {
public:
    Window(std::string title, int x, int y, int width, int height, uint32_t flags);
    ~Window();

    void close();
    void show();
    void hide();
    void setVisibility(bool visibility);
    void setTitle(std::string title);
    void setSize(int width, int height);
    void setPosition(int x, int y);
    void setFullscreen(bool fullscreen);
    void setResizable(bool resizable);
    void setBorderless(bool borderless);
    void setOpacity(float opacity);

    template<typename SceneType>
    void setScene();
    
    SDL_Renderer* getSDLRenderer() const;
};

}

#endif // DUCK_ENGINE_CORE_WINDOW_H