//
// Created by 33611 on 24/03/2023.
//

#include <stdlib.h>
#include "fonctions.h"
#include "struct.h"
#include "id.h"
#include <stdio.h>

Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *l = create_line(p1, p2);

    shp->ptrShape = l;
    return shp;
}

Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square *sqr = create_square(p, length);

    shp->ptrShape = sqr;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle *rect = create_rectangle(p, width, height);

    shp->ptrShape = rect;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px, py);
    Circle *circle = create_circle(p, radius);
    
    shp->ptrShape = circle;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n){
    Shape *shp = create_empty_shape(POLYGON);
    Point **points = (Point**) malloc(n*sizeof(Point*));

    for (int i = 0; i < n; i++){
        Point *p = create_point(lst[i*2], lst[i*2+1]);
        points[n] = p;
    }

    Polygon *poly = create_polygon(n, points);

    shp->ptrShape = poly;
    return shp;
}

void delete_shape(Shape *shape){

    if(shape->shape_type == POLYGON){
        Polygon *poly = shape->ptrShape;
        free(poly->points);
    }

    free(shape);

}

void print_shape(Shape *shape){
    SHAPE_TYPE type = shape->shape_type;
    printf("id : %d ", shape->id);

    switch ( type ) {
        case POINT:
            printf("type : POINT "); //seul facon de pront la valeur d'une enum, cf : https://stackoverflow.com/questions/3168306/print-text-instead-of-value-from-c-enum
            print_point(shape->ptrShape);
        case LINE:
            printf("type : LINE ");
            print_line(shape->ptrShape);
        case SQUARE:
            printf("type : SQUARE ");
            print_square(shape->ptrShape);
        case RECTANGLE:
            printf("type : RECTANGLE ");
            print_rectangle(shape->ptrShape);
        case CIRCLE:
            printf("type : CIRCLE ");
            print_circle(shape->ptrShape);
        case POLYGON:
            printf("type : POLYGON ");
            print_polygon(shape->ptrShape);

        default:
            printf("shape.c : Incorrect SHAPE_TYPE to print");

    }

}

unsigned int get_next_id(){

}