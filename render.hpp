#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

// Global SDL objects
extern SDL_Window *window;
extern SDL_Renderer *renderer;

// Enum class for animation states
enum class AnimationState {
    Idle,
    InAir,
    Jumping,
    Landing,
    Roll,
    Run,
    Sprint,
    BasicVault,
    Climbing,
    Hanging,
    LongVault,
    OnTopClimbing,
    OnTopVault
};

enum class AnimationDirection{
    Left,
    Right,
    Up,
    Down,
    UpLeft,
    UpRight,
    DownLeft,
    DownRight
};

class AnimatedSprite {
public:
    AnimatedSprite();
    ~AnimatedSprite();

    // Load textures for all animation states
    void LoadTextures();

    // Slice a spritesheet into frames
    void SliceSpriteSheet(SDL_Texture* texture, AnimationState state);

    // Play the animation for the given state
    void PlayAnimation(AnimationState state, SDL_FRect* destRect, bool loop, bool isFlipped, int frameDelay);

    void SetDirection(AnimationDirection dir);

    AnimationDirection GetDirection() const;
        
private:
    std::unordered_map<AnimationState, std::vector<SDL_Texture*>> textures;
    std::unordered_map<AnimationState, std::vector<SDL_FRect>> frames;
    int frameDelay = 100; // Default delay in milliseconds
    AnimationDirection direction = AnimationDirection::Right; // Default direction
};