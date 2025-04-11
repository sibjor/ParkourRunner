#include "render.hpp"

AnimatedSprite::AnimatedSprite()
{
    LoadTextures();
}

AnimatedSprite::~AnimatedSprite()
{
    // Free all textures
    for (auto &[state, textureList] : textures)
    {
        for (auto &texture : textureList)
        {
            SDL_DestroyTexture(texture);
        }
    }
}

void AnimatedSprite::LoadTextures()
{
    // Map of animation states to file paths
    std::unordered_map<AnimationState, std::string> assetPaths = {
        {AnimationState::Idle, "assets/Basic movement pack/SpriteSheet/Idle.png"},
        {AnimationState::InAir, "assets/Basic movement pack/SpriteSheet/in air.png"},
        {AnimationState::Jumping, "assets/Basic movement pack/SpriteSheet/jumping.png"},
        {AnimationState::Landing, "assets/Basic movement pack/SpriteSheet/landing.png"},
        {AnimationState::Roll, "assets/Basic movement pack/SpriteSheet/Roll.png"},
        {AnimationState::Run, "assets/Basic movement pack/SpriteSheet/run.png"},
        {AnimationState::Sprint, "assets/Basic movement pack/SpriteSheet/sprint.png"},
        {AnimationState::BasicVault, "assets/Basic vault pack/SpriteSheet/Basic vault.png"},
        {AnimationState::Climbing, "assets/Basic vault pack/SpriteSheet/climbing.png"},
        {AnimationState::Hanging, "assets/Basic vault pack/SpriteSheet/hanging.png"},
        {AnimationState::LongVault, "assets/Basic vault pack/SpriteSheet/long vault.png"},
        {AnimationState::OnTopClimbing, "assets/Basic vault pack/SpriteSheet/On top climbing.png"},
        {AnimationState::OnTopVault, "assets/Basic vault pack/SpriteSheet/on top vault.png"}};

    // Load textures for each animation state
    for (const auto &[state, path] : assetPaths)
    {
        SDL_Surface *surface = IMG_Load(path.c_str());
        if (!surface)
        {
            std::cerr << "Failed to load surface: " << path << " - " << SDL_GetError() << std::endl;
            continue;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_DestroySurface(surface);

        if (!texture)
        {
            std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
            continue;
        }

        // Slice the spritesheet into frames
        SliceSpriteSheet(texture, state);
    }
}

void AnimatedSprite::SliceSpriteSheet(SDL_Texture *texture, AnimationState state)
{
    float textureWidth, textureHeight;
    SDL_GetTextureSize(texture, &textureWidth, &textureHeight); // SDL3 function to get texture size

    // Define the frame dimensions (e.g., 64x64 pixels per frame)
    float frameWidth = 64.0f;
    float frameHeight = 64.0f;

    // Calculate the number of frames in the spritesheet
    int columns = static_cast<int>(textureWidth / frameWidth);
    int rows = static_cast<int>(textureHeight / frameHeight);

    // Store each frame as a rectangle
    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < columns; ++x)
        {
            SDL_FRect frameRect = {
                static_cast<float>(x) * frameWidth,
                static_cast<float>(y) * frameHeight,
                frameWidth,
                frameHeight};
            frames[state].push_back(frameRect);
        }
    }

    // Store the original texture for rendering
    textures[state].push_back(texture);
}

void AnimatedSprite::PlayAnimation(AnimationState state, SDL_FRect *destRect)
{
    static Uint32 lastFrameTime = 0;
    static int currentFrame = 0;

    auto &frameRects = frames[state];
    if (frameRects.empty())
        return;

    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastFrameTime >= 100) // 100ms per frame
    {
        lastFrameTime = currentTime;
        currentFrame = (currentFrame + 1) % frameRects.size();
    }

    // Render the current frame to the destination rectangle using SDL_RenderTexture
    SDL_RenderTexture(renderer, textures[state][0], &frameRects[currentFrame], destRect);
}