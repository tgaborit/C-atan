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
* \def HEXAGONS
* Définit le côté des hexagones.
*/
#define HEXAGONS 78

SDL_bool isInArea(SDL_MouseButtonEvent mouse_button, SDL_Rect area);

void quit(SDL_bool * paction_launched);

void SDL_ExitWithError(const char *message);

#endif //CATANE_CONTROLLER_H
