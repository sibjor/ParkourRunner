#pragma once

/* Central:
    - Acts as a "central" for common stuff
    - Such as dependencies
    - Variables
    - Functions
    - etc...
    */

// C++ Standard libraries
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

// C Standard libraries
#include <stdio.h>
#include <time.h>

// Third-party libraries
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

// Self defined headers
#include "profiler.hpp"
#include "artwork.hpp"
#include "gameloop.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

/* std::filesystem i pretty young...
- implemented and standardized
- as late/early as in the
- C++17 standard
- ( first coined in the "Boost" C++..
- ..project/library/collection )
*/
namespace fs = std::filesystem;

class Central
{
public:
    // Objects
    Profiler *profiler;
    Artwork *playerSprite;
    GameLoop *gameLoop;

    Central();
    ~Central();
    bool InitObjects();
    bool DestroyObjects();

private:

};