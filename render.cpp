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
    {Animation::BasicVault, "assets/Basic movement pack/SpriteSheet/Idle.png"}};

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