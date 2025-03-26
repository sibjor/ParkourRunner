#include "central.hpp"

void ReportRecources(std::string since)
{
    currentTime = SDL_GetTicks(); // Get milliseconds from when SDL was initialized
    std::cout << "Closing : " << since << " executed since: " << currentTime - lastTime << "ms" << std::endl;
    lastTime = currentTime;
}

bool LoadSpriteSheets(std::string assetsDir)
{
    /* First step is to declare a vector, which
        - will store SDL_Surface pointers, which
        - will be loaded as SDL_Texture pointers
        - then call SDL_RenderTexture(renderer, texture, NULL, NULL)
        - then SDL_RenderPresent(renderer) 
        - don't forget: art is of dimensions: 192x96 (pixels?)
        - you were told to implement similar dimensions of w & h
        - cited from teacher, referring to the practice of a GPU
        */
    std::vector<SDL_Surface *> spriteSheets;

    if (!fs::exists(assetsDir))
    {
        SDL_Log("Couldn't find sprite sheets");
        return false;
    }

    for (const auto &entry : fs::directory_iterator(assetsDir))
    {
        ;
        if (entry.is_regular_file())
        {
            const std::string fileassetsDir = entry.path().string();
            SDL_Surface *spriteSheet = IMG_Load(fileassetsDir.c_str());
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

bool CleanSpriteSheets(bool cleanAll = false)
{
    if (cleanAll)
    {
        for (auto surface : spriteSheets)
        {
            SDL_DestroySurface(surface);
        }
        spriteSheets.clear();
    }
    return true;
}