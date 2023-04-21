//
// Created by 33611 on 12/04/2023.
//

#ifndef L1_PROJETC_INTERFACE_H
#define L1_PROJETC_INTERFACE_H

#include "shape.h"

int choice(int n_options, int character);
void print_accueuil();
void print_list_shape(Shape** list_shape, int len);
void print_dessin();
void add_shape(Shape** list_shape, int* n_shape);

int* ask_points(int nb_points);
void ask_radius(int* radius);
void ask_size_rectangle(int* width, int* height);
void ask_length_square(int* length);
void ask_nb_points(int* nb_points);

Shape *add_point();
Shape *add_line();
Shape *add_circle();
Shape *add_square();
Shape *add_rectangle();
Shape *add_polygon();

#endif //L1_PROJETC_INTERFACE_H
