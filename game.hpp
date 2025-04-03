#pragma once

#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "process.hpp"
class Game
{
public:
    Game();
    ~Game();

    void Init(const char* title, int width, int height);
    void HandleEvents();
    void Update();
    void Clean();

    bool Running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Game state variables
    int playerX, playerY;
    int playerWidth, playerHeight;
    int playerSpeed;
}