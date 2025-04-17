#pragma once

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

enum class Direction {
    None,
    Up,
    Down,
    Left,
    Right,
};

enum class Animation {
    Idle,
    InAir,
    Jumping,
    Landing,
    Roll,
    Run,
    Sprint,
    BasicVault,
    Climbing,
    Hanging,
    LongVault,
    TopClimb,
    TopVault,
};

enum class EnvironmentObject{
    Ground,
    ObstacleClimb,
    ObstacleHang,
    ObstacleLongVault,
    ObstacleTopClimb,
    ObstacleVault,
};

extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern const char* window_title;
extern int window_width;
extern int window_height;
extern Uint32 window_flags;

class Sprite
{
public:
    void SliceSpriteSheet(float frameSize);
private:

};

class Level
{
public:
    void RenderEntireObject(EnvironmentObject object);
private:
    
};