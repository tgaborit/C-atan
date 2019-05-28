/**
 * \file controller_help.c
 * \brief Implémente les fonctions de controller_help.h
 * \author Pauline.M
 * \version 1.0
 * \date 23 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage de l'aide dans le jeu.
 */

#include "controller_help.h"
#include "fenetre.h"

/**
* \fn void controllerHelp(SDL_Window* window)
* \brief Fonction principale du contrôleur de l'aide.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement de l'aide
* Elle détecte les actions du joueur et quitte l'environnement le cas échéant.
*
* \param[in,out] window Pointeur vers la fenêtre du jeu.
*/
void controllerHelp(SDL_Window* window)
{
    Help(window);
    SDL_bool subprogram_launched = SDL_TRUE;

    while(subprogram_launched){

        SDL_Event subevent;
        while(SDL_PollEvent(&subevent))
        {
            switch(subevent.type){
                case SDL_MOUSEBUTTONDOWN:
                    switch(SDL_BUTTON(SDL_GetMouseState(NULL, NULL))){
                        case SDL_BUTTON_LEFT :
                            if(subevent.button.x >= 1870 && subevent.button.y<=70)
                                subprogram_launched = SDL_FALSE;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
	}
	return;
}
