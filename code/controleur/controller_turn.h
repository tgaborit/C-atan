/**
* \file controller_turn.h
* \brief En-tête du contrôleur du tour du joueur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* En-tête déclarant les fonctions du contrôleur du tour du joueur, ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_TURN_H
#define CATANE_CONTROLLER_TURN_H

#include <SDL.h>

/**
* \enum TurnButton
* Tous les boutons existants dans l'environnement "Tour du joueur" ainsi que le non-bouton.
*/
typedef enum {
        DEVCRAFT_BUTTON,
        ROADCRAFT_BUTTON,
        SETTLECRAFT_BUTTON,
        CITYCRAFT_BUTTON,

        KNIGHTDEV_BUTTON,
        MONOPDEV_BUTTON,
        INVENTDEV_BUTTON,
        ROADSDEV_BUTTON,
        UNIVDEV_BUTTON,

        DICE_BUTTON,
        ENDTURN_BUTTON,

        HELP_BUTTON,

        NO_TURNBUTTON
} TurnButton;

/**
* \def NTURNBUTTONS
* Définit le nombre de boutons de l'environnement "Tour du joueur".
*/
#define NTURNBUTTONS 12

/**
* \def CRAFTW
* Définit la largeur d'un bouton de craft.
*/
#define CRAFTW 250

/**
* \def CRAFTH
* Définit la hauteur d'un bouton de craft.
*/
#define CRAFTH 75

/**
* \def DEVW
* Définit la largeur d'un bouton de carte développement.
*/
#define DEVW 400

/**
* \def DEVH
* Définit la hauteur d'un bouton de carte développement.
*/
#define DEVH 75

void controllerTurn(SDL_bool* program_launched, SDL_Window* window/*, Game* the_game*/);

void drawTurnButtons(SDL_Window* window);

TurnButton whichTurnButton(SDL_MouseButtonEvent mouse_button);
    TurnButton whichCraftButton(SDL_MouseButtonEvent mouse_button);
    TurnButton whichDevButton(SDL_MouseButtonEvent mouse_button);

void initTurnButtons();
    void initCraftAreas();
        void initRoadCraftArea();
        void initSettleCraftArea();
        void initCityCraftArea();
        void initDevCraftArea();
    void initDevCardsAreas();
        void initKnightDevArea();
        void initMonopDevArea();
        void initInventDevArea();
        void initRoadsDevArea();
        void initUnivDevArea();
    void initDiceArea();
    void initEndTurnArea();
    void initHelpArea();

#endif //CATANE_CONTROLLER_TURN_H
