/**
* \file controller_turn_buttons.h
* \brief En-tête des boutons de l'environnement "Tour du joueur"
* \author Titouan Gaborit
* \date 29 mars 2019
*
* En-tête déclarant les fonctions de gestion des boutons du tour du joueur ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_TURN_BUTTONS_H
#define CATANE_CONTROLLER_TURN_BUTTONS_H

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
#define CRAFTW 200

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

void drawButtonsTurn(SDL_Renderer* renderer);

TurnButton whichButtonTurn(SDL_MouseButtonEvent mouse_button);
    TurnButton whichCraftButton(SDL_MouseButtonEvent mouse_button);
    TurnButton whichDevButton(SDL_MouseButtonEvent mouse_button);

void initButtonsTurn();
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

#endif //CATANE_CONTROLLER_TURN_BUTTONS_H
