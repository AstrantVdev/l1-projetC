//
// Created by 33611 on 12/04/2023.
//

#include <stdio.h>

#include "interface.h"
#include "struct.h"
#include "shape.h"


int choice(int n_option)
{
    int correct = 1, select = 0;
    printf("\nVotre choix :");
    while(correct) {
        correct = scanf("%d", &select);
        if (correct)
            if ((select < 0) || (select > n_option)) correct = 0;
        if (!correct) {
            printf("\nErreur dans la saisie, veuillez réessayer : ");
        }
    }
    return select;
}


void print_accueuil()
{
    printf("BIENVENUE DANS \"DRAW MY VECT\" : LE LOGICIEL DE DESSIN VECTORIEL"
           "\nActions possibles :\n"
           "\t1- Ajouter une forme\n"
           "\t2- Afficher la liste des formes\n"
           "\t3- Supprimer une forme\n"
           "\t4- Tracer le dessin\n"
           "\t5- Aide\n"
           "\t6- Quitter le logiciel\n");
}


void print_list_shape(Shape* list_shape, int len)
{
    printf("\nListe des formes :");
    for(int i = 0; i < len; i++){
        printf("\n\t-%d : ", i);
        print_shape(list_shape+i);
    }
}


void print_dessin()
{
    printf("\n\nA venir prochainement \n\n");
}

void print_add_shape()
{
    printf("Veuillez choisir une action :\n"
           "\t1- Ajouter un point\n"
           "\t2- Ajouter une ligne\n"
           "\t3- Ajouter cercle\n"
           "\t4- Ajouter un carre\n"
           "\t5- Ajouter un rectangle\n"
           "\t6- Ajouter un polygone\n"
           "\t7- Revenir au menu precedent\n");
}