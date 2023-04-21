//
// Created by 33611 on 12/04/2023.
//

#ifndef L1_PROJETC_INTERFACE_H
#define L1_PROJETC_INTERFACE_H

#include "struct.h"

int choice(int n_options, int n_tab);
void print_accueil();
void print_list_shape(Shape** list_shape, int len);
void print_dessin();
void add_shape(Shape** list_shape, int* n_shape);

int* add_points(int nb_points);
void add_radius(int* radius);
void add_size_rectangle(int* width, int* height);
void add_length_square(int* length);
void add_nb_points(int* nb_points);

Shape *print_add_point();
Shape *print_add_line();
Shape *print_add_circle();
Shape *print_add_square();
Shape *print_add_rectangle();
Shape *print_add_polygon();

#endif //L1_PROJETC_INTERFACE_H
