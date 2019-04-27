/**
* \file controller_turn_buttons.h
* \brief En-tête des boutons de l'environnement "Tour du joueur"
* \author Titouan Gaborit
* \date 29 mars 2019
*
* En-tête déclarant les fonctions de gestion des boutons du tour du joueur ainsi que la définition des macros relatives.
*/

#ifndef CATANE_CONTROLLER_TURN_BUTTONS_H
#define CATANE_CONTROLLER_TURN_BUTTONS_H

/**
* \enum TurnButton
* Tous les boutons existants dans l'environnement "Tour du joueur" ainsi que le non-bouton.
*/
typedef enum {
        WOOD_BUTTON,
        WHEAT_BUTTON,
        CLAY_BUTTON,
        SHEEPS_BUTTON,
        ROCK_BUTTON,

        DEVCRAFT_BUTTON,
        ROADCRAFT_BUTTON,
        SETTLECRAFT_BUTTON,
        CITYCRAFT_BUTTON,

        DICE_BUTTON,
        ENDTURN_BUTTON,

        HELP_BUTTON,

        NO_BUTTON
} TurnButton;

/**
* \def NTURNBUTTONS
* Définit le nombre de boutons de l'environnement "Tour du joueur"
*/
#define NTURNBUTTONS 12

/**
* \def CARDW
* Définit la largeur d'une carte ressource
*/
#define CARDW 115

/**
* \def CARDH
* Définit la hauteur d'une carte ressource
*/
#define CARDH 166

/**
* \def CRAFTW
* Définit la largeur d'un bouton de craft
*/
#define CRAFTW 200

/**
* \def CRAFTH
* Définit la hauteur d'un bouton de craft
*/
#define CRAFTH 75

void drawButtonsTurn(SDL_Renderer* renderer);

TurnButton whichButtonTurn(SDL_MouseButtonEvent mouse_button);
    TurnButton whichCardButton(SDL_MouseButtonEvent mouse_button);
    TurnButton whichCraftButton(SDL_MouseButtonEvent mouse_button);

void initButtonsTurn();
    void initCardsAreas();
        void initWoodCard();
        void initWheatCard();
        void initClayCard();
        void initSheepsCard();
        void initRockCard();
    void initDevCraftArea();
        void initRoadCraftArea();
        void initSettleCraftArea();
        void initCityCraftArea();
        void initCraftAreas();
    void initDiceArea();
    void initEndTurnArea();
    void initHelpArea();

#endif //CATANE_CONTROLLER_TURN_BUTTONS_H
