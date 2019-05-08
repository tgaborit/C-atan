#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "partie.h"
#include "test_plateau.h"
#include "test_get_plateau.h"
#include "test_set_plateau.h"
#include "UTest-joueur.h"
#include "UTest-set_partie.h"
#include "affiche_texte.h"
#include "fenetre.h"


int main(int argc, char** argv)
{
	main_partie_test();
	main_get_plateau_test();
	main_set_plateau_test();
	main_test();
	main_joueur_test();

	SDL_Window* window = InitFenetre();
	SDL_Renderer* renderer = NULL;

	Partie* partie = init_partie();
	Joueur* j = init_joueur(ROUGE,"Emmanuel Durel");
	add_joueur(j,partie);
	Joueur* k = init_joueur(BLEU,"remi");
	add_joueur(k,partie);

	renderer = updateFenetre(partie,window,renderer);

	AfficheTexte_CarteDev_Succes(renderer);
	AfficheTexte_CarteDev_Echec(renderer);
	AfficheTexte_ChoixRessource(renderer);
	AfficheTexte_Monopole_Echec(renderer);
	AfficheTexte_Monopole_Succes(renderer);
    AfficheTexte_Decouverte_Echec(renderer);
	AfficheTexte_Decouverte_Succes(renderer);
    AfficheTexte_Point_Echec(renderer);
	AfficheTexte_Point_Succes(renderer);
	AfficheTexte_Routes_Echec(renderer);
	AfficheTexte_Routes_Succes(renderer);
	AfficheTexte_ChoixRoutes(renderer);

    SDL_bool program_launched = SDL_TRUE;

	while(program_launched)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{

				case SDL_KEYDOWN :
					switch(event.key.keysym.sym)
					{
						case SDLK_q :
							program_launched = SDL_FALSE;
							break;
						default :
							continue;
					}

				case SDL_QUIT :
					program_launched = SDL_FALSE;
					break;


				default :
					break;
			}
		}
	}
	destroyFenetre(window,renderer);

	return EXIT_SUCCESS;
}
