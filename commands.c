#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "commands.h"
#include "main.c"
#include "utils.h"

Command* create_commande(){
    Command *cmd = (Command*) malloc(sizeof(Command));
    cmd->str_size = 0;
    cmd->str_size = 0;
    return cmd;
}

void add_str_param(Command* cmd, char* p){
    cmd->str_params[cmd->str_size] = p;
    cmd->str_size++;
}

void add_int_param(Command* cmd, int p){
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size++;
}

void free_cmd(Command* cmd){
    for(int i = 0; i < cmd->str_size; i++){
        free(cmd->str_params[i]);
    }
    free(cmd);
}

int read_exec_command(Command* cmd){

    if (strcmp(cmd->name, "clear") == 0){
        cmd_clear(cmd);
    }else if (strcmp(cmd->name, "exit") == 0){
        cmd_exit(cmd);
    }else if (strcmp(cmd->name, "point") == 0){
        cmd_point(cmd);
    }else if (strcmp(cmd->name, "line") == 0){
        cmd_line(cmd);
    }else if (strcmp(cmd->name, "circle") == 0){
        cmd_circle(cmd);
    }else if (strcmp(cmd->name, "square") == 0){
        cmd_square(cmd);
    }else if (strcmp(cmd->name, "rectangle") == 0){
        cmd_rectangle(cmd);
    }else if (strcmp(cmd->name, "polygon") == 0){
        cmd_polygon(cmd);
    }else if (strcmp(cmd->name, "plot") == 0){
        cmd_plot(cmd);
    }else if (strcmp(cmd->name, "list") == 0){
        cmd_list(cmd);
    }else if (strcmp(cmd->name, "delete") == 0){
        cmd_delete(cmd);
    }else if (strcmp(cmd->name, "erase") == 0){
        cmd_erase(cmd);
    }else if (strcmp(cmd->name, "help") == 0){
        cmd_help(cmd);
    }else{
        printf("lol c pas une commande ca");
    }

}

void read_from_stdin(Command* cmd){
    printf("Entrez une commande :\n> ");

    char c[64];
    fgets(c, 64, stdin);

    int name = 1;
    char *arg = NULL;
    for(arg = strtok(c, " "); arg != NULL; arg = strtok(NULL," ")){
        int digit = 0;

        if(name){
            strcpy(cmd->name, arg);
            name = 0;
        }

        for(int i = 0; i < strlen(arg); i++){
            if(isalpha(arg[i])){
                digit = 0;
                break;
            }

            digit += (int) c*10^i;

        }

        if(digit){
            add_int_param(cmd, digit);
        }else{
            add_str_param(cmd, arg);
        }

    }

}



void cmd_clear(Command* cmd){
    erase_area(app->area);
    clear_area(app->area);

    jump_page();
    printf("Les shapes ont été détruites avec succès :d");
}

void cmd_exit(Command* cmd){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nVous avez fermé l'application avec succès :D");
    app->running = 0;
}

void cmd_point(Command* cmd){
    if(cmd->int_size != 2){
        jump_page();
        printf("Erreur, cette commande est de la forme :    point x y");
        return;
    }

    int x = cmd->int_params[0];
    int y = cmd->int_params[1];

    if(x > app->area->width){
        printf("Erreur, x: %d est supérieur à la largeur de la planche, %d", x, app->area->width);
        return;
    }

    if(x > app->area->height){
        printf("Erreur, y: %d est supérieur à la hauteur de la planche, %d", y, app->area->height);
        return;
    }

    Shape *point = create_point_shape(x, y);
    add_shape_to_area(app->area, point);

    jump_page();
    printf("Le point a été créé avec succès uwu");
}

void cmd_line(Command* cmd){

    if(cmd->int_size != 4){
        jump_page();
        printf("Erreur, cette commande est de la forme :    line x1 y1 x2 y2");
        return;
    }

    int x1 = cmd->int_params[0];
    int y1 = cmd->int_params[1];
    int x2 = cmd->int_params[2];
    int y2 = cmd->int_params[3];

    Shape *line = create_line_shape(x1, y1, x2, y2);
    add_shape_to_area(app->area, line);

    jump_page();
    printf("La ligne a été créé avec succès ;3");
}

void cmd_circle(Command* cmd){
    if(cmd->int_size != 3){
        jump_page();
        printf("Erreur, cette commande est de la forme :    circle x y radius");
        return;
    }

    int x = cmd->int_params[0];
    int y = cmd->int_params[1];
    int radius = cmd->int_params[2];

    Shape *circle = create_circle_shape(x, y, radius);
    add_shape_to_area(app->area, circle);

    jump_page();
    printf("Le cercle a été créé avec succès o-o");
}

void cmd_square(Command* cmd){
    if(cmd->int_size != 3){
        jump_page();
        printf("Erreur, cette commande est de la forme :    square x y length");
        return;
    }

    int x = cmd->int_params[0];
    int y = cmd->int_params[1];
    int length = cmd->int_params[2];

    Shape *square = create_square_shape(x, y, length);
    add_shape_to_area(app->area, square);

    jump_page();
    printf("Le carré a été créé avec succès a_a");
}

void cmd_rectangle(Command* cmd){
    if(cmd->int_size != 4){
        jump_page();
        printf("Erreur, cette commande est de la forme :    rectangle x y width height");
        return;
    }

    int x = cmd->int_params[0];
    int y = cmd->int_params[1];
    int width = cmd->int_params[2];
    int length = cmd->int_params[3];

    Shape *rect = create_rectangle_shape(width, length);
    add_shape_to_area(app->area, rect);

    jump_page();
    printf("Le rectangle a été créé avec succès ;)");
}

void cmd_polygon(Command* cmd){
    if(cmd->int_size < 6){
        jump_page();
        printf("Erreur, cette commande est de la forme :    polygon x1 y1 x2 y2 x3 y3 ...");
        return;
    }

    Shape *poly = create_polygon_shape(cmd->int_params, cmd->int_size);
    add_shape_to_area(app->area, poly);

    jump_page();
    printf("Le polygone a été créé avec succès a_a");
}

void cmd_plot(Command* cmd){
    jump_page();

    draw_area(app->area);
    print_area(app->area);
}

void cmd_list(Command* cmd){
    printf("Listes des shapes :");
    for(int i = 0; i < app->area->nb_shape; i++){
        print_shape(app->area->shapes[i]);
    }
}

void cmd_delete(Command* cmd){

}

void cmd_erase(Command* cmd){

}

void cmd_help(Command* cmd){

}
