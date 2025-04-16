#pragma once

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
    void AnimateSprite(Animation animation);
private:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    int width;
    int height;
    int x_pos;
    int y_pos;
    int frameCount;
    int frameDelay;
    std::vector<std::pair<Animation, std::string>> paths;
};

class Level
{
public:
    void RenderObject(EnvironmentObject object);
private:
    std::vector<std::pair<EnvironmentObject, std::string>> paths;
};