#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


#include "Plateau.h"
#include "ressource.h"
#include "get_plateau.h"
#include "joueur.h"
#include "plateau.h"

void AfficheTuile(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;

	image = SDL_LoadBMP("imagecatane/plateau.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(texture == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectangle;

	if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectangle.x = 530;
	rectangle.y =0;


	if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}


void AfficheTuileArgile(SDL_Renderer* renderer, double x, double y)
{
	SDL_Surface *image = NULL;
	SDL_Texture *argile = NULL;

	image = SDL_LoadBMP("imagecatane/tuileargile.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	argile = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(argile == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectargile;

	if(SDL_QueryTexture(argile, NULL, NULL, &rectargile.w, &rectargile.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectargile.x = x;
	rectargile.y = y;


	if(SDL_RenderCopy(renderer, argile, NULL, &rectargile) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}


void AfficheTuileBle(SDL_Renderer* renderer, double x, double y)
{
	SDL_Surface *image = NULL;
	SDL_Texture *ble = NULL;

	image = SDL_LoadBMP("imagecatane/tuileble.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	ble = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(ble == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectble;

	if(SDL_QueryTexture(ble, NULL, NULL, &rectble.w, &rectble.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectble.x = x;
	rectble.y = y;


	if(SDL_RenderCopy(renderer, ble, NULL, &rectble) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}


void AfficheTuileBois(SDL_Renderer* renderer, double x, double y)
{
	SDL_Surface *image = NULL;
	SDL_Texture *bois = NULL;

	image = SDL_LoadBMP("imagecatane/tuilebois.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	bois = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(bois == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectbois;

	if(SDL_QueryTexture(bois, NULL, NULL, &rectbois.w, &rectbois.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectbois.x = x;
	rectbois.y = y;


	if(SDL_RenderCopy(renderer, bois, NULL, &rectbois) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

void AfficheTuileMouton(SDL_Renderer* renderer, double x, double y)
{
	SDL_Surface *image = NULL;
	SDL_Texture *mouton = NULL;

	image = SDL_LoadBMP("imagecatane/tuilemouton.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	mouton = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(mouton == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectmouton;

	if(SDL_QueryTexture(mouton, NULL, NULL, &rectmouton.w, &rectmouton.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectmouton.x = x;
	rectmouton.y = y;


	if(SDL_RenderCopy(renderer, mouton, NULL, &rectmouton) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

void AfficheTuileRoche(SDL_Renderer* renderer, double x, double y)
{
	SDL_Surface *image = NULL;
	SDL_Texture *roche = NULL;

	image = SDL_LoadBMP("imagecatane/tuileroche.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	roche = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(roche == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectroche;

	if(SDL_QueryTexture(roche, NULL, NULL, &rectroche.w, &rectroche.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectroche.x = x;
	rectroche.y = y;


	if(SDL_RenderCopy(renderer, roche, NULL, &rectroche) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}



//Pour affichage des tuiles sur le plateau
void AfficheRandomTuile(Plateau* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy)
{
	TypeRessource type = getType(p, x, y);

	switch(type)
	{
		case ARGILE :
			AfficheTuileArgile(renderer, posimx, posimy);
			break;

		case BLE :
			AfficheTuileBle(renderer, posimx, posimy);
			break;

		case BOIS :
			AfficheTuileBois(renderer, posimx, posimy);
			break;

		case MOUTON :
			AfficheTuileMouton(renderer, posimx, posimy);
			break;

		case PIERRE :
			AfficheTuileRoche(renderer, posimx, posimy);
			break;

		default :
			break;
	}
}



void AfficheTuilePlateau(Plateau *p, SDL_Renderer *renderer)
{
	AfficheRandomTuile(p, -1, 2, renderer, 756, 109);
	AfficheRandomTuile(p, 0, 2, renderer, 891, 109);
	AfficheRandomTuile(p, 1, 2, renderer, 1026, 109);

	AfficheRandomTuile(p, -1.5, 1, renderer, 688, 225);
	AfficheRandomTuile(p, -0.5, 1, renderer, 823, 225);
	AfficheRandomTuile(p, 0.5, 1, renderer, 959, 225);
	AfficheRandomTuile(p, 1.5, 1, renderer, 1094, 225);

	AfficheRandomTuile(p, -2, 0, renderer, 620, 343);
	AfficheRandomTuile(p, -1, 0, renderer, 755, 343);
	AfficheRandomTuile(p, 1, 0, renderer, 1026, 343);
	AfficheRandomTuile(p, 2, 0, renderer, 1161, 343);

	AfficheRandomTuile(p, -1.5, -1, renderer, 688, 460);
	AfficheRandomTuile(p, -0.5, -1, renderer, 823, 460);
	AfficheRandomTuile(p, 0.5, -1, renderer, 959, 460);
	AfficheRandomTuile(p, 1.5, -1, renderer, 1094, 460);

	AfficheRandomTuile(p, -1, -2, renderer, 756, 579);
	AfficheRandomTuile(p, 0, -2, renderer, 891, 579);
	AfficheRandomTuile(p, 1, -2, renderer, 1026, 579);
}
