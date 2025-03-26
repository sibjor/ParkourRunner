#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <stdio.h>
#include <time.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

/* std::filesystem i pretty young...
- implemented and standardized
- as late/early as in the
- C++17 standard
- ( first coined in the "Boost" C++..
- ..project/library/collection )
*/
namespace fs = std::filesystem;

/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
