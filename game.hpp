#pragma once

#include "render.hpp"

class Game : public Level, public Sprite
{
public: 
    Game();
    ~Game();
    void Init();
    void Run();
    void Render();
    void HandleInput(SDL_Event &event);
    void Update();
    void Cleanup();
private:
};