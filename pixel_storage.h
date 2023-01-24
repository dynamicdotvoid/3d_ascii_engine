#ifndef PIXEL_STORAGE_H
#define PIXEL_STORAGE_H

#include "pixel_handler.h"

// entry struct in the drawn pixels linked list
struct pixel_entry {
    struct pixel *pixel_node;  // the pixel data to be stored
    struct pixel_entry *next_entry;  // the next entry in the linked list
};

// insert an pixel into the drawn pixels linked list(make an entry)
//
// @param node pixel data to insert into the linked list
// @return pointer to entry
struct pixel_entry *insert_entry(struct pixel node);

// remove and free an entry from the drawn pixels linked list
//
// @param removal_entry pointer to entry to remove and free
void remove_entry(struct pixel_entry *removal_entry);

// return a pointer to the head entry of the linked list
//
// @return pointer to the head entry of the linked list
struct pixel_entry *fetch_head_entry();

#endif  // PIXEL_STORAGE_H
