#pragma once

#include "central.hpp"

/* Class Artwork:
- Separation of concerns are implemented
- having listened to citations of speech performance
- by speaker, stating a function should be as small
- as possible, preferrably responsible for one single
- heads of executed task of demand or interest
*/


class Artwork
{

public:

    /* Constructor */
    Artwork();

    /* Destructor */
    ~Artwork();

    /* Search and load .png files of the directory */

    /* Initialize .png files as SDL_Surface:s */

    /* Initialize SDL_Surface:s as SDL_Texture:s*/

    /* Load*/

private:
    /* Surfaces and textures */
    std::vector<SDL_Surface *> surfaces;
    std::vector<SDL_Texture *> textures;

    /* Vector pointer containing
    - Hardcoded paths to artwork directories */
    std::vector<std::string*> artworkDirectories;
     
};