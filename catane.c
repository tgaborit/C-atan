#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "controller_turn.h"
#include "set_partie.h"
#include "fenetre.h"
#include "controller_preparation.h"

int main()
{
    SDL_Window* window = InitFenetre();

    SDL_bool program_launched = SDL_TRUE;


	Partie* partie = init_partie();
	Joueur* j = init_joueur(ROUGE,"Emmanuel Durel");
	add_joueur(j,partie);
	Joueur* k = init_joueur(BLEU,"remi");
	add_joueur(k,partie);

    for(int i=0; i<100; ++i){
        gain_ressource(ARGILE,k);
        gain_ressource(MOUTON,k);
        gain_ressource(BLE,k);
        gain_ressource(BOIS,k);
        gain_ressource(PIERRE,k);
    }

    //controllerTurn(&program_launched, window, partie);

    controllerPreparation(&program_launched, window, partie);

    destroyFenetre(window);

    return EXIT_SUCCESS;

}
