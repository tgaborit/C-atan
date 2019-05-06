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

/**
* \enum TerrainButton
* Tous les boutons existants dans l'environnement "Choix d'un terrain" ainsi que le non-bouton.
*/
typedef enum {


        NO_TERRAINBUTTON
} TerrainButton;

/**
* \def NTERRAINBUTTONS
* Définit le nombre de boutons de l'environnement "Choix d'un terrain".
*/
#define NTERRAINBUTTONS 12

/**
* \def TERRAINS
* Définit le côté d'un bouton de terrain.
*/
#define TERRAINS 80

void controllerTerrain(/*TerrainButton* terrain_chosen, */SDL_Renderer* renderer, SDL_bool* program_launched);

void drawTerrainButtons(SDL_Renderer* renderer);

void initTerrainButtons();

#endif //CATANE_CONTROLLER_TERRAIN_H
