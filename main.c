/*
    l1-project C : Dessin vectoriel
           ----------
           | MAIN.C |
           ----------

Fichier principal du programme.
Initialise l'application et lance la boucle principale.
Permet de lire la saisie de l'utilisateur et d'exécuter les commandes.

Réalisé par DELHAYE Guillaume et PORTAL Sacha

*/

#include <stdio.h>
#include <stdlib.h>

#include "area.h"
#include "pixel.h"
#include "commands.h"

// Etat et zone de dessin de l'application, défini comme variable globale
App *app= NULL;

int main(){
    app = (App*) malloc(sizeof(App));
    app->area = create_area(100, 25);
    app->running = 1;
    app->area->nb_shape = 0;

    print_area(app->area);

    // Boucle principale
    while(app->running){
        Command *cmd = create_commande();
        read_from_stdin(cmd);
        read_exec_command(cmd);
        free_cmd(cmd);
    }

    // Suppression de la zone de dessin
    delete_area(app->area);

    return 0;
}