#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "fenetre.h"
#include "partie.h"


int main(int argc, char **argv)
{
	SDL_Window* w = InitFenetre();
	SDL_Renderer* r = NULL;
    Partie* p = init_partie();
    r = updateFenetre(p, w, r);

	TTF_Init();


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

    destroyFenetre(w,r);
	return EXIT_SUCCESS;
}
