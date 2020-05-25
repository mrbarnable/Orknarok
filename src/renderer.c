#include "renderer.h"


SDL_Renderer *gp_renderer = NULL;
SDL_Texture *gp_color_buffer_texture = NULL;
uint32_t *gp_color_buffer = NULL;

bool initialize_renderer(void) {
    gp_renderer = SDL_CreateRenderer(gp_window, -1, 0);

    if (NULL == gp_renderer)
    {
        log_error("Error initializing renderer\n");
        return FALSE;
    }

    gp_color_buffer = (uint32_t*)malloc(sizeof(uint32_t)
                *  WINDOW_WIDTH 
                *  WINDOW_HEIGHT);
                     

    gp_color_buffer_texture = SDL_CreateTexture(
                gp_renderer,
                SDL_PIXELFORMAT_ARGB8888,
                SDL_TEXTUREACCESS_STREAMING,
                WINDOW_WIDTH,
                WINDOW_HEIGHT
            );
    
}



void clear_color_buffer(uint32_t color) {
    for (int y = 0; y < WINDOW_HEIGHT; y++) {
        for (int x = 0; x < WINDOW_WIDTH; x++) {
            gp_color_buffer[(WINDOW_WIDTH * y) + x] = color;
        }
    }
}


void fill_color_buffer(SDL_Texture *texture_buffer) {
    texture_buffer = SDL_CreateTexture(
                gp_renderer,
                SDL_PIXELFORMAT_ARGB8888,
                SDL_TEXTUREACCESS_STREAMING,
                WINDOW_WIDTH,
                WINDOW_HEIGHT
            );
}


void render_color_buffer(void) {
    SDL_UpdateTexture(
        gp_color_buffer_texture,
        NULL,
        gp_color_buffer,
        (int)(WINDOW_WIDTH * sizeof(uint32_t))
    );

    SDL_RenderCopy(
        gp_renderer,
        gp_color_buffer_texture,
        NULL,
        NULL
    );
}


void render(void) {
    SDL_SetRenderDrawColor(gp_renderer, 0, 0, 0, 255);
    SDL_RenderClear(gp_renderer);


    render_color_buffer();
    clear_color_buffer(0xFFFFFF00);

    SDL_RenderPresent(gp_renderer);
}


void destroy_renderer(SDL_Renderer *renderer) {
    free(gp_color_buffer);
    gp_color_buffer = 0;
    SDL_DestroyRenderer(gp_renderer);
}