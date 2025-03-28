#include "artwork.hpp"

/* Constructor */
Artwork::Artwork(){
    std::cout << "Initializing Artwork..." << std::endl;
}

/* Destructor */
Artwork::~Artwork()
{
    // Free the surfaces
    for (auto &surface : surfacesMovementPack)
    {
        SDL_DestroySurface(surface);
    }
    for (auto &surface : surfacesVaultPack)
    {
        SDL_DestroySurface(surface);
    }

    // Free the textures
    for (auto &texture : texturesMovementPack)
    {
        SDL_DestroyTexture(texture);
    }
    for (auto &texture : texturesVaultPack)
    {
        SDL_DestroyTexture(texture);
    }

    // Free memory
    free(this);
}
/* Loading the surfaces of choice*/
bool Artwork::LoadMovementPackSurfaces()
{
    // Load the surfaces of the movement pack
    for (auto &entry : std::filesystem::directory_iterator(MovementPackPNGDirectory))
    {
        surfacesMovementPack.push_back(IMG_Load(entry.path().c_str()));
    }
};
bool Artwork::LoadVaultPackSurfaces()
{
    // Load the surfaces of the vault pack
    for (auto &entry : std::filesystem::directory_iterator(VaultPackPNGDirectory))
    {
        surfacesVaultPack.push_back(IMG_Load(entry.path().c_str()));
    }
};
bool Artwork::LoadAllSurfaces()
{
    // Load all surfaces
    LoadMovementPackSurfaces();
    LoadVaultPackSurfaces();
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Load the textures of choice*/
bool Artwork::LoadMovementPackTextures()
{
    // Load the textures of the movement pack
    for (auto &surface : surfacesMovementPack)
    {
        texturesMovementPack.push_back(SDL_CreateTextureFromSurface(renderer, surface));
    }
};
bool Artwork::LoadVaultPackTextures()
{
    // Load the textures of the vault pack
    for (auto &surface : surfacesVaultPack)
    {
        texturesVaultPack.push_back(SDL_CreateTextureFromSurface(renderer, surface));
    }
};
bool Artwork::LoadAllTextures()
{
    // Load all textures
    LoadMovementPackTextures();
    LoadVaultPackTextures();
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Wrapping up the wrappers above */

bool Artwork::LoadAndRenderAll()
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
    if (!RenderAll)
    {
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
bool Artwork::RenderMovementPack()
{
    for (auto &texture : texturesMovementPack)
    {
        SDL_RenderTexture(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    return SDL_APP_CONTINUE;
};
bool Artwork::RenderVaultPack()
{
    for (auto &texture : texturesVaultPack)
    {
        SDL_RenderTexture(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    return SDL_APP_CONTINUE;
};
bool Artwork::RenderAll()
{
    RenderMovementPack();
    RenderVaultPack();
    return SDL_APP_CONTINUE;
};