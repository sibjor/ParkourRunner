/*   

***DETAILS & CREDITS:***
{
    - Title: PR-2D-H; "Parkour Runner 2D Horizontal"
    - Dev: Sixten Algot Björling, student
    - Profile: "sibjor", github account
    - Page: https://github.com/sibjor
    - Site: Forsbergs School, Kingdom of Sweden
    - Date: March 2025
    - Issued by: Sebastian Jensen, lecturer
    
    *** EXTERNAL MATERIAL ***

        SDL, latest

            License: Zlib, permitted usage, modification and distribution
            Author: Sam Lantinga
            Profile: "libsdl-org", github account
            Links:  
                - https://libsdl.org
                - https://github.com/libsdl-org/SDL

        SDL_image; latest
            License: 
                Zlib, permitted usage, modification and distribution
            Author: 
                "slouken", github account
            Link: https://github.com/libsdl-org/SDL_image
        Assets/Artwork:
            License: Permitted distribution of compiled material
            Artist: "Kainshiro"
            Links: 
                User: https://itch.io/profile/kainshiro
                Artwork: 

                ! Hopefully, as of today, 
                ! reference to terms and rights 
                ! granted "Dev" are 
                ! linked below:

                    - https://kainshiro.itch.io/pixel-art-basic-parkoursurvival-movement-pack
                    - https://kainshiro.itch.io/basic-vault-animation-pack
    *** COMMENTS ***
        
        sibjor: 
            
            "I hope spending time with this concept continuing studying
            game programming techniques and technologies of use like SDL,
            changing player perspective in versions. Experiments with e.g. 
            algorithms, shaders, physics (?) in both or blend between
            2D & 3D. Interesting right?"

            "Flexible feel, smoothness & charming attitude"
        
                    
} */

#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */

#include "central.hpp"

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    // SDL initialization
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

    // Initialize objects
    InitObjects();
    if (!InitObjects())
    {
        SDL_Log("Couldn't initialize objects: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE; /* carry on with the program! */
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }
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
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Calling destructor of profiler
    // It will reset the timers
    // and free memory
    SDL_Quit();
}