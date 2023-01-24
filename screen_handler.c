#include <stdio.h>
#include "screen_handler.h"

void draw_screen(struct pixel_entry *head_draw_entry) {
    // clear the screen
    printf("\x1b[2J");
    // move the cursor to the home position
    printf("\x1b[H");

    unsigned int current_x_position = 0;
    unsigned int current_y_position = 0;
    while (current_y_position <= MAX_HEIGHT) {
        // if current coordinates match current entry's coordinates
        if (current_x_position == head_draw_entry->pixel_node->x && current_y_position == head_draw_entry->pixel_node->y) {
            putchar(PIXEL_CHAR);

            head_draw_entry = head_draw_entry->next_entry;
        } else {
            putchar(FILL_CHAR);
        }

        // if reached end of row
        if (current_x_position >= MAX_WIDTH) {
            putchar('\n');

            current_x_position = 0;
            current_y_position++;
        }
        current_x_position++;
    }
}
