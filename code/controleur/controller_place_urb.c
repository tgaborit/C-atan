/**
*
*
* \author Titouan Gaborit
* \date 1 avril 2019
*
*
*/

#include <SDL.h>

#include "controller.h"
#include "controller_place_urb.h"

void controllerPlaceUrb(SDL_bool program_launched, SDL_Renderer* renderer/*, Game* the_game*/)
{
    SDL_bool placing_launched = SDL_TRUE;
    while(program_launched && placing_launched)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_BACKSPACE :
                    printf("Appui sur touche Retour arriere\n");
                    printf("Appel de la fonction quitPlacing(&placing_launched)\n");
                    quitPlacing(&placing_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
                printf("Appel de la fonction quitProgram(&program_launched)\n");
                quitProgram(&program_launched);
                break;

            default :
                break;
            }
        }
    }
}

/**
* \fn void quitPLacing(SDL_bool * placing_launched)
* \brief Fonction annulant le placement d'un urb
*
* Donne la valeur SDL_False à l'état du placement, ce qui le fera sortir de la boucle de controlerPlaceUrb
* et revenir à l'environnement Tour du joueur.
*
* \param[in,out] pplacing_launched Pointeur vers l'état du placement
*
*/
void quitPlacing(SDL_bool * pplacing_launched)
{
    *pplacing_launched = SDL_FALSE;
}
