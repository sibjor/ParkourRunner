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

enum class FirstLayer : bool
{
    INITIALIZE,
    ACTIVE,
    CLEANUP,
    SHUTDOWN,
    ERROR,
};
enum class GameState : bool

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

enum class GameMenu : bool
{
    PROLOUGUE,
    MAIN_MENU,
    SETTINGS,
    CREDITS,
    GAME_OVER_MENU,
    HIGHSCORE_MENU,
    ERROR,
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

    /* GetName()
    - returns the name of the object, as string
    */
    std::string SetGetName(std::string name);

    /* GetAddress()
    - returns the address of the object, as string*/
    std::string GetAddress();

private:
    std::string name;
    std::string address;
};