/*
    l1-project C : Dessin vectoriel
           -----------
           | SHAPE.C |
           -----------

Contient l'ensemble des fonctions liés aux formes
et à leur pointeur générique Shape.

Réalisé par DELHAYE Guillaume et PORTAL Sacha

*/

#include <stdlib.h>
#include "shape.h"
#include "id.h"
#include <stdio.h>

Point *create_point(int px, int py)
{
    /* Créé et retourne un point. */

    Point* p = NULL;
    p = (Point*) malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;
    return p;
}
void delete_point(Point * point)
{
    /* Supprime un point. */

    free(point);
    point = NULL;
}
void print_point(Point * p)
{
    /* Affiche les informations d'un point. */

    printf("POINT %d %d\n", p->pos_x, p->pos_y);
}



Line *create_line(Point * p1, Point * p2)
{
    /* Créé et retourne une ligne. */

    Line* line = NULL;
    line = (Line*) malloc(sizeof(Line));
    line->p1 = p1;
    line->p2 = p2;
    return line;
}
void delete_line(Line * line)
{
    /* Supprime une ligne et ses deux points. */

    free(line->p1);
    free(line->p2);
    free(line);
    line = NULL;
}
void print_line(Line * line)
{
    /* Affiche les informations d'une ligne. */

    printf("LINE %d %d %d %d\n", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}



Square *create_square(Point * point, int length)
{
    /* Créé et retourne un carré. */

    Square* square = NULL;
    square = (Square*) malloc(sizeof(Square));
    square->p = point;
    square->length = length;
    return square;
}
void delete_square(Square * square)
{
    /* Supprime un carré et le point qu'il contient. */

    free(square->p);
    free(square);
    square = NULL;
}
void print_square(Square * square)
{
    /* Affiche les informations d'un carré. */

    printf("SQUARE %d %d %d\n", square->p->pos_x, square->p->pos_y, square->length);
}



Rectangle *create_rectangle(Point * point, int width, int height)
{
    /* Créé et retourne un rectangle. */

    Rectangle * rectangle = NULL;
    rectangle = (Rectangle*) malloc(sizeof(Rectangle));
    rectangle->p = point;
    rectangle->width = width;
    rectangle->height = height;
    return rectangle;
}
void delete_rectangle(Rectangle * rectangle)
{
    /* Supprime un rectangle et le point qu'il contient. */

    free(rectangle->p);
    free(rectangle);
    rectangle = NULL;
}
void print_rectangle(Rectangle * rectangle)
{
    /* Affiche les informations d'un rectangle. */

    printf("RECTANGLE %d %d %d %d\n", rectangle->p->pos_x, rectangle->p->pos_y, rectangle->width,
           rectangle->height);
}



Circle *create_circle(Point * center, int radius)
{
    /* Créé et retourne un cercle. */

    Circle * circle = NULL;
    circle = (Circle*) malloc(sizeof(Circle));
    circle->p = center;
    circle->radius = radius;
    return circle;
}
void delete_circle(Circle * circle)
{
    /* Supprime un cercle et son point central. */

    free(circle->p);
    free(circle);
    circle = NULL;
}
void print_circle(Circle * circle)
{
    /* Affiche les informations d'un cercle. */

    printf("CIRCLE %d %d %d\n", circle->p->pos_x, circle->p->pos_y, circle->radius);
}



Polygon *create_polygon(int n, Point** tab)
{
    /* Créé et retourne un polygone. */

    Polygon* polygon = NULL;
    polygon = (Polygon*) malloc(sizeof(Polygon));
    polygon->n = n;
    polygon->points = tab;
    return polygon;
}
void delete_polygon(Polygon * polygon)
{
    /* Supprime un polygone et l'ensemble de ses points. */

    for(int i = 0; i < polygon->n; i++) free(polygon->points[i]);
    free(polygon->points);
    free(polygon);
    polygon = NULL;
}
void print_polygon(Polygon * polygon)
{
    /* Affiche les informations d'un polygone. */

    printf("POLYGON");
    for(int i = 0; i < polygon->n; i++) {
        printf(" %d %d", ((polygon->points)[i])->pos_x, ((polygon->points)[i])->pos_y);
    }
    printf("\n");
}

Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    /* Créé et retourne une forme avec son identifiant. */

    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py) {
    /* Créé et retourne une forme qui pointe sur un point. */

    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2){
    /* Créé et retourne une forme qui pointe sur une ligne. */

    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *l = create_line(p1, p2);

    shp->ptrShape = l;
    return shp;
}

Shape *create_square_shape(int px, int py, int length){
    /* Créé et retourne une forme qui pointe sur un carré. */

    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square *sqr = create_square(p, length);

    shp->ptrShape = sqr;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    /* Créé et retourne une forme qui pointe sur un rectangle. */

    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle *rect = create_rectangle(p, width, height);

    shp->ptrShape = rect;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius){
    /* Créé et retourne une forme qui pointe sur un cercle. */

    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px, py);
    Circle *circle = create_circle(p, radius);
    
    shp->ptrShape = circle;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n){
    /* Créé et retourne une forme qui pointe sur un polygone. */

    Shape *shp = create_empty_shape(POLYGON);
    Point **list_p = (Point**) malloc(n*sizeof(Point*));

    for (int i = 0; i < n; i++){
        list_p[i] = create_point(lst[i*2], lst[i*2+1]);
    }
    Polygon *poly = create_polygon(n, list_p);

    shp->ptrShape = poly;
    return shp;
}

void delete_shape(Shape *shape){
    /* Supprime une forme. Redirige sur la bonne fonction selon le type de forme. */

    SHAPE_TYPE type = shape->shape_type;
    switch ( type ) {
        case POINT: {
            delete_point(shape->ptrShape);
            break;
        }
        case LINE: {
            delete_line(shape->ptrShape);
            break;
        }
        case SQUARE: {
            delete_square(shape->ptrShape);
            break;
        }
        case RECTANGLE: {
            delete_rectangle(shape->ptrShape);
            break;
        }
        case CIRCLE: {
            delete_circle(shape->ptrShape);
            break;
        }
        case POLYGON: {
            delete_polygon(shape->ptrShape);
            break;
        }

        default: {
            printf("shape.c : Incorrect SHAPE_TYPE to print");
            break;
        }

    }
}

void print_shape(Shape *shape){
    /* Affiche une forme. Redirige sur la bonne fonction selon le type de forme. */

    SHAPE_TYPE type = shape->shape_type;
    printf("id : %d ", shape->id);

    switch ( type ) {
        case POINT:{
            print_point(shape->ptrShape);
            break;
        }
        case LINE:{
            print_line(shape->ptrShape);
            break;
        }
        case SQUARE:{
            print_square(shape->ptrShape);
            break;
        }
        case RECTANGLE:{
            print_rectangle(shape->ptrShape);
            break;
        }
        case CIRCLE:{
            print_circle(shape->ptrShape);
            break;
        }
        case POLYGON:{
            print_polygon(shape->ptrShape);
            break;
        }
        default:{
            printf("shape.c : Incorrect SHAPE_TYPE to print");
            break;
        }

    }

}