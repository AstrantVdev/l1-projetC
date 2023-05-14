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
int read_exec_command(Command* cmd);
void read_from_stdin(Command* cmd);



void cmd_clear(Command* cmd);
void cmd_exit(Command* cmd);
void cmd_point(Command* cmd);
void cmd_line(Command* cmd);
void cmd_circle(Command* cmd);
void cmd_square(Command* cmd);
void cmd_rectangle(Command* cmd);
void cmd_polygon(Command* cmd);
void cmd_plot(Command* cmd);
void cmd_list(Command* cmd);
void cmd_delete(Command* cmd);
void cmd_erase(Command* cmd);
void cmd_help(Command* cmd);

#endif //L1_PROJECT_COMMANDS_H