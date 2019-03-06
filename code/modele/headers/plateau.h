/**
 * \file plateau.h
 * \brief Definition du Plateau
 * \author Emmanuel.D
 * \version 1.0
 * \date 5 mars 2019
 *
 * Definit les structures et fonctions utiles à la création et la gestion d'un plateau du jeu.
 */

#include "ressource.h"
#include "joueur.h"
#ifndef CODE_H
#define CODE_H


/**
 * \enum Infrastructure
 * \brief Definition d'une Infrastructure
 *
 *Definit plusieurs types d'infrastructures nécessaires pour construire sur le plateau.
 *
 */

typedef enum
{
    ville,          /*!< ville du jeu */
    colonie,        /*!< colonie du jeu */
    route,          /*!< relie les villes et colonies entre elles */
    vide            /*!< est une infrastructure par defaut afin de remplir les endroits vides du plateau */
}Infrastructure;


/**
 * \enum Mouvement
 * \brief Possibilités de mouvement
 *
 * Mouvement recense les possibilités de déplacement sur le plateau
 * dans tous les sens d'une tuile à une autre.
 *
 */

typedef enum
{
    G,      /*!< déplacement à gauche */
    D,      /*!< déplacement à droite */
    HG,     /*!< déplacement en haut à gauche */
    BG,     /*!< déplacement en bas à gauche */
    HD,     /*!< déplacement en haut à droite */
    BD      /*!< déplacement en bas à droite */
}Mouvement;


/**
 * \struct Arrete
 * \brief Arrete d'une Tuile
 *
 * Structure liant une infrastructure et un joueur pour une arrete donnée
 *
 */

typedef struct
{
    Infrastructure i;           /*!< type d'Infrastructure présente sur l'Arrete */
    Joueur* owner;       /*!< Joueur possédant l'Infrastructure sur l'Arrete */
}Arrete;


/**
 * \struct Sommet
 * \brief Sommet d'une Tuile
 *
 * Structure liant une infrastructure et un joueur pour un sommet donné
 *
 */

typedef struct
{
    Infrastructure i;           /*!< type d'Infrastructure présente sur le Sommet */
    Joueur* owner;       /*!< Joueur possédanr l'Infrastructure sur le Sommet */
}Sommet;


/**
 * \struct Tuile
 * \brief Tuile du Plateau
 *
 * Structure recenssant les informations d'une case du plateau, les constructions sur ses bords,
 *la probabilité de récupérer une ressource, le type de ressource de la case et la présence ou non du brigand.
 *
 */

typedef struct
{
    Sommet s[6];                /*!< Tableau recenssant les six Sommetes de la Tuile */
    Arrete a[6];                /*!< Tableau recenssant les six Arretes de la Tuile */
    int brigand;                /*!< Booléen (0 ou 1) indiquant ou non la présence du brigand */
    int proba;                  /*!< Entier compris entre 2 et 12 (excepté 7) indiquant le numéro à effectuer pour gagner la ressource "type" */
    TypeRessource type;         /*!< Type de ressource à gagner sur la Tuile */
}Tuile;


/**
 * \struct Noeud
 * \brief Noeud du Plateau
 *
 * Structure rassemblant une Tuile du Plateau avec un tableau de six Noeuds adjacents ainsi qu'une position.
 *
 */

typedef struct Noeud
{
    Tuile* t;                /*!< Tuile associée au Noeud */
    struct Noeud adjacence[6];      /*!< Noeuds des Tuiles adjacentes à la Tuile du Noeud */
    int x;                          /*!< Position abscisse dans le repère de la Tuile du Noeud */
    int y;                          /*!< Position ordonnée dans le repère de la Tuile du Noeud */
}Noeud;


typedef Noeud* Plateau;

Plateau* initPlateau();

int poserInfrastructure(Plateau* p,Infrastructure i,int x, int y, int pos);

int deplacementPlateau(Mouvement m);

int bougerVoleur(int x, int y);



#endif
