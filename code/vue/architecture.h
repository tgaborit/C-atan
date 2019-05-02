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
 * \fn AfficheBouttonDev(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des cartes développement
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBouttonDev(SDL_Renderer *renderer);


/**
 * \fn AfficheBouttonRoute(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des routes
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBouttonRoute(SDL_Renderer *renderer);

/**
 * \fn AfficheBouttonColonie(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des colonies
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBouttonColonie(SDL_Renderer *renderer);


/**
 * \fn AfficheBouttonVille(SDL_Renderer *renderer)
 * \brief Fonction affichant le bouton des villes
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheBouttonVille(SDL_Renderer *renderer);

#endif
