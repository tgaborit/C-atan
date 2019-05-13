/**
 * \file developpement.c
 * \brief Implémente les fonctions de developpement.h
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage des cartes de développement dans le jeu.
 */

#include "developpement.h"

//Carte Developpement
/*void AfficheCartesDev(SDL_Renderer *renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;

	image = SDL_LoadBMP("images/cartedev.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(texture == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectangle;

	if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectangle.x = 1251.5;
	rectangle.y = 780;


	if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}*/

/**
 * \fn AfficheChevalier(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Chevalier
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheChevalier(SDL_Renderer *renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *chevalier = NULL;

	image = SDL_LoadBMP("images/chevalier.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	chevalier = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(chevalier == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectchevalier;

	if(SDL_QueryTexture(chevalier, NULL, NULL, &rectchevalier.w, &rectchevalier.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectchevalier.x = 100;
	rectchevalier.y = 275;


	if(SDL_RenderCopy(renderer, chevalier, NULL, &rectchevalier) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}


/**
 * \fn AfficheMonopole(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Monopole
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheMonopole(SDL_Renderer *renderer)
{
	SDL_Surface* image = NULL;
	SDL_Texture* monopole = NULL;

	image = SDL_LoadBMP("images/monopole.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	monopole = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(monopole == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectmonopole;

	if(SDL_QueryTexture(monopole, NULL, NULL, &rectmonopole.w, &rectmonopole.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectmonopole.x = 100;
	rectmonopole.y = 375;


	if(SDL_RenderCopy(renderer, monopole, NULL, &rectmonopole) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheInvention(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Invention
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheInvention(SDL_Renderer *renderer)
{
	SDL_Surface* image = NULL;
	SDL_Texture* invention = NULL;

	image = SDL_LoadBMP("images/invention.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	invention = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(invention == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectinvention;

	if(SDL_QueryTexture(invention, NULL, NULL, &rectinvention.w, &rectinvention.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectinvention.x = 100;
	rectinvention.y = 475;


	if(SDL_RenderCopy(renderer, invention, NULL, &rectinvention) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheRouteDev(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Route
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheRouteDev(SDL_Renderer *renderer)
{
	SDL_Surface* image = NULL;
	SDL_Texture* route = NULL;

	image = SDL_LoadBMP("images/routedev.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	route = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(route == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectroute;

	if(SDL_QueryTexture(route, NULL, NULL, &rectroute.w, &rectroute.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectroute.x = 100;
	rectroute.y = 575;


	if(SDL_RenderCopy(renderer, route, NULL, &rectroute) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheUniversite(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Universite
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheUniversite(SDL_Renderer *renderer)
{
	SDL_Surface* image = NULL;
	SDL_Texture* universite = NULL;

	image = SDL_LoadBMP("images/universite.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	universite = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(universite == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectuniversite;

	if(SDL_QueryTexture(universite, NULL, NULL, &rectuniversite.w, &rectuniversite.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectuniversite.x = 100;
	rectuniversite.y = 675;


	if(SDL_RenderCopy(renderer, universite, NULL, &rectuniversite) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheGrandeArmee(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte réussite de la Plus Grande Armée
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheGrandeArmee(SDL_Renderer *renderer)
{
    SDL_Surface* image = NULL;
	SDL_Texture* reussitechevalier = NULL;

	image = SDL_LoadBMP("images/cartereussitechevalier.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	reussitechevalier = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(reussitechevalier == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectreussitechevalier;

	if(SDL_QueryTexture(reussitechevalier, NULL, NULL, &rectreussitechevalier.w, &rectreussitechevalier.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectreussitechevalier.x = 150;
	rectreussitechevalier.y = 75;


	if(SDL_RenderCopy(renderer, reussitechevalier, NULL, &rectreussitechevalier) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheGrandeRoute(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte réussite du Plus Grand Nombre de Route
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheGrandeRoute(SDL_Renderer *renderer)
{
    SDL_Surface* image = NULL;
	SDL_Texture* reussiteroute = NULL;

	image = SDL_LoadBMP("images/cartereussiteroute.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	reussiteroute = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(reussiteroute == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectreussiteroute;

	if(SDL_QueryTexture(reussiteroute, NULL, NULL, &rectreussiteroute.w, &rectreussiteroute.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectreussiteroute.x = 325;
	rectreussiteroute.y = 75;


	if(SDL_RenderCopy(renderer, reussiteroute, NULL, &rectreussiteroute) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}