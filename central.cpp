#include "central.hpp"

void SDLProfiler(std::string context)
{
    currentTime = SDL_GetTicks(); // Get milliseconds from when SDL was initialized
    std::cout << "Closing : " << context << " executed since: " << currentTime - lastTime << "ms" << std::endl;
    lastTime = currentTime;
}

bool LoadSpriteSheets(std::string assetsDir)
{
    /*
    - Vector of SDL_Surface pointers
    - which will store every element
    - included in the assets/ directory
    */
    std::vector<SDL_Surface *> spriteSheets;

    if (!fs::exists(assetsDir))
    {
        SDL_Log("Couldn't find sprite sheets");
        return false;
    }

    /* 
    - A loop iterating through assetDir "assets/" path 
    - Both devided directories are visited, by using "fs::recursive_directory_iterator"
    - (instead of) fs::directory iterator
    */
    for (const auto &entry : fs::recursive_directory_iterator(assetsDir))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".png")
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

bool CleanSurfaces(bool cleanAll = false, std::vector<SDL_Surface *> spriteSheets)
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

bool CleanTextures(bool cleanAll = false, std::vector<SDL_Texture *> spriteTextures){
    
}