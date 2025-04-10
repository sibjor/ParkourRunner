#define SDL_MAIN_USE_CALLBACKS 1 /* Use the callbacks instead of main() */

#include "render.hpp" // Include the AnimatedSprite class

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

const char *appName = "Validator 13";
AnimatedSprite *animatedSprite;                              // Global instance of AnimatedSprite
AnimationState currentAnimationState = AnimationState::Idle; // Default animation state
AnimationDirection currentDirection = AnimationDirection::Right; // Default direction
// Animation frame delay in milliseconds
static int frameDelay = 70;

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{

    /* Create the window and renderer */
    if (!SDL_CreateWindowAndRenderer(appName, 800, 600, SDL_WINDOW_FULLSCREEN, &window, &renderer))
    {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    /* Initialize the animated sprite
    - will call the LoadTextures() function*/
    animatedSprite = new AnimatedSprite();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    SDL_Keycode key = event->key.key;
    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        if (key == SDLK_ESCAPE)
        {
            return SDL_APP_SUCCESS; /* End the program, reporting success to the OS. */
        }
        else if (key == SDLK_SPACE)
        {
            // Play Jumping animation when spacebar is pressed
            if (currentDirection == AnimationDirection::Right)
                animatedSprite->PlayAnimation(AnimationState::Jumping, nullptr, false, false, frameDelay);
            else if (currentDirection == AnimationDirection::Left)
                animatedSprite->PlayAnimation(AnimationState::Jumping, nullptr, false, true, frameDelay);
        }
        else if (key == SDLK_RIGHT || key == SDLK_D)
        {
            currentDirection = AnimationDirection::Right; // Update currentDirection
            animatedSprite->SetDirection(currentDirection); // Update AnimatedSprite's direction
            currentAnimationState = AnimationState::Run;
            animatedSprite->PlayAnimation(currentAnimationState, nullptr, true, false, frameDelay);
        }
        else if (key == SDLK_LEFT || key == SDLK_A)
        {
            currentDirection = AnimationDirection::Left; // Update currentDirection
            animatedSprite->SetDirection(currentDirection); // Update AnimatedSprite's direction
            currentAnimationState = AnimationState::Run;
            animatedSprite->PlayAnimation(currentAnimationState, nullptr, true, true, frameDelay);
        }
        else
        {
            // Handle other key presses (optional)
            currentAnimationState = AnimationState::Idle; // Reset to Idle state
            animatedSprite->PlayAnimation(currentAnimationState, nullptr, true, false, frameDelay);
        }
    }

    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_FRect destRect = {300.0f, 300.0f, 128.0f, 128.0f}; // Position and size of the animation

    /* Clear the screen */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /* Play the current animation */
    animatedSprite->PlayAnimation(currentAnimationState, &destRect, true, false, frameDelay);

    /* Present the rendered frame */
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    delete animatedSprite; // Clean up the animated sprite
}