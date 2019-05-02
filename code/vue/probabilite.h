/**
 * \file probabilite.h
 * \brief Déclare les fonctions de probabilite.c
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage des probabilites dans le jeu.
 */

#ifndef PROBABILITE_H
#define PROBABILITE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "SDL_erreur.h"
#include "partie.h"
#include "get_plateau.h"

/**
 * \fn Affiche2(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 2 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche2(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche3(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 3 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche3(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche4(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 4 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche4(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche5(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 5 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche5(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche6(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 6 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche6(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche7(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 7 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche7(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche8(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 8 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche8(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche9(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 9 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche9(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche10(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 10 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche10(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche11(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 11 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche11(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn Affiche12(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 12 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche12(SDL_Renderer* renderer, double posx, double posy);

/**
 * \fn AfficheProbaNormal(SDL_Renderer *renderer)
 * \brief Fonction affichant les probabiltés tel que c'est décrit dans les règles du jeu classique
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheProbaNormal(SDL_Renderer* renderer);

/**
 * \fn AfficheRandomProba(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy)
 * \brief Fonction affichant les probabiltés de manière aléatoire
 *
 *
 * \param p, la partie actuelle
 * \param x et y les coordonnées du noeud recherché
 * \param renderer, le rendu actuel
 * \param posimx et posimy les coordonnées en pixel de l'image à afficher
 * \return aucun
 */
void AfficheRandomProba(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

/**
 * \fn AfficheRandomProbaPlateau(Partie* p, SDL_Renderer* renderer)
 * \brief Fonction affichant les probabiltés de manière aléatoire sur le plateau
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheRandomProbaPlateau(Partie *p, SDL_Renderer *renderer);

#endif
