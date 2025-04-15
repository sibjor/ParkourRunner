#include "central.hpp"

const char *window_title = "Validator 13";
const int window_width = 1200;
const int window_height = 1000;
const int window_flags = SDL_EVENT_WINDOW_SHOWN;
extern SDL_Renderer *renderer = nullptr;
extern SDL_Window *window = nullptr;

Object::Object()
{
    paths = {
        {AssetID::Idle, "assets/Basic movement pack/SpriteSheet/Idle.png"},
        {AssetID::Run, "assets/Basic movement pack/SpriteSheet/run.png"},
        {AssetID::Jumping, "assets/Basic movement pack/SpriteSheet/jumping.png"},
        {AssetID::InAir, "assets/Basic movement pack/SpriteSheet/in air.png"},
        {AssetID::Landing, "assets/Basic movement pack/SpriteSheet/landing.png"},
        {AssetID::Sprint, "assets/Basic movement pack/SpriteSheet/sprint.png"},
        {AssetID::Roll, "assets/Basic movement pack/SpriteSheet/Roll.png"},
        {AssetID::BasicVault, "assets/Basic vault pack/SpriteSheet/Basic vault.png"},
        {AssetID::OnTopVault, "assets/Basic vault pack/SpriteSheet/on top vault.png"},
        {AssetID::LongVault, "assets/Basic vault pack/SpriteSheet/long vault.png"},
        {AssetID::Climbing, "assets/Basic vault pack/SpriteSheet/climbing.png"},
        {AssetID::OnTopClimbing, "assets/Basic vault pack/SpriteSheet/On top climbing.png"},
        {AssetID::Hanging, "assets/Basic vault pack/SpriteSheet/hanging.png"},
        {AssetID::Ground, "assets/Ground.png"},
        {AssetID::ObstacleVault, "assets/obstacle_vault.png"},
        {AssetID::ObstacleLongVault, "assets/obstacle_long_vault.png"},
        {AssetID::ObstacleClimb, "assets/obstacle_climb.png"},
        {AssetID::ObstacleHang, "assets/obstacle_hang.png"},
        {AssetID::ObstacleTopClimb, "assets/obstacle_top_climb.png"}};

    for (const auto &pair : paths)
    {
        SDL_Surface *surface = IMG_Load(pair.second.c_str());
        if (!surface)
        {
            SDL_Log("Failed to load image: %s", SDL_GetError());
            continue;
        }
        surfaces[pair.first].push_back(surface);

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture)
        {
            SDL_Log("Failed to create texture: %s", SDL_GetError());
            continue;
        }
        textures[pair.first].push_back(texture);
    }
}
Object::~Object()
{
    for (auto &surfaceVec : surfaces)
    {
        for (auto *surface : surfaceVec.second)
        {
            SDL_DestroySurface(surface);
        }
    }

    for (auto &textureVec : textures)
    {
        for (auto *texture : textureVec.second)
        {
            SDL_DestroyTexture(texture);
        }
    }
}

void Object::DrawGround()
{;
    SDL_FRect dstrect = {0, 0, static_cast<float>(window_width), static_cast<float>(window_height)};
    SDL_RenderTexture(renderer, textures[AssetID::Ground][0], NULL, &dstrect);
}

void Object::Player()
{
    // Draw player logic here

}