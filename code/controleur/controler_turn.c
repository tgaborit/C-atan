/**
* \file controler_turn.c
* \brief Fonctions du contrôleur du tour du joueur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* Programme gérant les actions du joueur lors de son tour de jeu : les intéractions avec les cartes ressources ainsi que le bouton de fin de tour.
*
*/

#include <SDL.h>
#include "controler_turn.h"
#include "controler_turn_buttons.h"

/**
* \fn void controlerTurn(SDL_bool program_launched, partie * the_partie)
* \brief Fonction principale du contrôleur du tour du joueur
*
* Cette fonction se répète tant que le joueur reste dans l'environnement de son tour de jeu.
* Elle détecte les actions du joueur et fait appel aux fonctions de callback en fonction de ces actions.
*
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on sort de la fonction et on quitte le programme.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur
*/
void controlerTurn(SDL_bool program_launched, SDL_Renderer* renderer/*, Game* the_game*/) /*à appeler avec la structure the_partie*/
{
    initButtonsTurn();
    drawButtons(renderer);
    SDL_RenderPresent(renderer);
    while(program_launched)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_USEREVENT:
                printf("Appel de la fonction displayBoardEvent(the_game)\n");
                /*displayBoardEvent(the_game);*/
                break;

            case SDL_MOUSEBUTTONDOWN :
                switch(whichButtonTurn(event.button))
                {
                case WOOD_BUTTON :
                    printf("Clic sur carte bois\n");
                    break;

                case WHEAT_BUTTON :
                    printf("Clic sur carte ble\n");
                    break;

                case CLAY_BUTTON :
                    printf("Clic sur carte argile\n");
                    break;

                case SHEEPS_BUTTON :
                    printf("Clic sur carte moutons\n");
                    break;

                case ROCK_BUTTON :
                    printf("Clic sur carte roche\n");
                    break;

                case ENDTURN_BUTTON :
                    printf("Clic sur bouton Fin de tour\n");
                    printf("Appel de la fonction endTurnEvent(renderer, the_game)\n");
                    //endTurnEvent(renderer, the_game);
                    break;

                case DEVCRAFT_BUTTON :
                    printf("Clic sur bouton Craft developpement\n");
                    printf("Appel de la fonction craftDevEvent(renderer, the_game)\n");
                    craftDevEvent(/*the_game*/);
                    break;

                case ROADCRAFT_BUTTON :
                    printf("Clic sur bouton Craft route\n");
                    printf("Appel de la fonction controllerPlaceRoad(renderer, the_game)\n");
                    //controllerPlaceRoad(renderer, the_game);
                    break;

                case SETTLECRAFT_BUTTON :
                    printf("Clic sur bouton Craft colonie\n");
                    printf("Appel de la fonction controllerPlaceUrb(renderer, the_game, SETTLE_PLACING)\n");
                    //controllerPlaceUrb(renderer, the_game, SETTLE_PLACING);
                    break;

                case CITYCRAFT_BUTTON :
                    printf("Clic sur bouton Craft ville\n");
                    printf("Appel de la fonction controllerPlaceUrb(renderer, the_game, CITY_PLACING)\n");
                    //controllerPlaceUrb(renderer, the_game, CITY_PLACING);
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

void craftDevEvent(/*Game* the_game*/)
{
    SDL_Event ev;
    printf("Appel de la fonction craftDev(the_game)\n");
    //craftDev(the_game);
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
