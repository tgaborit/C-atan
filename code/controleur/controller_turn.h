/**
* \file controller_turn.h
* \brief En-tête du contrôleur du tour du joueur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* En-tête déclarant les fonctions du contrôleur du tour du joueur.
*/

#ifndef CATANE_CONTROLLER_TURN_H
#define CATANE_CONTROLLER_TURN_H

void controllerTurn(SDL_bool program_launched, SDL_Renderer* renderer/*, Game* the_game*/);

void quit(SDL_bool * program_launched);

void rollDiceEvent(/*Game* the_game*/);
void endTurnEvent(/*Game* the_game*/);
void craftDevEvent(/*Game* the_game*/);

#endif //CATANE_CONTROLLER_TURN_H
