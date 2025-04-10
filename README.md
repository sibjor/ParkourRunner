# Runner

## About

- Author: [sibjor](https://www.github.com/sibjor), Sixten Algot Björling
- Location: Forsbergs School, Kingdom of Sweden, Stockholm
- Issued by: Sebastian Jensen

## Project Dependencies

```mermaid
flowchart TD
    A(C Standard Lib)
    B(C++ Standard Lib)
    C(SDL)
    D(SDL_image)
    E(SDL_mixer)
    F(profiler.hpp) 
    G(time.hpp) 
    H(data.hpp)
    I(main.cpp)
    J{Validator 13 by sibjor@github}
    K(game.hpp)

    A --> C
    A --> D
    A --> E

    C --> K
    D --> K
    E --> K

    B --> G
    B --> H
    B --> F

    G --> F

    H --> I
    F --> I
    K --> I

    I --> J

```
## Important 

- [Exporting with emscripten](https://wiki.libsdl.org/SDL3/README/emscripten)
- [SDL GPU API](https://wiki.libsdl.org/SDL3/CategoryGPU)
- [clock_t C++](https://en.cppreference.com/w/c/chrono/clock_t)
- [SDL_GetTicks](https://wiki.libsdl.org/SDL3/SDL_GetTicks)

## Good to know
- ***central.hpp*** is meant to finally be a pre-compiled header
- All planned usage of externally produced materials follows permitted terms stated in the relative license copy.

## IMPLEMENTATION

- Threads arent used so far, [read why](https://wiki.libsdl.org/SDL3/README/emscripten)

- Stuff are meant to be visualized in tree models or charts

- Program first initializes the ***root object***
- the ***root object*** is defined in ***mainloop.cpp***
- the ***main loop*** is also defined there
- Parent object spawns their objects from ***layer 1***
- All objects except Root are spawned in a vector
- Child objects are spawned in a ***layer*** above the parent
- Objects are part of a ***tree*** structure

- Paths to files are defined in ***data***
- ***data*** contains .csv files
- path to ***data*** is defined in ***filesystem.hpp***


## Stuff I've learnt:

- GPU calculation symmetric dimensions of pixels, e.g. 100x100 not 100x92 by default
- Vector implementation
- SDL library (basic knowledge by now)
- 

```