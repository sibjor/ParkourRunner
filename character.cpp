#include "character.hpp"

/* Class CharacterArtwork:
- Separation of concerns are implemented
- having listened to citations of speech performance
- by speaker, stating a function should be as small
- as possible, preferrably responsible for one single
- heads of executed task of demand or interest
*/

/* First step is to declare a vector, which
        - will store SDL_Surface pointers, which
        - will be loaded as SDL_Texture pointers
        - then call SDL_RenderTexture(renderer, texture, NULL, NULL)
        - then SDL_RenderPresent(renderer)
        - don't forget: art is of dimensions: 192x96 (pixels?)
        - you were told to implement similar dimensions of w & h
        - cited from teacher, referring to the practice of a GPU
        */

class CharacterArtwork
{

public:
    /* The constructor should be held
    - responsible of initialization
    - of one or both sprite sheets
    - of player character artwork
    - used in the game
    */
    CharacterArtwork();

    /* The destructor is responsible for
    - cleanup of player character artwork
    - of the game.
    */
    ~CharacterArtwork();

    /* Loading the asset packs of choice*/
    void LoadMovementPack(std::string SpriteSheetDirectory);
    void LoadVaultPack(std::string SpriteSheetDirectory);
    void LoadAllSpriteSheets();

private:
    // Movement pack
    std::vector<SDL_Surface *> surfacesMovementPack;
    std::vector<SDL_Texture *> texturesMovementPack;
    // Vault pack
    std::vector<SDL_Surface *> surfacesVaultPack;
    std::vector<SDL_Texture *> texturesVaultPack;
    // Movement & Vault pack combined
    std::vector<SDL_Surface *> surfacesAllSpriteSheets;
    std::vector<SDL_Texture *> texturesAllSpriteSheets;
};