/**
* \file controller_place_road.c
* \brief Fonctions du contrôleur du placement d'une route
* \author Titouan Gaborit
* \date 1 mai 2019
*
* Programme gérant les actions du joueur lors du placement d'une route : le choix du chemin sur lequel elle sera construite.
*
*/

#include <SDL.h>

#include "controller.h"
#include "controller_place_road.h"
#include "controller_place_road_buttons.h"

/**
* \fn void controllerPlaceUrb(SDL_bool program_launched, SDL_Renderer* renderer, Game* the_game)
* \brief Fonction principale du contrôleur du placement d'une route.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du placement d'une route.
* Elle détecte les actions du joueur et fait appel aux fonctions de callback en fonction de ces actions.
*
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on sort de la fonction et on quitte le programme.
* \param[in,out] placement_launched Etat du placement : si devient SDL_False, on sort de la fonction.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
*/
void controllerPlaceRoad(SDL_bool program_launched, SDL_Renderer* renderer/*, Game* the_game*/)
{
    SDL_bool placing_launched = SDL_TRUE;
    SDL_Event ev;
//    initButtonsPlaceUrb();
    while(program_launched && placing_launched)
    {
//        drawButtonsPlaceUrb(renderer);
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
//            case SDL_MOUSEBUTTONDOWN :
//                controllerPlaceUrbButton(event.button, &placing_launched/*, the_game,*/, urb_placing);
//                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_BACKSPACE :
                    printf("Appui sur touche Retour arriere\n");
                    printf("Appel de la fonction quit(&placing_launched)\n");
                    quit(&placing_launched);
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
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}
