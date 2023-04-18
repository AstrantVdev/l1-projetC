#include "struct.h"

#ifndef L1_PROJECT_FONCTIONS_H
#define L1_PROJECT_FONCTIONS_H



Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);



Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);



Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);



Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);



Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);



Polygon *create_polygon(int n, Point** tab);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);



#endif