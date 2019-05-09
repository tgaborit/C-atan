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
//#include "get_partie.h"

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
    initPlayerButtons();
    while(choice_launched)
    {
        drawPlayerButtons(window);
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

void drawPlayerButtons(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_GetRenderer(window);

    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect player_buttons[NPLAYERBUTTONS] = {player1_area, player2_area, player3_area, player4_area};
    if(SDL_RenderDrawRects(renderer, player_buttons, NPLAYERBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn void initPlayerButtons()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Choix d'un joueur".
*
* Initialise les champs des rectangles des zones correspondant aux boutons des joueurs.
* Fait appel aux fonctions d'initialisation pour la carte Bois, la carte Blé, la carte Argile, la carte Moutons et la carte Roche.
*/
void initPlayerButtons()
{
    SDL_Rect* player_buttons[NPLAYERBUTTONS] = {&player1_area, &player2_area, &player3_area, &player4_area};
    int i;

    for(i = 0; i < /*get_nbjoueurs()*/4; ++i)
    {
        player_buttons[i]->h = PLAYERH;
        player_buttons[i]->w = PLAYERW;
    }

    initPlayer1Placement();
    initPlayer2Placement();
    initPlayer3Placement();
    initPlayer4Placement();
}

void initPlayer1Placement()
{
    player1_area.x = 10;
}

void initPlayer2Placement()
{
    player2_area.x = player1_area.x + player1_area.w + 5;
}

void initPlayer3Placement()
{
    player3_area.x = player2_area.x + player2_area.w + 5;
}

void initPlayer4Placement()
{
    player4_area.x = player3_area.x + player3_area.w + 5;
}
