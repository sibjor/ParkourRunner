#include "game.hpp"

Game::Game()
{
    // Constructor implementation
    std::vector<std::string> assets = {
        "assets/Basic movement pack/SpriteSheet/Idle.png",
        "assets/Basic movement pack/SpriteSheet/in air.png",
        "assets/Basic movement pack/SpriteSheet/junping.png",
        "assets/Basic movement pack/SpriteSheet/landing.png",
        "assets/Basic movement pack/SpriteSheet/Roll.png",
        "assets/Basic movement pack/SpriteSheet/run.png",
        "assets/Basic movement pack/SpriteSheet/sprint.png",
        "assets/Basic vault pack/SpriteSheet/Basic vault.png",
        "assets/Basic vault pack/SpriteSheet/climbing.png",
        "assets/Basic vault pack/SpriteSheet/hanging.png",
        "assets/Basic vault pack/SpriteSheet/long vault.png",
        "assets/Basic vault pack/SpriteSheet/On top climbing.png",
        "assets/Basic vault pack/SpriteSheet/on top vault.png",
    };
}
Game::~Game()
{
    // Destructor implementation
}
void Game::InitAssets()
{

    for (const auto &asset : assets)
    {
        std::cout << "Loading asset: " << asset << std::endl;
        // Load the asset here (e.g., using SDL_image or other libraries)
        IMG_Load(asset.c_str());
        if (SDL_GetError())
        {
            std::cerr << "Failed to load asset: " << asset << " Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            std::cout << "Successfully loaded asset: " << asset << std::endl;
        }

    }
}

