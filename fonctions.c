#include <stdio.h>
#include <stdlib.h>
#include "shape.h"
#include "fonctions.h"

Point *create_point(int px, int py)
{
    Point* p = NULL;
    p = (Point*) malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;
    return p;
}
void delete_point(Point * point)
{
    free(point);
    point = NULL;
}
void print_point(Point * p)
{
    printf("POINT %d %d", p->pos_x, p->pos_y);
}



Line *create_line(Point * p1, Point * p2)
{
    Line* line = NULL;
    line = (Line*) malloc(sizeof(Line));
    line->p1 = p1;
    line->p2 = p2;
    return line;
}
void delete_line(Line * line)
{
    free(line->p1);
    free(line->p2);
    free(line);
    line = NULL;
}
void print_line(Line * line)
{
    printf("LINE %d %d %d %d", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}



Square *create_square(Point * point, int length)
{
    Square* square = NULL;
    square = (Square*) malloc(sizeof(Square));
    square->p = point;
    square->length = length;
    return square;
}
void delete_square(Square * square)
{
    free(square->p);
    free(square);
    square = NULL;
}
void print_square(Square * square)
{
    printf("SQUARE %d %d %d\n", square->p->pos_x, square->p->pos_y, square->length);
}



Rectangle *create_rectangle(Point * point, int width, int height)
{
    Rectangle * rectangle = NULL;
    rectangle = (Rectangle*) malloc(sizeof(Rectangle));
    rectangle->p = point;
    rectangle->width = width;
    rectangle->height = height;
    return rectangle;
}
void delete_rectangle(Rectangle * rectangle)
{
    free(rectangle->p);
    free(rectangle);
    rectangle = NULL;
}
void print_rectangle(Rectangle * rectangle)
{
    printf("RECTANGLE %d %d %d %d\n", rectangle->p->pos_x, rectangle->p->pos_y, rectangle->width,
           rectangle->height);
}



Circle *create_circle(Point * center, int radius)
{
    Circle * circle = NULL;
    circle = (Circle*) malloc(sizeof(Circle));
    circle->p = center;
    circle->radius = radius;
    return circle;
}
void delete_circle(Circle * circle)
{
    free(circle->p);
    free(circle);
    circle = NULL;
}
void print_circle(Circle * circle)
{
    printf("CIRCLE %d %d %d\n", circle->p->pos_x, circle->p->pos_y, circle->radius);
}



Polygon *create_polygon(int n, Point** tab)
{
    Polygon* polygon = NULL;
    polygon = (Polygon*) malloc(sizeof(Polygon));
    polygon->n = n;
    polygon->points = tab;
    return polygon;
}
void delete_polygon(Polygon * polygon)
{
    for(int i = 0; i < polygon->n; i++) free(polygon->points[i]);
    free(polygon->points);
    free(polygon);
    polygon = NULL;
}
void print_polygon(Polygon * polygon)
{
    printf("POLYGON");
    for(int i = 0; i < polygon->n; i++)
        printf(" %d %d", ((polygon->points)[i])->pos_x, ((polygon->points)[i])->pos_y);
    printf("\n");
}