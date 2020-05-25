#ifndef _RENDERER_H
#define _RENDERER_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>
#include "constants.h"
#include "window.h"


extern SDL_Renderer *gp_renderer;
extern SDL_Texture *gp_color_buffer_texture;
extern uint32_t *gp_color_buffer;


bool initialize_renderer();
void clear_color_buffer(uint32_t color);
void fill_color_buffer(SDL_Texture *texture_buffer);
void render_color_buffer(void);
void render(void);
void destroy_renderer(SDL_Renderer *renderer);

#endif // _RENDERER_H