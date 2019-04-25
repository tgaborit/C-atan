#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "Plateau.h"



void SDL_ExitWithError(const char *message)
{
	SDL_Log("ERREUR : Initialisation SDL > %s\n", SDL_GetError());
	SDL_Quit();
        exit(EXIT_FAILURE);
}


//Carte Argile
void AfficheCarteArgile(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *cargile = NULL;

	image = SDL_LoadBMP("imagecatane/carteargile.bmp");

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

//Carte Blé
void AfficheCarteBle(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *cble = NULL;

	image = SDL_LoadBMP("imagecatane/carteble.bmp");

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

//Carte Bois
void AfficheCarteBois(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *cbois = NULL;

	image = SDL_LoadBMP("imagecatane/cartebois.bmp");

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

//Carte Mouton
void AfficheCarteMouton(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *cmouton = NULL;

	image = SDL_LoadBMP("imagecatane/cartemouton.bmp");

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



//Carte Roche
void AfficheCarteRoche(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *croche = NULL;

	image = SDL_LoadBMP("imagecatane/carteroche.bmp");

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
