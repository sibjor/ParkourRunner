#include "render.hpp"

SDL_Renderer *renderer = nullptr;

std::vector<std::pair<EnvironmentObject, std::string>> objectPaths{
    {EnvironmentObject::Ground, "assets/Ground.png"}};

std::vector<std::pair<Animation, std::string>> spritePaths{
    {Animation::Idle, "assets/Basic movement pack/SpriteSheet/Idle.png"},
    {Animation::Run, "assets/Basic movement pack/SpriteSheet/run.png"},
    {Animation::Sprint, "assets/Basic movement pack/SpriteSheet/sprint.png"},
    {Animation::Jumping, "assets/Basic movement pack/SpriteSheet/jumping.png"},
    {Animation::InAir, "assets/Basic movement pack/SpriteSheet/in air.png"},
    {Animation::Landing, "assets/Basic movement pack/SpriteSheet/landing.png"},
    {Animation::Roll, "assets/Basic movement pack/SpriteSheet/Roll.png"},
    {Animation::BasicVault, "assets/Basic vault pack/SpriteSheet/Basic vault.png"},
    {Animation::LongVault, "assets/Basic vault pack/SpriteSheet/long vault.png"},
    {Animation::TopVault, "assets/Basic vault pack/SpriteSheet/on top vault.png"},
    {Animation::Climbing, "assets/Basic vault pack/SpriteSheet/climbing.png"},
    {Animation::Hanging, "assets/Basic vault pack/SpriteSheet/hanging.png"},
    {Animation::TopClimb, "assets/Basic vault pack/SpriteSheet/On top climbing.png"}};

void GameObject::PrepareAll(std::vector<std::tuple<std::pair<EnvironmentObject, std::string>, SDL_Texture *, SDL_FRect>> objectTuple)
{

}

void Sprite::PrepareAll(std::vector<std::tuple<std::pair<Animation, std::string>, SDL_Texture *, SDL_FRect>> spriteTuple)
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    float sheetWidth = surface->w;
    float sheetHeight = surface->h;

    float spriteWidth = sheetWidth / 16;
    float spriteHeight = sheetHeight;

    int columns = 16;
    int rows = 1;

    while(spriteTuple.size() < spritePaths.size())
    {

    }
}