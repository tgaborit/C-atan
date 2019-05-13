/**
 * \file developpement.h
 * \brief Déclare les fonctions de developpement.c
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage des cartes de développement dans le jeu.
 */

#ifndef DEVELOPPEMENT_H
#define DEVELOPPEMENT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "SDL_erreur.h"


/**
 * \fn AfficheChevalier(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Chevalier
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheChevalier(SDL_Renderer *renderer);

/**
 * \fn AfficheMonopole(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Monopole
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheMonopole(SDL_Renderer *renderer);

/**
 * \fn AfficheInvention(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Invention
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheInvention(SDL_Renderer *renderer);

/**
 * \fn AfficheRouteDev(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Route
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheRouteDev(SDL_Renderer *renderer);

/**
 * \fn AfficheUniversite(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte développement Universite
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheUniversite(SDL_Renderer *renderer);

/**
 * \fn AfficheGrandeArmee(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte réussite de la Plus Grande Armée
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheGrandeArmee(SDL_Renderer *renderer);

/**
 * \fn AfficheGrandeRoute(SDL_Renderer *renderer)
 * \brief Fonction affichant la carte réussite du Plus Grand Nombre de Route
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheGrandeRoute(SDL_Renderer *renderer);


#endif
