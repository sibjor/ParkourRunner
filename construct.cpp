#include "construct.hpp"

void SDLMainLoop::InitializeSDL()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init(SDL_INIT_VIDEO) failed: %s\n", SDL_GetError());
        return(2);
    }
}