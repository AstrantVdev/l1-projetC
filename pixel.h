/*
    l1-project C : Dessin vectoriel
           -----------
           | PIXEL.H |
           -----------

Déclare toutes les fonctions liés à la création des pixels et le
traçage des formes en pixels.

Défini aussi la structure Pixel.

Réalisé par DELHAYE Guillaume et PORTAL Sacha

*/

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

void pixel_line(Line* line, Pixel*** pixel, int* nb_pixels);

void pixel_square(Square * shape, Pixel*** pixel, int* nb_pixels);
void pixel_rectangle(Rectangle * shape, Pixel*** pixel, int* nb_pixels);
void pixel_circle(Circle* shape, Pixel*** pixel, int* nb_pixels);
void pixel_polygon(Polygon * shape, Pixel*** pixel, int* nb_pixels);

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel** pixel, int nb_pixels);

#endif //L1_PROJETC_PIXEL_H