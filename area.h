#include "shape.h"

#ifndef L1_PROJETC_AREA_H
#define L1_PROJETC_AREA_H

#define SHAPE_MAX 100 // Nombre maximum de formes
#define BOOL int

typedef struct area {
    unsigned int width; // Nombre de pixels en largeur ou nombre de colonnes (axe x)
    unsigned int height; // Nombre de pixels en hauteur ou nombre de lignes (axe y)
    BOOL** mat; // Matrice des pixels de taille (width * height)
    Shape* shapes[SHAPE_MAX]; // Tableau des formes;
    int nb_shape; // Nombre de formes dans le tableau shapes (taille logique)
} Area;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);

typedef struct{
    int running;
    Area *area;
} App;

#endif