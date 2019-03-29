/**
* \file controler_turn_buttons.h
* \brief En-tête des boutons de l'environnement "Tour du joueur"
* \author Titouan Gaborit
* \date 29 mars 2019
*
* En-tête déclarant les fonctions de gestion des boutons du tour du joueur ainsi que la définition des macros relatives.
*/

#ifndef CATANE_CONTROLER_TURN_BUTTONS_H
#define CATANE_CONTROLER_TURN_BUTTONS_H

/**
* \enum TurnButton
* Tous les boutons existants dans l'environnement "Tour du joueur" ainsi que le non-bouton.
*/
typedef enum {NO_BUTTON, WOOD_BUTTON, WHEAT_BUTTON, CLAY_BUTTON, SHEEPS_BUTTON, ROCK_BUTTON, ENDTURN_BUTTON} TurnButton ;

/**
* \def CARDW
* Définit la largeur d'une carte ressource
*/
#define CARDW 115

/**
* \def CARDW
* Définit la hauteur d'une carte ressource
*/
#define CARDH 166


void initWoodCard();
void initWheatCard();
void initClayCard();
void initSheepsCard();
void initRockCard();
void initCardsAreas();

void initEndTurnArea();

void initButtonsTurn();

TurnButton whichButtonTurn(SDL_MouseButtonEvent mouse_button);
void drawButtons(SDL_Renderer* renderer);

#endif //CATANE_CONTROLER_TURN_BUTTONS_H
