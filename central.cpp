#include "central.hpp"

class Profiler
{

public:
    /* Contructor of profiler
    - initializes both C and SDL timers
    */
    Profiler()
    {
        ProfilerSDLBegin("SDL Profiler initialized");
        ProfilerCBegin("C Profiler initialized");
    };

    /* Destructor of profiler
    - first stating the time passed
    - of both SDL and C timers
    - since last reset or
    - since initialization
    - then, afterwards
    - resets both SDL and C
    - timers to zero and then
    - frees the memory
    */
    ~Profiler()
    {
        ProfilerTailAll();
        ResetSDLTimer();
        ResetCTimer();
        free(this);
    };

    /* From head to tail, since initialization of SDL
    measuring time between parties defined below?
    - awaits verification
    - resetting the SDL timer when preferred
    */
    void ProfilerSDLBegin(std::string sequence);
    void ProfilerSDLEnd();
    void ResetSDLTimer()
    {
        beginSDLTimer = 0;
        tailCTimer = 0;
        differenceBetweenSDLTimers = 0;
    };
    /* From head to tails, recording and measuring
    - time passed between parties
    - resetting the C timer when preferred
    */
    void ProfilerCBegin(std::string sequence);
    void ProfilerCEnd();
    void ResetCTimer()
    {
        headCTimer = 0;
        tailCTimer = 0;
        differenceBetweenCTimers = 0;
    };

    /* If not wanting to use destructor
    - one is given the oppurtunity to
    - call both SDL & C timer endings
    - at once
    - Use destructor when resetting
    - the timers
    */
    void ProfilerTailAll(){
        ProfilerSDLEnd();
        ProfilerCEnd();
    }

private:
    clock_t headCTimer = 0;
    clock_t tailCTimer;
    unsigned int differenceBetweenCTimers = tailCTimer - headCTimer;

    unsigned int beginSDLTimer = 0;
    unsigned int tailCTimer;
    unsigned int differenceBetweenSDLTimers = tailCTimer - beginSDLTimer;
};

/* Class CharacterArtwork:
- Separation of concerns are implemented
- having listened to citations of speech performance
- by speaker, stating a function should be as small
- as possible, preferrably responsible for one single
- sequence of executed task of demand or interest
*/
class CharacterArtwork{

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
    void LoadMovementPack(std::string SpriteSheetDirectory){
        for(auto &entry : fs::directory_iterator(SpriteSheetDirectory)){
            surfacesMovementPack.push_back(IMG_Load(entry.path().c_str()));
            texturesMovementPack.push_back(SDL_CreateTextureFromSurface(renderer, surfacesMovementPack.back()));
        }
    };
    void LoadVaultPack(std::string SpriteSheetDirectory);
    void LoadAllSpriteSheets();
    
    private:
    // Movement pack
    std::vector<SDL_Surface *> surfacesMovementPack;
    std::vector<SDL_Texture *> texturesMovementPack;
    // Vault pack
    std::vector<SDL_Surface *> surfacesVaultPack;
    std::vector<SDL_Texture *> texturesVaultPack;
    // Movement & Vault pack together
    std::vector<SDL_Surface *> surfacesAllSpriteSheets;
    std::vector<SDL_Texture *> texturesAllSpriteSheets;

};