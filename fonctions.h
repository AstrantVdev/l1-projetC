#ifndef FONCTIONS_H
#define FONCTIONS_H

typedef struct {
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

#endif