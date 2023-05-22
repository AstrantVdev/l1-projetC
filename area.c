/*
    l1-project C : Dessin vectoriel
           ----------
           | AREA.C |
           ----------

Contient toutes les fonctions liées à la zone de dessin.

Réalisé par DELHAYE Guillaume et PORTAL Sacha

*/

#include <stdio.h>
#include <stdlib.h>

#include "area.h"
#include "pixel.h"

Area* create_area(unsigned int width, unsigned int height){
    /* Crée et renvoie une zone de dessin de taille width * height. */

    Area* area = NULL;
    area = (Area*) malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->mat = (BOOL**) malloc(height*sizeof(BOOL*));
    for(int i = 0; i < height; i++){
        area->mat[i] = (BOOL*) malloc(width*sizeof(BOOL));
    }
    // Initialisation de la matrice à 0
    clear_area(area);
    area->nb_shape = 0;
    return area;
}

void add_shape_to_area(Area* area, Shape* shape){
    /* Ajoute une forme "shape" à une zone de dessin. */

    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;
}

void clear_area(Area* area){
    /* Remet à 0 une zone de dessin. */

    for(int i = 0; i < area->height; i++){
        for(int j = 0; j < area->width; j++){
            area->mat[i][j] = 0;
        }
    }
}

void erase_area(Area* area){
    /* Efface toutes le formes d'une zone de dessin. */

    for(int i = 0; i < area->nb_shape; i++){
        delete_shape(area->shapes[i]);
    }
    area->nb_shape = 0;
}

void delete_area(Area* area){
    /* Supprime une zone de dessin. */

    erase_area(area);
    for(int i = 0; i < area->height; i++){
        free(area->mat[i]);
    }
    free(area->mat);
    free(area);
    area = NULL;
}

void draw_area(Area* area){
    /* Dessine toutes les formes d'une zone de dessin, en traçant les pixels
     * de chaque formes. */

    int nb_pixels = 0;
    for(int i = 0; i < area->nb_shape; i++){
        nb_pixels = 0;
        // Pixels de la forme shape[i]
        Pixel** list_pixel = create_shape_to_pixel(area->shapes[i], &nb_pixels);

        // On modife les pixels de la grille pour mettre ceux de la forme à 1
        for(int j = 0; j < nb_pixels; j++){
            if ((list_pixel[j]->px >= 0) && (list_pixel[j]->px < area->width) && (list_pixel[j]->py >= 0) && (list_pixel[j]->py < area->height))
                area->mat[list_pixel[j]->py][list_pixel[j]->px] = 1;
        }

        // Suppression de la liste des pixels de la forme
        delete_pixel_shape(list_pixel, nb_pixels);
    }

}

void print_area(Area* area){
    /* Affiche une zone de dessin. */

    for(int i = 0; i < area->height; i++){
        for(int j = 0; j < area->width; j++){
            if (area->mat[i][j] == 0) printf("-");
            else printf("o");
        }
        printf("\n");
    }
    printf("\n");
}
