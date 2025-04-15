#include "central.hpp"

const char *window_title = "Validator 13";
const int window_width = 1200;
const int window_height = 1000;
const int window_flags = SDL_EVENT_WINDOW_SHOWN;
extern SDL_Renderer *renderer = nullptr;
extern SDL_Window *window = nullptr;

Object::Object()
{
    // Initialize paths for all AssetIDs
    paths = {
        {AssetID::Idle, "assets/Basic movement pack/SpriteSheet/Idle.png"},
        {AssetID::Run, "assets/Basic movement pack/SpriteSheet/run.png"},
        {AssetID::Jumping, "assets/Basic movement pack/SpriteSheet/jumping.png"},
        {AssetID::InAir, "assets/Basic movement pack/SpriteSheet/in air.png"},
        {AssetID::Landing, "assets/Basic movement pack/SpriteSheet/landing.png"},
        {AssetID::Sprint, "assets/Basic movement pack/SpriteSheet/sprint.png"},
        {AssetID::Roll, "assets/Basic movement pack/SpriteSheet/Roll.png"},
        {AssetID::BasicVault, "assets/Basic vault pack/SpriteSheet/Basic vault.png"},
        {AssetID::OnTopVault, "assets/Basic vault pack/SpriteSheet/on top vault.png"},
        {AssetID::LongVault, "assets/Basic vault pack/SpriteSheet/long vault.png"},
        {AssetID::Climbing, "assets/Basic vault pack/SpriteSheet/climbing.png"},
        {AssetID::OnTopClimbing, "assets/Basic vault pack/SpriteSheet/On top climbing.png"},
        {AssetID::Hanging, "assets/Basic vault pack/SpriteSheet/hanging.png"},
        {AssetID::Ground, "assets/Ground.png"},
        {AssetID::ObstacleVault, "assets/obstacle_vault.png"},
        {AssetID::ObstacleLongVault, "assets/obstacle_long_vault.png"},
        {AssetID::ObstacleClimb, "assets/obstacle_climb.png"},
        {AssetID::ObstacleHang, "assets/obstacle_hang.png"},
        {AssetID::ObstacleTopClimb, "assets/obstacle_top_climb.png"}};

    // Load all textures and surfaces
    for (const auto &pair : paths)
    {
        SDL_Surface *surface = IMG_Load(pair.second.c_str());
        if (!surface)
        {
            SDL_Log("Failed to load image: %s", SDL_GetError());
            continue;
        }
        surfaces[pair.first].push_back(surface);

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture)
        {
            SDL_Log("Failed to create texture for AssetID: %d, Error: %s", static_cast<int>(pair.first), SDL_GetError());
            continue;
        }
        textures[pair.first].push_back(texture);

        // Store the texture dimensions
        textureDimensions[pair.first] = {static_cast<float>(surface->w), static_cast<float>(surface->h)};
        SDL_Log("Texture dimensions for AssetID %d: %dx%d", static_cast<int>(pair.first), surface->w, surface->h);
    }

    // Slice all spritesheets
    for (const auto &pair : textures)
    {
        AssetID id = pair.first;

        // Example: Assume all spritesheets have 4 rows and 4 columns
        int rows = 4;
        int cols = 4;

        SliceSpriteSheets(id, rows, cols);
    }
}

Object::~Object()
{
    // Free all SDL_Surface pointers
    for (auto &surfaceVec : surfaces)
    {
        for (auto *surface : surfaceVec.second)
        {
            SDL_DestroySurface(surface);
        }
    }

    // Free all SDL_Texture pointers
    for (auto &textureVec : textures)
    {
        for (auto *texture : textureVec.second)
        {
            SDL_DestroyTexture(texture);
        }
    }

    // Clear frames (no dynamic memory allocation here, so no need to delete)
    frames.clear();
}

void Object::SliceSpriteSheets(AssetID id, int rows, int cols)
{
    // Check if the texture dimensions exist
    if (textureDimensions.find(id) == textureDimensions.end())
    {
        SDL_Log("Texture dimensions not found for AssetID: %d", static_cast<int>(id));
        return;
    }

    // Get the stored dimensions
    float textureWidth = textureDimensions[id].first;
    float textureHeight = textureDimensions[id].second;

    // Calculate the size of each frame
    float frameWidth = textureWidth / cols;
    float frameHeight = textureHeight / rows;

    // Slice the spritesheet into frames
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            SDL_FRect frame = {col * frameWidth, row * frameHeight, frameWidth, frameHeight};
            frames[id].push_back(frame);
        }
    }

    SDL_Log("Sliced spritesheet for AssetID %d into %zu frames", static_cast<int>(id), frames[id].size());
}

void Object::DrawFrames(AssetID id, int startFrame, int endFrame, SDL_FRect *rect)
{
    // Check if the texture and frames exist
    if (textures.find(id) == textures.end() || textures[id].empty())
    {
        SDL_Log("Texture not found for AssetID: %d", static_cast<int>(id));
        return;
    }

    if (frames.find(id) == frames.end())
    {
        SDL_Log("Frames not found for AssetID: %d", static_cast<int>(id));
        return;
    }

    // Validate the frame range
    if (startFrame < 0 || endFrame >= frames[id].size() || startFrame > endFrame)
    {
        SDL_Log("Invalid frame range: %d to %d for AssetID: %d", startFrame, endFrame, static_cast<int>(id));
        return;
    }

    // Render each frame in the range
    for (int frame = startFrame; frame <= endFrame; ++frame)
    {
        SDL_RenderTexture(renderer, textures[id][0], &frames[id][frame], rect);
    }
}

float Object::GetGroundLevel(float x)
{
    return groundLevel;
}

void Object::DrawGround()
{
    // Render the ground texture to cover the entire window
    SDL_FRect dstrect = {0, 0, static_cast<float>(window_width), static_cast<float>(window_height)};
    if (textures.find(AssetID::Ground) == textures.end() || textures[AssetID::Ground].empty() || textures[AssetID::Ground][0] == nullptr)
    {
        SDL_Log("Ground texture is missing or invalid!");
        return;
    }

    SDL_RenderTexture(renderer, textures[AssetID::Ground][0], NULL, &dstrect);
}

void Object::UpdateCamera()
{
    // Define the camera's threshold
    const float cameraThresholdX = 100.0f; // Pixels
    const float cameraThresholdY = 100.0f;

    // Check if the player is outside the camera's threshold
    if (playerPosition.x - cameraPosition.x > cameraThresholdX)
    {
        cameraPosition.x = playerPosition.x - cameraThresholdX;
    }
    else if (cameraPosition.x - playerPosition.x > cameraThresholdX)
    {
        cameraPosition.x = playerPosition.x + cameraThresholdX;
    }

    if (playerPosition.y - cameraPosition.y > cameraThresholdY)
    {
        cameraPosition.y = playerPosition.y - cameraThresholdY;
    }
    else if (cameraPosition.y - playerPosition.y > cameraThresholdY)
    {
        cameraPosition.y = playerPosition.y + cameraThresholdY;
    }
}

void Object::Player(Direction direction, float deltaTime)
{
    // Update player position based on direction and velocity
    switch (direction)
    {
    case Direction::North:
        velocity.y = -playerSpeed; // Moving up (e.g., climbing)
        break;
    case Direction::South:
        velocity.y = playerSpeed; // Moving down
        break;
    case Direction::East:
        velocity.x = playerSpeed; // Moving right
        isFlipped = false;        // Ensure the sprite is not flipped
        break;
    case Direction::West:
        velocity.x = -playerSpeed; // Moving left
        isFlipped = true;          // Flip the sprite horizontally
        break;
    case Direction::None:
        velocity.x = 0; // No horizontal movement
        break;
    }

    // Apply gravity to the player's vertical velocity
    if (!isGrounded) // Only apply gravity if the player is not on the ground
    {
        velocity.y += gravity.strength * deltaTime;

        // Cap the fall speed to the maximum fall speed
        if (velocity.y > gravity.maxFallSpeed)
        {
            velocity.y = gravity.maxFallSpeed;
        }
    }

    // Update player position
    playerPosition.x += velocity.x * deltaTime;
    playerPosition.y += velocity.y * deltaTime;

    // Check if the player is grounded
    if (playerPosition.y >= groundLevel)
    {
        playerPosition.y = groundLevel;
        velocity.y = 0; // Stop falling
        isGrounded = true;
    }
    else
    {
        isGrounded = false;
    }

    // Handle jumping
    if (isJumping && isGrounded)
    {
        velocity.y = -jumpStrength; // Apply an upward force
        isGrounded = false;         // The player is no longer grounded
    }

    // Render the player
    if (velocity.x != 0 || velocity.y != 0)
    {
        DrawFrames(AssetID::Run, 0, frames[AssetID::Run].size() - 1, &playerRect);
    }
    else
    {
        DrawFrames(AssetID::Idle, 0, frames[AssetID::Idle].size() - 1, &playerRect);
    }

    // Update the camera position
    UpdateCamera();
}