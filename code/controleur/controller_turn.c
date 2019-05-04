/**
* \file controller_turn.c
* \brief Fonctions du contrôleur du tour du joueur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* Programme gérant les actions du joueur lors de son tour de jeu : les interactions avec les cartes ressources ainsi que le bouton de fin de tour.
*
*/

#include <stdio.h>
#include <SDL.h>
#include "controller.h"
#include "controller_turn.h"
#include "controller_turn_buttons.h"
#include "controller_place_urb.h"
#include "controller_place_road.h"
#include "controller_turn_events.h"

/**
* \fn void controllerTurn(SDL_bool* program_launched, Game* the_game)
* \brief Fonction principale du contrôleur du tour du joueur.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement de son tour de jeu.
* Elle détecte les actions du joueur et fait appel aux fonctions de callback en fonction de ces actions.
*
* \param[in,out] program_launched Pointeur vers l'état du programme : si devient SDL_False, on sort de la fonction et on quitte le programme.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
*/
void controllerTurn(SDL_bool* program_launched, SDL_Renderer* renderer/*, Game* the_game*/) /*à appeler avec la structure the_partie*/
{
    initButtonsTurn();
    while(*program_launched)
    {
        drawButtonsTurn(renderer);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_USEREVENT:
                printf("Appel de la fonction de la vue displayBoardEvent(the_game)\n");
                //displayBoardEvent(the_game);
                break;

            case SDL_MOUSEBUTTONDOWN :
                switch(whichButtonTurn(event.button))
                {
//                case WOOD_BUTTON :
//                    printf("Clic sur carte bois\n");
//                    break;
//
//                case WHEAT_BUTTON :
//                    printf("Clic sur carte ble\n");
//                    break;
//
//                case CLAY_BUTTON :
//                    printf("Clic sur carte argile\n");
//                    break;
//
//                case SHEEPS_BUTTON :
//                    printf("Clic sur carte moutons\n");
//                    break;
//
//                case ROCK_BUTTON :
//                    printf("Clic sur carte roche\n");
//                    break;

                case DEVCRAFT_BUTTON :
                    printf("Clic sur bouton Craft developpement\n");
                    printf("Appel de la fonction craftDevEvent(the_game)\n");
                    craftDevEvent(/*the_game*/);
                    break;

                case ROADCRAFT_BUTTON :
                    printf("Clic sur bouton Craft route\n");
                    printf("Appel de la fonction controllerPlaceRoad(program_launched, renderer, the_game)\n");
                    controllerPlaceRoad(program_launched, renderer/*, the_game*/);
                    break;

                case SETTLECRAFT_BUTTON :
                    printf("Clic sur bouton Craft colonie\n");
                    printf("Appel de la fonction controllerPlaceUrb(program_launched, renderer, the_game, SETTLE_PLACING)\n");
                    controllerPlaceUrb(program_launched, renderer/*, the_game*/, SETTLE_PLACING);
                    break;

                case CITYCRAFT_BUTTON :
                    printf("Clic sur bouton Craft ville\n");
                    printf("Appel de la fonction controllerPlaceUrb(program_launched, renderer, the_game, CITY_PLACING)\n");
                    controllerPlaceUrb(program_launched, renderer/*, the_game*/, CITY_PLACING);
                    break;

                case KNIGHTDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Chevalier\n");
//                    printf("Appel de la fonction controllerPlaceUrb(program_launched, renderer, the_game, CITY_PLACING)\n");
//                    controllerPlaceUrb(program_launched, renderer/*, the_game*/, CITY_PLACING);
                    break;

                case MONOPDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Monopole\n");
//                    printf("Appel de la fonction controllerPlaceUrb(program_launched, renderer, the_game, CITY_PLACING)\n");
//                    controllerPlaceUrb(program_launched, renderer/*, the_game*/, CITY_PLACING);
                    break;

                case INVENTDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Invention\n");
//                    printf("Appel de la fonction controllerPlaceUrb(program_launched, renderer, the_game, CITY_PLACING)\n");
//                    controllerPlaceUrb(program_launched, renderer/*, the_game*/, CITY_PLACING);
                    break;

                case ROADSDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Routes\n");
//                    printf("Appel de la fonction controllerPlaceUrb(program_launched, renderer, the_game, CITY_PLACING)\n");
//                    controllerPlaceUrb(program_launched, renderer/*, the_game*/, CITY_PLACING);
                    break;

                case UNIVDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Universite\n");
                    printf("Appel de la fonction useUnivEvent(the_game)\n");
                    useUnivEvent(/*the_game*/);
                    break;

                case ENDTURN_BUTTON :
                    printf("Clic sur bouton Fin de tour\n");
                    printf("Appel de la fonction endTurnEvent(the_game)\n");
                    endTurnEvent(/*the_game*/);
                    break;

                case DICE_BUTTON :
                    printf("Clic sur bouton Lancer les des\n");
                    printf("Appel de la fonction rollDiceEvent(the_game)\n");
                    rollDiceEvent(/*the_game*/);
                    break;

                case HELP_BUTTON :
                    printf("Clic sur bouton Aide\n");
                    break;

                default :
                    break;
                }
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_q :
                    printf("Appui sur touche Q\n");
                    printf("Appel de la fonction quit(program_launched)\n");
                    quit(program_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
                printf("Appel de la fonction quit(program_launched)\n");
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}
