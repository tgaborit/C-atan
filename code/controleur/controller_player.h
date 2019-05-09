/**
* \file controller_player.h
* \brief En-tête du contrôleur du choix d'un joueur
* \author Titouan Gaborit
* \date 9 mai 2019
*
* En-tête déclarant les fonctions du contrôleur du choix d'un joueur ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_PLAYER_H
#define CATANE_CONTROLLER_PLAYER_H

#include <SDL.h>

/**
* \enum PlayerButton
* Tous les boutons existants dans l'environnement "Choix d'un joueur" ainsi que le non-bouton.
*/
typedef enum {
        PLAYER1_BUTTON,
        PLAYER2_BUTTON,
        PLAYER3_BUTTON,
        PLAYER4_BUTTON,

        NO_PLAYERBUTTON
} PlayerButton;

/**
* \def NPLAYERBUTTONS
* Définit le nombre de boutons de l'environnement "Choix d'un joueur".
*/
#define NPLAYERBUTTONS 4

/**
* \def PLAYERW
* Définit la largeur d'un bouton de joueur.
*/
#define PLAYERW 460

/**
* \def PLAYERH
* Définit la hauteur d'un bouton de joueur.
*/
#define PLAYERH 35

void controllerPlayer(PlayerButton* player_chosen, SDL_Window* window, SDL_bool* program_launched);

void drawPlayerButtons(SDL_Window* window);

PlayerButton whichPlayerButton(SDL_MouseButtonEvent mouse_button);

void initPlayerButtons();
    void initPlayer1Placement();
    void initPlayer2Placement();
    void initPlayer3Placement();
    void initPlayer4Placement();

#endif //CATANE_CONTROLLER_PLAYER_H
