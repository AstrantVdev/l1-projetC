#include <stdlib.h>
#include <stdio.h>

#include "pixel.h"
#include "shape.h"

Pixel *create_pixel(int px, int py){
    Pixel *pixel = (Pixel*) malloc(sizeof(Pixel));
    pixel->px = px;
    pixel->py = py;
    return pixel;
}

void pixel_point(Point* pt, Pixel** pixel_tab, int* nb_pixels)
{
    pixel_tab[(*nb_pixels)++] = create_pixel(pt->pos_x, pt->pos_y);
}

void delete_pixel(Pixel *pixel){
    free(pixel);
}



void pixel_line(Line* line, Pixel*** pixel, int* nb_pixels){
    int xa = line->p1->pos_x,
            xb = line->p2->pos_x,
            ya = line->p1->pos_y,
            yb = line->p2->pos_y;

    if (xa > xb){
        xb = xa;
        xa = line->p2->pos_x;
        yb = ya;
        ya = line->p2->pos_y;
    }

    int dx = xb - xa,
            dy = yb - ya;

    int dmin = dx,
            dmax = abs(dy);
    if(dmin > dmax){
        dmin = abs(dy);
        dmax = dx;
    }

    int nb_segs = dmin + 1;
    int len_seg = (dmax + 1) / (dmin + 1);

    int* segments = (int*) malloc(sizeof(int)*nb_segs);
    for(int i = 0; i < nb_segs; i++){
        segments[i] = len_seg;
    }

    int restants = (dmax + 1) % (dmin + 1);

    int *cumuls = (int *)malloc(nb_segs*sizeof(int));
    cumuls[0]=0;
    for (int i = 1; i < nb_segs;i++)
    {
        cumuls[i] = ((i+1)*restants)%(dmin+1) < (i*restants)%(dmin+1);
        segments[i] = segments[i]+cumuls[i];
    }

    *pixel = (Pixel**) realloc(*pixel, sizeof (Pixel*)*( *nb_pixels + len_seg*nb_segs + restants));

    if (dy >= 0) {
        if (dx > dy) {

            for (int i = 0; i < nb_segs; i++) {

                for (int j = 0; j < segments[i]; j++) {
                    Point pt = {xa, ya};
                    pixel_point(&pt, *pixel, nb_pixels);
                    xa++;
                }
                ya++;

            }

        } else {


            for (int i = 0; i < nb_segs; i++) {

                for (int j = 0; j < segments[i]; j++) {
                    Point pt = {xa, ya};
                    pixel_point(&pt, *pixel, nb_pixels);
                    ya++;
                }
                xa++;

            }

        }
    }else{
        if (dx > abs(dy)) {

            for (int i = 0; i < nb_segs; i++) {

                for (int j = 0; j < segments[i]; j++) {
                    Point pt = {xa, ya};
                    pixel_point(&pt, *pixel, nb_pixels);
                    xa++;
                }
                ya--;

            }

        } else {


            for (int i = 0; i < nb_segs; i++) {

                for (int j = 0; j < segments[i]; j++) {
                    Point pt = {xa, ya};
                    pixel_point(&pt, *pixel, nb_pixels);
                    ya--;
                }
                xa++;

            }

        }

    }

    free(segments);

}

void pixel_line_for_poly(Line* line, Pixel*** pixel, int* nb_pixels){
    pixel_line(line, pixel, nb_pixels);
}


void pixel_circle(Circle * circle, Pixel*** pixel, int* nb_pixels){
    int x = 0,
    y = circle->radius,
    d = circle->radius - 1;

    int point_x = circle->p->pos_x,
    point_y = circle->p->pos_y;

    while(y >= x) {
        *pixel = realloc(*pixel, sizeof(Pixel *) * (*nb_pixels + 8));
        (*pixel)[(*nb_pixels)++] = create_pixel(point_x + x, point_y + y);
        (*pixel)[(*nb_pixels)++] = create_pixel(point_x + y, point_y + x);
        (*pixel)[(*nb_pixels)++] = create_pixel(point_x - x, point_y + y);
        (*pixel)[(*nb_pixels)++] = create_pixel(point_x - y, point_y + x);
        (*pixel)[(*nb_pixels)++] = create_pixel(point_x + x, point_y - y);
        (*pixel)[(*nb_pixels)++] = create_pixel(point_x + y, point_y - x);
        (*pixel)[(*nb_pixels)++] = create_pixel(point_x - x, point_y - y);
        (*pixel)[(*nb_pixels)++] = create_pixel(point_x - y, point_y - x);

        if (d > 2 * x) {
            d -= 2 * x + 1;
            x++;
        }else if (d < 2 * (circle->radius - y)){
            d += 2 * y - 1;
            y--;
        }else{
            d += 2*x - 2*y + 2;
            y--;
            x++;
        }

    }

}

void pixel_square(Square * sqr, Pixel*** pixel, int* nb_pixels){
    Point *p1 = create_point(sqr->p->pos_x, sqr->p->pos_y);
    Point *p2 = create_point(sqr->p->pos_x + sqr->length - 1, sqr->p->pos_y);
    Point *p3 = create_point(sqr->p->pos_x, sqr->p->pos_y  + sqr->length - 1);
    Point *p4 = create_point(sqr->p->pos_x + sqr->length - 1, sqr->p->pos_y + sqr->length - 1);


    Line* line = create_line(p1, p2);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    line = create_line(p2, p4);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    line = create_line(p4, p3);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    line = create_line(p3, p1);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    delete_point(p1);
    delete_point(p2);
    delete_point(p3);
    delete_point(p4);

}

void pixel_rectangle(Rectangle * rect, Pixel*** pixel, int* nb_pixels){
    Point *p1 = create_point(rect->p->pos_x, rect->p->pos_y);
    Point *p2 = create_point(rect->p->pos_x + rect->width - 1, rect->p->pos_y);
    Point *p3 = create_point(rect->p->pos_x, rect->p->pos_y  + rect->height - 1);
    Point *p4 = create_point(rect->p->pos_x + rect->width - 1, rect->p->pos_y + rect->height - 1);

    Line* line = create_line(p1, p2);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    line = create_line(p2, p4);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    line = create_line(p4, p3);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    line = create_line(p3, p1);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    delete_point(p1);
    delete_point(p2);
    delete_point(p3);
    delete_point(p4);
}

void pixel_polygon(Polygon * poly, Pixel*** pixel, int* nb_pixels){

    Line *line;
    for(int i = 0; i < poly->n-1; i++){
        line = create_line(poly->points[i], poly->points[i+1]);
        pixel_line_for_poly(line, pixel, nb_pixels);
        free(line);
    }
    line = create_line(poly->points[poly->n-1], poly->points[0]);
    pixel_line_for_poly(line, pixel, nb_pixels);
    free(line);

    for(int i = 0; i < poly->n; i++){
        delete_point(poly->points[i]);
    }

}



Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels){
    Pixel** pixel = (Pixel**) malloc(sizeof(Pixel*));

    switch ( shape->shape_type ) {
        case POINT: {
            pixel_point(shape->ptrShape, pixel, nb_pixels);
            break;
        }
        case LINE: {
            pixel_line(shape->ptrShape, &pixel, nb_pixels);
            break;
        }
        case SQUARE: {
            pixel_square(shape->ptrShape, &pixel, nb_pixels);
            break;
        }
        case RECTANGLE: {
            pixel_rectangle(shape->ptrShape, &pixel, nb_pixels);
            break;
        }
        case CIRCLE: {
            pixel_circle(shape->ptrShape, &pixel, nb_pixels);
            break;
        }
        case POLYGON: {
            pixel_polygon(shape->ptrShape, &pixel, nb_pixels);
            break;
        }
        default: {
            printf("pixel.c : Incorrect SHAPE_TYPE to create");
            break;
        }

    }
    return pixel;

}

void delete_pixel_shape(Pixel** pixel, int nb_pixels){
    for (int i=0; i<nb_pixels; i++) {
        free(pixel[i]);
    }

}