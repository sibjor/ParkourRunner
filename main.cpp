/*
 * This example code reads frames from a camera and draws it to the screen.
 *
 * This is a very simple approach that is often Good Enough. You can get
 * fancier with this: multiple cameras, front/back facing cameras on phones,
 * color spaces, choosing formats and framerates...this just requests
 * _anything_ and goes with what it is handed.
 *
 * This code is public domain. Feel free to use it for any purpose!
 */

#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */

#include "central.hpp"
#include "character.hpp"
#include "profiler.hpp"
#include "gameloop.hpp"

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    profiler->ProfilerHeadBoth("Inside SDL_AppInit, ");

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("sibjor@github.com", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    if(!characterArtwork)
    {
        SDL_Log("Couldn't create characterArtwork: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    profiler->ProfilerResetBoth("Leaving SDL_AppInit, ");
    return SDL_APP_CONTINUE; /* carry on with the program! */
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    profiler->ProfilerHeadBoth("Inside SDL_AppEvent, ");
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }
    profiler->ProfilerResetBoth("Leaving SDL_AppEvent, ");
    return SDL_APP_CONTINUE; /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program.
    - Profiler should only be nested inside of scope, to avoid spamming */
SDL_AppResult SDL_AppIterate(void *appstate)
{

    return SDL_APP_CONTINUE; /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{   
    profiler->ProfilerHeadBoth("Inside SDL_AppQuit, ");
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Calling destructor of profiler
    // It will reset the timers
    // and free memory
    profiler->~Profiler();
    SDL_Quit();
}
