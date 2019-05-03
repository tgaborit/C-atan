#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "partie.h"
#include "test_plateau.h"
#include "test_get_plateau.h"
#include "test_set_plateau.h"
#include "UTest-joueur.h"
#include "UTest-partie.h"
#include "fenetre.h"


int main(int argc, char** argv)
{
	//main_partie_test();
	//main_get_plateau_test();
	//main_set_plateau_test();
	//main_test();
	//main_joueur_test();
	SDL_Window* window = InitFenetre();
	SDL_Renderer* renderer = NULL;

	Partie* partie = init_partie();
	Joueur* j = init_joueur(ROUGE,"manu");
	add_joueur(j,partie);
	Joueur* k = init_joueur(BLEU,"remi");

	renderer = updateFenetre(partie,window,renderer);

	partie->plateau->adjacence[0]->t->s[3].i = VILLE;
	partie->plateau->adjacence[0]->t->s[3].owner = j;


	renderer = updateFenetre(partie,window,renderer);

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
