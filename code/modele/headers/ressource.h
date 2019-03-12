/**
 * \file ressource.h
 * \brief deffinition de la structure Ressource
 * \author Rémi.F
 * \version 0
 * \date 05 mars 2019
 *
 * Header, deffinition structure Ressource et CarteDev
 *
 */
#ifndef RESSOURCE_H
#define RESSOURCE_H

/**
 * \enum Type_ressource
 * \brief Représente les différents types de ressources présentent dans le jeu
 *
 */
typedef enum {
    BOIS, /*!<bois>*/
    PIERRE, /*!<pierre>*/
    ARGILE, /*!<argile>*/
    MOUTON /*!<mouton>*/
    }TypeRessource;


  /**
 * \enum TypeCartDev
 * \brief Représente les différents types de cartes developpements présentent dans le jeu
 *
 */
typedef enum{
MONOPOLE,
CHEVALIER,
ROUTES,
POINT
} TypeCarteDev;


/**
 * \struct Ressource
 * \brief Structure représentant une carte ressource dans la partie .
 *
 * la structure est deffinie par un Type_ressource qui représente le type de la ressource (bois,argile...)
 * et un entier qui représente le nombre de carte Ressource du même type présentes dans la main du joueur
 *
 */
typedef struct{
TypeRessource type; /*!<type de la ressource (enum) >*/
int nb_ressource; /*!<entier nombre de ressource de ce type dans la main du joueur>*/
} Ressource;

/**
 * \struct CarteDev
 * \brief Structure représentant une carte developpement dans la partie .
 *
 * la structure est deffinie par un TypeCarteDev qui représente le type de carte (chevalier,point de victoire...)
 * et un entier qui représente le nombre de carte developpement du même type présentes dans la main du joueur
 *
 */
typedef struct{
TypeCarteDev type; /*!<type de la carte (enum) >*/
int nb_carte; /*!<entier nombre de carte de ce type dans la main du joueur>*/
} CarteDev;


#endif

