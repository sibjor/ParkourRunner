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

enum class UI : int 
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

enum class Molecule : int
{
    ATOM,
    CATALYST,
    MOLECULE,
};

enum SynthesisProtocol : int
{

};

enum class Compound : int
{
    WATER,
    CARBON_DIOXIDE,
    AMMONIA,
    METHANE,
    ETHANOL,
    GLUCOSE,
    SODIUM_CHLORIDE,
    CALCIUM_CARBONATE,
    SULFURIC_ACID,
    ACETIC_ACID,
};
enum class Catalyst : int
{
    ENZYME,
    METAL,
    NON_METAL,
    ORGANIC,
    INORGANIC,
};

/* PLACE VARIABLES IN THEIR CLASS OF SCOPE!!! */

class RootLayer
{

public:

    std::string lineSeparator = "----------------------------------------";
    std::string *name;
    std::string *address;
    std::vector <RootLayer*> *objects;

    // PROFILER VARIABLES
    clock_t start = clock();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    void CountTicksFrom();
    void CountTicksTo();

    // endTime - startTime = elapsedTime
    void PrintElapsedTime(std::string description);

    /* Constructor of the first layer */
    RootLayer();

    /* Destructor of the first layer */
    virtual ~RootLayer();

    // CALL IN CONSTRUCTOR
    void InitArtwork();
    void InitAudio();
    void InitGenerator();
    void InitProgram();

    // CALL IN DESTRUCTOR

    // NON-GAME
    virtual void Prolougue();
    virtual void MainMenu();
    virtual void Settings();
    virtual void Credits();
    virtual void GameOver();
    virtual void Highscore();
    virtual void Pause();

    // UTILITIES
    std::string CurrentDateTime();
    virtual std::string NavigateToPath(std::string path);
    virtual std::string NavigateToFile(std::string file);
    virtual std::string NavigateToDirectory(std::string directory);
    virtual std::string SelectContent(std::string fileNameContains);

    // SHUTDOWN
    virtual void QuitRootLayer();

    // GRAPHICS
    virtual void LoadObject();

    virtual void LoadAllObjects();

    virtual void RenderAllObjects();

    virtual void RenderObject(std::string name);

    virtual void RenderAllTextures();

    virtual void RenderAllSurfaces();

    virtual void RenderAllTexturesAndSurfaces();

    virtual void RenderObject();

    // HANDLERS
    virtual void HandleState();

    virtual void HandleInput();

    virtual void HandleEvent();

    virtual void HandleCollision();

    virtual void HandleAnimation();

    virtual void HandleSound();

    virtual void HandleMusic();

};