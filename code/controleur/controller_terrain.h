/**
* \file controller_terrain.h
* \brief En-tête du contrôleur du choix d'un terrain
* \author Titouan Gaborit
* \date 6 mai 2019
*
* En-tête déclarant les fonctions du contrôleur du choix d'un terrain ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_TERRAIN_H
#define CATANE_CONTROLLER_TERRAIN_H

#include <SDL.h>

void controllerTerrain(/*TerrainButton* terrain_chosen, */SDL_Renderer* renderer, SDL_bool* program_launched);

#endif //CATANE_CONTROLLER_TERRAIN_H
