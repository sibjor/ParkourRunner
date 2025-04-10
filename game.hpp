#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

class Game
{
    public:
        Game();
        ~Game();
        void Init();
        void Cleanup();
        void HandleEvents();
        void Update();
};