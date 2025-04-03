#pragma once

#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "process.hpp"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

class Game
{
public:
    Game();
    ~Game();

    void Initialize(const char* title, int width, int height);
    void HandleEvents();
    void Update();
    void Clean();
    bool Running() { return isRunning; }

    void Draw();
    void LoadTexture(const char* path);
    void RenderTexture(SDL_Texture* texture, SDL_Rect dimension);
    void RenderText(const char* text, SDL_Rect dimension);

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Game state variables
    int playerX, playerY;
    int playerWidth, playerHeight;
    int playerSpeed;

    SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]);
    SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event);
    SDL_AppResult SDL_AppIterate(void *appstate);
    void SDL_AppQuit(void *appstate, SDL_AppResult result);
};