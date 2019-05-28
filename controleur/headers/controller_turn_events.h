/**
* \file controller_turn_events.h
* \brief
* \author Titouan Gaborit
* \date 4 mai 2019
*
* En-tête des fonctions de callback appelées lors d'un évènement particulier.
*
*/

#ifndef CATANE_CONTROLLER_TURN_EVENTS_H
#define CATANE_CONTROLLER_TURN_EVENTS_H

#include <SDL.h>
#include "partie.h"

void craftDevEvent(SDL_Window* window, Partie* the_game);
void craftRoadEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched);
void craftSettleEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched);
void craftCityEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched);

void useKnightEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched);
void useMonopEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched);
void useInventEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched);
void useRoadsEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched);
void useUnivEvent(Partie* the_game, SDL_Window* window);

void rollDiceEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched);
void endTurnEvent(Partie* the_game);

void activateRobberEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched, int bool_knight);

#endif //CATANE_CONTROLLER_TURN_EVENTS_H
