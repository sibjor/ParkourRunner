#pragma once

#include "render.hpp"


class GameManager : public AssetManager
{
public:
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