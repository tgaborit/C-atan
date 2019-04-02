/**
*
*
* \author Titouan Gaborit
* \date 1 avril 2019
*
*
*/

#include <SDL.h>
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
                case SDLK_q :
                    printf("Appui sur touche Q\n");
                    printf("Appel de la fonction quit(&program_launched)\n");
                    quit(&program_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
                printf("Appel de la fonction quit(&program_launched)\n");
                quit(&program_launched);
                break;

            default :
                break;
            }
        }
    }
}

/**
* \fn void quit(SDL_bool * program_launched)
* \brief Fonction activant la fin du jeu
*
* Donne la valeur SDL_False à l'état du programme, ce qui le fera sortir de la boucle de controlerTurn et quitter du programme
*
* \param[in,out] pprogram_launched Pointeur vers l'état du programme
*
*/
void quit(SDL_bool * pprogram_launched)
{
    *pprogram_launched = SDL_FALSE;
}
