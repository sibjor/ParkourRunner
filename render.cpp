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

void EnvironmentNavigated::DisplayTextures(SDL_Renderer *renderer, EnvironmentObject objectType)
{
    // Map the object type to the corresponding texture
    std::string objectName;
    switch (objectType)
    {
    case EnvironmentObject::Ground:
        SDL_FRect *groundRect = new SDL_FRect();
        objectName = "Ground";
        groundRect->x = 0.0f;
        groundRect->y = 0.0f;
        groundRect->w = 800.0f;
        groundRect->h = 600.0f;
        SDL_RenderTexture(renderer, textures[objectName], nullptr, groundRect);
        break;
    case EnvironmentObject::Obstacle_Vault:
        SDL_FRect *obstacleVaultRect = new SDL_FRect();
        objectName = "Obstacle_Vault";
        obstacleVaultRect->x = 400.0f;
        obstacleVaultRect->y = 400.0f;
        obstacleVaultRect->w = 64.0f;
        obstacleVaultRect->h = 64.0f;
        SDL_RenderTexture(renderer, textures[objectName], nullptr, obstacleVaultRect);
        break;
    default:
        std::cerr << "Unknown environment object type" << std::endl;
        return;
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

void AnimatedSprite::PlayAnimation(AnimationState state, bool reversed)
{
    // Check if the state exists in the textures map
    if (textures.find(state) == textures.end())
    {
        std::cerr << "Animation state not found: " << static_cast<int>(state) << std::endl;
        return;
    }

    // Get the frames for the current animation state
    const auto &framesList = frames[state];

    // Determine the order of frame iteration
    if (reversed)
    {
        for (int i = framesList.size() - 1; i >= 0; --i)
        {
            SDL_FRect dstRect = {0.0f, 0.0f, framesList[i].w, framesList[i].h};
            SDL_RenderTexture(renderer, textures[state][0], &framesList[i], &dstRect);

            // Delay for the specified frame delay
            SDL_Delay(frameDelay);
        }
    }
    else
    {
        for (size_t i = 0; i < framesList.size(); ++i)
        {
            SDL_FRect dstRect = {0.0f, 0.0f, framesList[i].w, framesList[i].h};
            SDL_RenderTexture(renderer, textures[state][0], &framesList[i], &dstRect);

            // Delay for the specified frame delay
            SDL_Delay(frameDelay);
        }
    }

    // If looping is enabled, restart the animation
    if (loop)
    {
        PlayAnimation(state, loop, renderer, reversed, frameDelay);
    }
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