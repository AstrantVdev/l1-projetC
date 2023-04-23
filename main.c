#include <stdio.h>
#include <stdlib.h>

#include "shape.h"
#include "interface.h"

int main(){
    int menu = 1, n_shape = 0;
    Shape** list_shape = (Shape**) calloc(SHAPE_MAX, sizeof(Shape*));
    while(menu){
        print_accueuil();
        menu = choice(6, 1);
        switch(menu){
            case 1: {
                add_shape(list_shape, &n_shape);
                break;
            }
            case 2: {
                print_list_shape(list_shape, n_shape);
                break;
            }
            case 3: {
                print_draw();
                break;
            }
            case 4: {
                print_delete_shape();
                break;
            }
            case 5: {
                print_help();
                break;
            }
            case 6:{
                menu = 0;
                break;
            }
            default:{
                printf("Error\n");
                break;
            }
        }
    }
    for(int i = 0; i < n_shape; i++){
        delete_shape(list_shape[i]);
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