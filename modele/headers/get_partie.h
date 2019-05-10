/**
 * \file get_partie.h
 * \brief fonctions d'accés à la structure partiepour la vue et le controleur
 * \author Rémi.F
 * \version 0
 * \date 4 mai 2019
 *
 */


#ifndef GET_PARTIE_H
#define GET_PARTIE_H

#define NB_JOUEUR_MAX

#include "partie.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

/**
* \fn Joueur get_joueur_actif(Partie* partie);
* \brief renvoie le Joueur qui a la main
*
* \param Partie*: partie en cours
* \return Joueur: joueur qui a la main
*/
Joueur* get_joueur_actif(Partie* partie);

/**
 * \fn int  get_nbcartedev(TypeCarteDev type, Joueur* joueur)
 * \brief Fonction qui retourne les cartes developpemnts possédées par le joueur
 *
 * fonction renvoillant le nombre de carte developpement d'un certain type possédé par le joueur actif
 * \param TypeCarteDev: le type de la carte developpemnt dont on veut connaitre le nombre, Partie* partie en cours
 * \return int:le nombre de la carte developpement du type passé en paramètre possédé par le joueur actif
 */
int  get_nbcartedev_joueuractif(TypeCarteDev type,Partie* partie);

/**
 * \fn int  get_nbressource_joueuractif(TypeRessource type, Partie* partie)
 * \brief Fonction qui retourne les ressources possédées par le joueur actif
 *fonction renvoillant le nombre de ressource d'un certain type possédé le joueur actif
 * \param Type_ressource: le type de la ressource dont on veut connaitre le nombre, Partie* partie en cours
 * \return int:le nombre de la ressource du type passé en paramètre possédé par le joueur
 */
int  get_nbressource_joueuractif(TypeRessource type, Partie* partie);

/**
 * \fn int get_score_joueuractif(Joueur joueur)
 * \brief Fonction qui retourne le score du joueur actif
 *
 * \param Partie* partie en cours
 * \return int:le score du joueur actif.
 */

int get_score_joueuractif(Partie* partie);

  /**
* \fn int get_nbjoueurs(Partie* partie)
* \brief renvoie le nombre de joueurs dans la partie
*
* \param Partie*:partie
* \return int: nombre de joueurs.
*/
int get_nbjoueurs(Partie* partie);

/**
* \fn int get_score_max
* \brief retourne le score du joueur le plus fort
*
* renvoie le score du joueur ayant le plus de point si plusieurs joueur sont a égalité renvoie
 * le score le plus fort
* \param Partie: partie en cours
* \return int: score max dans la partie
*/
int get_score_max(Partie* partie);

/**
* \fn Joueur* get_score_max
* \brief retourne un pointeur sur le joueur qui a le score le plus fort
*
* renvoie le joueur ayant le plus de point si plusieurs joueur sont a égalité renvoie le joeur qui a joué le plus tot au premier tour
* exemple: si tout les score sont à 2 renvoie le joueur qui a jouer en premier
*
* \param Partie: partie en cours
* \return Joueur*: joueur ayant le plus haut score
*/
Joueur* get_joueur_score_max(Partie* partie);




#endif
