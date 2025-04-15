#pragma once

#include <map>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include "profiler.hpp"
#include "data.hpp"

enum class AssetID {
    Idle,
    Run,
    Jumping,
    InAir,
    Landing,
    Sprint,
    Roll,
    BasicVault,
    OnTopVault,
    LongVault,
    Climbing,
    OnTopClimbing,
    Hanging,
    Ground,
    ObstacleVault,
    ObstacleLongVault,
    ObstacleClimb,
    ObstacleHang,
    ObstacleTopClimb
};

enum class Direction
{
    None,    // No movement
    North,   // Up
    South,   // Down
    East,    // Right
    West,    // Left
    Northeast,
    Northwest,
    Southeast,
    Southwest
};

struct Velocity
{
    float x; // Horizontal speed
    float y; // Vertical speed
};

struct Gravity
{
    float strength;   // The strength of gravity (e.g., pixels per second squared)
    float maxFallSpeed; // The maximum speed the player can fall
};

/*

    Please use this file to implemenet as much
    logic as possible for rendering Assets
    moving or not, background or foreground
    DrawPlayer sprite or whatever

    Try to reuse logic through inheritance and
    polymorphism as much as possible
*/

extern const char *window_title;
extern const int window_width;
extern const int window_height;
extern const int window_flags;
extern SDL_Renderer *renderer;
extern SDL_Window *window;


class Object
{
public:
    Object();
    ~Object();
    void SliceSpriteSheets(AssetID id, int rows, int cols);
    void DrawFrames(AssetID id, int startFrame, int endFrame, SDL_FRect *rect);
    void DrawObject(AssetID id, SDL_FRect *rect, int frame);
    void DrawGround();
    void DrawObstacle(AssetID id, SDL_FRect *rect);
    void UpdateCamera();
    void Player(Direction direction, float deltaTime);
    float GetGroundLevel(float x);
    void GenerateMap();

    std::map<AssetID, std::vector<SDL_Surface*>> surfaces;
    std::map<AssetID, std::vector<SDL_Texture*>> textures;

private:

    // Add member variables and methods here
    std::map<AssetID, std::vector<SDL_FRect>> frames;
    std::map<AssetID, std::string> paths;
    std::map<AssetID, std::pair<float, float>> textureDimensions; // Store the dimensions of each texture
    SDL_FRect playerRect;          // The player's position and size
    SDL_FPoint playerPosition;     // The player's position
    Velocity velocity;             // The player's velocity
    Gravity gravity = {9.8f, 50.0f}; // Gravity strength and max fall speed
    float playerSpeed = 200.0f;    // The player's movement speed
    float jumpStrength = 300.0f;   // The strength of the player's jump
    bool isGrounded = false;       // Whether the player is on the ground
    bool isJumping = false;        // Whether the player is jumping
    bool isFlipped = false;        // Whether the sprite is flipped horizontally
    float groundLevel = 500.0f;    // The Y-coordinate of the ground
    SDL_FPoint cameraPosition;     // The camera's position
};