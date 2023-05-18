//
// Created by 33611 on 12/04/2023.
//

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "shape.h"


int choice(int n_option, int character)
{
    int correct = 0;
    char select_char = 'n';
    int select_int = 0;

    int borne_inf = 0, borne_sup = n_option;
    if (character)
    {
        borne_inf = 65;
        borne_sup = 65 + n_option-1;
    }

    printf("\nVotre choix :");
    while(!correct) {
        if (character) {
            fflush(stdin);
            correct = scanf(" %c", &select_char);
        }
        else {
            fflush(stdin);
            correct = scanf("%d", &select_int);
        }
        if (correct){
            if (character) {
                if ((select_char < borne_inf) || (select_char > borne_sup)) correct = 0;
            }else if ((select_int < borne_inf) || (select_int > borne_sup)) correct = 0;
        }
        if (!correct) {
            printf("\nErreur dans la saisie, veuillez reessayer : ");
        }
    }
    if (character) return select_char - 64;
    else return select_int;
}


void print_accueuil()
{
    printf("BIENVENUE DANS \"DRAW MY VECT\" : LE LOGICIEL DE DESSIN VECTORIEL"
           "\nActions possibles :\n"
           "\tA- Ajouter une forme\n"
           "\tB- Afficher la liste des formes\n"
           "\tC- Supprimer une forme\n"
           "\tD- Tracer le dessin\n"
           "\tE- Aide\n"
           "\tF- Quitter le logiciel\n");
}


void print_list_shape(Shape** list_shape, int len)
{
    if (len == 0) printf("\nListe vide\n\n");
    else{
        printf("\nListe des formes :\n\n");
        for(int i = 0; i < len; i++) {
            print_shape(list_shape[i]);
        }
        printf("\n");
    }
}

int* ask_points(int nb_point)
{
    int success = 0;
    int *coords = (int*) malloc(sizeof(int)*nb_point*2);
    if (nb_point == 1){
        printf("\nSaisir les coordonnees du point x y : ");
        fflush(stdin);
        success = scanf("%d %d", coords, coords+1);
        while (!success){
            printf("\nErreur dans la saisie, veuillez resaisir les coordonnees x y : ");
            fflush(stdin);
            success = scanf("%d %d", coords, coords+1);
        }
    }else{
        for (int i = 0; i < nb_point; i++) {
            printf("\nSaisir les coordonnees du point %d x%d y%d :", i+1, i+1, i+1);
            fflush(stdin);
            success = scanf("%d %d", coords + 2 * i, coords + 2 * i + 1);
            while (!success) {
                printf("\nErreur dans la saisie, veuillez resaisir les coordonnees x%d y%d : ", i+1, i+1);
                fflush(stdin);
                success = scanf("%d %d", coords + 2 * i, coords + 2 * i + 1);
            }
        }
    }
    return coords;
}

void ask_radius(int* radius)
{
    int success = 0;
    printf("\nSaisir le rayon du cercle : ");
    fflush(stdin);
    success = scanf("%d", radius);
    while (!success){
        printf("\nErreur dans la saisie, veuillez resaisir le rayon : ");
        fflush(stdin);
        success = scanf("%d", radius);
    }
}

void ask_size_rectangle(int* width, int* height)
{
    int success = 0;
    printf("\nSaisir la longueur du rectangle : ");
    fflush(stdin);
    success = scanf("%d", width);
    while (!success){
        printf("\nErreur dans la saisie, veuillez resaisir la longueur : ");
        fflush(stdin);
        success = scanf("%d", width);
    }
    printf("\nSaisir la largeur du rectangle : ");
    fflush(stdin);
    success = scanf("%d", height);
    while (!success){
        printf("\nErreur dans la saisie, veuillez resaisir la largeur : ");
        fflush(stdin);
        success = scanf("%d", height);
    }
}

void ask_length_square(int* length)
{
    int success = 0;
    printf("\nSaisir la longueur du carre : ");
    fflush(stdin);
    success = scanf("%d", length);
    while (!success){
        printf("\nErreur dans la saisie, veuillez resaisir la longueur : ");
        fflush(stdin);
        success = scanf("%d", length);
    }
}

void ask_nb_points(int* nb_points)
{
    int success = 0;
    printf("\nSaisir le nombre de point du polygone (minimum 3) : ");
    fflush(stdin);
    success = scanf("%d", nb_points);
    while (!success || *nb_points < 3){
        printf("\nErreur dans la saisie, veuillez resaisir le nombre de point (minimum 3) : ");
        fflush(stdin);
        success = scanf("%d", nb_points);
    }
}

Shape *add_point()
{
    int* coords;
    Shape* point;
    printf("\n|| Ajout d'un point ||");
    coords = ask_points(1);
    point = create_point_shape(coords[0], coords[1]);
    free(coords);
    return point;
}
Shape *add_line()
{
    int* coords;
    Shape* line;
    printf("\n|| Ajout d'une ligne ||");
    coords = ask_points(2);
    line = create_line_shape(coords[0], coords[1], coords[2], coords[3]);
    free(coords);
    return line;
}
Shape *add_circle()
{
    int radius = 0, *coords;
    Shape* circle;
    printf("\n|| Ajout d'un cercle ||");

    coords = ask_points(1);
    ask_radius(&radius);

    circle = create_circle_shape(coords[0], coords[1], radius);
    free(coords);
    return circle;
}
Shape *add_square()
{
    int length = 0, *coords;
    Shape* square;
    printf("\n|| Ajout d'un carre ||");

    coords = ask_points(1);
    ask_length_square(&length);

    square = create_square_shape(coords[0], coords[1], length);
    free(coords);
    return square;
}
Shape *add_rectangle()
{
    int width = 0, height = 0, *coords;
    Shape* rectangle;
    printf("\n|| Ajout d'un rectangle ||");

    coords = ask_points(1);
    ask_size_rectangle(&width, &height);

    rectangle = create_rectangle_shape(coords[0], coords[1], width, height);
    free(coords);
    return rectangle;
}

Shape *add_polygon()
{
    int *coords, nb_point = 0;
    Shape* polygon;
    printf("\n|| Ajout d'un polygone ||");

    ask_nb_points(&nb_point);
    coords = ask_points(nb_point);

    polygon = create_polygon_shape(coords, nb_point);
    free(coords);
    return polygon;
}