#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

namespace fs = std::filesystem;

/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

std::vector<SDL_Surface *> spriteSheets;

unsigned int lastTime = 0, currentTime;

/* Function measuring time of execution since last timestamp
   Included parameter should describe the first execution below*/
void ReportRecources(std::string since);

/* */
bool LoadSpriteSheets(std::string assetsDir);
bool CleanSpriteSheets(bool cleanAll = false);