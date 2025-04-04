#pragma once

#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

#include "process.hpp"
#include "profiler.hpp"
#include "time.hpp"
#include "data.hpp"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

const std::string data_path = "data/";
const std::string assets_path = "assets/";

class Program : Process
{
    public:
        Program();
        ~Program();

        
    private:

    
};