#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
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