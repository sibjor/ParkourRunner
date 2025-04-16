#include "render.hpp"

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;
const char* window_title = "Validator 13";
int window_width = 1200;
int window_height = 1000;
Uint32 window_flags = SDL_EVENT_WINDOW_SHOWN;