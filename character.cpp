#include "character.hpp"
#include "gameloop.hpp"

/* First step is to declare a vector, which
        - will store SDL_Surface pointers, which
        - will after "SDL_CreateTextureFromSurface"
        - be loaded as SDL_Texture pointers
        - then call SDL_RenderTexture(renderer, texture, NULL, NULL)
        - then SDL_RenderPresent(renderer)
        - don't forget: art is of dimensions: 192x96 (pixels?)
        - you were told to implement similar dimensions of w & h
        - cited from teacher, referring to the practice of a GPU
        */

std::vector<SDL_Surface *> surfacesMovementPack;
std::vector<SDL_Surface *> surfacesVaultPack;
std::vector<SDL_Texture *> texturesMovementPack;
std::vector<SDL_Texture *> texturesVaultPack;

const std::string MovementPackPNGDirectory = "assets/Basic movement pack/SpriteSheet/";
const std::string VaultPackPNGDirectory = "assets/Basic vault pack/SpriteSheet/";

////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Loading the surfaces of choice*/
bool CharacterArtwork::LoadMovementPackSurfaces()
{
    // Load the surfaces of the movement pack
    for (auto &entry : std::filesystem::directory_iterator(MovementPackPNGDirectory))
    {
        surfacesMovementPack.push_back(IMG_Load(entry.path().c_str()));
    }
};
bool CharacterArtwork::LoadVaultPackSurfaces()
{
    // Load the surfaces of the vault pack
    for (auto &entry : std::filesystem::directory_iterator(VaultPackPNGDirectory))
    {
        surfacesVaultPack.push_back(IMG_Load(entry.path().c_str()));
    }
};
bool CharacterArtwork::LoadAllSurfaces()
{
    // Load all surfaces
    LoadMovementPackSurfaces();
    LoadVaultPackSurfaces();
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Load the textures of choice*/
bool CharacterArtwork::LoadMovementPackTextures()
{
    // Load the textures of the movement pack
    for (auto &surface : surfacesMovementPack)
    {
        texturesMovementPack.push_back(SDL_CreateTextureFromSurface(renderer, surface));
    }
};
bool CharacterArtwork::LoadVaultPackTextures()
{
    // Load the textures of the vault pack
    for (auto &surface : surfacesVaultPack)
    {
        texturesVaultPack.push_back(SDL_CreateTextureFromSurface(renderer, surface));
    }
};
bool CharacterArtwork::LoadAllTextures()
{
    // Load all textures
    LoadMovementPackTextures();
    LoadVaultPackTextures();
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Wrapping up the wrappers above */

bool CharacterArtwork::LoadAndRenderAll()
{
    if (!LoadAllSurfaces())
    {
        SDL_Log("Couldn't load all surfaces: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    if (!LoadAllTextures())
    {
        SDL_Log("Couldn't load all textures: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    if (!RenderAll){
        SDL_Log("Couldn't render all textures: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    else
    {

        LoadAllSurfaces();
        LoadAllTextures();
        RenderAll();
    }

    return SDL_APP_CONTINUE;
};

/* Rendering the textures of choice*/
bool CharacterArtwork::RenderMovementPack()
{
    while (SDL_APP_CONTINUE)
    {
        for (auto &texture : texturesMovementPack)
        {
            SDL_RenderTexture(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
        }
    }
};
bool CharacterArtwork::RenderVaultPack()
{
    while (SDL_APP_CONTINUE)
    {
        for (auto &texture : texturesVaultPack)
        {
            SDL_RenderTexture(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
        }
    }
};
bool CharacterArtwork::RenderAll()
{
    RenderMovementPack();
    RenderVaultPack();
};