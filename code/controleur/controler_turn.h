/**
* \file controler_turn.h
* \brief En-tête du contrôleur du tour du joueur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* En-tête déclarant les fonctions du contrôleur du tour du joueur ainsi que la définition des macros relatives aux boutons du tour de jeu.
*/

#ifndef CATANE_CONTROLER_TURN_H
#define CATANE_CONTROLER_TURN_H

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

/**
* \enum TurnButton
* Tous les boutons existants dans l'environnement "Tour du joueur" ainsi que le non-bouton.
*/
typedef enum {NO_BUTTON, WOOD_BUTTON, WHEAT_BUTTON, CLAY_BUTTON, SHEEPS_BUTTON, ROCK_BUTTON, ENDTURN_BUTTON} TurnButton ;

void controlerTurn(SDL_bool program_launched, SDL_Renderer* renderer/*, partie * the_partie*/);
void quit(SDL_bool * program_launched);

void initWoodCard();
void initWheatCard();
void initClayCard();
void initSheepsCard();
void initRockCard();
void initCardsAreas();

void initEndTurnArea();

TurnButton whichButtonTurn(SDL_MouseButtonEvent mouse_button);
void drawButtons(SDL_Renderer* renderer);

void SDL_ExitWithError(const char *message);

#endif //CATANE_CONTROLER_TURN_H
