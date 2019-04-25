#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "Plateau.h"


void AfficheBouttonDev(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

	SDL_Rect bouttondev;
	bouttondev.x = 1520;
	bouttondev.y = 300;
	bouttondev.w = 200;
	bouttondev.h = 75;

	if(SDL_RenderFillRect(renderer, &bouttondev) != 0)
		SDL_ExitWithError("Impossible de remplir un rectangle");

	SDL_RenderPresent(renderer);
}


void AfficheBouttonRoute(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

	SDL_Rect bouttonroute;
	bouttonroute.x = 1520;
	bouttonroute.y = 425;
	bouttonroute.w = 200;
	bouttonroute.h = 75;

	if(SDL_RenderFillRect(renderer, &bouttonroute) != 0)
		SDL_ExitWithError("Impossible de remplir un rectangle");

	SDL_RenderPresent(renderer);
}


void AfficheBouttonColonie(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

	SDL_Rect bouttoncolonie;
	bouttoncolonie.x = 1520;
	bouttoncolonie.y = 550;
	bouttoncolonie.w = 200;
	bouttoncolonie.h = 75;

	if(SDL_RenderFillRect(renderer, &bouttoncolonie) != 0)
		SDL_ExitWithError("Impossible de remplir un rectangle");

	SDL_RenderPresent(renderer);
}


void AfficheBouttonVille(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

	SDL_Rect bouttonville;
	bouttonville.x = 1520;
	bouttonville.y = 675;
	bouttonville.w = 200;
	bouttonville.h = 75;

	if(SDL_RenderFillRect(renderer, &bouttonville) != 0)
		SDL_ExitWithError("Impossible de remplir un rectangle");

	SDL_RenderPresent(renderer);
}

