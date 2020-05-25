#include "input.h"
#include <SDL2/SDL.h>

bool gb_is_running = false;


void process_input() {
    static SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        gb_is_running = false;
        break;
    case SDL_KEYDOWN:
        if (SDLK_ESCAPE == event.key.keysym.sym)
        {
            gb_is_running = false;
        }
        break;         
    }

}