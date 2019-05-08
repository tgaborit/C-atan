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
 * \fn void AffichePseudoJ1(SDL_Renderer* renderer, Joueur* j);
 * \brief Fonction affichant le pseudo et le score du joueur 1.
 *
 *
 * \param renderer, le rendu actuel
 * \param j, le joueur 1
 * \return aucun
 */
void AffichePseudoJ1(SDL_Renderer* renderer, Joueur* j);

/**
 * \fn void AffichePseudoJ2(SDL_Renderer* renderer, Joueur* j);
 * \brief Fonction affichant le pseudo et le score du joueur 2.
 *
 *
 * \param renderer, le rendu actuel
 * \param j, le joueur 2
 * \return aucun
 */
void AffichePseudoJ2(SDL_Renderer* renderer, Joueur* j);

/**
 * \fn void AffichePseudoJ3(SDL_Renderer* renderer, Joueur* j);
 * \brief Fonction affichant le pseudo et le score du joueur 3.
 *
 *
 * \param renderer, le rendu actuel
 * \param j, le joueur 3
 * \return aucun
 */
void AffichePseudoJ3(SDL_Renderer* renderer, Joueur* j);

/**
 * \fn void AffichePseudoJ4(SDL_Renderer* renderer, Joueur* j);
 * \brief Fonction affichant le pseudo et le score du joueur 4.
 *
 *
 * \param renderer, le rendu actuel
 * \param j, le joueur 4
 * \return aucun
 */
void AffichePseudoJ4(SDL_Renderer* renderer, Joueur* j);

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
#endif
