#pragma once

#include <map>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include "profiler.hpp"
#include "data.hpp"

enum class AssetID {
    Idle,
    Run,
    Jumping,
    InAir,
    Landing,
    Sprint,
    Roll,
    BasicVault,
    OnTopVault,
    LongVault,
    Climbing,
    OnTopClimbing,
    Hanging,
    Ground,
    ObstacleVault,
    ObstacleLongVault,
    ObstacleClimb,
    ObstacleHang,
    ObstacleTopClimb
};

/*

    Please use this file to implemenet as much
    logic as possible for rendering Assets
    moving or not, background or foreground
    DrawPlayer sprite or whatever

    Try to reuse logic through inheritance and
    polymorphism as much as possible
*/

extern const char *window_title;
extern const int window_width;
extern const int window_height;
extern const int window_flags;
extern SDL_Renderer *renderer;
extern SDL_Window *window;

class Object
{
public:
    Object();
    ~Object();
    void Player();
    void DrawGround();
    void DrawObstacle(AssetID id, SDL_FRect *rect);
    void DrawObstacle(AssetID id, SDL_FRect *rect);
    void GenerateMap();

    std::map<AssetID, std::vector<SDL_Surface*>> surfaces;
    std::map<AssetID, std::vector<SDL_Texture*>> textures;

private:
    std::map<AssetID, std::string> paths;
};