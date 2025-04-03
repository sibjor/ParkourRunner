// C++ Standard libraries

#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

/* HERE FOLLOWS PROCESS DEFENITIONS */

enum class Process
{
    LOG,
    SELECT,
    READ,
    PARSE,
    WRITE,
    ERROR,

    SPAWN_OBJECT,
    SPAWN_PROCESS,
};

/* HERE FOLLOWS PROCESS STATUS*/

enum class ProcessStatus
{

    SCHEDULED,

    CLOSE_TO,
    FAR_FROM,
    HALFWAY,

    NOT_ACTIVE,
    ACTIVATING,
    ACTIVE,
    SHUTTING_DOWN,
    SELF_DESTRUCT,
    CLEANING_UP,
    IN_ERROR,
};

enum class ProcessPosition
{
    MAIN_THREAD,
    MAIN_LOOP,

    PARENT_POSITION,
    CHILD_POSITION,
    SIBLING_POSITION,
    SELF_POSITION,

    LAYER_SELF,
    LAYER_PARENT,
    LAYER_CHILD,
    LAYER_SIBLING,
};

