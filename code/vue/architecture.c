/**
 * \file architecture.c
 * \brief Implémente les fonctions de architecture.h
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage des constructions dans le jeu.
 */

#include "architecture.h"

/**
 * \fn AfficheBouttonDev(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des cartes développement
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */

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

/**
 * \fn AfficheBouttonRoute(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des routes
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
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

/**
 * \fn AfficheBouttonColonie(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des colonies
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
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

/**
 * \fn AfficheBouttonVille(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des villes
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
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

