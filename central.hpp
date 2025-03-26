#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

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

unsigned int lastTime = 0, currentTime;

/* Function measuring time of execution since last timestamp
   Included parameter should describe the first execution below*/
void SDLProfiler(std::string context);

/* First step is to declare a vector, which
        - will store SDL_Surface pointers, which
        - will be loaded as SDL_Texture pointers
        - then call SDL_RenderTexture(renderer, texture, NULL, NULL)
        - then SDL_RenderPresent(renderer)
        - don't forget: art is of dimensions: 192x96 (pixels?)
        - you were told to implement similar dimensions of w & h
        - cited from teacher, referring to the practice of a GPU
        */
bool LoadSpriteSheets(std::string assetsDir);
void Idle();
bool CleanSurfaces(bool cleanAll = false, std::vector<SDL_Surface *> spriteSheets);
bool CleanTextures(bool cleanAll = false, std::vector<SDL_Texture *> spriteTextures);