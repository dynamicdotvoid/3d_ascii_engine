#include "pixel_handler.h"

// entry struct in the drawn pixels linked list
struct pixel_entry {
    extern struct pixel pixel_node;  // the pixel data to be stored
    struct pixel_entry *next_entry;  // the next entry in the linked list
}

// insert an pixel into the drawn pixels linked list(make an entry)
//
// @param pixel_node pixel data to insert into the linked list
// @return pointer to entry
struct pixel_entry *insert_entry(extern struct pixel pixel_node);

// remove and free an entry from the drawn pixels linked list
//
// @param removal_entry entry to remove and free
void remove_entry(struct pixel_entry removal_entry);

// draw the screen with the given points
//
// @param pointer to the start of the linked list containing drawn pixels
// @return success
int draw_screen(struct pixel_entry *head_entry);
