/**
* \file catane.c
* \brief Programme du jeu Catane
* \author Titouan Gaborit
* \date 25 avril 2019
*
* Fichier contenant la fonction main du jeu Catane
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "controller_turn.h"
#include "set_partie.h"
#include "fenetre.h"
#include "controller_preparation.h"
#include "controller_dice.h"
#include "controller.h"
#include "affiche_texte.h"

/**
* \fn int main()
* \brief Entree du programme
*
* \return 0 si arret normal
*/
int main()
{
    SDL_Window* window = InitFenetre();

    SDL_bool program_launched = SDL_TRUE;


	Partie* partie = init_partie();
	Joueur* j = init_joueur(ROUGE,"Emmanuel Durel");
	add_joueur(j,partie);
	Joueur* k = init_joueur(BLEU,"remi");
	add_joueur(k,partie);
	Joueur* f = init_joueur(BLANC,"pauline");
	add_joueur(f,partie);
	Joueur* g = init_joueur(ORANGE,"titou");
	add_joueur(g,partie);

    for(int i=0; i<10; ++i){
        gain_ressource(ARGILE,k);
        gain_ressource(MOUTON,k);
        gain_ressource(BLE,k);
        gain_ressource(BOIS,k);
        gain_ressource(PIERRE,k);

        gain_ressource(ARGILE,j);
        gain_ressource(MOUTON,j);
        gain_ressource(BLE,j);
        gain_ressource(BOIS,j);
        gain_ressource(PIERRE,j);
    }

    controllerPreparation(&program_launched, window, partie);

    while (program_launched == SDL_TRUE)
    {
        AfficheTexte_Joueur(window, partie);
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
