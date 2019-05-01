/**
* \file controller.c
* \brief Fonctions générales du contrôleur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* Fonctions utilisées par le contrôleur pour plusieurs environnements.
*
*/

#include <SDL.h>
#include "controller.h"

/**
* \fn SDL_bool isInArea(SDL_MouseButtonEvent mouse_button, SDL_Rect area)
* \brief Détecte si un clic a été fait dans une zone précise ou non.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \param[in] area Zone dans laquelle le clic a été fait ou non.
*
* \return SDL_TRUE si le clic a été fait dans la zone, SDL_FALSE sinon.
*/
SDL_bool isInArea(SDL_MouseButtonEvent mouse_button, SDL_Rect area)
{
    if ((mouse_button.x>=area.x)&&(mouse_button.x<=area.x+area.w))
    {
        if ((mouse_button.y>=area.y)&&(mouse_button.y<=area.y+area.h))
            return SDL_TRUE;
    }
    return SDL_FALSE;
}

/**
* \fn void quit(SDL_bool * paction_launched)
* \brief Fonction activant la fin d'une action.
*
* Donne la valeur SDL_False à l'état de l'action, ce qui le fera sortir de la boucle de controler* et quitter cette action.
*
* \param[in,out] paction_launched Pointeur vers l'état d'une action.
*/
void quit(SDL_bool * paction_launched)
{
    *paction_launched = SDL_FALSE;
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
