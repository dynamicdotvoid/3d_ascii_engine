#include <stdio.h>
#include <stdlib.h>
#include "pixel_handler.h"
#include "pixel_storage.h"
#include "screen_handler.h"

int main() {
    create_pixel(100, 100, 255, 255, 255);

    struct pixel_entry *pixels_head_entry = fetch_head_entry();
    draw_screen(pixels_head_entry);

    getchar();  // prevent from closing
    return 0;
}
