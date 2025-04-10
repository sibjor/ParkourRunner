#include "game.hpp"

Animation::Animation(SDL_Renderer* renderer, const std::string& spritesheetPath, int frameWidth, int frameHeight, int frameDelay)
    : texture(nullptr), currentFrame(0), frameDelay(frameDelay), lastUpdateTime(0)
{
    // Load the spritesheet as a surface to get its dimensions
    SDL_Surface* surface = IMG_Load(spritesheetPath.c_str());
    if (!surface) {
        std::cerr << "Failed to load spritesheet: " << spritesheetPath << " - " << SDL_GetError() << std::endl;
        return;
    }

    // Get the dimensions of the spritesheet
    int textureWidth = surface->w;
    int textureHeight = surface->h;

    // Create a texture from the surface
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface); // Free the surface after creating the texture

    if (!texture) {
        std::cerr << "Failed to create texture from spritesheet: " << SDL_GetError() << std::endl;
        return;
    }

    // Slice the spritesheet into frames
    for (int y = 0; y < textureHeight; y += frameHeight) {
        for (int x = 0; x < textureWidth; x += frameWidth) {
            SDL_Rect frame = {x, y, frameWidth, frameHeight};
            frames.push_back(frame);
        }
    }
}

Animation::~Animation()
{
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Animation::Update()
{
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime > lastUpdateTime + frameDelay) {
        currentFrame = (currentFrame + 1) % frames.size(); // Loop through frames
        lastUpdateTime = currentTime;
    }
}

void Animation::Render(SDL_Renderer* renderer, int x, int y, int scale)
{
    if (!texture || frames.empty()) return;

    SDL_Rect destRect = {x, y, frames[currentFrame].w * scale, frames[currentFrame].h * scale};
    SDL_RenderTexture(renderer, texture, &frames[currentFrame], &destRect);
}