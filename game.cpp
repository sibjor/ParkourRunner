#include "game.hpp"

std::vector<SDL_Surface*> Animation::LoadSurfaces(std::vector<std::string> assets)
{
    for (int i = 0; i < assets.size(); i++)
    {
        SDL_Surface* surface = IMG_Load(assets[i].c_str());
        if (surface == nullptr)
        {
            std::cerr << "Failed to load image: " << assets[i] << " Error: " << SDL_GetError() << std::endl;
            continue;
        }
        surfaces.push_back(surface);
    }
}