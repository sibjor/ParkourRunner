#define SDL_MAIN_USE_CALLBACKS 1  /* Use the callbacks instead of main() */

#include "render.hpp"  // Include the AnimatedSprite class

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;


const char* appName = "Validator 13";
AnimatedSprite* animatedSprite;  // Global instance of AnimatedSprite

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    /* Create the window and renderer */
    if (!SDL_CreateWindowAndRenderer(appName, 800, 600, SDL_WINDOW_FULLSCREEN, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    /* Initialize the animated sprite 
    - will call the LoadTextures() function*/
    animatedSprite = new AnimatedSprite();

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
    SDL_FRect destRect = {100.0f, 100.0f, 64.0f, 64.0f};  // Position and size of the animation

    /* Clear the screen */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /* Play the Idle animation */
    animatedSprite->PlayAnimation(AnimationState::Idle, &destRect);

    /* Present the rendered frame */
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    delete animatedSprite;  // Clean up the animated sprite
}