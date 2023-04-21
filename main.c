#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"
#include "shape.h"
#include "struct.h"
#include "id.h"
#include "interface.h"

int main(){

    int menu = 1, n_shape = 0;
    Shape** list_shape = (Shape**) malloc(SHAPE_MAX*sizeof(Shape*));
    while(menu){
        print_accueil();
        menu = choice(7, 0);
        switch(menu){
            case 1: {
                add_shape(list_shape, &n_shape);
                break;
            }
            case 2: {
                print_list_shape(list_shape, n_shape);
                break;
            }
            case 6:{
                menu = 0;
                break;
            }
            default:{
                printf("A venir prochainement");
                break;
            }
        }
    }
    return 0;
};

/* A conserver au cas où ça sera utile

    Point* List_point = (Point*) malloc(40*sizeof(Point));
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            List_point[i*10+j].pos_x = i;
            List_point[i*10+j].pos_y = j;
        }
    }
    int trouver;
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 80; j++){
            trouver = 0;
            for(int k = 0; k < 40; k++){
                if ((List_point[k].pos_x == j) && (List_point[k].pos_y == i)) trouver = 1;
            }
            if (trouver) printf("#");
            else printf(".");
        }
        printf("\n");

    }*/