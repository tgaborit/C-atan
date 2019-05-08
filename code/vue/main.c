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
#include "affiche_texte.h"
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

    AfficheTexte_Init(renderer);

    SDL_Delay(1000);

    partie->plateau->adjacence[0]->t->a[4].i = ROUTE;
    partie->plateau->adjacence[0]->t->a[4].owner = k;

    partie->plateau->adjacence[0]->t->a[3].i = ROUTE;
    partie->plateau->adjacence[0]->t->a[3].owner = k;

    partie->plateau->adjacence[0]->t->s[3].i = VILLE;
    partie->plateau->adjacence[0]->t->s[3].owner = k;

    partie->plateau->adjacence[5]->t->s[2].i = VILLE;
    partie->plateau->adjacence[5]->t->s[2].owner = j;

    partie->plateau->adjacence[5]->t->s[3].i = VILLE;
    partie->plateau->adjacence[5]->t->s[3].owner = j;

    partie->plateau->adjacence[5]->t->a[2].i = ROUTE;
    partie->plateau->adjacence[5]->t->a[2].owner = j;

    partie->plateau->adjacence[5]->t->a[3].i = ROUTE;
    partie->plateau->adjacence[5]->t->a[3].owner = j;



    renderer = updateFenetre(partie,window,renderer);

    SDL_Delay(2000);
    AfficheTexte_PosColonie(renderer);
    SDL_Delay(2000);
    AfficheTexte_PosRoute(renderer);
    SDL_Delay(2000);
    AfficheTexte_PosVille(renderer);
    SDL_Delay(2000);
    AfficheTexte_Joueur(renderer);
    SDL_Delay(2000);
    AfficheTexte_PosRoute(renderer);
    SDL_Delay(2000);
    AfficheTexte_PosVille(renderer);
    SDL_Delay(2000);
    AfficheTexte_PosRoute(renderer);
    SDL_Delay(2000);
    AfficheTexte_Joueur(renderer);
    SDL_Delay(2000);
    AfficheTexte_PosVille(renderer);
    SDL_Delay(2000);
    AfficheTexte_PosRoute(renderer);
    SDL_Delay(2000);

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
