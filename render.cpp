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

        // Set texture scaling mode to nearest neighbor for sharp rendering
        SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

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

void AnimatedSprite::PlayAnimation(AnimationState state, SDL_FRect* destRect, bool loop, bool isFlipped, int frameDelay)
{
    static Uint32 lastFrameTime = 0;
    static int currentFrame = 0;
    bool hasFinished = false;

    auto& frameRects = frames[state];
    if (frameRects.empty())
        return;

    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastFrameTime >= frameDelay) // Use the provided frameDelay
    {
        lastFrameTime = currentTime;

        if (loop) {
            // Loop the animation
            currentFrame = (currentFrame + 1) % frameRects.size();
        } else {
            // Stop at the last frame if not looping
            if (currentFrame < frameRects.size() - 1) {
                currentFrame++;
            } else {
                // Mark the animation as finished when it reaches the last frame
                hasFinished = true;
            }
        }
    }

    // Determine the flip mode based on the direction and isFlipped parameter
    SDL_FlipMode flip = SDL_FLIP_NONE;
    if (direction == AnimationDirection::Left || isFlipped) {
        flip = SDL_FLIP_HORIZONTAL;
    }

    // Render the current frame to the destination rectangle using SDL_RenderCopyExF
    SDL_RenderTextureRotated(renderer, textures[state][0], &frameRects[currentFrame], destRect, 0.0, nullptr, flip);
}

void AnimatedSprite::SetDirection(AnimationDirection newDirection)
{
    // Only update the direction if it is different from the current direction
    if (direction != newDirection) {
        direction = newDirection;

        // Optional: Reset animation frame when direction changes
        // This ensures the animation starts fresh when switching directions
        static int currentFrame = 0;
        currentFrame = 0;
    }
}

AnimationDirection AnimatedSprite::GetDirection() const
{
    return direction;
}