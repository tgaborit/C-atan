/**
* \file controller.h
* \brief En-tête générale du contrôleur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* En-tête déclarant les fonctions générales du contrôleur ainsi que la définition des macros générales.
*
*/

#ifndef CATANE_CONTROLLER_H
#define CATANE_CONTROLLER_H

/**
* \def WINDOWW
* Définit la largeur de la fenêtre.
*/
#define WINDOWW 1920

/**
* \def WINDOWH
* Définit la hauteur de la fenêtre.
*/
#define WINDOWH 950

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

/**
* \def HEXAGONS
* Définit le côté des hexagones.
*/
#define HEXAGONS 78

/**
* \def BANNERH
* Définit la hauteur d'un bouton de joueur.
*/
#define BANNERH 35

SDL_bool isInArea(SDL_MouseButtonEvent mouse_button, SDL_Rect area);

void quit(SDL_bool * paction_launched);

void initPosRectHex(SDL_Rect** hex_rect, float center_x, float center_y, float hexagon_s);
void initPosRectHexLying(SDL_Rect** hex_rect, float center_x, float center_y, float hexagon_s);

//void SDL_ExitWithError(const char *message);

#endif //CATANE_CONTROLLER_H
