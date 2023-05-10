#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

}

void read_from_stdin(Command* cmd){
    printf("Entrez une commande :\n> ");

    char c[64];
    fgets(c, 64, stdin);

    char *ptr = strtok(c, " ");

    while(ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

}