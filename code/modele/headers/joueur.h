/**
 * \file joueur.h
 * \brief deffinition de la strucuture joueur et prototype des fonctions associées
 * \author Rémi.F
 * \version 0
 * \date 05 mars 2019
 *
 * Header, deffinition structure joueur et prototype fonctions associées à joueur
 *
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include "ressource.h"
#include<stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>




#define TAILLE_MAX_PSEUDO  16 //taille max de caractère dans le pseudo d'un joueur

/**
 * \enum Couleur
 * \brief Couleur possible pour le joueur
 *
 * contient les différentes couleurs possible pour un joueur
 */

typedef enum {
    ROUGE, VERT, ORANGE, BLEU}
    Couleur;

/**
 * \enum Status
 * \brief Status du joueur en attente ou joue
 *
 * représente le status du joueur si il est en train de jouer ou il attend son tour
 */
typedef enum {
    JOUE, /*!<c'est le tour du joueur>*/
    ATTEND /*<le joueur attend son tour>*/
}Status;



/**
 * \struct Joueur
 * \brief Structure représentant un joueur dans la partie .
 * un joueur est associé à une couleur un pseudo pour l'identifier
 * la structure contient les cartes dans la main du joueur stocké dans des tableaux
 * la structure reseigne également sur le score du joueur.
 *
 */
typedef struct {
int score; /*!<entier représentant le nombre de points de victoire du joueur>*/
char pseudo[TAILLE_MAX_PSEUDO]; /*!<chaine de caractères stokant le pseudo choisi par le joueur>*/
Status status; /*<deffinie si c'est le tour du joueur ou si il est en attente>*/
Ressource ressource[4] ; /*!<tableau de ressource représentant les ressources en main du joueur classé par type (une case par type de ressource)>*/
CarteDev carte_dev [4] ; /*!<tableau de Developpement représentant les cartes_dev en main du joueur classé par type (une case par type de ressource)>*/
Couleur couleur; /*!<couleur associé au joueur choisie au début de la parie>*/
}Joueur;

/**
 * \fn void set_pseudo(Joueur joueur);
 * \brief Initialisaton pseudo joueur
 *
 *
 * \param Char* pseudo choisie par le joueur Joueur*: joueur dont on initialise le pseudo
 * \return: aucun
 */
void set_pseudo(Joueur* joueur, char* pseudo);

/**
 * \fn void set_status(Joueur joueur);
 * \brief Initialisaton status du joueur
 *
 *
 * \param Status status Joueur*: joueur dont on initialise le status
 * \return: aucun
 */
void set_status(Joueur* joueur, Status satus);


/**
 * \fn void init_main_ressource(Joueur joueur);
 * \brief Initialisation des cartes en main du joueur
 *
 *
 * \param initialise les carte en main du joueur en trillant le tableau par type dans un ordre précis
 * \return: aucun
 */
void init_main_ressource(Joueur* joueur);

/**
 * \fn void init_main_cartdev(Joueur joueur);
 * \brief Initialisation des cartes en main du joueur
 *
 *
 * \param initialise les carte en main du joueur en trillant le tableau par type dans un ordre précis
 * \return: aucun
 */
void init_main_cartedev(Joueur* joueur);


/**
 * \fn void init_joueur(Couleur couleur,char* pseudo)
 * \brief Fonction d'initialisationde la structure joueur
 *
 * fonction qui alloue la mémoire necessaire à la création d'un joueur, lui donne son pseudo et sa couleur et initialise son score à 0 ainsi que le nombre de ses cartes en main
 * \param Couleur: la couleur choisi par le joueur char* le pseudo choisi par le joueur.
 * \return: aucun
 */
Joueur* init_joueur(Couleur couleur,char* pseudo);



/**
 * \fn int get_score(Joueur joueur)
 * \brief Fonction qui retourne le score du joueur
 *
 * fonction renvoillant le score du joueur passé en paramètre
 * \param Joueur : joueur dont on veut connètrele score
 * \return int:la valeur score cotenue dans la structure joueur passé en paramètre
 */
int get_score(Joueur* joueur);



/**
 * \fn void gain_ressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui ajoute une carte ressource dans la main du joueur
 *
 * fait gagner au joueur une ressource spécifique
 * \param  Type_ressource: le type de la ressource gagné, Joueur: la structure joueur qui gagne cette ressource
 * \return aucun
 */
void gain_ressource(TypeRessource type, Joueur* joueur);

/**
 * \fn void perte_ressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui fait perdre une carte ressource dans la main du joueur
 *
 * fait perdre au joueur une ressource spécifique
 * \param  Type_ressource: le type de la ressource gagné, Joueur: la structure joueur qui perd cette ressource
 * \return aucun
 */
void perte_ressource(TypeRessource type, Joueur* joueur);

/**
 * \fn int  get_nbressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui retourne les ressources possédées par le joueur
 *
 * fonction renvoillant le nombre de ressource d'un certain type possédé par un joueur
 * \param Type_ressource: le type de la ressource dont on veut connaitre le nombre, Joueur: le joeur dont on veut connaitre le nombre de ressource
 * \return int:le nombre de la ressource du type passé en paramètre possédé par le joueur
 */
int  get_nbressource(TypeRessource type, Joueur* joueur);


/**
 * \fn void gain_cartedev(TypeCarteDev type, Joueur* joueur)
 * \brief Fonction qui ajoute une carte developpement dans la main du joueur
 *
 * fait gagner au joueur une carte developpement spécifique
 * \param  TypeCarteDev: le type de la carte developpement gagné, Joueur: la structure joueur qui gagne cette carte
 * \return aucun
 */
void gain_cartedev(TypeCarteDev type, Joueur* joueur);

/**
 * \fn void perte_cartedev(TypeCarteDev type, Joueur* joueur)
 * \brief Fonction qui enlève une carte developpement dans la main du joueur
 *
 * fait gagner au joueur une carte developpement spécifique
 * \param  TypeCarteDev: le type de la carte developpement gagné, Joueur: la structure joueur qui gagne cette carte
 * \return aucun
 */
void perte_ressource(TypeRessource type, Joueur* joueur);

/**
 * \fn int  get_nbcartedev(TypeCarteDev type, Joueur* joueur)
 * \brief Fonction qui retourne les cartes developpemnts possédées par le joueur
 *
 * fonction renvoillant le nombre de carte developpement d'un certain type possédé par un joueur
 * \param TypeCarteDev: le type de la carte developpemnt dont on veut connaitre le nombre, Joueur: le joeur dont on veut connaitre le nombre de carte developpment
 * \return int:le nombre de la carte developpement du type passé en paramètre possédé par le joueur
 */
int  get_nbressource(TypeRessource type, Joueur* joueur);

#endif // JOUEUR_H
 
