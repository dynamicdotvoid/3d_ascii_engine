#include <stdio.h>
#include "screen_handler.h"

void draw_screen() {
    // clear the screen
    printf("\x1b[2J");
    // move the cursor to the home position
    printf("\x1b[H");
    

    int current_x_position = 0;
    int current_y_position = 0;
    while(current_y_position <= MAX_HEIGHT) {
        putchar(FILL_CHAR);

        // if reached end of row
        if(current_x_position >= MAX_WIDTH) {
            putchar('\n');

            current_x_position = 0;
            current_y_position++;
        }
        current_x_position++;
    }
}
