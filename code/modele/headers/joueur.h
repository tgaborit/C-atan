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

/**
 * \enum Couleur
 * \brief Couleur possible pour le joueur
 *
 * contient les différentes couleurs possible pour un joueur
 */
typedef enum Couleur{
    ROUGE, VERT, ORANGE, BLEU} Couleur;

/**
 * \enum Status
 * \brief Status du joueur en attente ou joue
 *
 * représente le status du joueur si il est en train de jouer ou il attend son tour
 */
typedef enum Status{
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
char[] pseudo; /*!<chaine de caractères stokant le pseudo choisi par le joueur>*/
Status status /*<deffinie si c'est le tour du joueur ou si il est en attente>*/
Ressource[4] ressource; /*!<tableau de ressource représentant les ressources en main du joueur classé par type (une case par type de ressource)>*/
Developpement[4] carte_dev; /*!<tableau de Developpement représentant les cartes_dev en main du joueur classé par type (une case par type de ressource)>*/
Couleur couleur; /*!<couleur associé au joueur choisie au début de la parie>*/
}Joueur;


void set_pseudo(Joueur joueur);
/**
 * \fn void init_joueur(Couleur couleur,char* pseudo)
 * \brief Fonction d'initialisationde la structure joueur
 *
 * fonction qui alloue la mémoire necessaire à la création d'un joueur, lui donne son pseudo et sa couleur et initialise son score à 0 ainsi que le nombre de ses cartes en main
 * \param Couleur: la couleur choisi par le joueur char* le pseudo choisi par le joueur.
 * \return: aucun
 */
void init_joueur(Couleur couleur,char* pseudo);



/**
 * \fn int get_score(Joueur joueur)
 * \brief Fonction qui retourne le score du joueur
 *
 * fonction renvoillant le score du joueur passé en paramètre
 * \param Joueur : joueur dont on veut connètrele score
 * \return int:la valeur score cotenue dans la structure joueur passé en paramètre
 */
int get_score(Joueur joueur);



/**
 * \fn void gain_ressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui ajoute une carte ressource dans la main du joueur
 *
 * fait gagner au joueur une ressource spécifique
 * \param  Type_ressource: le type de la ressource gagné, Joueur: la structure joueur qui gagne cette ressource
 * \return aucun
 */
void gain_ressource(Type_ressource type, Joueur* joueur);

/**
 * \fn void perte_ressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui fait perdre une carte ressource dans la main du joueur
 *
 * fait perdre au joueur une ressource spécifique
 * \param  Type_ressource: le type de la ressource gagné, Joueur: la structure joueur qui perd cette ressource
 * \return aucun
 */
void perte_ressource(Type_ressource type, Joueur* joueur);

/**
 * \fn int  get_nbressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui retourne les ressources possédées par le joueur
 *
 * fonction renvoillant le nombre de ressource d'un certain type possédé par un joueur
 * \param Type_ressource: le type de la ressource dont on veut connaitre le nombre, Joueur: le joeur dont on veut connaitre le nombre de ressource
 * \return int:le nombre de la ressource du type passé en paramètre possédé par le joueur
 */
int  get_nbressource(Type_ressource type, Joueur* joueur);

#endif // JOUEUR_H
