#include <stdlib.h>

#include "pixel.h"
#include "struct.h"

Pixel *create_pixel(int px, int py){

}

void pixel_point(Point* pt, Pixel** pixel, int* nb_pixels)
{
    Pixel** pixel_tab = (Pixel**) malloc (sizeof (Pixel*));
    pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);

    realloc(pixel, sizeof (Pixel*) * (*nb_pixels));
    pixel[*nb_pixels] = *pixel_tab;
    *nb_pixels += 1;
}

void delete_pixel(Pixel * pixel){

}



void pixel_line(Line* line, Pixel** pixel, int* nb_pixels){
    int xa = line->p1->pos_x,
    xb = line->p2->pos_x,
    ya = line->p1->pos_y,
    yb = line->p2->pos_y;

    if (xa < xb){
        xb = xa;
        xa = line->p2->pos_x;
    }

    if(ya < yb){
        yb = ya;
        ya = line->p2->pos_y;
    }

    int dx = xa - xb,
    dy = -(yb - ya);

    int dmin = dx,
    dmax = dy;

    if(dx > dy){
        dmin = dy;
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
        cumuls[i] = ((i*restants)%(dmin+1) < ((i-1)*restants)%(dmin+1));
        segments[i] = segments[i]+cumuls[i];
    }

    if(dx > dy){

        for(int  i = 0; i < nb_segs; i++){

            for(int j = 0; j < segments[i]; j++ ){
                Point pt = { pt.pos_x, pt.pos_y };

                pixel_point(&pt, pixel, nb_pixels);
                xa++;
            }

            ya--;

        }

    }else{


        for(int  i = 0; i < nb_segs; i++){

            for(int j = 0; j < segments[i]; j++ ){
                Point pt = { pt.pos_x, pt.pos_y };

                pixel_point(&pt, pixel, nb_pixels);
                ya--;
            }

            xa++;

        }

    }

    free(segments);

}



void pixel_square(Shape* shape, Pixel** pixel, int* nb_pixels){

}

void pixel_rectangle(Shape* shape, Pixel** pixel, int* nb_pixels){

}

void pixel_circle(Shape* shape, Pixel** pixel, int* nb_pixels){

}

void pixel_polygon(Shape* shape, Pixel** pixel, int* nb_pixels){

}