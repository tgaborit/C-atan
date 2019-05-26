/**
* \file controller_dice.h
* \brief En-tête du contrôleur du lancer de dés
* \author Titouan Gaborit
* \date 27 mars 2019
*
* En-tête déclarant les fonctions du contrôleur du lancer de dés, ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_DICE_H
#define CATANE_CONTROLLER_DICE_H

#include <SDL.h>
#include "partie.h"

/**
* \enum DiceButton
* Tous les boutons existants dans l'environnement "Lancer des dés" ainsi que le non-bouton.
*/
typedef enum {
        DICE_BUTTON,

        NO_DICEBUTTON
} DiceButton;

void controllerDice(SDL_bool* program_launched, SDL_Window* window, Partie* the_game);

void drawDiceButton(SDL_Window* window);

DiceButton whichDiceButton(SDL_MouseButtonEvent mouse_button);

void initDiceButton();

#endif //CATANE_CONTROLLER_DICE_H
