/**
*
*
* \author Titouan Gaborit
* \date 26 avril 2019
*
*
*/
#include <SDL.h>

#include "controller.h"
#include "controller_place_urb_buttons.h"

void drawButtonsPlaceUrb(SDL_Renderer* renderer)
{
    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

/*
    SDL_Rect place_urb_buttons[] = {};
    if(SDL_RenderDrawRects(renderer, place_urb_buttons, NTURNBUTTON) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");
*/

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}
