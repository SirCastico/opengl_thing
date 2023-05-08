#include "gl_renderer.hpp"
#include "SDL.h"
#include "SDL_error.h"
#include "SDL_video.h"
#include <stdexcept>
#include <glad/gl.h>

void GlRenderer::init(){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)<0){
        throw std::runtime_error(SDL_GetError());
    }
    _window = SDL_CreateWindow(
        "yep", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        800, 
        600, 
        SDL_WINDOW_OPENGL
    );
    if(_window==nullptr){
        SDL_Quit();
        throw std::runtime_error("failed window create");
    }

    SDL_GL_CreateContext(_window);

    gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

    glViewport(0, 0, 800, 600);
}

void GlRenderer::run(){
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running =0;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running =0;
                    break;
                default:
                    break;
                }
            }
            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                    glViewport(0, 0, event.window.data1, event.window.data2);
                }
            }
        }
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        SDL_GL_SwapWindow(_window);
    }   
}