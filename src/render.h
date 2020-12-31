#ifndef INC_3D_VIEWER_TESTS_RENDER_H
#define INC_3D_VIEWER_TESTS_RENDER_H

#include <SDL2/SDL.h>
#include "object/object.h"

class Render {
public:
    Render();
    ~Render();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    static bool InitSDL();
    bool CreateWindow();
    bool CreateRenderer();
    void SetupRenderer();
};


#endif //INC_3D_VIEWER_TESTS_RENDER_H
