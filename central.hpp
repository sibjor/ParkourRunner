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
        - Virtual functions can be overridden in the derived classes.
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
    STARTING,
    RUNNING,
    PAUSED,
    GAME_OVER,
    NEW_HIGHSCORE,
    CLEANUP,
    EXIT,
    ERROR,
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

enum class GameMenus : int
{
    PROLOUGUE,
    MAIN_MENU,
    HIGHSCORE_MENU,
    SETTINGS,
    CREDITS,
    GAME_OVER_MENU,
    ERROR,
};

enum class MenuBackground : int
{
    PROLOGUE,
    MAIN_MENU,
    GAME_OVER,
    SETTINGS,
    CREDITS,
    HIGHSCORE,
    ERROR,
};

enum class OutsideEnvironment : int
{
    LOWER_CLASS,
    MIDDLE_CLASS,
    UPPER_CLASS,
    PRISON_YARD,
    PARK,
    SCHOOL,

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


/* PLACE VARIABLES IN THEIR CLASS OF SCOPE!!! */

class RootLayer
{

public:
    /* Root Variables*/
    std::string lineSeparator = "----------------------------------------";
    std::string *name;
    std::string *address;
    std::vector<RootLayer *> *objects;

    /* Constructor of the first layer */
    RootLayer();

    /* Destructor of the first layer */
    virtual ~RootLayer();

    virtual void LoadObject();

    virtual void LoadAllObjects();

    // UTILITIES
    std::string CurrentDateTime();
    virtual std::string NavigateToPath(std::string path);
    virtual std::string NavigateToFile(std::string file);
    virtual std::string NavigateToDirectory(std::string directory);
    virtual std::string SelectContent(std::string fileNameContains);

    // SHUTDOWN
    virtual void QuitRootLayer();
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

class Artwork : RootLayer

{
public:
    /* Hardcoded animations separated, unfortunately necessary... */

    // Movement pack
    std::string idleAnim = "assets/Basic movement pack/SpriteSheet/Idle.png";
    std::string inAirAnim = "assets/Basic movement pack/SpriteSheet/in air.png";
    std::string jumpingAnim = "assets/Basic movement pack/SpriteSheet/jumping.png";
    std::string landingAnim = "assets/Basic movement pack/SpriteSheet/landing.png";
    std::string rollAnim = "assets/Basic movement pack/SpriteSheet/Roll.png";
    std::string runAnim = "assets/Basic movement pack/SpriteSheet/run.png";
    std::string sprintAnim = "assets/Basic movement pack/SpriteSheet/sprint.png";

    // Vault pack
    std::string basicVaultAnim = "assets/Basic vault pack/SpriteSheet/Basic vault.png";
    std::string climbingAnim = "assets/Basic vault pack/SpriteSheet/climbing.png";
    std::string hangingAnim = "assets/Basic vault pack/SpriteSheet/hanging.png";
    std::string longVaultAnim = "assets/Basic vault pack/SpriteSheet/long vault.png";
    std::string onTopClimbingAnim = "assets/Basic vault pack/SpriteSheet/On top climbing.png";
    std::string onTopVaultAnim = "assets/Basic vault pack/SpriteSheet/on top vault.png";

    Artwork();
    ~Artwork();

    // ARTWORK RELATED
    void InitArtwork();

    void InitAudio();

    void InitGenerator();

    virtual void RenderAllObjects();

    virtual void RenderObject(std::string name);

    virtual void RenderAllTextures();

    virtual void RenderAllSurfaces();

    virtual void RenderAllTexturesAndSurfaces();

    virtual void RenderObject();

    // AUDIO

    void HandleMusic();

    void HandleSound();

private:
};

class Handler : RootLayer
{
public:
    // HANDLERS

    void HandleCollision();

    void HandleAnimation();

    void HandleState();

    void HandleInput();

    void HandleEvent();

private:
};

class Scene : RootLayer
{
public:
    // SCENE RELATED
    virtual void InitScene(enum class SceneType sceneType);
    virtual void RenderScene();
    virtual void LoadScene();
    virtual void CleanupScene();
    virtual void LoopScene();
    /* UpdateScene()
    - */
    virtual void UpdateScene();
    virtual void HandleScene();
    virtual void HandleSceneEvents();
    virtual void HandleSceneInput();

private:
};

class UI : Scene
{
public:
    // NON-GAME, UI RELATED
    virtual void Prolougue();

    virtual void MainMenu();

    virtual void Settings();

    virtual void Credits();

    virtual void GameOver();

    virtual void Highscore();

    virtual void Pause();

private:
};