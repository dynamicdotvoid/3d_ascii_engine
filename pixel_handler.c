#include "stdlib.h"
#include "pixel_handler.h"
#include "pixel_storage.h"

struct rgb_color internal_make_color_struct(int red_intensity, int green_intensity, int blue_intensity) {
    struct rgb_color *made_struct = (struct rgb_color *)malloc(sizeof(struct rbg_color));

    made_struct->red = red_intensity;
    made_struct->green = green_intensity;
    made_struct->blue = blue_intensity;

    return *made_struct;
}

struct pixel internal_make_pixel_struct(int x_pos, int y_pos, struct rgb_color color_struct) {
    struct pixel *made_pixel = (struct pixel *)malloc(sizeof(struct pixel));

    made_pixel->x = x_pos;
    made_pixel->y = y_pos;
    made_pixel->color = color_struct;

    return *made_pixel;
}

struct pixel_entry *create_pixel(int x_pos, int y_pos, int red_intensity, int green_intensity, int blue_intensity) {
    struct rgb_color pixel_data_color = internal_make_color_struct(red_intensity, green_intensity, blue_intensity);
    struct pixel pixel_data = internal_make_pixel_struct(x_pos, y_pos, pixel_data_color);

    return insert_entry(pixel_data);
}
