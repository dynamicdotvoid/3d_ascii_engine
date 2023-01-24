#include "stdlib.h"
#include "pixel_storage.h"
#include "pixel_handler.h"

struct pixel_entry *head_entry = NULL;

struct pixel_entry *insert_entry(struct pixel node) {
    struct pixel_entry restore_head_entry = *head_entry;  // copy of head entry
    struct pixel_entry *entry = (struct pixel_entry *)malloc(sizeof(struct pixel_entry));

    entry->pixel_node = &node;
    entry->next_entry = NULL;

    if (head_entry == NULL) {
        // no head entry yet
        goto insert_func_end;
    }

    // there is already a entry in the list
    // decide on an entry's position through the x and y positions due to how the screen draws pixels
    int found_place;  // track if a place for the entry has been found 
    do {
        // if the entry's y and x are less than or equal to head_entry's x and y
        found_place = (entry->pixel_node->y <= head_entry->pixel_node->y && entry->pixel_node->x <= head_entry->pixel_node->x);

        if (found_place) {
            head_entry->next_entry = entry;
            entry->next_entry = head_entry;

            goto insert_func_end;
        }
        head_entry = head_entry->next_entry;
    } while (!found_place);
    // restore head_entry after incrementing
    *head_entry = restore_head_entry;

    insert_func_end:
        head_entry = entry;
        
        return entry;
}

void remove_entry(struct pixel_entry *removal_entry) {
    struct pixel_entry restore_head_entry = *head_entry;  // copy of head entry
    // search for entry in linked list
    int found_entry;  // track if the entry has been found 
    do {
        // if head_entry's next entry is the removal entry, or if head_entry is the removal entry
        found_entry = (head_entry->next_entry == removal_entry) || (head_entry == removal_entry);

        if (found_entry) {
            head_entry->next_entry = removal_entry->next_entry;
            // update head_entry if it's being removed
            if (head_entry == removal_entry) {
                head_entry = head_entry->next_entry;
            }

            goto remove_func_end;
        }

        head_entry = head_entry->next_entry;
    } while (!found_entry);
    // restore head_entry after incrementing
    *head_entry = restore_head_entry;
    
    remove_func_end:
        free(removal_entry);
}
