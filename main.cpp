/*
  Copyright (C) 1997-2025 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely.
*/
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include "render.hpp"

Level *level;
Sprite *player;

void RenderWhiteBackground()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}


/* Here follows the main loop! */

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    /* Create the window and renderer */
    if (!SDL_CreateWindowAndRenderer(window_title, window_width, window_height, window_flags, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    level = new Level();
    player = new Sprite();

    player->SliceAllSpriteSheets();

    return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_KEY_DOWN ||
        event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_RenderClear(renderer);

    RenderWhiteBackground();
    level->RenderEntireObject(EnvironmentObject::Ground);
    


    SDL_RenderPresent(renderer);


    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    /* Free the window and renderer */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    /* Quit SDL */
    SDL_Quit();
}
