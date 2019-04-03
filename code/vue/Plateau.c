#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "Plateau.h"
#include "carte.c"
#include "tuile.c"
#include "architecture.c"
#include "developpement.c"
#include "probabilite.c"

#define WINDOWW 1920
#define WINDOWH 950
#define RED 64
#define GREEN 159
#define BLUE 255



void AfficheFenetre(){

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
 
	if(SDL_Init(SDL_INIT_VIDEO)!=0)		
		SDL_ExitWithError("Initialisation SDL impossible");

	//Creation de la fenetre en fullscreen et rendu
	if(SDL_CreateWindowAndRenderer(WINDOWW, WINDOWH, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer) != 0)
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
		
	AfficheDe(renderer);

	AfficheChevalier(renderer);
	AfficheMonopole(renderer);
	AfficheInvention(renderer);
	AfficheRouteDev(renderer);
	AfficheUniversite(renderer);
	AfficheGrandeArmee(renderer);
	AfficheGrandeRoute(renderer);

	Plateau * p = initPlateau();
	
	AfficheTuilePlateau(p, renderer);
	
	//AfficheProbaNormal(renderer);
	
	AfficheRandomProbaPlateau(p, renderer);

	AfficheTuile(renderer);
	
	AfficheCarteArgile(renderer);
	AfficheCarteBle(renderer);
	AfficheCarteBois(renderer);
	AfficheCarteMouton(renderer);
	AfficheCarteRoche(renderer);		

	AfficheJoueur(renderer);

	AfficheSkip(renderer);
	
	AfficheHelp(renderer);

	AfficheBouttonDev(renderer);
	AfficheBouttonRoute(renderer);
	AfficheBouttonColonie(renderer);
	AfficheBouttonVille(renderer);
	

	
//Event fermeture fenetre
	SDL_bool program_launched = SDL_TRUE;

	while(program_launched)
	{
		SDL_Event event;
		
		while(SDL_PollEvent(&event))	
		{
			switch(event.type)
			{

				case SDL_KEYDOWN :
					switch(event.key.keysym.sym)
					{
						case SDLK_q :
							program_launched = SDL_FALSE;
							break;
						default :
							continue;
					}
 
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



void AfficheJoueur(SDL_Renderer* renderer)
{
	
	//Creation de la barre avec les noms des joueurs et le score
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect barrejoueurs;
	barrejoueurs.x = 0;
	barrejoueurs.y = 0;
	barrejoueurs.w = WINDOWW;
	barrejoueurs.h = 35;
	
	if(SDL_RenderFillRect(renderer, &barrejoueurs) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}


void AfficheSkip(SDL_Renderer* renderer)
{

	SDL_Surface *image = NULL;
	SDL_Texture *skip = NULL;
	
	image = SDL_LoadBMP("imagecatane/skip.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	skip = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	
	
	if(skip == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectskip;

	if(SDL_QueryTexture(skip, NULL, NULL, &rectskip.w, &rectskip.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");
	
	rectskip.x = 300;		
	rectskip.y = 820;


	if(SDL_RenderCopy(renderer, skip, NULL, &rectskip) !=0) 
		SDL_ExitWithError("Impossible d'afficher la texture");
	
	SDL_RenderPresent(renderer);
}


void AfficheDe(SDL_Renderer* renderer)
{
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect de;
	de.x = 1570;
	de.y = 110;
	de.w = 100;
	de.h = 100;
	
	if(SDL_RenderFillRect(renderer, &de) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}


void AfficheHelp(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *help = NULL;
	
	image = SDL_LoadBMP("imagecatane/help.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	help = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	
	
	if(help == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect recthelp;

	if(SDL_QueryTexture(help, NULL, NULL, &recthelp.w, &recthelp.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");
	
	recthelp.x = 1875;		
	recthelp.y = 0;


	if(SDL_RenderCopy(renderer, help, NULL, &recthelp) !=0) 
		SDL_ExitWithError("Impossible d'afficher la texture");
	
	SDL_RenderPresent(renderer);

}
