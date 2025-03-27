#pragma once

#include "character.hpp"
#include "profiler.hpp"
#include "central.hpp"

/* This file aims to wraps up the aspects of the game,
    - targeting SDL_AppIterate and SDL_AppEvent,
    - delivering readability and a clean machine
    */


class GameLoop
{
public:
    /* Constructor*/
    GameLoop();
    /* Destructor*/
    ~GameLoop();

    bool GameLoopInit();
    bool GameLoopActive();

private:
};