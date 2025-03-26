#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <stdio.h>
#include <time.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

/* std::filesystem i pretty young...
- implemented and standardized
- as late/early as in the
- C++17 standard
- ( first coined in the "Boost" C++..
- ..project/library/collection )
*/
namespace fs = std::filesystem;

/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

/* First step is to declare a vector, which
        - will store SDL_Surface pointers, which
        - will be loaded as SDL_Texture pointers
        - then call SDL_RenderTexture(renderer, texture, NULL, NULL)
        - then SDL_RenderPresent(renderer)
        - don't forget: art is of dimensions: 192x96 (pixels?)
        - you were told to implement similar dimensions of w & h
        - cited from teacher, referring to the practice of a GPU
        */




/* Class CharacterArtwork:
- Separation of concerns are implemented
- having listened to citations of speech performance
- by speaker, stating a function should be as small
- as possible, preferrably responsible for one single
- sequence of executed task of demand or interest
*/
class CharacterArtwork{

    public:
    /* The constructor should be held
    - responsible of initialization
    - of one or both sprite sheets
    - of player character artwork
    - used in the game
    */
    CharacterArtwork();
    
    /* The destructor is responsible for
    - cleanup of player character artwork
    - of the game.
    */
    ~CharacterArtwork();
    void LoadMovementPack(std::string SpriteSheetDirectory);
    void LoadVaultPack(std::string SpriteSheetDirectory);
    void LoadAllSpriteSheets();
    
    private:
    // Movement pack
    std::vector<SDL_Surface *> surfacesMovementPack;
    std::vector<SDL_Texture *> texturesMovementPack;
    // Vault pack
    std::vector<SDL_Surface *> surfacesVaultPack;
    std::vector<SDL_Texture *> texturesVaultPack;
    // Movement & Vault pack together
    std::vector<SDL_Surface *> surfacesAllSpriteSheets;
    std::vector<SDL_Texture *> texturesAllSpriteSheets;

};

/* class Profiler:
- Measuring time between timestamps
- from head to tail
- implementing both contructor of both timers
- and the respective destructor, as well for both timers
*/
class Profiler
{

public:
    Profiler();
    ~Profiler();

    
    /* From head to tail, measuring time between parties defined below*/
    void ProfilerSDLBegin(std::string sequence);
    void ProfilerSDLEnd();
    void ResetSDLTimer();
    void ProfilerCBegin(std::string sequence);
    void ProfilerCEnd();
    void ResetCTimer();


private:
    /* The C timer measuring parties*/
    clock_t headCTimer;
    clock_t tailCTimer;
    unsigned int differenceBetweenCTimers;

    /* The SDL timer measuring parties*/
    unsigned int beginSDLTimer;
    unsigned int tailSDLTimer;
    unsigned int differenceBetweenSDLTimers;
};