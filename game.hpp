#pragma once

#include "render.hpp"

class GameManager : public AssetManager
{
public:
    SDL_Window *window = nullptr;
    const char *window_title = "Validator 13";
    int window_width = 1200;
    int window_height = 1000;
    Uint32 window_flags = SDL_EVENT_WINDOW_SHOWN;
    
    GameManager();
    ~GameManager();

    void Init();
    void LoadResources();
    void PrepareArtwork();

    void Run();
    void Render();
    void Update();
    void HandleInput(SDL_Event &event);

    void Prologue();
    void LoadingScreen();
    void GameOverScreen();

    void MainMenu();
    void PauseMenu();
    void GameOverMenu();

    void NewGame();
    void LoadGame();
    void SaveGame();
    void ExitGame();
    void RestartGame();
    void ResumeGame();

    void Pause();
    void Settings();
    void Credits();

    void Cleanup();
    void Quit();

private:
};