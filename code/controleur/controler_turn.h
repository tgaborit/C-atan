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

void controlerTurn(SDL_bool program_launched, SDL_Renderer* renderer/*, partie * the_partie*/);
void quit(SDL_bool * program_launched);

void SDL_ExitWithError(const char *message);

#endif //CATANE_CONTROLER_TURN_H
