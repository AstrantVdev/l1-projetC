#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "commands.h"

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

}

void cmd_exit(Command* cmd){

}

void cmd_point(Command* cmd){

}

void cmd_line(Command* cmd){

}

void cmd_circle(Command* cmd){

}

void cmd_square(Command* cmd){

}

void cmd_rectangle(Command* cmd){

}

void cmd_polygon(Command* cmd){

}

void cmd_plot(Command* cmd){

}

void cmd_list(Command* cmd){

}

void cmd_delete(Command* cmd){

}

void cmd_erase(Command* cmd){

}

void cmd_help(Command* cmd){

}
