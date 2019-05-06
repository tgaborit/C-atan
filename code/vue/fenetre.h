/**
 * \file fenetre.h
 * \brief Implémente les fonctions de fenetre.c
 * \author Pauline.M
 * \version 1.0
 * \date 01 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage du jeu.
 */


#ifndef FENETRE_H
#define FENETRE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "partie.h"
#include "get_plateau.h"
#include "architecture.h"
#include "carte.h"
#include "tuile.h"
#include "developpement.h"
#include "probabilite.h"
#include "place_infra.h"
#include "affiche_joueur.h"
#include "SDL_erreur.h"

/**
 * \fn SDL_Window* InitFenetre()
 * \brief Fonction créant une fenêtre.
 *
 *
 * \param aucun
 * \return Affiche une fenêtre
 */
SDL_Window* InitFenetre();

/**
 * \fn SDL_Renderer* updateFenetre(Partie* p, SDL_Window* window, SDL_Renderer* oldrenderer)
 * \brief Fonction mettant à jour le plateau de jeu en fonction de la partie
 *
 *
 * \param p, la partie de jeu
 * \param window, la fenêtre du jeu
 * \param oldrenderer, le rendu actuel à détruire pour mettre le jeu à jour
 * \return le nouveau renderer, et affiche le plateau à jour
 */
SDL_Renderer* updateFenetre(Partie* p, SDL_Window* window, SDL_Renderer* oldrenderer);

/**
 * \fn void destroyFenetre(SDL_Window* window, SDL_Renderer* renderer)
 * \brief Fonction détruisant la fenêtre et le renderer, et permettant de quitter SDL.
 *
 *
 * \param window, la fenêtre du jeu
 * \param renderer, le rendu actuel
 * \return aucun
 */
void destroyFenetre(SDL_Window* window, SDL_Renderer* renderer);

/**
 * \fn void AfficheHelp(SDL_Renderer* renderer)
 * \brief Fonction affichant le bouton "?" (help)
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheHelp(SDL_Renderer *renderer);

/**
 * \fn void AfficheDe(SDL_Renderer* renderer)
 * \brief Fonction affichant le dé
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheDe(SDL_Window* window, SDL_Renderer *renderer);

/**
 * \fn void AfficheSkip(SDL_Renderer* renderer)
 * \brief Fonction affichant le bouton pour passer son tour
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheSkip(SDL_Renderer *renderer);

/**
 * \fn void AfficheJetonVoleur(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy)
 * \brief Fonction affichant le jeton du voleur
 *
 *
 * \param p, la partie de jeu actuel
 * \param x et y les coordonnées du noeud recherché
 * \param renderer, le rendu actuel
 * \param posimx et posimy les position en pixel dans la fenetre
 * \return aucun
 */
void AfficheJetonVoleur(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

/**
 * \fn void AfficheVoleur(Partie* p, SDL_Renderer* renderer)
 * \brief Fonction affichant le voleur
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheVoleur(Partie* p, SDL_Renderer* renderer);



#endif
