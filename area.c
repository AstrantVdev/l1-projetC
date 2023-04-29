#include <stdio.h>
#include <stdlib.h>

#include "area.h"
#include "pixel.h"


Area* create_area(unsigned int width, unsigned int height){
    Area* area = NULL;
    area = (Area*) malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->mat = (BOOL**) malloc(height*sizeof(BOOL*));
    for(int i = 0; i < width; i++){
        area->mat[i] = (BOOL*) calloc(width, sizeof(BOOL));
    }
    area->nb_shape = 0;
    return area;
}

void add_shape_to_area(Area* area, Shape* shape){
    area->shapes[area->nb_shape++] = shape;
}

void clear_area(Area* area){
    for(int i = 0; i < area->width; i++){
        for(int j = 0; j < area->height; j++){
            area->mat[i][j] = 0;
        }
    }
}

void erase_area(Area* area){
    for(int i = 0; i < area->nb_shape; i++){
        delete_shape(area->shapes[i]);
    }
}

void delete_area(Area* area){
    erase_area(area);
    for(int i = 0; i < area->width; i++){
        free(area->mat[i]);
    }
    free(area->mat);
    free(area);
    area = NULL;
}

void draw_area(Area* area){
    Pixel** list_pixel = NULL;
    int nb_pixels = 0;
    for(int i = 0; i < area->nb_shape; i++){
        list_pixel = create_shape_to_pixel(area->shapes[i], &nb_pixels);
        for(int j = 0; j < nb_pixels; j++){
            area->mat[list_pixel[j]->px][list_pixel[j]->py] = 1;
        }
    }
}

void print_area(Area* area){
    for(int i = 0; i < area->height; i++){
        for(int j = 0; j < area->width; j++){
            if (area->mat[i][j] == 0) printf("-");
            else printf("*");
        }
        printf("\n");
    }
    printf("\n");
}