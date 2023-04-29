#include "shape.h"

#ifndef L1_PROJETC_PIXEL_H
#define L1_PROJETC_PIXEL_H

typedef struct {
    int px;
    int py;
} Pixel;

Pixel *create_pixel(int px, int py);
void pixel_point(Point* shape, Pixel** pixel, int* nb_pixels);
void delete_pixel(Pixel * pixel);

void pixel_line(Line* line, Pixel** pixel, int* nb_pixels);

void pixel_square(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_rectangle(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_polygon(Shape* shape, Pixel** pixel, int* nb_pixels);

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel** pixel, int nb_pixels);

#endif