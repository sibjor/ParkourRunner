#include "character.hpp"
#include "profiler.hpp"

/* This file aims to wraps up the aspects of the game,
    - targeting SDL_AppIterate and SDL_AppEvent,
    - delivering readability and a clean machine
    */

/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
extern SDL_Renderer *renderer = NULL;

/* The characterArtwork object*/
CharacterArtwork *characterArtwork = new CharacterArtwork();
/* The profiler object*/
Profiler *profiler = new Profiler();

class GameLoop{
    public:
    /* Constructor
        - not declaring flags (?)
        - as e.g. SDL_AppFailure
        - since they are included
        - in defenition stated
        - in adjacent source file
        */
    bool GameLoop::Gameloop(){
        if(!GameLoopInit()){
            SDL_Log("Couldn't initialize the game loop: %s", SDL_GetError());
        }
        else{
            GameLoopInit();
        }
    };
    /* Destructor*/
    ~GameLoop(){
        // Free memory
        free(this);
    };
    /* Clean practices */
    bool GameLoopInit();
    bool GameLoopActive();

    private:
};