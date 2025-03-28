#pragma once

/* Root:
    "A "central" and/or
    "middleman" between
    common files of the
    project... It contains
    several centralized
    implementations, such as:
    - Libraries
    - Constants
    - Macros
    - Flags
    - Variables
    - Functions
    - virtual destructors
    - etc...
    */

// C++ Standard libraries
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
#include <algorithm>

// C Standard libraries
#include <stdio.h>
#include <time.h>

// Third-party libraries
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

// Self defined headers
#include "profiler.hpp"
#include "artwork.hpp"
#include "gameloop.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960

/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

/* std::filesystem i pretty young...
- implemented and standardized
- as late/early as the
- C++17 standard
*/
namespace fs = std::filesystem;

enum class RootLayer : int
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

enum class GameMenu : int
{
    PROLOUGUE,
    MAIN_MENU,
    SETTINGS,
    CREDITS,
    GAME_OVER_MENU,
    HIGHSCORE_MENU,
    ERROR,
};

enum class UI : int{
    BUTTON,
    TEXT,
    CHECKBOX,
    SLIDER,
    DROPDOWN,
    TOGGLE,

};

enum class Color : int{
    RED,
    GREEN,
    BLUE,
    WHITE,
};

enum class Shape2D : int{
    CIRCLE,
    SQUARE,
    TRIANGLE,
    RECTANGLE,
};

class Root
{
public:
    /* Constructor
    - prints initialization
    status to the console */
    Root(std::string name);
    /* virtual ~Root()

    - Free's memory
    - Used to ensure that the correct destructor
    is called when an object of a derived class
    is deleted via a pointer to the base class


    NOTE:
    - Objects of derived classes will call.
    both the base class destructor and
    their own destructor when deleted
    through polymorphism.

    - e.g: Root* exampleObj = new Derived();
    */
    virtual ~Root();

    // VARIABLES
    std::string *name;
    clock_t *timeBegun;
    clock_t timeElapsed;
    std::string lineSeparator = "----------------------------------------";

    // INITIALIZATION
    virtual void InitApplication();
    // PROFILING
    clock_t InitProfiler();
    std::string TicksSinceStart();
    std::string TicksSinceSpecificStart();

    // UTILITIES
    virtual std::string SpecifyPath(std::string path);
    virtual std::string SpecifyFile(std::string file);
    virtual std::string SpecifyDirectory(std::string directory);
    virtual std::string SelectAll(std::string included);
    std::string CurrentDateTime();

    // OBJECTS
    virtual void InitObject();
    virtual void InitAllObjects();

    // ADDITION
    virtual void AddObject(Root *object);
    virtual void AddAllObjects(std::vector<Root *> list);

    // CLEANUP
    virtual void CleanupObject(Root *object);

    virtual void CleanupAllObjects(std::vector<Root *> list);

    // SHUTDOWN
    virtual void QuitRoot();

    // GRAPHICS
    virtual void LoadObject();

    virtual void LoadAllObjects();

    virtual void RenderAllObjects();

    virtual void RenderObject(std::string name);

    virtual void RenderAllTextures();

    virtual void RenderAllSurfaces();

    virtual void RenderAllTexturesAndSurfaces();

    virtual void RenderObject();

    // UPDATE

    virtual void UpdateSingle(Root* object);
    virtual void UpdateListed(std::vector<Root *> list);

    // HANDLERS
    virtual void HandleState();

    virtual void HandleInput();

    virtual void HandleEvent();

    virtual void HandleCollision();

    virtual void HandleAnimation();

    virtual void HandleSound();

    virtual void HandleMusic();

    /* GetName()
    - returns the name of the object, as string
    */
    std::string *GetSetName(std::string name);

    /* GetAddress()
    - returns the address of the object, as string*/
    std::string GetSetAddress();

private:
    std::string address;

    std::vector<Root *> objectsList;
};