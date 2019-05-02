/**
* \file controller_place_road.h
* \brief En-tête du contrôleur du placement d'une route
* \author Titouan Gaborit
* \date 1 mai 2019
*
* En-tête déclarant les fonctions du contrôleur du placement d'une route.
*
*/

#ifndef CATANE_CONTROLLER_PLACE_ROAD_H
#define CATANE_CONTROLLER_PLACE_ROAD_H

void controllerPlaceRoad(SDL_bool* program_launched, SDL_Renderer* renderer/*, Game* the_game*/);
    void controllerPlaceRoadButton(SDL_MouseButtonEvent button, SDL_bool* pplacing_launched/*, Game* the_game*/);

void placeRoadEvent(SDL_bool* pplacing_launched/*, Game* the_game,*/, double x, double y, int position);

#endif //CATANE_CONTROLLER_PLACE_ROAD_H
