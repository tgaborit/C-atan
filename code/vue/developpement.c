#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "Plateau.h"

//Carte Developpement
/*void AfficheCartesDev(SDL_Renderer *renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;
	
	image = SDL_LoadBMP("imagecatane/cartedev.bmp");

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


void AfficheChevalier(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect chevalier;
	chevalier.x = 100;
	chevalier.y = 275;
	chevalier.w = 400;
	chevalier.h = 75;
	
	if(SDL_RenderFillRect(renderer, &chevalier) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}



void AfficheMonopole(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect monopole;
	monopole.x = 100;
	monopole.y = 375;
	monopole.w = 400;
	monopole.h = 75;
	
	if(SDL_RenderFillRect(renderer, &monopole) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}


void AfficheInvention(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect invention;
	invention.x = 100;
	invention.y = 475;
	invention.w = 400;
	invention.h = 75;
	
	if(SDL_RenderFillRect(renderer, &invention) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}


void AfficheRouteDev(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect routedev;
	routedev.x = 100;
	routedev.y = 575;
	routedev.w = 400;
	routedev.h = 75;
	
	if(SDL_RenderFillRect(renderer, &routedev) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}


void AfficheUniversite(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect universite;
	universite.x = 100;
	universite.y = 675;
	universite.w = 400;
	universite.h = 75;
	
	if(SDL_RenderFillRect(renderer, &universite) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}


void AfficheGrandeArmee(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect universite;
	universite.x = 150;
	universite.y = 75;
	universite.w = 125;
	universite.h = 175;
	
	if(SDL_RenderFillRect(renderer, &universite) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}

void AfficheGrandeRoute(SDL_Renderer *renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect universite;
	universite.x = 325;
	universite.y = 75;
	universite.w = 125;
	universite.h = 175;
	
	if(SDL_RenderFillRect(renderer, &universite) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}
