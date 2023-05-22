/*
    l1-project C : Dessin vectoriel
           --------------
           | COMMANDS.H |
           --------------

Déclare l'ensemble des fonctions permettant de gérer, d'executer
et de lire les commandes.
Défini aussi la structure Command.

Réalisé par DELHAYE Guillaume et PORTAL Sacha

*/

#ifndef L1_PROJECT_COMMANDS_H
#define L1_PROJECT_COMMANDS_H

#include "area.h"

typedef struct {
    char name[50];
    int int_size;
    int int_params[10];
    int str_size;
    char* str_params[10];
} Command;

Command* create_commande();

void add_str_param(Command* cmd, char* p);
void add_int_param(Command* cmd, int p);
void free_cmd(Command* cmd);
void read_exec_command(Command* cmd);
void read_from_stdin(Command* cmd);

void jump_page();


void cmd_clear();
void cmd_exit();
void cmd_point(Command* cmd);
void cmd_line(Command* cmd);
void cmd_circle(Command* cmd);
void cmd_square(Command* cmd);
void cmd_rectangle(Command* cmd);
void cmd_polygon(Command* cmd);
void cmd_plot();
void cmd_list();
void cmd_delete(Command* cmd);
void cmd_erase();
void cmd_help();

#endif //L1_PROJECT_COMMANDS_H