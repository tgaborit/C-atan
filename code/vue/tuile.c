#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>


#include "Plateau.h"


void AfficheTuile(SDL_Renderer* renderer)		
{
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;
	
	image = SDL_LoadBMP("imagecatane/plateau.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	
	//switch avec fonction manu ?
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


