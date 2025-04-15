#include "render.hpp"

EnvironmentNavigated::EnvironmentNavigated()
{
    EnvironmentNavigated::LoadTextures();
}
EnvironmentNavigated::~EnvironmentNavigated()
{
    // Free all textures
    for (auto &[name, texture] : textures)
    {
        SDL_DestroyTexture(texture);
    }
}
void EnvironmentNavigated::LoadTextures()
{
    // Map of environment objects to file paths
    std::unordered_map<std::string, std::string> assetPaths = {
        {"Ground", "assets/Ground.png"},
        {"Obstacle_Vault", "assets/obstacle1.png"},
        {"Obstacle_Climb", "assets/obstacle2.png"},
        {"Obstacle_Long_Vault", "assets/obstacle3.png"},
        {"Obstacle_Top_Vault", "assets/obstacle4.png"},
        {"Obstacle_Top_Climb", "assets/obstacle5.png"}};

    // Load textures for each environment object
    for (const auto &[name, path] : assetPaths)
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

        // Store the texture in the map
        textures[name] = texture;
    }
}

void EnvironmentNavigated::DisplayTextures(SDL_Renderer *renderer, SDL_FRect *destRect, EnvironmentObject objectType)
{
    // Map the object type to the corresponding texture
    std::string objectName;
    switch (objectType)
    {
    case EnvironmentObject::Ground:
        objectName = "Ground";
        destRect->x = 0.0f;
        destRect->y = 0.0f;
        destRect->w = 800.0f;
        destRect->h = 600.0f;
        break;
    case EnvironmentObject::Obstacle_Vault:
        objectName = "Obstacle_Vault";
        destRect->x = 400.0f;
        destRect->y = 400.0f;
        destRect->w = 64.0f;
        destRect->h = 64.0f;
        break;
    default:
        std::cerr << "Unknown environment object type" << std::endl;
        return;
    }

    // Render the texture
    auto it = textures.find(objectName);
    if (it != textures.end())
    {
        // Get the original texture size
        float textureWidth, textureHeight;
        SDL_GetTextureSize(it->second, &textureWidth, &textureHeight);

        // Set the destination rectangle size to match the texture size
        destRect->w = textureWidth;
        destRect->h = textureHeight;

        // Render the texture
        SDL_RenderTexture(renderer, it->second, nullptr, destRect);
    }
    else
    {
        std::cerr << "Texture not found for object: " << objectName << std::endl;
    }
}
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

void AnimatedSprite::PlayAnimation(AnimationState state, SDL_FRect* destRect, bool loop, bool isFlipped, int frameDelay)
{
    static Uint32 lastFrameTime = 0;
    static int currentFrame = 0;

    auto& frameRects = frames[state];
    if (frameRects.empty())
        return;

    // Customize behavior based on the animation state
    switch (state)
    {
    case AnimationState::Jumping:
        loop = false; // Jumping should not loop
        frameDelay = 150; // Custom frame delay for Jumping
        break;

    case AnimationState::Run:
        loop = true; // Running should loop
        frameDelay = 70; // Faster frame delay for Running
        break;

    case AnimationState::Idle:
        loop = true; // Idle should loop
        frameDelay = 100; // Default frame delay for Idle
        break;

    // Add cases for other AnimationStates as needed
    default:
        break;
    }

    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastFrameTime >= frameDelay)
    {
        lastFrameTime = currentTime;

        if (loop)
        {
            // Loop the animation
            currentFrame = (currentFrame + 1) % frameRects.size();
        }
        else
        {
            // Stop at the last frame if not looping
            if (currentFrame < frameRects.size() - 1)
            {
                currentFrame++;
            }
        }
    }

    // Determine the flip mode based on the direction and isFlipped parameter
    SDL_FlipMode flip = SDL_FLIP_NONE;
    if (direction == AnimationDirection::Left || isFlipped)
    {
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