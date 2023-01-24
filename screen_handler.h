#include "pixel_storage.h"

// MAX_WIDTH x MAX_HEIGHT is the screen resolution of the program
// ex: MAX_WIDTH = 700, MAX_HEIGHT = 500, screen resolution = 700 x 500
#define MAX_WIDTH 500
#define MAX_HEIGHT 500
#define FILL_CHAR '.'  // what character to fill empty spaces with
#define PIXEL_CHAR '0'  //what character to fill pixel spaces with

// draw the screen with the given points
//
// @param pointer to the start of the linked list containing drawn pixels
void draw_screen();  //TODO: Add argument 'struct pixel_entry *head_draw_entry'
