/**
* \file controller_place_road.h
* \brief En-tête du contrôleur du placement d'une route
* \author Titouan Gaborit
* \date 1 avril 2019
*
* En-tête déclarant les fonctions du contrôleur du placement d'une route.
*
*/

#ifndef CATANE_CONTROLLER_PLACE_ROAD_H
#define CATANE_CONTROLLER_PLACE_ROAD_H

void controllerPlaceRoad(SDL_bool program_launched, SDL_Renderer* renderer/*, Game* the_game*/);

void quitPlacing(SDL_bool * pplacing_launched);

#endif //CATANE_CONTROLLER_PLACE_ROAD_H
