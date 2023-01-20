#include <stdio.h>

// 500 x 500 "screen" size
#define MAX_WIDTH 500
#define MAX_HEIGHT 500

int main() {
    // Clear the screen
    printf("\x1b[2J");
    // Move cursor to home position
    printf("\x1b[H");

    int current_x_position = 0;
    int current_y_position = 0;
    while(current_y_position <= MAX_HEIGHT) {
        putchar('.');

        if(current_x_position >= MAX_WIDTH) {
            putchar('\n');

            current_x_position = 0;
            current_y_position++;
        }
        current_x_position++;
    }

    return 0;
}
