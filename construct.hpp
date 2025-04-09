#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

#include "process.hpp"

#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

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

class SDLMainLoop
{

public:
    SDLMainLoop();
    ~SDLMainLoop();
    SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]);
    SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event);
    SDL_AppResult SDL_AppIterate(void *appstate);
    void SDL_AppQuit(void *appstate, SDL_AppResult result);

public:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

class Construct : public Process, public FileManager, public Profiler
{
public:
    Construct(const char *name_of_host, const char *name_of_self, const u_int *id);
    ~Construct();
    void InitializeSDL();
    void InititalizeProfiler();
    void InitializeFileSystem();
};