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
 * \fn AfficheTexte_NoRessource(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas assez de ressources pour l'action demandée.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_NoRessource(SDL_Window* window);

/**
 * \fn AfficheTexte_NoCarte(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas assez de cartes pour l'action demandée.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_NoCarte(SDL_Window* window);

/**
 * \fn AfficheTexte_StopAction(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a annulé une action.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_StopAction(SDL_Window* window);

/**
 * \fn AfficheTexte_Joueur(SDL_Window* window)
 * \brief affiche un message sur le joueur dont c'est le tour de jeu
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Joueur(SDL_Window* window, Partie* partie);

/**
 * \fn AfficheTexte_Init(SDL_Window* window)
 * \brief affiche un message d'accueil en début de partie
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Init(SDL_Window* window);

/**
 * \fn AfficheTexte_MAJ(SDL_Window* window)
 * \brief affiche l'état actuel complet de messages (pour un nouveau rendu par exemple)
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_MAJ(SDL_Window* window);

/**
 * \fn AfficheTexte_PosRoute(SDL_Window* window)
 * \brief affiche un message d'indication pour poser une route
 *
 *
* \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosRoute(SDL_Window* window);


/**
 * \fn AfficheTexte_PosRoute_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la route n'a pas pu etre posée
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosRoute_Echec(SDL_Window* window);


/**
 * \fn AfficheTexte_PosRoute_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, la route a été posée
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosRoute_Succes(SDL_Window* window);

/**
 * \fn AfficheTexte_PosColonie(SDL_Window* window)
 * \brief affiche un message d'indication pour poser une colonie
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosColonie(SDL_Window* window);

/**
 * \fn AfficheTexte_PosColonie_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, la colonie a été posée.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosColonie_Succes(SDL_Window* window);


 /**
 * \fn AfficheTexte_PosColonie_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, la colonie n'a pas pu etre posée.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosColonie_Echec(SDL_Window* window);


/**
 * \fn AfficheTexte_PosVille(SDL_Window* window)
 * \brief affiche un message d'indication pour poser une ville
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosVille(SDL_Window* window);


/**
 * \fn AfficheTexte_PosVille_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, la ville a ete posee.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosVille_Succes(SDL_Window* window);


/**
 * \fn AfficheTexte_PosVille_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, la ville n'a pas pu etre posee
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosVille_Echec(SDL_Window* window);


/**
 * \fn AfficheTexte_CarteDev_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, une carte developpement a ete choisie.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_CarteDev_Succes(SDL_Window* window);


/**
 * \fn AfficheTexte_CarteDev_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, une carte developpement n'a pas pu etre choisie.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_CarteDev_Echec(SDL_Window* window);


/**
 * \fn AfficheTexte_ChoixRessource(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur doit choisir un type de ressource.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_ChoixRessource(SDL_Window* window);


/**
 * \fn AfficheTexte_Monopole_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a utilisé une carte monopole.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Monopole_Succes(SDL_Window* window, int vol);


/**
 * \fn AfficheTexte_Monopole_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas de carte monopole à jouer.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Monopole_Echec(SDL_Window* window);


/**
 * \fn AfficheTexte_Decouverte_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a utilisé une carte decouverte.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Decouverte_Succes(SDL_Window* window);



/**
 * \fn AfficheTexte_Point_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a utilisé une carte point.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Point_Succes(SDL_Window* window);


/**
 * \fn AfficheTexte_Routes_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a utilisé une carte routes.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Routes_Succes(SDL_Window* window);


/**
 * \fn AfficheTexte_Routes_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas de carte routes à jouer ou les emplacements des routes sont invalides.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Routes_Echec(SDL_Window* window);


/**
 * \fn AfficheTexte_Chevalier_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas de carte routes à jouer ou les emplacements des routes sont invalides.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Chevalier_Succes(SDL_Window* window);


/**
 * \fn AfficheTexte_Chevalier_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas de carte Chevalier a jouer ou bien les parametres sont invalides.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Chevalier_Echec(SDL_Window* window);


/**
 * \fn AfficheTexte_ChoixTuileVoleur(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur doit choisir une tuile ou il souhaite poser le voleur.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_ChoixTuileVoleur(SDL_Window* window);


/**
 * \fn AfficheTexte_ChoixJoueurVoler(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur doit choisir un autre joueur a voler.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_ChoixJoueurVoler(SDL_Window* window);


/**
 * \fn AfficheTexte_LancerDe(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur doit lancer le de.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_LancerDe(SDL_Window* window);

/**
 * \fn AfficheTexte_nbVol(SDL_Window* window, int nb_vol)
 * \brief affiche un message d'indication sur des eventuels joueurs volés.
 *
 *
 * \param window la fenetre de jeu, nb_vol le nombre de joueurs volés.
 * \return aucun
 */
void AfficheTexte_nbVol(SDL_Window* window,int nb_vol);

#endif
