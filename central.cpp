#include "central.hpp"

SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;
const char *window_title = "Validator 13";
const int window_width = 1200;
const int window_height = 1000;
const int window_flags = SDL_EVENT_WINDOW_SHOWN;

/* 
    Usage of smart pointers makes deallocation unnecessary
    and the code cleaner.
*/
void Assets::LoadAssets()
{
    paths = {
        // Basic movement pack
        std::make_unique<std::string>("assets/Basic movement pack/SpriteSheet/Idle.png"),
        std::make_unique<std::string>("assets/Basic movement pack/SpriteSheet/run.png"),
        std::make_unique<std::string>("assets/Basic movement pack/SpriteSheet/jumping.png"),
        std::make_unique<std::string>("assets/Basic movement pack/SpriteSheet/in air.png"),
        std::make_unique<std::string>("assets/Basic movement pack/SpriteSheet/landing.png"),
        std::make_unique<std::string>("assets/Basic movement pack/SpriteSheet/sprint.png"),
        std::make_unique<std::string>("assets/Basic movement pack/SpriteSheet/Roll.png"),
        // Basic vault pack
        std::make_unique<std::string>("assets/Basic vault pack/SpriteSheet/Basic vault.png"),
        std::make_unique<std::string>("assets/Basic vault pack/SpriteSheet/on top vault.png"),
        std::make_unique<std::string>("assets/Basic vault pack/SpriteSheet/long vault.png"),
        std::make_unique<std::string>("assets/Basic vault pack/SpriteSheet/climbing.png"),
        std::make_unique<std::string>("assets/Basic vault pack/SpriteSheet/On top climbing.png"),
        std::make_unique<std::string>("assets/Basic vault pack/SpriteSheet/hanging.png"),
        // Ground
        std::make_unique<std::string>("assets/Ground.png"),
        // Obstacles
        std::make_unique<std::string>("assets/obstacle_vault.png"),
        std::make_unique<std::string>("assets/obstacle_long_vault.png"),
        std::make_unique<std::string>("assets/obstacle_climb.png"),
        std::make_unique<std::string>("assets/obstacle_hang.png"),
        std::make_unique<std::string>("assets/obstacle_top_climb.png"),
    };
    // Load surfaces from paths
    surfaces.reserve(paths.size());
    for (const auto &path : paths)
    {
        SDL_Surface *surface = IMG_Load(path->c_str());
        if (!surface)
        {
            SDL_Log("Failed to load image: %s", SDL_GetError());
            continue;
        }
        surfaces.push_back(std::make_unique<SDL_Surface *>(surface));
    }
    // Create textures from surfaces
    textures.reserve(surfaces.size());
    for (const auto &surface : surfaces)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, *surface);
        if (!texture)
        {
            SDL_Log("Failed to create texture: %s", SDL_GetError());
            continue;
        }
        textures.push_back(std::make_unique<SDL_Texture *>(texture));
    }
    // Create rectangles for each texture
    rects.reserve(textures.size());
    for (size_t i = 0; i < textures.size(); ++i)
    {
        float texture_width, texture_height;
        if (SDL_GetTextureSize(*textures[i], &texture_width, &texture_height) != 0)
        {
            SDL_Log("Failed to get texture size: %s", SDL_GetError());
            continue;
        }

        SDL_FRect *rect = new SDL_FRect();
        rect->x = 0;
        rect->y = 0;
        rect->w = texture_width;
        rect->h = texture_height;
        rects.push_back(std::make_unique<SDL_FRect *>(rect));
    }

}