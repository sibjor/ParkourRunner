#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include "profiler.hpp"
#include "data.hpp"

/*

    Please use this file to implemenet as much
    logic as possible for rendering artwork
    moving or not, background or foreground
    player sprite or whatever

    Try to reuse logic through inheritance and
    polymorphism as much as possible
*/


class Render
{
public:
    Render();
    ~Render();
    void Init();
    // Should finish with assigning all SDL_FRect objects
    // to the corresponding vectors
    void LoadAssets();
    void RenderScene();
    void CleanUp();

private:
    std::vector<SDL_Surface *> artwork;
    std::vector<SDL_Texture *> textures;
    std::vector<SDL_FRect*> player;
    std::vector<SDL_FRect*> ground;
    std::vector<SDL_FRect*> groundObjects;
    std::vector<SDL_FRect*> background_layer_0;
    std::vector<SDL_FRect*> background_layer_1;
};
