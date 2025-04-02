/* RootLayer:
    Surrounding source files implement this header.
    Acts as a "central" or "middleman" for the whole project.
    It is designed to contain nearly all the necessary -
    includes and declarations for the project such as:
    - C++ Standard Libraries
    - Third-party Libraries
    - Enums
    - Classes
    - Functions
    - Variables
    - Constants
    - Macros
    - ...
    NOTE:
        - All classes derives from the RootLayer class.
        - When so - there is no need for constructors/destructors in the derived classes.
        - Profiling is implemented in the RootLayer class.
        - Varibles are declared in their respective scope or class.
        - Enums are meant to be implemented as a "switch" or "case" statement.
        - functions can be overridden in the derived classes.
    */
// C++ Standard libraries

#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>

// Third-party libraries
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 810
#define WINDOW_TITLE "ParkourRunner2DHorizontal"

/* std::filesystem i pretty young...
- implemented and standardized
- as late/early as the
- C++17 standard
*/
namespace fs = std::filesystem;

enum class RootLayerLayer : int
{
    INITIALIZE,
    ACTIVE,
    CLEANUP,
    SHUTDOWN,
    ERROR,
};

enum class MenuScene : int
{
    PROLOGUE,
    MAIN_MENU,
    SETTINGS,
    CREDITS,
    GAME_OVER,
    HIGHSCORE,
    ERROR,
};

enum class GameScene : int
{
    INTRO,
    DISTRICT_LOWER_CLASS,
    DISTRICT_MIDDLE_CLASS,
    DISTRICT_UPPER_CLASS,
    PRISON_YARD,
    PRISON_CELL,
    PRISON_LABOUR,
    TRAFFIC_IN_AIR,
    TRAFFIC_ON_GROUND,
    GAME_PAUSED,
    GAME_OVER,

};
enum class GameState : int

{
    // MENUS
    PROLOUGUE,
    MAIN_MENU,
    HIGHSCORE_MENU,
    SETTINGS,
    CREDITS,
    GAME_OVER_MENU,

    // IN-GAME
    INTRO,
    ACTIVE,
    PAUSED,
    ACHIEVEMENT,
    EXIT,
    ERROR,
};

enum class GameMood : int
{
    HAPPY,
    SAD,
    ANGRY,
    CONFUSED,
    SCARED,
    EXCITED,
    BORED,
    RELAXED,
    NERVOUS,
    CALM,
};

enum class Color : int
{
    RED,
    GREEN,
    BLUE,
    WHITE,
    BLACK,
    YELLOW,
    ORANGE,
    PURPLE,
    PINK,
    BROWN,
    GREY,
};

enum class Shapes2D : int
{
    LINE,
    POINT,
    TRIANGLE,
    RECTANGLE,
    CIRCLE,
    CONE,
    CONTOUR,
};

enum class UIComponent : int
{
    BUTTON,
    TEXT,
    IMAGE,
    SLIDER,
    CHECKBOX,
    RADIOBUTTON,
    DROPDOWN,
};

enum class Environment : int
{
    LOWER_CLASS,
    MIDDLE_CLASS,
    UPPER_CLASS,
    PRISON_YARD,
    PARK,
    SCHOOL,
    SEWER,
    LABOUR_CAMP,
    TRAFFIC_IN_AIR,
};

enum class SynthesisCompund : int
{
    REAGENT,
    CATALYST,
    SOLVENT,
};

/* HERE FOLLOWS THE CHEMISTRY ENUM CLASSES */

enum class PeriodicTable : int
{
    HYDROGEN,
    HELIUM,
    LITHIUM,
    BERYLLIUM,
    BORON,
    CARBON,
    NITROGEN,
    OXYGEN,
    FLUORINE,
    NEON,
    SODIUM,
    MAGNESIUM,
    ALUMINUM,
    SILICON,
    PHOSPHORUS,
    SULFUR,
    CHLORINE,
    ARGON,
};

enum class ChemicalBond : int
{
    SINGLE_BOND,
    DOUBLE_BOND,
    TRIPLE_BOND,
    IONIC_BOND,
    COVALENT_BOND,
    POLAR_COVALENT_BOND,
    METALLIC_BOND,
};

enum class ChemicalState : int
{
    SOLID,
    LIQUID,
    GAS,
};

enum class PHScale : int
{
    ACIDIC,
    NEUTRAL,
    ALKALINE,
};

enum class ChemicalReaction : int
{
    REDUCTION,
    OXIDATION,
    NATURALIZATION,
};

enum class Acid : int
{
    SULFURIC_ACID,
    NITRIC_ACID,
    HYDROCHLORIC_ACID,
    ACETIC_ACID,
    PHOSPHORIC_ACID,
};

enum class Base : int
{
    SODIUM_BICARBONATE,
    SODIUM_HYDROXIDE,
    POTASSIUM_HYDROXIDE,
    CALCIUM_HYDROXIDE,
    MAGNESIUM_HYDROXIDE,
    AMMONIUM_HYDROXIDE,
};

enum class Solvent : int
{
    WATER,
    ETHANOL,
    ACETONE,
    METHANOL,
    ETHYL_ACETATE,
    ACETIC_ACID,
    HEXANE,
    BENZENE,
    TOLUENE,
    CHLOROFORM,
};

enum class Catalyst : int
{
    PLATINUM,
    PALLADIUM,
    NICKEL,
    IRIDIUM,
    RHODIUM,
    RUTHENIUM,
    OSMIUM,
    TUNGSTEN,
    MOLYBDENUM,
    TANTALUM,
};

enum class MoleculeType : int
{
    HORMONE,
    NEUROTRANSMITTER,
    INHIBITOR,
    TOXIN,
    PESTICIDE,
    ENZYME,
    PROTEIN,
    CARBOHYDRATE,
    LIPID,
    DISINFECTANT,
    ANTIBIOTIC,
    MUTAGEN,

};

/* HERE FOLLOWS MEDICAL CONDITIONS AND MEDICINES */

enum class MedicalCondition : int
{
    ANXIETY,
    DEPRESSION,
    SCHIZOPHRENIA,
    BIPOLAR_DISORDER,
    PTSD,
    OCD,
    ADHD,
    AUTISM,
    EATING_DISORDER,
    ADDICTION,
    INSOMNIA,
};

enum class DrugType : int
{
    STIMULANT,
    DEPRESSANT,
    HALLUCINOGEN,
    ANALGESIC,
    ANESTHETIC,
    ANTIDEPRESSANT,
    ANTIPSYCHOTIC,
    ANXIOLYTIC,
    SEDATIVE,
    TRANQUILIZER,
    VACCINE,
    ANTIBODY,
};

/* Character Enum Classes */

enum class CharacterAge : int
{
    BABY,
    CHILD,
    TEENAGER,
    ADULT,
    OLD_ADULT,
    SENIOR,
};

enum class CharacterSex : int
{
    MALE,
    FEMALE,
    TRANS,
    NON_BINARY,
};

enum class CharacterOccupation : int
{
    // Closer implementations
    LABOURER,
    GUARD,
    SCIENTIST,
    ENGINEER,
    ARCHITECT,
    DOCTOR,
    AGENT,

    // Other occupations
    UNEMPLOYED,
    STUDENT,
    POLICE_OFFICER,
    FIRE_FIGHTER,
    PARAMEDIC,
    NURSE,
    TEACHER,
    ARTIST,
    MUSICIAN,
    WRITER,

};

enum class CharacterMood : int
{
    HAPPY,
    SAD,
    ANGRY,
    CONFUSED,
    SCARED,
    EXCITED,
    BORED,
    RELAXED,
    NERVOUS,
    CALM,
};

enum class CharacterStatus : int
{
    ALIVE,
    DEAD,
    TIRED,
    EXHAUSTED,
    HUNGRY,
    THIRSTY,
    WEAK,
    HEALTHY,
    STRONG,
    INJURED,
    SICK,
    RECOVERING,
    UNCONSCIOUS,
    ON_SUBSTANCE,
    INCAPACITATED,
    PARALYZED,
    INFECTED,
    VACCINATED,
    IMMUNE,
    INFERTILE,
};

enum class CharacterTrait : int
{
    BRAVE,
    COWARDLY,
    HONEST,
    DISHONEST,
    LOYAL,
    BETRAYING,
    INTELLIGENT,
    DUMB,
    STRONG,
    WEAK,
    FAST,
    SLOW,
};

/* Faction related */

enum class Faction : int
{
    // Your faction
    THE_SILENCE,

    // Evil factions
    THE_CHEMICAL_SOCIETY,
    GUARDIANS_OF_THE_CHAIN,

    // Lower strata tribes
    SIMPLY_ARMED_RELATIONSHIPS,
    SHEPHERDS_OF_THE_APOCALYPSE,
    CARVERS_OF_HISTORY,
    A_WANDERERS_PEACE,
    THE_ROYAL_HONOR,

};

/* More enum classes to add such as blockchain hosted trading,
price of hired blades, taxi, insurances, political voting, bribing etc..
*/

/* PLACE VARIABLES IN THEIR CLASS OF SCOPE!!! */

class RootLayer
{

public:
    /* Root Variables*/
    std::string lineSeparator = "----------------------------------------";
    std::string *name;
    std::string *address;
    std::vector<RootLayer *> *objects;

    RootLayer();

    ~RootLayer();

    void LoadObject();

    void LoadAllObjects();

    // UTILITIES
    std::string CurrentDateTime();
    std::string NavigateToPath(std::string path);
    std::string NavigateToFile(std::string file);
    std::string NavigateToDirectory(std::string directory);
    std::string SelectContent(std::string fileNameContains);

    // SHUTDOWN
    void QuitRootLayer();

private:
};

class Profiler : RootLayer
{
public:
    // PROFILER VARIABLES
    clock_t start = clock();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    Profiler();
    ~Profiler();

    void CountTicksFrom();
    void CountTicksTo();

private:
};

class GameLayer : RootLayer
{
public:
    // CELSIUS SCALE
    std::vector<int> celsiusScale;

    GameLayer()
    {
        // Initialize the Celsius scale from -273 to 1000
        // Resulting in a vector of integers
        // with 1274 elements
        for (int i = -273; i <= 1000; ++i)
        {
            celsiusScale.push_back(i);
        }
    }
    ~GameLayer()
    {
        celsiusScale.clear();
    }

private:
};

class Artwork : GameLayer
{
public:
    // Player asset paths
    // Movement pack

    std::vector<std::string> playerMovementPack {
        "assets/Basic movement pack/SpriteSheet/Idle.png",
        "assets/Basic movement pack/SpriteSheet/in air.png",
        "assets/Basic movement pack/SpriteSheet/jumping.png",
        "assets/Basic movement pack/SpriteSheet/landing.png",
        "assets/Basic movement pack/SpriteSheet/Roll.png",
        "assets/Basic movement pack/SpriteSheet/run.png",
        "assets/Basic movement pack/SpriteSheet/sprint.png",
    };

    // Vault pack
    std::vector<std::string> playerVaultPack {
        "assets/Basic vault pack/SpriteSheet/Basic vault.png",
        "assets/Basic vault pack/SpriteSheet/climbing.png",
        "assets/Basic vault pack/SpriteSheet/hanging.png",
        "assets/Basic vault pack/SpriteSheet/long vault.png",
        "assets/Basic vault pack/SpriteSheet/on top climbing.png",
        "assets/Basic vault pack/SpriteSheet/on top vault.png",
    };

    Artwork();
    ~Artwork();

    /* Audio */
    void InitAudio();

    void PlaySound();
    void PlaySoundEffect();

    void PlayVoice(Character *actor, CharacterMood *actorMood);
    void PlayMurmurSound(Dialouge *dialogue, std::vector<Character *> *actors, CharacterMood *murmurMood);

    /* Theme music of the game*/
    void PlayThemeMusic();
    /* Cool audio effects loading new menus or save-games */
    void EnterSceneSound(GameState *gameState);
    /* Dependent on the in-game mood and status, stated in GameMood enum class */
    void PlaySoundtrack(GameMood *gameMood);

    /* Video */

    void InitVideo();

    /* Insert any object to return a vector of its fields */
    std::vector<std::string> PrepareAssets();
    std::vector<SDL_Surface *> ReturnSurfaces(std::vector<std::string> *assetsVector);
    std::vector<SDL_Texture *> ReturnTextures(std::string *surface, int *width, int *height);

    /* For stuff standing still, holding position */
    void RenderStatic(SDL_Texture *texture, int *width, int *height);
    /* For stuff breathing, moving, running, jumping etc.. */
    void RenderDynamic(std::vector<SDL_Texture *> textures, int frameRate);
    /* Background for the specific environment
    - Enum class "Environment" as parameter
    */
    void RenderBackground(Environment *environment);

private:
};

class Character : GameLayer
{
public:
private:
    // Characters are referred to by nick name
    std::string nickName;
    // The faction enum class
    Faction faction;
    // Character stats
    int health;
    int stamina;
    int strength;
    int speed;
    int agility;
    int intelligence;
    int charisma;
    int luck;
};

class Player : Character
{
public:
    Player();
    ~Player();

private:
};

class Dialouge : Artwork
{
public:
    Dialouge();
    ~Dialouge()
    {
        delete publicSpeechIndex;
        delete smallTalkIndex;
        delete repliqueIndex;
        delete thoughtIndex;
        delete narratorIndex;
        delete memoryIndex;
    };

    /* Similar to a comic-style implementation */
    void InitDialogue();
    // For when the mayor talks in public
    void PublicSpeech(std::string comment, int conversationIndex, Character *actor);
    void PublicSpeechContinue(std::string subComment, int conversationIndex, Character *actor);
    // For citizens talking to each other
    void SmallTalk(std::string comment, int conversationIndex, Character *actor);
    void SmallTalkContinue(std::string subComment, int conversationIndex, Character *actor);
    void Murmur(std::vector<Character *> actors = {}, Dialouge *dialogue = nullptr);
    // Dialogue in private between two characters
    void Replique(std::string comment, int conversationIndex, Character *actor);
    void RepliqueContinue(std::string subComment, int conversationIndex, Character *actor);
    void Thought(std::string thought, int conversationIndex, Character *actor);
    void ThoughtContinue(std::string subThought, int conversationIndex, Character *actor);
    void Narrator(std::string text, int conversationIndex, Character *actor);
    void NarratorContinue(std::string subText, int conversationIndex, Character *actor);
    void Memory(std::string image, int conversationIndex, Character *actor);
    void MemoryContinue(std::string subImage, int conversationIndex, Character *actor);

private:
    // Dialogue variables
    int *publicSpeechIndex;
    int *smallTalkIndex;
    int *repliqueIndex;
    int *thoughtIndex;
    int *narratorIndex;
    int *memoryIndex;
};

class Handler : RootLayer
{
public:
    // HANDLERS
    void HandleInput();
    void HandleCollision();
    void HandleAnimation();
    void HandleState();
    void HandleEvent();

private:
};

class Scene : RootLayer
{
public:
    // SCENE RELATED
    void InitScene(enum class SceneType sceneType);
    void RenderScene();
    void LoadScene();
    void CleanupScene();
    void LoopScene();
    /* UpdateScene()
    - */
    void UpdateScene();
    void HandleScene();
    void HandleSceneEvents();
    void HandleSceneInput();

private:
};

class UI : Scene
{
public:
    // NON-GAME, UI RELATED
    void Prolougue();

    void MainMenu();

    void Settings();

    void Credits();

    void GameOver();

    void Highscore();

    void Pause();

private:
};