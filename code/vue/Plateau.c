#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "Plateau.h"

#define WINDOWW 1900
#define WINDOWH 1080
#define RED 64
#define GREEN 159
#define BLUE 255


void SDL_ExitWithError(const char *message)
{
	SDL_Log("ERREUR : Initialisation SDL > %s\n", SDL_GetError());
	SDL_Quit();
        exit(EXIT_FAILURE);
}

void AfficheFenetre(){

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
 
	if(SDL_Init(SDL_INIT_VIDEO)!=0)		
		SDL_ExitWithError("Initialisation SDL impossible");

	//Creation de la fenetre et rendu
	if(SDL_CreateWindowAndRenderer(WINDOWW, WINDOWH, 0, &window, &renderer) != 0)
		SDL_ExitWithError("Impossible de creer la fenetre et le rendu");


	SDL_SetWindowTitle(window, "Catane");
		
	//Couleur fond 
	if(SDL_SetRenderDrawColor(renderer, RED, GREEN, BLUE, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = WINDOWW;
	rectangle.h = WINDOWH;
	
	if(SDL_RenderFillRect(renderer, &rectangle) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");	


	SDL_RenderPresent(renderer);


	//Event fermeture fenetre
	SDL_bool program_launched = SDL_TRUE;

	while(program_launched)
	{
		SDL_Event event;
		
		while(SDL_PollEvent(&event))	
		{
			switch(event.type)
			{
				case SDL_QUIT :
					program_launched = SDL_FALSE;
					break;
				

				default :
					break;	
			}
		}
	}	

	//Fermeture fenetre avec destruction rendu et fenetre
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit(); 	
}




