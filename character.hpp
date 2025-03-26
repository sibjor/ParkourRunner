#include "central.hpp"

/* Class CharacterArtwork:
- Separation of concerns are implemented
- having listened to citations of speech performance
- by speaker, stating a function should be as small
- as possible, preferrably responsible for one single
- heads of executed task of demand or interest
*/
class CharacterArtwork
{

public:
    // Movement pack
    static std::vector<SDL_Surface *> surfacesMovementPack;
    static std::vector<SDL_Texture *> texturesMovementPack;
    // Vault pack
    static std::vector<SDL_Surface *> surfacesVaultPack;
    static std::vector<SDL_Texture *> texturesVaultPack;

    /* The constructor should be held
    - responsible of initialization
    - of one or both sprite sheets
    - of player character artwork
    - used in the game
    */
   CharacterArtwork::CharacterArtwork()
    {
        // Initialize and render the surfaces and textures
        LoadAndRenderAll();
    };

    /* The destructor is responsible for
    - cleanup of player character artwork
    - of the game.
    */
    ~CharacterArtwork()
    {
        // Free memory
        free(this);
    };

    /* Loading the surfaces of choice*/
    bool LoadMovementPackSurfaces();
    bool LoadVaultPackSurfaces();
    bool LoadAllSurfaces();

    /* Loading the textures of choice*/
    bool LoadMovementPackTextures();
    bool LoadVaultPackTextures();
    bool LoadAllTextures();

    /* Rendering the textures of choice
        - as below also possibly
        - loading both surface
        - and textures in
        - advance...
        */
    bool LoadAndRenderAll();
    /* Not as powerful */
    bool RenderMovementPack();
    bool RenderVaultPack();
    bool RenderAll();

private:
};