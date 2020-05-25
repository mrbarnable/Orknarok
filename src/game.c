#include <game.h>


void setup(void) {
   if(initialize_window() && initialize_renderer())
   {gb_is_running = true;}
}


void update(void) {

}



void exit_game(void) {
    destroy_renderer(gp_renderer);
    destroy_window();
}