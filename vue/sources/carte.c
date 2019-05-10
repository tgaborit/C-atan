/**
 * \file carte.c
 * \brief Implémente les fonctions de carte.h
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage des cartes dans le jeu.
 */

 #include "vue/headers/carte.h"
 #include "vue/headers/SDL_erreur.h"

/**
 * \fn AfficheCarteArgile(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes argile
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteArgile(SDL_Renderer* renderer){
	SDL_Surface *image = NULL;
	SDL_Texture *cargile = NULL;

	image = SDL_LoadBMP("images/carteargile.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	cargile = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(cargile == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectargile;

	if(SDL_QueryTexture(cargile, NULL, NULL, &rectargile.w, &rectargile.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectargile.x = 557.5;
	rectargile.y = 782;


	if(SDL_RenderCopy(renderer, cargile, NULL, &rectargile) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheCarteBle(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes blé
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteBle(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *cble = NULL;

	image = SDL_LoadBMP("images/carteble.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	cble = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(cble == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectble;

	if(SDL_QueryTexture(cble, NULL, NULL, &rectble.w, &rectble.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectble.x = 729.5;
	rectble.y = 784;


	if(SDL_RenderCopy(renderer, cble, NULL, &rectble) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheCarteBois(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes bois
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteBois(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *cbois = NULL;

	image = SDL_LoadBMP("images/cartebois.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	cbois = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(cbois == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectbois;

	if(SDL_QueryTexture(cbois, NULL, NULL, &rectbois.w, &rectbois.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectbois.x = 902.5;
	rectbois.y = 779;


	if(SDL_RenderCopy(renderer, cbois, NULL, &rectbois) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheCarteMouton(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes mouton
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteMouton(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *cmouton = NULL;

	image = SDL_LoadBMP("images/cartemouton.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	cmouton = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(cmouton == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectmouton;

	if(SDL_QueryTexture(cmouton, NULL, NULL, &rectmouton.w, &rectmouton.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectmouton.x = 1075.5;
	rectmouton.y = 780;


	if(SDL_RenderCopy(renderer, cmouton, NULL, &rectmouton) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}


/**
 * \fn AfficheCarteRoche(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes roche
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteRoche(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *croche = NULL;

	image = SDL_LoadBMP("images/carteroche.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	croche = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(croche == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectroche;

	if(SDL_QueryTexture(croche, NULL, NULL, &rectroche.w, &rectroche.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectroche.x = 1251.5;
	rectroche.y = 780;


	if(SDL_RenderCopy(renderer, croche, NULL, &rectroche) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}
