/**
* \file controller_turn_events.h
* \brief
* \author Titouan Gaborit
* \date 4 mai 2019
*
*
*
*/

#ifndef CATANE_CONTROLLER_TURN_EVENTS_H
#define CATANE_CONTROLLER_TURN_EVENTS_H

#include <SDL.h>

void craftDevEvent(/*Game* the_game*/);
void craftRoadEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched);

void useMonopEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched);
void useInventEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched);
void useRoadsEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched);
void useUnivEvent(/*Game* the_game*/);

void rollDiceEvent(/*Game* the_game*/);
void endTurnEvent(/*Game* the_game*/);

#endif //CATANE_CONTROLLER_TURN_EVENTS_H
