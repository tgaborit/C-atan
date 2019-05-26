/**
 * \file affiche_joueur.h
 * \brief Implémente les fonctions de affiche_joueur.c
 * \author Pauline.M
 * \version 1.0
 * \date 05 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage des informations des joueurs.
 */

#ifndef AFFICHE_JOUEUR_H
#define AFFICHE_JOUEUR_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "partie.h"
#include "get_plateau.h"
#include "get_partie.h"
#include "SDL_erreur.h"
#include "ressource.h"



/**
 * \fn void AfficheJoueur(SDL_Renderer* renderer)
 * \brief Fonction affichant les noms et les scores des joueurs
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheJoueur(SDL_Renderer* renderer);

/**
 * \fn void AfficheInfoJoueurs(Joueur* j, SDL_Renderer* renderer, int x);
 * \brief Fonction affichant le pseudo et le score d'un joueur.
 *
 *
 * \param j, le joueur
 * \param renderer, le rendu actuel
 * \param x, la coordonnée x du rectangle d'affichage des informations
 * \return aucun
 */
void AfficheInfoJoueurs(Joueur* j, SDL_Renderer* renderer, int x);

/**
 * \fn void AfficheListeJoueurs(Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant le pseudo et le score tous les joueurs participant à la partie.
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheListeJoueurs(Partie* p, SDL_Renderer* renderer);

/**
 * \fn void AfficheNombreRessources(TypeRessource type, Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant le nombre de chaque ressource pour le joueur courant
 *
 *
 * \param type, le type de ressource
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNombreRessources(TypeRessource type, Partie* p, SDL_Renderer* renderer);

/**
 * \fn void AfficheNombreDev(TypeCarteDev type, Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant le nombre de chaque carte développement pour le joueur courant
 *
 *
 * \param type, le type de développement
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNombreDev(TypeCarteDev type, Partie* p, SDL_Renderer* renderer);

/**
 * \fn void AfficheNbCarte(Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant le nombre de toutes les cartes pour le joueur courant
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNbCarte(Partie* p, SDL_Renderer* renderer);

/**
 * \fn void AfficheNbReussiteChevalier(Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant 1 si la carte réussite est en possession du joueur, sinon 0
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNbReussiteChevalier(Partie*p, SDL_Renderer* renderer);

/**
 * \fn void AfficheNbReussiteRoute(Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant 1 si la carte réussite est en possession du joueur, sinon 0
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNbReussiteRoute(Partie*p, SDL_Renderer* renderer);
#endif
