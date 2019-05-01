/**
* \file controller_place_road_buttons.h
* \brief En-tête des boutons de l'environnement "Placement d'une route"
* \author Titouan Gaborit
* \date 1 mai 2019
*
* En-tête déclarant les fonctions de gestion des boutons du placement d'une route ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_PLACE_ROAD_BUTTONS_H
#define CATANE_CONTROLLER_PLACE_ROAD_BUTTONS_H

/**
* \enum PlaceRoadButton
* Tous les boutons existants dans l'environnement "Placement d'une route" ainsi que le non-bouton.
*/
typedef enum {
        PATHXX0_BUTTON,
        PATHXX1_BUTTON,
        PATHXX2_BUTTON,
        PATHXX3_BUTTON,
        PATHXX4_BUTTON,
        PATHXX5_BUTTON,

        PATHX0X_BUTTON,
        PATHX1X_BUTTON,
        PATHX2X_BUTTON,
        PATHX3X_BUTTON,
        PATHX4X_BUTTON,
        PATHX5X_BUTTON,

        PATH0XX_BUTTON,
        PATH1XX_BUTTON,
        PATH2XX_BUTTON,
        PATH3XX_BUTTON,
        PATH4XX_BUTTON,
        PATH5XX_BUTTON,

        PATHNE0_BUTTON,
        PATHNE1_BUTTON,
        PATHNE2_BUTTON,
        PATHNE3_BUTTON,
        PATHNE4_BUTTON,
        PATHNE5_BUTTON,

        PATHEE0_BUTTON,
        PATHEE1_BUTTON,
        PATHEE2_BUTTON,
        PATHEE3_BUTTON,
        PATHEE4_BUTTON,
        PATHEE5_BUTTON,

        PATHSE0_BUTTON,
        PATHSE1_BUTTON,
        PATHSE2_BUTTON,
        PATHSE3_BUTTON,
        PATHSE4_BUTTON,
        PATHSE5_BUTTON,

        PATHSW0_BUTTON,
        PATHSW1_BUTTON,
        PATHSW2_BUTTON,
        PATHSW3_BUTTON,
        PATHSW4_BUTTON,
        PATHSW5_BUTTON,

        PATHWW0_BUTTON,
        PATHWW1_BUTTON,
        PATHWW2_BUTTON,
        PATHWW3_BUTTON,
        PATHWW4_BUTTON,
        PATHWW5_BUTTON,

        PATHNW0_BUTTON,
        PATHNW1_BUTTON,
        PATHNW2_BUTTON,
        PATHNW3_BUTTON,
        PATHNW4_BUTTON,
        PATHNW5_BUTTON,

        NO_BUTTON
} PlaceRoadButton;

/**
* \def NPLACEROADBUTTON
* Définit le nombre de boutons de l'environnement "Placement d'une route".
*/
#define NPLACEROADBUTTONS 18

/**
* \def PATHS
* Définit le côté d'un bouton de chemin.
*/
#define PATHS 40

/**
* \def BOARDCENTERX
* Définit l'abscisse du centre du plateau.
*/
#define BOARDCENTERX 960

/**
* \def BOARDCENTERY
* Définit l'ordonnée du centre du plateau.
*/
#define BOARDCENTERY 431

void drawButtonsPlaceRoad(SDL_Renderer* renderer);

void initButtonsPlaceRoad();
    void initPosRectHexLying(SDL_Rect** hex_buttons, int center_x, int center_y, int hexagon_s);

#endif //CATANE_CONTROLLER_PLACE_ROAD_BUTTONS_H
