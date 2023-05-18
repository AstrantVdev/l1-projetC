#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "commands.h"
#include "utils.h"
extern App *app;

Command* create_commande(){
    Command *cmd = (Command*) malloc(sizeof(Command));
    cmd->int_size = 0;
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

void read_exec_command(Command* cmd){

    printf("Commande : %s, %d\n", cmd->name, strcmp(cmd->name, "help"));
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
        printf("Erreur, %s n'est pas une commande\n", cmd->name);
    }

}

void read_from_stdin(Command* cmd){
    printf("\n>> ");

    char c[64];
    fgets(c, 64, stdin);

    for(int i = 0; c[i] != '\0'; i++){
        if(c[i] == '\n'){
            c[i] = '\0';
            break;
        }
    }

    strchr( c, '\n' );

    int name = 1;
    char *arg = NULL;
    for(arg = strtok(c, " "); arg != NULL; arg = strtok(NULL," ")){
        int digit = 1;

        if(name){
            strcpy(cmd->name, arg);
            name = 0;
            continue;

        }

        for(int i = 0; arg[i] != 0; i++){
            if(isalpha(arg[i])){
                digit = 0;
                break;
            }

        }

        if(digit){
            digit = atoi(arg);
            add_int_param(cmd, digit);
        }else{
            add_str_param(cmd, arg);
        }

    }
}



void cmd_clear(Command* cmd){
    clear_area(app->area);

    jump_page();
    printf("L'aire est maintenant vide :d\n");
}

void cmd_exit(Command* cmd){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nVous avez ferme l'app avec succes :D\n");
    app->running = 0;
}

void cmd_point(Command* cmd){

    if(cmd->int_size != 2){
        jump_page();
        printf("Erreur, cette commande est de la forme :    point x y\n");
        return;
    }

    int x = cmd->int_params[0];
    int y = cmd->int_params[1];

    Shape *point = create_point_shape(x, y);
    add_shape_to_area(app->area, point);

    jump_page();
    printf("Le point a ete cree avec succes uwu\n");
}

void cmd_line(Command* cmd){

    if(cmd->int_size != 4){
        jump_page();
        printf("Erreur, cette commande est de la forme :    line x1 y1 x2 y2\n");
        return;
    }

    int x1 = cmd->int_params[0];
    int y1 = cmd->int_params[1];
    int x2 = cmd->int_params[2];
    int y2 = cmd->int_params[3];

    Shape *line = create_line_shape(x1, y1, x2, y2);
    add_shape_to_area(app->area, line);

    jump_page();
    printf("La ligne a ete cree avec succes ;3\n");
}

void cmd_circle(Command* cmd){
    if(cmd->int_size != 3){
        jump_page();
        printf("Erreur, cette commande est de la forme :    circle x y radius\n");
        return;
    }

    int x = cmd->int_params[0];
    int y = cmd->int_params[1];
    int radius = cmd->int_params[2];

    Shape *circle = create_circle_shape(x, y, radius);
    add_shape_to_area(app->area, circle);

    jump_page();
    printf("Le cercle a ete cree avec succes o-o\n");
}

void cmd_square(Command* cmd){
    if(cmd->int_size != 3){
        jump_page();
        printf("Erreur, cette commande est de la forme :    square x y length\n");
        return;
    }

    int x = cmd->int_params[0];
    int y = cmd->int_params[1];
    int length = cmd->int_params[2];

    Shape *square = create_square_shape(x, y, length);
    add_shape_to_area(app->area, square);

    jump_page();
    printf("Le carre a ete cree avec succes a_a\n");
}

void cmd_rectangle(Command* cmd){
    if(cmd->int_size != 4){
        jump_page();
        printf("Erreur, cette commande est de la forme :    rectangle x y width height\n");
        return;
    }

    int x = cmd->int_params[0];
    int y = cmd->int_params[1];
    int width = cmd->int_params[2];
    int length = cmd->int_params[3];

    Shape *rect = create_rectangle_shape(x, y, width, length);
    add_shape_to_area(app->area, rect);
    
    jump_page();
    printf("Le rectangle a ete cree avec succes ;)\n");
}

void cmd_polygon(Command* cmd){
    if(cmd->int_size < 6){
        jump_page();
        printf("Erreur, cette commande doit contenir au minimum trois points en coordonnées\n");
        return;
    }
    if (cmd->int_size % 2 != 0){
        jump_page();
        printf("Erreur, cette commande est de la forme :    polygon x1 y1 x2 y2 ... xn yn\n");
        return;
    }

    Shape *poly = create_polygon_shape(cmd->int_params, cmd->int_size/2);
    add_shape_to_area(app->area, poly);

    jump_page();
    printf("Le polygone a ete cree avec succes a_a\n");
}

void cmd_plot(Command* cmd){
    jump_page();

    draw_area(app->area);
    print_area(app->area);
}

void cmd_list(Command* cmd){
    if (app->area->nb_shape == 0){
        printf("Il n'y a pas de shapes dans l'area :(\n");
        return;
    }
    printf("Listes des shapes :\n");
    for(int i = 0; i < app->area->nb_shape; i++){
        print_shape(app->area->shapes[i]);
    }
}

void cmd_delete(Command* cmd){

    if(cmd->str_size != 1){
        jump_page();
        printf("Erreur, cette commande est de la forme :    delete id\n");
        return;
    }

    for(int i = 0; i < app->area->nb_shape; i++){
        print_shape(app->area->shapes[i]);
    }
    for(int i = 0; i < app->area->nb_shape; i++) {
        if (app->area->shapes[i]->id == cmd->int_params[0]) {
            delete_shape(app->area->shapes[i]);
            app->area->shapes[i] = NULL;
            break;
        }
    }
}

void cmd_erase(Command* cmd){
    erase_area(app->area);
}

void cmd_help(Command* cmd){
    printf("- clear : effacer l'ecran\n"
           "- exit : quitter le programme\n"
           "- point x y : ajouter un point\n"
           "- line x1 y1 x2 y2 : ajouter un segment reliant deux points (x1, y1) et (x2, y2)\n"
           "- circle x y radius : ajouter un cercle de centre (x, y) et de rayon radius\n"
           "- square x y length : ajouter un carre dont le coin superieur gauche est (x, y) et de cote length.\n"
           "- rectangle x y width height : ajouter un rectangle dont le coin superieur gauche est (x, y), de\n"
           "largeur width et de longueur height\n"
           "- polygon x1 y1 x2 y2 x3 y3 ... ... : ajouter un polygone avec la liste des points donnes\n"
           "- plot : rafraichir l'ecran pour afficher toutes les formes geometriques de l'image (en fonction des\n"
           "regles d'affichage)\n"
           "- list : afficher la liste de l'ensemble des formes geometriques qui composent l'image ainsi que\n"
           "toutes leurs informations\n"
           "- delete id : supprimer une forme a partir de son identifiant id.\n"
           "- erase : supprimer toutes les formes d'une image.\n");

}
