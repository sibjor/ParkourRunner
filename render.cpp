#include "render.hpp"

SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;
const char *window_title = "Validator 13";
int window_width = 1200;
int window_height = 1000;
Uint32 window_flags = SDL_EVENT_WINDOW_SHOWN;

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
    {Animation::TopClimb, "assets/Basic vault pack/SpriteSheet/On top climbing.png"}
    };

void Sprite::AnimatePlayer(Animation animation)
{
    
}

void Level::RenderEntireObject(EnvironmentObject object)
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = IMG_Load(objectPaths[static_cast<int>(object)].second.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderTexture(renderer, texture, nullptr, nullptr);

    SDL_DestroySurface(surface);
    SDL_DestroyTexture(texture);
}

void Sprite::SliceSpriteSheet(Animation animation)
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = IMG_Load(spritePaths[static_cast<int>(animation)].second.c_str());

    float sheetWidth = surface->w;
    float sheetHeight = surface->h;

    float spriteWidth = sheetWidth / 16;
    float spriteHeight = sheetHeight;

    int columns = 16;
    int rows = 1;

    std::vector<SDL_FRect> spriteClips;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            SDL_FRect clip;
            clip.x = x * spriteWidth;
            clip.y = y * spriteHeight;
            clip.w = spriteWidth;
            clip.h = spriteHeight;

            spriteClips.push_back(clip);
            for (const auto &clip : spriteClips)
            {
                slicedSheets.push_back(std::make_pair(animation, clip));
            }
        }
    }

    SDL_DestroySurface(surface);
    SDL_DestroyTexture(texture);
}

void Sprite::SliceAllSpriteSheets()
{
    for (int i = 0; i < spritePaths.size(); i++)
    {
        SliceSpriteSheet(static_cast<Animation>(i));
    }
}