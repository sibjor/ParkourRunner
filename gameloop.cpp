#include "gameloop.hpp"

/* Constructor
    - should not define flags (?)
    - as e.g. SDL_AppFailure
    - since they are included
    - in defenition stated
    - in adjacent source file
*/
GameLoop::GameLoop()
{
    std::cout << "Game Loop Initialized" << std::endl;
}
/* Destructor
    - should not define flags (?)
    - as e.g. SDL_AppFailure
    - since they are included
    - in defenition stated
    - in adjacent source file
*/
GameLoop::~GameLoop()
{
    // Free memory
    free(this);
}
/*  GameLoopInit()
    - load all surfaces and textures
    - render them passing
    - SDL_AppContinue or success
    */
