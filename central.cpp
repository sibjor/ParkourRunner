#include "central.hpp"

bool InitObjects(){
    // Initialize the profiler
    profiler = new Profiler();
    if (!profiler)
    {
        SDL_Log("Couldn't initialize profiler: %s", SDL_GetError());
        return false;
    }

    // Initialize the character sprite
    playerSprite = new Artwork();


    // Initialize the game loop
    gameLoop = new GameLoop();

    return true;
}