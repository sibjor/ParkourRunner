#include "central.hpp"

const char *window_title = "Validator 13";
const int window_width = 1200;
const int window_height = 1000;
const int window_flags = SDL_EVENT_WINDOW_SHOWN;
extern SDL_Renderer *renderer = nullptr;
extern SDL_Window *window = nullptr;

/*
    InitAssets()
    - This function initializes the assets for the game
    - Paths, surfaces, textures, and rectangles are created in order described here
    - pair.first represents the AssetID enum class
    - pair.second represents the file path to the asset

    */
void Assets::InitAssets()
{
    // Definiera sökvägar för varje resurs
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

    // Ladda ytor från sökvägar
    for (const auto &pair : paths)
    {
        SDL_Surface *surface = IMG_Load(pair.second.c_str());
        if (!surface)
        {
            SDL_Log("Failed to load image: %s", SDL_GetError());
            continue;
        }
        surfaces[pair.first] = std::make_unique<SDL_Surface>(*surface);
    }

    // Skapa texturer från ytor
    for (const auto &pair : surfaces)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, pair.second.get());
        if (!texture)
        {
            SDL_Log("Failed to create texture: %s", SDL_GetError());
            continue;
        }
        textures[pair.first] = std::make_unique<SDL_Texture>(*texture);
    }

    // Skapa rektanglar för varje textur
    for (const auto &pair : textures)
    {
        float width, height;
        if (SDL_GetTextureSize(pair.second.get(), &width, &height) != 0)
        {
            SDL_Log("Failed to get texture size: %s", SDL_GetError());
            continue;
        }

        auto rect = std::make_unique<SDL_FRect>();
        rect->x = 0;
        rect->y = 0;
        rect->w = width;
        rect->h = height;

        rects[pair.first] = std::move(rect);
    }
}