/**
* \file controller_preparation.h
* \brief En-tête du contrôleur de la préparation du jeu
* \author Titouan Gaborit
* \date 16 mai 2019
*
* En-tête déclarant la fonction du contrôleur de la préparation du jeu.
*
*/

#ifndef CATANE_CONTROLLER_PREPARATION_H
#define CATANE_CONTROLLER_PREPARATION_H

#include <SDL.h>
#include "partie.h"

void controllerPreparation(SDL_bool* program_launched, SDL_Window* window, Partie* the_game);

#endif //CATANE_CONTROLLER_PREPARATION_H
