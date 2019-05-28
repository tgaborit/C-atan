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
 * void setOnFirst_list_joueur(List_joueur* l)
 * \brief deffinie le joueur courant comme le premier de la liste
 *
 * \param List_joueur* l liste des joueurs de la partie
 * \return aucun
 */

void setOnFirst_list_joueur(List_joueur* l);

/**
 * \fn int get_des(Partie* partie)
 * \brief Simule un lancé de dès
 *
 *  retourne la valeur du lancé de des le plus récent de la partie.
 * \param partie un pointeur vers la partie.
 * \return int: valeur obtenu
 */
int get_des(Partie* partie);

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
 * \fn char* get_pseudo_joueuractif(Partie* partie)
 * \brief Fonction qui retourne le pseudo du joueur actif
 *
 * \param Partie* partie en cours
 * \return char*:le pseudo du joueur actif
 */

 char* get_pseudo_joueuractif(Partie* partie);

 /**
 * \fn int get_nbChevalier_joueuractif(Partie* partie)
 * \brief Fonction qui retourne le nombre de chevaliers activés par le joueur actif
 *
 * \param Partie* partie en cours
 * \return int:le nombre de chevaliers activés par le joueur actif
 */

int get_nbChevalier_joueuractif(Partie* partie);


/**
 * \fn Joueur* get_joueur_chevaliers(Partie* partie)
 * \brief Fonction qui retourne le joueur possédant le plus d'activations de chevaliers.
 *
 * \param Partie* partie en cours
 * \return retourne le joueur en question, ou NULL en cas d'égalité ou si personne n'a activé plus de trois chevaliers.
 */

Joueur* get_joueur_chevaliers(Partie* partie);


/**
 * \fn Joueur* get_joueur_routes(Partie* partie)
 * \brief Fonction qui retourne le joueur possédant le plus d'activations de chevaliers.
 *
 * \param Partie* partie en cours
 * \return retourne le joueur en question, ou NULL en cas d'égalité ou si personne n'a posé plus de cinq routes.
 */
Joueur* get_joueur_routes(Partie* partie);


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

/**
* \fn int test_pseudo(char* pseudo, Partie* partie)
* \brief retourne un flag qui indique l'unité ou non du pseudo choisi.
*retourne 0 si le pseudo n'est pas encore utiliser dans la partie, -1 sinon
*
* \param char*:pseudo à vérifier,Partie: partie en cours
* \return int:retourne 0 si le pseudo n'est pas encore utiliser dans la partie, -1 sinon
*/
int test_pseudo(char* pseudo, Partie* partie);




#endif
