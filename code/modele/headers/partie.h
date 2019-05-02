/**
 * \file partie.h
 * \brief deffinition de la structure Partie et les prototypes des fonctions liées à la partie
 * \author Rémi.F
 * \version 0
 * \date 05 mars 2019
 *
 */


#ifndef PARTIE_H
#define PARTIE_H

#define NB_JOUEUR_MAX

#include"joueur.h"
#include "plateau.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>


/**
 * \struct Node_joueur
 * \brief noeud de List_joueur
 *
 */
typedef struct Node_joueur{
Joueur* joueur;
struct Node_joueur* next;
}Node_joueur;

/**
 * \struct List_joueur
 * \brief Liste des joueur inscrità la partie
 *
 */
 typedef struct{
 Node_joueur* first;
 Node_joueur* current;
 Node_joueur* last;
 }List_joueur;
/**
 * \struct Partie
 * \brief représante completement l'état de la partie
 *
 * contient un tableau de joueurs (joueurs inscrits dans la partie
 * contient la strcture Plateau représentant l'état du plateau de jeu
 */

 typedef struct{
     List_joueur* joueurs; /*!<liste contenant tout les joueurs inscrit dans la partie>*/
     Plateau* plateau; /*!<structure représentant l'état du plateau de jeu>*/
     CarteDev* cartedev; /*!<tableau de la pile des carte developpement>*/
 }Partie;

  /**
* \fn void init_partie (Partie partie)
* \brief initialise la strucure partie qui contient toute les information relatives à la partie
*
* alloue la mémoire necessaire à la structure partie,
*initialise le pateau aléatoirement et initialise le tableau de joueur à null
* \param
* \return aucun
*/
Partie* init_partie();

   /**
* \fn void free_partie(Partie* partie)
* \brief libère la mémoire allouée pour une structure partie
*
* \param
* \return aucun
*/
void free_partie(Partie* partie);

  /**
* \fn int find_joueur(Partie* partie, Joueur* joueur)
* \brief place le current de la liste sur le joueur passé en paramètre
*
* \param Partie*:partie, Joueur*:joueur
* \return int: -1 si le joueur n'est pas dans la partie, 0 tout s'est bien passé
*/
int find_joueur(Partie* partie, Joueur* joueur);

 /**
* \fn void add_joueur(Joueur joueur, Partie partie)
* \brief inscrit un nouveau joueur à la partie
*
* ajoute un joueur au tableau de joueur contenue dans la sructure partie
* \param Joueur: joueur à ajouter Patie: partie dans laquelle le joueur est inscrit
* \return aucun
*/
 void add_joueur(Joueur* joueur,Partie* partie);
  /**
* \fn int get_nbjoueurs(Partie* partie)
* \brief renvoie le nombre de joueurs dans la partie
*
* \param Partie*:partie
* \return int: nombre de joueurs.
*/
int get_nbjoueurs(Partie* partie);
  /**
* \fn void donner_main(Partie partie, Joueur joueur)
* \brief donne la main au joueur passé en paramètre
*
*
* \param Partie: partie Joueur: joueur
* \return aucun
*/
void donner_main(Partie* partie, Joueur* joueur);

/**
* \fn Joueur get_joueur_actif(Partie* partie);
* \brief renvoie le Joueur qui a la main
*
* \param Partie*: partie en cour
* \return Joueur: joueur qui a la main
*/
Joueur* get_joueur_actif(Partie* partie);

/**
* \fn void passer_tour(Partie partie)
* \brief passe au tour suivant
*
* appelle la fonction donner_main
* \param Partie partie
* \return aucun
*/
void passer_tour(Partie* partie);

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
 * \fn int lancer_des()
 * \brief Simule un lancé de dès
 *
 *  retourne une valeur aléatoire entre 2 et 12 en respectant les probabilité d'un vrai lancé de dès
 * \param aucun
 * \return int: valeur obtenu
 */
int lancer_des();


/**
 * \fn void distribution_ressource(List_Noeud)
 * \brief distribu les ressources en début de partie
 *
 *  ajoute les ressources juxtaposant les noeuds ou les joueurs ont placé leurs collonies au début de la partie
 * \param Partie: etat de la partie
 * \return aucun
 */
void distribution_ressource(Partie);


/**
 * \fn gagne_ressource(int lance_des, Partie partie);
 * \brief ajoute les ressource gagner en début de partie à la main du joueur
 *
 *  ajoute les ressources juxtaposant les noeuds ou les joueurs ont placé leurs collonies au début de la partie
 * \param Partie: etat de la partie
 * \return aucun
 */
void gagne_ressource(int lance_des, Partie partie);

/**
 * \fn int obtenir_cartedev (Partie* partie)
 * \brief donne une carte developpement au joueur qui en fait la demande
 *
 * \param Partie*: la partie en cours
 * \return int: 0 si tout c'est bien passé -1 si le joueur ne peut pas acheter de carte
 */
int obtenir_cartedev (Partie* partie);

/**
 * \fn int utiliser_monopole (Partie* partie, TypeRessource type)
 * \brief si le joueur courant possède une carte monopole il la défausse et prend les cartes ressources du type passé en paramètre
 *de tout les autre joueurs.
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte monopole
 */
int utiliser_monopole (Partie* partie, TypeRessource type);

/**
 * \fn int utiliser_decouverte (Partie* partie, TypeRessource type)
 * \brief si le joueur courant possède une carte decouverte il la défausse et gagne 2 carte ressource du type passé en paramètre
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte decouverte
 */
int utiliser_decouverte (Partie* partie, TypeRessource type);

/**
 * \fn int utiliser_point (Partie* partie)
 * \brief si le joueur courant possède une carte point il la défausse et gagne 1 point de score
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte point
 */
int utiliser_point (Partie* partie);
#endif //MODELE_REMI_CATANE_PARTIE_H
