/**
 * \file affiche_texte.h
 * \brief Déclare les fonctions de affiche_texte.c
 * \author Emmanuel.D
 * \version 1.0
 * \date 6 mai 2019
 *
 * Déclare les fonctions utiles à l'affichage de texte dans le jeu.
 */

#include "fenetre.h"
#include <string.h>

#ifndef AFFICHE_TEXTE_H
#define AFFICHE_TEXTE_H

#define TAILLE_FRAG 59

/**
 * \fn AfficheTexte_Joueur(SDL_Renderer* renderer)
 * \brief affiche un message sur le joueur dont c'est le tour de jeu
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Joueur(SDL_Renderer* renderer);

/**
 * \fn AfficheTexte_Init(SDL_Renderer* renderer)
 * \brief affiche un message d'accueil en début de partie
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Init(SDL_Renderer* renderer);

/**
 * \fn AfficheTexte_MAJ(SDL_Renderer* renderer)
 * \brief affiche l'état actuel complet de messages (pour un nouveau rendu par exemple)
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_MAJ(SDL_Renderer* renderer);

/**
 * \fn AfficheTexte_PosRoute(SDL_Renderer* renderer)
 * \brief affiche un message d'indication pour poser une route
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosRoute(SDL_Renderer* renderer);

/**
 * \fn AfficheTexte_PosColonie(SDL_Renderer* renderer)
 * \brief affiche un message d'indication pour poser une colonie
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosColonie(SDL_Renderer* renderer);

/**
 * \fn AfficheTexte_PosVille(SDL_Renderer* renderer)
 * \brief affiche un message d'indication pour poser une ville
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosVille(SDL_Renderer* renderer);


#endif
