/**
 * \file tuile.h
 * \brief Déclare les fonctions de tuile.c
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage des tuiles dans le jeu.
 */

#ifndef TUILE_H
#define TUILE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "partie.h"
#include "SDL_erreur.h"
#include "get_plateau.h"

/**
 * \fn AfficheTuile(SDL_Renderer* renderer)
 * \brief Fonction affichant le squelette du plateau.
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheTuile(SDL_Renderer* renderer);

/**
 * \fn AfficheTuileArgile(SDL_Renderer* renderer, double x, double y)
 * \brief Fonction affichant une tuile argile.
 *
 *
 * \param renderer, le rendu actuel
 * \param x et y la position en pixel de l'image
 * \return aucun
 */
void AfficheTuileArgile(SDL_Renderer* renderer, double x, double y);

/**
 * \fn AfficheTuileBle(SDL_Renderer* renderer, double x, double y)
 * \brief Fonction affichant une tuile blé.
 *
 *
 * \param renderer, le rendu actuel
 * \param x et y la position en pixel de l'image
 * \return aucun
 */
void AfficheTuileBle(SDL_Renderer* renderer, double x, double y);

/**
 * \fn AfficheTuileBois(SDL_Renderer* renderer, double x, double y)
 * \brief Fonction affichant une tuile bois.
 *
 *
 * \param renderer, le rendu actuel
 * \param x et y la position en pixel de l'image
 * \return aucun
 */
void AfficheTuileBois(SDL_Renderer* renderer, double x, double y);

/**
 * \fn AfficheTuileMouton(SDL_Renderer* renderer, double x, double y)
 * \brief Fonction affichant une tuile mouton.
 *
 *
 * \param renderer, le rendu actuel
 * \param x et y la position en pixel de l'image
 * \return aucun
 */
void AfficheTuileMouton(SDL_Renderer* renderer, double x, double y);

/**
 * \fn AfficheTuileRoche(SDL_Renderer* renderer, double x, double y)
 * \brief Fonction affichant une tuile roche.
 *
 *
 * \param renderer, le rendu actuel
 * \param x et y la position en pixel de l'image
 * \return aucun
 */
void AfficheTuileRoche(SDL_Renderer* renderer, double x, double y);

/**
 * \fn AfficheRandomTuile(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy)
 * \brief Fonction permettant de récuperer le type des tuiles et d'afficher les images des ressources
 *
 *
 * \param p, la partie actuelle
 * \param x et y les coordonnées du noeud recherché
 * \param renderer, le rendu actuel
 * \param posimx et posimy la position en pixel de l'image
 * \return aucun
 */
void AfficheRandomTuile(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

/**
 * \fn AfficheTuilePlateau(Partie* p, SDL_Renderer* renderer)
 * \brief Fonction affichant les tuiles de manière aléatoire
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */

void AfficheTuilePlateau(Partie* p, SDL_Renderer* renderer);


#endif
