#include "window.h"
#include "constants.h"


bool initialize_window(void) {
    if(0 != SDL_Init(SDL_INIT_EVERYTHING)) {
        log_error("Error initializing SDL\n");
        return FALSE;
    }

    gp_window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN |
        SDL_WINDOW_BORDERLESS
        );
    
    if (NULL == gp_window)
    {
        log_error("Error initializing window: %s\n", SDL_GetError());
        return FALSE;
    }

    return TRUE;
}


void destroy_window(void) {
    SDL_DestroyWindow(gp_window);
    SDL_Quit();
}
