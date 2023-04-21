//
// Created by 33611 on 12/04/2023.
//

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "struct.h"
#include "shape.h"


int choice(int n_option, int n_tab)
{
    int correct = 1, select = 0;
    for(int i = 0; i < n_tab; i++) printf("\t");
    printf("\nVotre choix :");
    while(correct) {
        correct = scanf("%d", &select);
        if (correct)
            if ((select <= 0) || (select > n_option)) correct = 0;
        if (!correct) {
            for(int i = 0; i < n_tab; i++) printf("\t");
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


void print_list_shape(Shape** list_shape, int len)
{
    printf("\nListe des formes :");
    for(int i = 0; i < len; i++){
        printf("\n\t-%d : ", i);
        print_shape(*(list_shape+i));
    }
}


void print_dessin()
{
    printf("\n\nA venir prochainement \n\n");
}

void add_shape(Shape** list_shape, int* n_shape)
{
    int choice_shape = 1;
    printf("\tVeuillez choisir une action :\n"
           "\t\t1- Ajouter un point\n"
           "\t\t2- Ajouter une ligne\n"
           "\t\t3- Ajouter un cercle\n"
           "\t\t4- Ajouter un carre\n"
           "\t\t5- Ajouter un rectangle\n"
           "\t\t6- Ajouter un polygone\n"
           "\t\t7- Revenir au menu precedent\n");
    while(choice_shape){
        choice_shape = choice(7, 1);
        switch(choice_shape){
            case 1 :{
                list_shape[*n_shape] = print_add_point();
                (*n_shape)++;
                break;
            }case 2 :{
                list_shape[*n_shape] = print_add_line();
                (*n_shape)++;
                break;
            }case 3 :{
                list_shape[*n_shape] = print_add_circle();
                (*n_shape)++;
                break;
            }case 4 :{
                list_shape[*n_shape] = print_add_square();
                (*n_shape)++;
                break;
            }case 5 :{
                list_shape[*n_shape] = print_add_rectangle();
                (*n_shape)++;
                break;
            }case 6 :{
                list_shape[*n_shape] = print_add_polygon();
                (*n_shape)++;
                break;
            }case 7 :{
                choice_shape = 0;
                break;
            }
            default:{
                printf("Error");
                choice_shape = 0;
                break;
            }
        }
    }

}

int* add_points(int nb_point)
{
    int success = 0;
    int *coords = (int*) malloc(sizeof(int)*nb_point);
    if (nb_point == 1){
        printf("\n\t\tSaisir les coordonnées du point x y : ");
        success = scanf("%d %d", coords, coords+1);
        while (!success){
            printf("\n\t\tErreur dans la saisie, veuillez resaisir les coordonnées x y : ");
            success = scanf("%d %d", coords, coords+1);
        }
    }else{
        for (int i = 0; i < nb_point; i++) {
            printf("\n\t\tSaisir les coordonnées du point n°%d x%d y%d :", i, i, i);
            success = scanf("%d %d", coords + 2 * i, coords + 2 * i + 1);
            while (!success) {
                printf("\n\t\tErreur dans la saisie, veuillez resaisir les coordonnées x%d y%d : ", i, i);
                success = scanf("%d %d", coords + 2 * i, coords + 2 * i + 1);
            }
        }
    }
    return coords;
}

void add_radius(int* radius)
{
    int success = 0;
    printf("\n\t\tSaisir le rayon du cercle : ");
    success = scanf("%d", radius);
    while (!success){
        printf("\n\t\tErreur dans la saisie, veuillez resaisir le rayon : ");
        success = scanf("%d", radius);
    }
}

void add_size_rectangle(int* width, int* height)
{
    int success = 0;
    printf("\n\t\tSaisir la longueur du rectangle : ");
    success = scanf("%d", width);
    while (!success){
        printf("\n\t\tErreur dans la saisie, veuillez resaisir la longueur : ");
        success = scanf("%d", width);
    }
    printf("\n\t\tSaisir la largeur du rectangle : ");
    success = scanf("%d", height);
    while (!success){
        printf("\n\t\tErreur dans la saisie, veuillez resaisir la largeur : ");
        success = scanf("%d", height);
    }
}

void add_length_square(int* length)
{
    int success = 0;
    printf("\n\t\tSaisir la longueur du carré : ");
    success = scanf("%d", length);
    while (!success){
        printf("\n\t\tErreur dans la saisie, veuillez resaisir la longueur : ");
        success = scanf("%d", length);
    }
}

void add_nb_points(int* nb_points)
{
    int success = 0;
    printf("\n\t\tSaisir le nombre de point du polygone : ");
    success = scanf("%d", nb_points);
    while (!success){
        printf("\n\t\tErreur dans la saisie, veuillez resaisir le nombre de point : ");
        success = scanf("%d", nb_points);
    }
}

Shape *print_add_point()
{
    int* coords;
    Shape* point;
    printf("\n\t\tAjout d'un point :");
    coords = add_points(1);
    point = create_point_shape(coords[0], coords[1]);
    free(coords);
    return point;
}
Shape *print_add_line()
{
    int* coords;
    Shape* line;
    printf("\n\t\tAjout d'une ligne :");
    coords = add_points(2);
    line = create_line_shape(coords[0], coords[1], coords[2], coords[3]);
    free(coords);
    return line;
}
Shape *print_add_circle()
{
    int radius = 0, *coords;
    Shape* circle;
    printf("\n\t\tAjout d'un cercle :");

    coords = add_points(1);
    add_radius(&radius);

    circle = create_circle_shape(coords[0], coords[1], radius);
    free(coords);
    return circle;
}
Shape *print_add_square()
{
    int length = 0, *coords;
    Shape* square;
    printf("\n\t\tAjout d'un carré :");

    coords = add_points(1);
    add_length_square(&length);

    square = create_square_shape(coords[0], coords[1], length);
    free(coords);
    return square;
}
Shape *print_add_rectangle()
{
    int width = 0, height = 0, *coords;
    Shape* rectangle;
    printf("\n\t\tAjout d'un carré :");

    coords = add_points(1);
    add_size_rectangle(&width, &height);

    rectangle = create_rectangle_shape(coords[0], coords[1], width, height);
    free(coords);
    return rectangle;
}

Shape *print_add_polygon()
{
    int *coords, nb_point = 0;
    Shape* polygon;
    printf("\n\t\tAjout d'un carré :");

    add_nb_points(&nb_point);
    coords = add_points(nb_point);

    polygon = create_polygon_shape(coords, nb_point);
    free(coords);
    return polygon;
}