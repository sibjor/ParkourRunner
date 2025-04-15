#define SDL_MAIN_USE_CALLBACKS 1 /* Use the callbacks instead of main() */

#include "render.hpp" // Include the AnimatedSprite class

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

const char *appName = "Validator 13";
AnimatedSprite *animatedSprite;                                  // Global instance of AnimatedSprite
AnimationState currentAnimationState = AnimationState::Idle;     // Default animation state
AnimationDirection currentDirection = AnimationDirection::Right; // Default direction
EnvironmentNavigated *environmentNavigated;                          // Global instance of EnvironmentNavigated
// Animation frame delay in milliseconds
static int frameDelay = 70;

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{

    /* Create the window and renderer */
    if (!SDL_CreateWindowAndRenderer(appName, 800, 600, SDL_EVENT_WINDOW_SHOWN, &window, &renderer))
    {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    // Init objects
    environmentNavigated = new EnvironmentNavigated(); // Skapa en instans av EnvironmentNavigated
    animatedSprite = new AnimatedSprite();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS; // Stäng programmet när kryssrutan klickas
    }

    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        SDL_Keycode key = event->key.key;

        if (key == SDLK_ESCAPE)
        {
            return SDL_APP_SUCCESS; // Stäng programmet när Escape trycks
        }
        else if (key == SDLK_SPACE)
        {
            currentAnimationState = AnimationState::Jumping;
            animatedSprite->PlayAnimation(currentAnimationState, true, renderer, false, frameDelay);
        }
        else if (key == SDLK_RIGHT || key == SDLK_D)
        {
            currentDirection = AnimationDirection::Right;
            animatedSprite->SetDirection(currentDirection);
            currentAnimationState = AnimationState::Run;
            
        }
        else if (key == SDLK_LEFT || key == SDLK_A)
        {
            currentDirection = AnimationDirection::Left;
            animatedSprite->SetDirection(currentDirection);
            currentAnimationState = AnimationState::Run;
            
        }
        else
        {
            currentAnimationState = AnimationState::Idle;
            
        }
    }

    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{

    /* Clear the screen */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    environmentNavigated->DisplayTextures(renderer, EnvironmentObject::Ground);     // Display environment artwork
    environmentNavigated->DisplayTextures(renderer, EnvironmentObject::Obstacle_Vault); // Display environment artwork
    /* Play the current animation */
    animatedSprite->PlayAnimation(currentAnimationState, true, renderer, false, frameDelay);

    /* Present the rendered frame */
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    delete animatedSprite; // Clean up the animated sprite
}