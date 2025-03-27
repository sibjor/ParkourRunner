#pragma once

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
#include "character.hpp"
#include "gameloop.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

/* The profiler object*/
Profiler *profiler = new Profiler();
/* The characterArtwork object*/
CharacterArtwork *characterArtwork = new CharacterArtwork();
/* The GameLoop object*/
GameLoop *gameLoop = new GameLoop();

/* std::filesystem i pretty young...
- implemented and standardized
- as late/early as in the
- C++17 standard
- ( first coined in the "Boost" C++..
- ..project/library/collection )
*/
namespace fs = std::filesystem;
