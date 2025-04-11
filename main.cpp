#define SDL_MAIN_USE_CALLBACKS 1 /* Use the callbacks instead of main() */

#include "render.hpp" // Include the AnimatedSprite class

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

const char *appName = "Validator 13";
AnimatedSprite *animatedSprite;                              // Global instance of AnimatedSprite
AnimationState currentAnimationState = AnimationState::Idle; // Default animation state

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
    animatedSprite->SetFrameDelay(50); // Set the frame delay for animations

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
            
            animatedSprite->SetFrameDelay(50); // Faster animation
            currentAnimationState = AnimationState::Jumping;
        }
        else if (key == SDLK_RIGHT || key == SDLK_D)
        {
            // Play Running animation when right arrow or 'D' key is pressed
            animatedSprite->SetDirection(AnimationDirection::Right); // Set direction to right
            animatedSprite->SetFrameDelay(100); // Normal speed
            currentAnimationState = AnimationState::Run;
        }
        else if (key == SDLK_LEFT || key == SDLK_A){
            animatedSprite->SetDirection(AnimationDirection::Left); // Set direction to left
            animatedSprite->SetFrameDelay(100); // Normal speed
            currentAnimationState = AnimationState::Run;
        }
        else
        {
            // Handle other key presses (optional)
            animatedSprite->SetFrameDelay(50);            // Reset to default delay
            currentAnimationState = AnimationState::Idle; // Reset to Idle state
        }
    }

    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_FRect destRect = {500.0f, 800.0f, 256.0f, 256.0f}; // Position and size of the animation

    /* Clear the screen */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /* Play the Idle animation */
    animatedSprite->PlayAnimation(currentAnimationState, &destRect);

    /* Present the rendered frame */
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    delete animatedSprite; // Clean up the animated sprite
}