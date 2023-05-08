#pragma once

#include "SDL.h"
#include "SDL_video.h"

class GlRenderer{
public:
    SDL_Window *_window;

    void init();
    void run();
};