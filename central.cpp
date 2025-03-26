#include "central.hpp"

void ReportRecources(std::string since)
{
    currentTime = SDL_GetTicks(); // Get milliseconds from when SDL was initialized
    std::cout << "Closing : " << since << " executed since: " << currentTime - lastTime << "ms" << std::endl;
    lastTime = currentTime;
}

bool LoadSpriteSheets(std::string path)
{

    if (!fs::exists(path))
    {
        SDL_Log("Couldn't find sprite sheets");
        return false;
    }

    for (const auto &entry : fs::directory_iterator(path))
    {
        if (entry.is_regular_file())
        {
            const std::string filePath = entry.path().string();
            SDL_Surface *spriteSheet = IMG_Load(filePath.c_str());
            if (spriteSheet == NULL)
            {
                SDL_Log("Couldn't load sprite sheet: %s", SDL_GetError());
                return false;
            }
            spriteSheets.push_back(spriteSheet);
        }
    }

    std::cout << "Loaded " << spriteSheets.size() << " sprite sheets" << std::endl;
    currentTime = SDL_GetTicks(); // Get milliseconds from when SDL was initialized
    std::cout << "Time to load sprite sheets: " << currentTime - lastTime << "ms" << std::endl;
    lastTime = currentTime;
    return true;
}

void CleanSpriteSheets()
{
    for (auto surface : spriteSheets)
    {
        SDL_DestroySurface(surface);
    }
    spriteSheets.clear();
}