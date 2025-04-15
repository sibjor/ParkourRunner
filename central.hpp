#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include "profiler.hpp"
#include "data.hpp"

/*

    Please use this file to implemenet as much
    logic as possible for rendering artwork
    moving or not, background or foreground
    DrawPlayer sprite or whatever

    Try to reuse logic through inheritance and
    polymorphism as much as possible
*/

extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern const char *window_title;
extern const int window_width;
extern const int window_height;
extern const int window_flags;

class DrawArtwork
{
public:
    DrawArtwork();
    ~DrawArtwork();
    void LoadAssets();

private:
    
    std::vector<std::unique_ptr<std::string*>> paths;
    std::vector<std::unique_ptr<SDL_Surface*>> surfaces;
    std::vector<std::unique_ptr<SDL_Texture*>> textures;
    std::vector<std::unique_ptr<SDL_FRect*>> rects;
};