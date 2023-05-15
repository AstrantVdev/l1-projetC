#include <stdio.h>
#include <stdlib.h>

#include "area.h"
#include "pixel.h"
#include "commands.h"

App *app= NULL;

int main(){
    app = (App*) malloc(sizeof(App));
    app->area = create_area(100, 25);
    app->running = 1;
    app->area->nb_shape = 0;

    print_area(app->area);

    while(app->running){
        Command *cmd = create_commande();
        read_from_stdin(cmd);
        read_exec_command(cmd);
        free_cmd(cmd);
    }

    delete_area(app->area);

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