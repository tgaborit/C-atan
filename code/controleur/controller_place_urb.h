/**
* \file controller_place_urb.h
* \brief En-tête du contrôleur du placement d'une colonie/ville
* \author Titouan Gaborit
* \date 1 avril 2019
*
* En-tête déclarant les fonctions du contrôleur du placement d'une colonie/ville.
*
*/

#ifndef CATANE_CONTROLLER_PLACE_URB_H
#define CATANE_CONTROLLER_PLACE_URB_H

/**
* \enum UrbPlacing
* Type de craft à placer entre une colonie et une ville.
*/
typedef enum {SETTLE_PLACING, CITY_PLACING} UrbPlacing;

void controllerPlaceUrb(SDL_bool program_launched, SDL_Renderer* renderer/*, Game* the_game*/, UrbPlacing urb_placing);
void controllerPlaceUrbButton(SDL_MouseButtonEvent button, SDL_bool* pplacing_launched/*, Game* the_game,*/, UrbPlacing urb_placing);

void placeUrbEvent(SDL_bool* pplacing_launched/*, Game* the_game,*/, double x, double y, int position, UrbPlacing urb_placing);

#endif //CATANE_CONTROLLER_PLACE_URB_H
