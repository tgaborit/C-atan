#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "controller_turn.h"
#include "set_partie.h"
#include "fenetre.h"
#include "controller_preparation.h"
#include "controller_dice.h"
#include "controller.h"

int main()
{
    SDL_Window* window = InitFenetre();

    SDL_bool program_launched = SDL_TRUE;


	Partie* partie = init_partie();
	Joueur* j = init_joueur(ROUGE,"Emmanuel Durel");
	add_joueur(j,partie);
	Joueur* k = init_joueur(BLEU,"remi");
	add_joueur(k,partie);
//	Joueur* f = init_joueur(BLANC,"pauline");
//	add_joueur(f,partie);
//	Joueur* g = init_joueur(ORANGE,"titou");
//	add_joueur(g,partie);

    for(int i=0; i<100; ++i){
        gain_ressource(ARGILE,k);
        gain_ressource(MOUTON,k);
        gain_ressource(BLE,k);
        gain_ressource(BOIS,k);
        gain_ressource(PIERRE,k);
    }

    controllerPreparation(&program_launched, window, partie);

    while (program_launched == SDL_TRUE)
    {
        controllerDice(&program_launched, window, partie);
        if(program_launched == SDL_FALSE)
            break;

        controllerTurn(&program_launched, window, partie);

        if(get_score_max(partie) >= 10)
            quit(&program_launched);

        passer_tour(partie);
    }

    destroyFenetre(window);

    return EXIT_SUCCESS;

}
