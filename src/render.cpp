#include <iostream>
#include "render.h"

using namespace std;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

Render::Render(): window(nullptr), renderer(nullptr) {
    InitSDL();
    CreateWindow();
    CreateRenderer();
    SetupRenderer();
}

Render::~Render() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

bool Render::InitSDL() {
    if(SDL_Init( SDL_INIT_EVERYTHING) == -1) {
        cout << " Failed to initialize SDL: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

bool Render::CreateWindow() {
    window = SDL_CreateWindow("3D Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_MAXIMIZED);

    if(window == nullptr) {
        std::cout << "Failed to create window: " << SDL_GetError();
        return false;
    }

    return true;
}

bool Render::CreateRenderer() {
    renderer = SDL_CreateRenderer(window, -1, 0);

    if(renderer == nullptr) {
        std::cout << "Failed to create renderer: " << SDL_GetError();
        return false;
    }

    return true;
}

void Render::SetupRenderer() {
    SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_SetRenderDrawColor(renderer, 35, 40, 45, 255);
}
