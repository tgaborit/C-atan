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
 * \fn AfficheBoutonDev(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des cartes développement
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */

void AfficheBoutonDev(SDL_Renderer *renderer)
{
    SDL_Surface* image = NULL;
	SDL_Texture* boutondev = NULL;

	image = SDL_LoadBMP("../images/dev.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image dev.bmp");

	boutondev = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(boutondev == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectboutondev;

	if(SDL_QueryTexture(boutondev, NULL, NULL, &rectboutondev.w, &rectboutondev.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectboutondev.x = 1520;
	rectboutondev.y = 300;


	if(SDL_RenderCopy(renderer, boutondev, NULL, &rectboutondev) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn AfficheBoutonRoute(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des routes
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBoutonRoute(SDL_Renderer *renderer)
{
    SDL_Surface* image = NULL;
	SDL_Texture* boutonroute = NULL;

	image = SDL_LoadBMP("../images/boutonroute.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image boutonroute.bmp");

	boutonroute = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(boutonroute == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectboutonroute;

	if(SDL_QueryTexture(boutonroute, NULL, NULL, &rectboutonroute.w, &rectboutonroute.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectboutonroute.x = 1520;
	rectboutonroute.y = 425;


	if(SDL_RenderCopy(renderer, boutonroute, NULL, &rectboutonroute) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn AfficheBoutonColonie(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des colonies
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBoutonColonie(SDL_Renderer *renderer)
{
 SDL_Surface* image = NULL;
	SDL_Texture* boutoncolonie = NULL;

	image = SDL_LoadBMP("../images/boutoncolonie.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image bouton colonie.bmp");

	boutoncolonie = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(boutoncolonie == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectboutoncolonie;

	if(SDL_QueryTexture(boutoncolonie, NULL, NULL, &rectboutoncolonie.w, &rectboutoncolonie.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectboutoncolonie.x = 1520;
	rectboutoncolonie.y = 550;


	if(SDL_RenderCopy(renderer, boutoncolonie, NULL, &rectboutoncolonie) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn AfficheBoutonVille(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des villes
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBoutonVille(SDL_Renderer *renderer)
{
    SDL_Surface* image = NULL;
	SDL_Texture* boutonville = NULL;

	image = SDL_LoadBMP("../images/boutonville.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image boutonville.bmp");

	boutonville = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(boutonville == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectboutonville;

	if(SDL_QueryTexture(boutonville, NULL, NULL, &rectboutonville.w, &rectboutonville.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectboutonville.x = 1520;
	rectboutonville.y = 675;


	if(SDL_RenderCopy(renderer, boutonville, NULL, &rectboutonville) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

