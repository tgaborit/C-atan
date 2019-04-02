/**
*
*
* \author Titouan Gaborit
* \date 1 avril 2019
*
*
*/

#ifndef CATANE_CONTROLLER_PLACE_URB_H
#define CATANE_CONTROLLER_PLACE_URB_H

typedef enum {SETTLE_PLACING, CITY_PLACING} UrbPlacing;

void controllerPlaceUrb(SDL_bool program_launched, SDL_Renderer* renderer/*, Game* the_game*/);

void quit(SDL_bool * pprogram_launched);

#endif //CATANE_CONTROLLER_PLACE_URB_H
