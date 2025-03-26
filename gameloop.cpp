#include "gameloop.hpp"

/* Load all surfaces and textures
    - render them passing
    - SDL_AppContinue or success
    */
bool GameLoopInit(){
    if(!characterArtwork->LoadAndRenderAll()){
        SDL_Log("Couldn't load and render all: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    else{
        characterArtwork->LoadAndRenderAll();
    }
    return SDL_APP_CONTINUE;
}
/* This is maybe so far the
- most powerful function
- looping, rendering, drawing
- the texture and artworks
- no need to call while() 
- since were returning
- as stated below
*/
bool GameLoopActive(){
    if(!characterArtwork->RenderAll()){
        SDL_Log("Couldn't render all: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    else{
        characterArtwork->RenderAll();
    }
    return SDL_APP_CONTINUE;
}