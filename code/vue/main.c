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

	renderer = updateFenetre(partie,window,renderer);

    partie->plateau->adjacence[0]->adjacence[0]->t->s[2].i=COLONIE;
    //partie->plateau->adjacence[0]->adjacence[2]->t->s[4].i=COLONIE;
    //partie->plateau->adjacence[0]->t->s[0].i=COLONIE;
    partie->plateau->adjacence[2]->adjacence[2]->t->s[2].i=COLONIE;
    partie->plateau->adjacence[3]->adjacence[1]->t->s[5].i=COLONIE;

    partie->plateau->adjacence[5]->t->s[3].i=VILLE;
    partie->plateau->adjacence[5]->adjacence[3]->t->s[4].i=VILLE;

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
