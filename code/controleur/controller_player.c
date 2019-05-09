/**
* \file controller_player.c
* \brief Fonctions du contrôleur du choix d'un joueur
* \author Titouan Gaborit
* \date 9 mai 2019
*
* Programme gérant l'environnement du choix d'un joueur : la détection d'un clic dessus par le joueur
* ou encore le fait de quitter l'environnement ou le programme.
*
*/

#include <stdio.h>
#include <SDL.h>
#include "controller.h"
#include "controller_player.h"

static SDL_Rect player1_area;           /*!< Rectangle correspondant à la zone de la carte Bois*/
static SDL_Rect player2_area;           /*!< Rectangle correspondant à la zone de la carte Blé*/
static SDL_Rect player3_area;           /*!< Rectangle correspondant à la zone de la carte Argile*/
static SDL_Rect player4_area;           /*!< Rectangle correspondant à la zone de la carte Moutons*/

/**
* \fn void controllerPlayer(PathButton* path_chosen, SDL_bool* program_launched)
* \brief Fonction principale du contrôleur du choix d'un joueur.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du choix d'un joueur.
* Elle détecte les actions du joueur et enregistre le joueur cliqué le cas échéant, quitte le programme ou l'environnement.
*
* \param[in,out] player_chosen Pointeur vers le joueur choisi dans lequel sera enregistré le joueur cliqué.
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on quitte le programme.
*/
void controllerPlayer(PlayerButton* player_chosen, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_bool choice_launched = SDL_TRUE;
//    initResourceButtons();
    while(choice_launched)
    {
//        drawPlayerButtons(window);
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
//            case SDL_MOUSEBUTTONDOWN :
//                switch(whichPlayerButton(event.button))
//                {
//                case WOOD_BUTTON :
//                    printf("Clic sur joueur 1\n");
//                    *player_chosen = WOOD_BUTTON;
//                    quit(&choice_launched);
//                    break;
//
//                case WHEAT_BUTTON :
//                    printf("Clic sur joueur 2\n");
//                    *player_chosen = WHEAT_BUTTON;
//                    quit(&choice_launched);
//                    break;
//
//                case CLAY_BUTTON :
//                    printf("Clic sur joueur 2\n");
//                    *player_chosen = CLAY_BUTTON;
//                    quit(&choice_launched);
//                    break;
//
//                case SHEEPS_BUTTON :
//                    printf("Clic sur joueur 2\n");
//                    *player_chosen = SHEEPS_BUTTON;
//                    quit(&choice_launched);
//                    break;
//
//                default :
//                    break;
//                }
//                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_BACKSPACE :
                    printf("Appui sur touche Retour arriere\n");
                    printf("Appel de la fonction quit(&choice_launched)\n");
                    quit(&choice_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
//                *player_chosen = NO_PLAYERBUTTON;
                printf("Appel de la fonction quit(&choice_launched)\n");
                quit(&choice_launched);
                printf("Appel de la fonction quit(program_launched)\n");
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}
