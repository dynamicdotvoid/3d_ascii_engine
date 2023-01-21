// rgb color holder used for pixels
struct rgb_color {
    int red : 8;    // intensity of red
    int green : 8;  // intensity of green
    int blue : 8;   // intensity of blue
}

// pixel struct passed into pixel related functions and stored
// uses a screen coordinate system
// example of a ~(700 x 500) screen using the screen coordinate system:
//     0 <----------> 700
//     __________________
// 0   |................|
// |   |................|
// |   |................|
// |   |................|
// |   |................|
// 500 ------------------
struct pixel {
    unsigned int x;          // x position of the pixel
    unsigned int y;          // y position of the pixel
    struct rgb_color color;  // rgb color of the pixel
}

// make a rgb_collor struct using the given arguments
//
// @param red intensity of red
// @param green intensity of green
// @param blue intensity of blue
// @return made rgb_color struct
struct rgb_color make_color_struct(int red, int green, int blue);

// make a pixel struct using the given arguments
// uses screen coordinate system
//
// @param x x position of the pixel
// @param y y position of the pixel
// @param color struct rgb_color of the pixel color
// @return made pixel struct
struct pixel internal_make_pixel_struct(int x, int y, struct rgb_color color);

// create and store a pixel with the supplied arguments
// uses logical coordinate system
// example of a ~(700 x 500) screen using the logical coordinate system:
//             250
//              |
//              |
//              |
// -350---------0-----------350
//              |
//              |
//              |
//            -250
//
// @param x_pos x position of the created pixel
// @param y_pos y position of the created pixel
// @param color struct of the desired rgb color
// @return success
int create_pixel(int x_pos, int y_pos, struct rgb_color color);
