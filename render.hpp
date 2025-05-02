#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

extern SDL_Renderer *renderer;

enum class Direction
{
    None,
    Up,
    Down,
    Left,
    Right,
};

enum class Animation
{
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

enum class EnvironmentObject
{
    Ground,
    ObstacleClimb,
    ObstacleHang,
    ObstacleLongVault,
    ObstacleTopClimb,
    ObstacleVault,
};

class Sprite
{
public:
    std::vector<std::tuple<std::pair<Animation, std::string>, SDL_Texture *, SDL_FRect>> spriteTuple;
    void PrepareAll(std::vector<std::tuple<std::pair<Animation, std::string>, SDL_Texture *, SDL_FRect>> spriteTuple);

private:
    std::vector<std::pair<Animation, std::string>> spritePaths;
};

class GameObject
{
public:
    std::vector<std::tuple<std::pair<EnvironmentObject, std::string>, SDL_Texture *, SDL_FRect>> objectTuple;
    void PrepareAll(std::vector<std::tuple<std::pair<EnvironmentObject, std::string>, SDL_Texture *, SDL_FRect>> objectTuple);
    void RenderWhiteBackground()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

private:
    std::vector<std::pair<EnvironmentObject, std::string>> objectPaths;
};

class AssetManager : public Sprite, public GameObject
{
public:
    void LoadAssets();
    void PlaceAssets();
};