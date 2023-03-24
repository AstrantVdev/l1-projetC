#include <stdio.h>
#include <fonctions.h>
unsigned int global_id = 0;

int main (){

    for(int i = 0; i < 25; i++){
        printf("%d", i);
        for(int j = 0; j < 80; j++) printf(".");
        printf("\n");
    }
    return 0;
};