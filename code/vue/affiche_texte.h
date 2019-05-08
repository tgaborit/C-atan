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
 * \fn AfficheTexte_PosRoute_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la route n'a pas pu etre posée
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosRoute_Echec(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_PosRoute_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la route a été posée
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosRoute_Succes(SDL_Renderer* renderer);

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
 * \fn AfficheTexte_PosColonie_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la colonie a été posée.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosColonie_Succes(SDL_Renderer* renderer);


 /**
 * \fn AfficheTexte_PosColonie_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la colonie n'a pas pu etre posée.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosColonie_Echec(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_PosVille(SDL_Renderer* renderer)
 * \brief affiche un message d'indication pour poser une ville
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosVille(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_PosVille_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la ville a ete posee.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosVille_Succes(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_PosVille_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la ville n'a pas pu etre posee
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosVille_Echec(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_CarteDev_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, une carte developpement a ete choisie.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_CarteDev_Succes(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_CarteDev_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, une carte developpement n'a pas pu etre choisie.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_CarteDev_Echec(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_ChoixRessource(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur doit choisir un type de ressource.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_ChoixRessource(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_Monopole_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur a utilisé une carte monopole.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Monopole_Succes(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_Monopole_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas de carte monopole à jouer.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Monopole_Echec(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_Decouverte_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur a utilisé une carte decouverte.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Decouverte_Succes(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_Decouverte_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas de carte decouverte à jouer.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Decouverte_Echec(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_Point_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur a utilisé une carte point.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Point_Succes(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_Point_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas de carte point à jouer.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Point_Echec(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_Routes_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur a utilisé une carte routes.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Routes_Succes(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_Routes_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas de carte routes à jouer ou les emplacements des routes sont invalides.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Routes_Echec(SDL_Renderer* renderer);


/**
 * \fn AfficheTexte_ChoixRoutes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, demande au joueur de choisir deux emplacements pour les routes à poser.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_ChoixRoutes(SDL_Renderer* renderer);

#endif
