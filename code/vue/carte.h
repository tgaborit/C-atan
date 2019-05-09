/**
 * \file carte.h
 * \brief Déclare les fonctions de carte.c
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage des cartes dans le jeu.
 */

#ifndef CARTE_H
#define CARTE_H

#include <SDL.h>

/**
 * \fn AfficheCarteArgile(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes argile
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteArgile(SDL_Renderer *renderer);

/**
 * \fn AfficheCarteBle(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes blé
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteBle(SDL_Renderer *renderer);

/**
 * \fn AfficheCarteBois(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes bois
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteBois(SDL_Renderer *renderer);

/**
 * \fn AfficheCarteMouton(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes mouton
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteMouton(SDL_Renderer *renderer);

/**
 * \fn AfficheCarteRoche(SDL_Renderer *renderer)
 * \brief Fonction affichant les cartes roche
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheCarteRoche(SDL_Renderer *renderer);

#endif

