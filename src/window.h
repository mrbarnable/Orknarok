#ifndef _WINDOW_H
#define _WINDOW_H

#include <SDL2/SDL.h>
#include <stdbool.h>

SDL_Window *gp_window;


bool initialize_window(void);
void destroy_window(void);

#endif // _WINDOW_H
