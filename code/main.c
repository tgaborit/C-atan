#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "controleur/controller_turn.h"
#include "modele/headers/set_partie.h"
#include "vue/fenetre.h"

int main()
{
    SDL_Window* window = InitFenetre();

    SDL_bool program_launched = SDL_TRUE;


	Partie* partie = init_partie();
	Joueur* j = init_joueur(ROUGE,"Emmanuel Durel");
	add_joueur(j,partie);
	Joueur* k = init_joueur(BLEU,"remi");
	add_joueur(k,partie);

    partie->plateau->adjacence[0]->t->a[4].i=ROUTE;
    partie->plateau->adjacence[1]->t->a[1].i=ROUTE;
    partie->plateau->adjacence[0]->t->a[4].owner=k;
    partie->plateau->adjacence[1]->t->a[1].owner=k;


    for(int i=0; i<100; ++i){
        gain_ressource(ARGILE,k);
        gain_ressource(MOUTON,k);
        gain_ressource(BLE,k);
        gain_ressource(BOIS,k);
        gain_ressource(PIERRE,k);
        gain_ressource(PIERRE,j);
    }

    controllerTurn(&program_launched, window, partie);

    destroyFenetre(window);

    return EXIT_SUCCESS;

}
