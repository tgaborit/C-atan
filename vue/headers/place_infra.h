/**
 * \file place_infra.h
 * \brief Déclare les fonctions de place_infra.c
 * \author Emmanuel.D
 * \version 1.0
 * \date 1 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage des probabilites dans le jeu.
 */

#include "fenetre.h"
#include <math.h>

#ifndef PLACE_INFRA_H
#define PLACE_INFRA_H

#define x_centre 960
#define y_centre 431
#define cote 78


/**
 * \fn void Affiche_Infrastructures(Partie* partie, SDL_Renderer* renderer)
 * \brief affiche les colonies/villes/routes présentes sur le plateau
 *
 *
 * \param partie un pointeur vers la partie actuelle
 * \param renderer le rendu actuel
 * \return aucun
 */
void Affiche_Infrastructures(Partie* partie, SDL_Renderer* renderer);


#endif // PLACE_INFRA_H
