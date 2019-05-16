/**
 * \file partie.h
 * \brief deffinition de la structure Partie et les prototypes des fonctions liées à la partie
 * \author Rémi.F
 * \version 0
 * \date 05 mars 2019
 *
 */


#ifndef SET_PARTIE_H
#define SET_PARTIE_H

#define NB_JOUEUR_MAX

#include "partie.h"
#include "get_partie.h"
#include "set_plateau.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>


  /**
* \fn void setOnFirst_joueur(Partie* partie)
* \brief remet la liste de joueurs sur le premier.
*
* \param Partie*:partie
* \return aucun retour.
*/
void setOnFirst_joueur(Partie* partie);

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
* \fn void donner_main(Partie partie, Joueur joueur)
* \brief donne la main au joueur passé en paramètre
*
*
* \param Partie: partie Joueur: joueur
* \return aucun
*/
void donner_main(Partie* partie, Joueur* joueur);

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
 * \fn int lancer_des(Partie* partie)
 * \brief Simule un lancé de dès
 *
 *  retourne une valeur aléatoire entre 2 et 12 en respectant les probabilité d'un vrai lancé de dès
 * \param partie un pointeur vers la partie.
 * \return int: valeur obtenu
 */
int lancer_des(Partie* partie);


/**
 * \fn void distribution_ressource(List_Noeud)
 * \brief distribu les ressources en début de partie
 *
 *  ajoute les ressources juxtaposant les noeuds ou les joueurs ont placé leurs collonies au début de la partie
 * \param Partie: etat de la partie
 * \return aucun
 */
void distribution_ressource(Partie* partie);

/**
 * \fn void gagne_ressource(int lance_des, Partie partie);
 * \brief distribue les ressources correspondant aux cases du numéro de dés
 *  ajoute les ressources aux joueurs possédant une construction à proximité de ces cases.
 * \param Partie: etat de la partie
 * \return aucun
 */
void gagne_ressource(int lance_des, Partie* partie);

/**
 * \fn void nb_routes_max(Partie* partie)
 * \brief met à jour le point déscerné au détenteur du plus de routes
 *
 *  Enleve un point à l'ancien détenteur et en rajoute un au nouveau (sauf en cas d'égalité)
 * \param Partie: etat de la partie
 * \return aucun retour
 */

void nb_routes_max(Partie* partie);


/**
 * \fn void nb_chevaliers_max(Partie* partie)
 * \brief met à jour le point déscerné au détenteur du plus de chevaliers activés.
 *
 *  Enleve un point à l'ancien détenteur et en rajoute un au nouveau (sauf en cas d'égalité)
 * \param Partie: etat de la partie
 * \return auncun retour
 */
void nb_chevaliers_max(Partie* partie);


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
 * \brief si le joueur courant possède une carte decouverte il la défausse et gagne 2 carte ressource des types passés en paramètre
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte decouverte
 */
int utiliser_decouverte (Partie* partie, TypeRessource type1, TypeRessource type2);

/**
 * \fn int utiliser_point (Partie* partie)
 * \brief si le joueur courant possède une carte point il la défausse et gagne 1 point de score
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte point
 */
int utiliser_point (Partie* partie);


/**
 * \fn int utiliser_routes(Partie* partie,int x1,int y1,int x2,int y2,int position1,int position2)
 * \brief si le joueur courant possede une carte routes il la defausse et pose deux routes.
 *
 * \param Partie*: la partie en cours, puis les parametres des endroits ou poser les deux routes
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte routes ou si la pose a échoué
 */
int utiliser_routes(Partie* partie,double x1,double y1,double x2,double y2,int position1,int position2);


/**
 * \fn int utiliser_chevalier(Partie* partie, double x, double y,Joueur* joueur)
 * \brief utilise une carte développemnt chevalier, bouge le voleur sur une nouvelle tuile de coordonée passé en paramètre,
 *vole une carte aléatoirement dans la main du joueur passé en paramètre et la donne au joueur qui appelle la carte chevalier.
 * \param Partie: etat de la partie
 * \return 0 si tout c'est bien passé -1 si le joueur passé en paramètre n'a pas d'infrastructuresur un sommet de la tuile de coordonnées (x,y)
 */
int utiliser_chevalier(Partie* partie, double x, double y,Joueur* joueur);


/**
 * \fn int vole_carte(Partie* partie,double x, double y, Joueur* victime)
 * \brief tente de voler une carte au hasard dans la main du joueur passé en parametre et de la donner ua joueur courant.
 *
 * \param Partie: etat de la partie, x et y les coordonnées de la tuile ou voler, victime le joueur à voler.
 * \return 0 si tout c'est bien passé -1 si le joueur passé en paramètre n'a pas d'infrastructure sur un sommet de la tuile de coordonnées (x,y) ou s'il n'a pas de cartes.
 */
int vole_carte(Partie* partie,double x, double y, Joueur* victime);

    /**
 * \fn int action_voleur(Partie* partie);
 * \brief si le des affiche 7, passe en revu les cartes ressource de tout les joueur et enlève la moitier des ressource des joueur qui ont plus de 7 cartes ressources.
 *
 * \param Partie*: la partie en cours
 * \return le nombre de gens volés
 */
int action_voleur(Partie* partie);

#endif //MODELE_REMI_CATANE_PARTIE_H
