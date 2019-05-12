
#ifndef PARTIE_H
#define PARTIE_H

#define NB_JOUEUR_MAX

#include "plateau.h"




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
* \fn void init_partie ()
* \brief initialise la strucure partie qui contient toute les information relatives à la partie
*
* alloue la mémoire necessaire à la structure partie,
*initialise le pateau aléatoirement et initialise le tableau de joueur à null
* \param
* \return aucun
*/
Partie* init_partie();

void setOnNext_list_joueur(List_joueur* list);
 	  /**

* \fn void free_partie (Partie* partie)
* \brief initialise la strucure partie qui contient toute les informations relatives à la partie
* supprime la mémoire allouée à la structure partie,
*initialise le pateau aléatoirement et initialise le tableau de joueur à null
* \param parte un pointeur vers la partie
* \return aucun
*/
void free_partie(Partie* partie);

#endif
