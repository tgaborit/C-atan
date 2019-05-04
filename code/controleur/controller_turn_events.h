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

#include "controller_path.h"
#include "controller_resource.h"

typedef enum {
        BLE,
        BOIS,
        PIERRE,
        ARGILE,
        MOUTON
} TypeRessource;/* pour tester */

typedef struct {
        double x;
        double y;
        int position;
} PathCoordinates;

void craftDevEvent(/*Game* the_game*/);
void craftRoadEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched);
    PathCoordinates pathButtonToPathCoordinates(PathButton path_clicked);
void useUnivEvent(/*Game* the_game*/);
void useInventEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched);
    TypeRessource resourceButtonToTypeRessource(ResourceButton resource_clicked);
void rollDiceEvent(/*Game* the_game*/);
void endTurnEvent(/*Game* the_game*/);

#endif //CATANE_CONTROLLER_TURN_EVENTS_H
