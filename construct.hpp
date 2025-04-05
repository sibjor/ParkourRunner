#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

#include "process.hpp"

#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */

enum class Type
{

    MAIN_PROGRAM,
    CHILD_PROGRAM,
    PROFILER,
    FILESYSTEM,
    WINDOW,
    RENDERER,
    AUDIO,
    SHADER,

};

