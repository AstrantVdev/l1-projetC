#include "shape.h"

#ifndef L1_PROJETC_PIXEL_H
#define L1_PROJETC_PIXEL_H

Pixel *create_pixel(int px, int py);
void pixel_point(Point* shape, Pixel** pixel, int* nb_pixels);
void delete_pixel(Pixel * pixel);

void pixel_line(Line* line, Pixel** pixel, int* nb_pixels);

void pixel_square(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_rectangle(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_polygon(Shape* shape, Pixel** pixel, int* nb_pixels);

#endif