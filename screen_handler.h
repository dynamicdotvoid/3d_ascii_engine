#include "pixel_storage.h"

// MAX_WIDTH x MAX_HEIGHT is the screen resolution of the program
#define MAX_WIDTH 5
#define MAX_HEIGHT 5
#define FILL_CHAR '.'  // what character to fill empty spaces with
#define PIXEL_CHAR '0'  //what character to fill pixel spaces with

// draw the screen with the given points
//
// @param pointer to the start of the linked list containing drawn pixels
void draw_screen(struct pixel_entry *head_draw_entry);
