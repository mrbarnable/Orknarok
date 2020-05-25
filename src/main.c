#include <stdio.h>
#include "game.h"

int main(int argc, char *argv[])
{   
    setup();

    while (gb_is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();
    return 0;
}
