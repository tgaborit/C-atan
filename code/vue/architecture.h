/**
 * \file architecture.h
 * \brief Déclare les fonctions de architecture.c
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage des constructions dans le jeu.
 */

#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "SDL_erreur.h"


/**
 * \fn AfficheBoutonDev(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des cartes développement
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBoutonDev(SDL_Renderer *renderer);


/**
 * \fn AfficheBoutonRoute(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des routes
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBoutonRoute(SDL_Renderer *renderer);

/**
 * \fn AfficheBoutonColonie(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des colonies
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBoutonColonie(SDL_Renderer *renderer);


/**
 * \fn AfficheBoutonVille(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des villes
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBoutonVille(SDL_Renderer *renderer);

#endif
