/*
    l1-project C : Dessin vectoriel
           --------
           | ID.C |
           --------

Défini la fonction get_next_id() pour récupérer un identifiant.

Réalisé par DELHAYE Guillaume et PORTAL Sacha

*/

#include "id.h"



unsigned int get_next_id()
{
    /* Retourne le prochain identifiant disponible, puis incrémente
    la valeur actuelle */

    // Définition rémanente de l'identifiant
    static int global_id = 1;
    return global_id++;
}
