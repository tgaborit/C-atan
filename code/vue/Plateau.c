#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "Plateau.h"
#include "carte.c"
#include "tuile.c"
#include "architecture.c"
#include "developpement.c"


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

	//AfficheTuileRoche(renderer);

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

				case SDL_MOUSEMOTION : //mouvement souris, déplacement
					//event.motion.x coordonee exacte en x (id y)
					//event.motion.xrel coordonee relative de x (id y)
					printf("%d / %d\n", event.motion.x, event.motion.y);
					break;


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
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect skip;
	skip.x = 300;
	skip.y = 820;
	skip.w = 150;
	skip.h = 75;
	
	if(SDL_RenderFillRect(renderer, &skip) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
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
	if(SDL_SetRenderDrawColor(renderer, 206, 24, 30, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");
	
	SDL_Rect help;
	help.x = 1875;
	help.y = 0;
	help.w = 35;
	help.h = 35;
	
	if(SDL_RenderFillRect(renderer, &help) != 0)	
		SDL_ExitWithError("Impossible de remplir un rectangle");
	
	SDL_RenderPresent(renderer);
}
