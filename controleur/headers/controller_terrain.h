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
* \enum TerrButton
* Tous les boutons existants dans l'environnement "Choix d'un terrain" ainsi que le non-bouton.
*/
typedef enum {
        TERRX0_BUTTON,
        TERRX1_BUTTON,
        TERRX2_BUTTON,
        TERRX3_BUTTON,
        TERRX4_BUTTON,
        TERRX5_BUTTON,

        TERR0X_BUTTON,
        TERR1X_BUTTON,
        TERR2X_BUTTON,
        TERR3X_BUTTON,
        TERR4X_BUTTON,
        TERR5X_BUTTON,

        TERRNN_BUTTON,
        TERRNE_BUTTON,
        TERRSE_BUTTON,
        TERRSS_BUTTON,
        TERRSW_BUTTON,
        TERRNW_BUTTON,

        NO_TERRBUTTON
} TerrButton;

/**
* \def NTERRBUTTONS
* Définit le nombre de boutons de l'environnement "Choix d'un terrain".
*/
#define NTERRBUTTONS 18

/**
* \def TERRAINS
* Définit le côté d'un bouton de terrain.
*/
#define TERRAINS 80

void controllerTerrain(TerrButton* terrain_chosen, SDL_Window* window, SDL_bool* program_launched);

void drawTerrButtons(SDL_Window* window);

TerrButton whichTerrButton(SDL_MouseButtonEvent mouse_button);

void initTerrButtons();

#endif //CATANE_CONTROLLER_TERRAIN_H
