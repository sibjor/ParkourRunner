#pragma once

#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

static SDL_Window *window;
static SDL_Renderer *renderer;

std::vector<std::string> assets = {
    "assets/Basic movement pack/SpriteSheet/Idle.png",
    "assets/Basic movement pack/SpriteSheet/in air.png",
    "assets/Basic movement pack/SpriteSheet/junping.png",
    "assets/Basic movement pack/SpriteSheet/landing.png",
    "assets/Basic movement pack/SpriteSheet/Roll.png",
    "assets/Basic movement pack/SpriteSheet/run.png",
    "assets/Basic movement pack/SpriteSheet/sprint.png",
    "assets/Basic vault pack/SpriteSheet/Basic vault.png",
    "assets/Basic vault pack/SpriteSheet/climbing.png",
    "assets/Basic vault pack/SpriteSheet/hanging.png",
    "assets/Basic vault pack/SpriteSheet/long vault.png",
    "assets/Basic vault pack/SpriteSheet/On top climbing.png",
    "assets/Basic vault pack/SpriteSheet/on top vault.png",
};


class Animation
{
public:
    void LoadSurfaces(std::vector<std::string> assets);
    void SliceSpriteSheet(SDL_Rect size);
    void SetFrameDelay(int delay);
    void AnimateStrip();

private:
    std::vector<SDL_Surface *> surfaces;
    std::vector<SDL_Texture *> textures;
    SDL_Rect srcRect, destRect;

    int frameWidth, frameHeight;
    int currentFrame;
    int totalFrames;
    int frameDelay;
    Uint32 lastFrameTime;
};