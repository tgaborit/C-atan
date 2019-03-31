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
    VIDE,           /*!< est une infrastructure par defaut afin de remplir les endroits vides du plateau */
    VILLE,          /*!< ville du jeu */
    COLONIE,        /*!< colonie du jeu */
    ROUTE           /*!< relie les villes et colonies entre elles */
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
    BG,     /*!< déplacement en haut à gauche */
    HG,     /*!< déplacement en haut à droite */
    BD,      /*!< déplacement à droite */
    HD,      /*!< déplacement en bas à droite */
    D,     /*!< déplacement en bas à gauche */
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

typedef struct Noeud{
    Tuile* t;                          /*!< Tuile associée au Noeud */
    struct Noeud** adjacence;           /*!< pointeur vers un tableau de pointeurs de Noeuds des Tuiles adjacentes à la Tuile du Noeud (tableau) */
    double x;                          /*!< Position abscisse dans le repère de la Tuile du Noeud */
    double y;                          /*!< Position ordonnée dans le repère de la Tuile du Noeud */
}Noeud;


typedef Noeud Plateau;


/**
 * \fn Plateau* initPlateau()
 * \brief Initialisation du Plateau, c'est à dire de tous ses Noeuds et Tuiles.
 *
 *
 * \param aucun paramètre
 * \return un pointeur vers une instance de type Plateau.
 */

Plateau* initPlateau();


/**
 * \fn void freePlateau(Plateau* p)
 * \brief Libération de la mémoire allouée à un plateau et son contenu.
 *
 *
 * \param p un pointeur vers le Plateau à libérer.
 * \return -1 si p est un pointeur nul, 0 sinon.
 */

 int freePlateau(Plateau* p);


/**
 * \fn int poserInfrastructure(Plateau* p, Infrastructure i, double x, double y, int pos)
 * \brief Fonction permettant de poser une infrastructure à un endroit du plateau si l'endroit en question est vide.
 *
 *
 * \param p est un pointeur vers le plateau, i est le type d'infrastructure à poser, x et y sont les coordonnées de la tuile en question et pos est la position sur la tuile en question.
 * \return 1 si l'action est validée, 0 sinon (cas ou il y a deja une infrastructure de présente).
 */

int poserInfrastructure(Plateau* p, Infrastructure i, double x, double y, int pos);


/**
 * \fn Noeud* deplacementPlateau(Plateau* p, double x, double y)
 * \brief Fonction permettant de se déplacer à un endroit du plateau.
 *
 *
 * \param p est un pointeur vers le plateau et x et y sont les coordonnées du noeud recherché.
 * \return un pointeur vers le noeud cherché.
 */

Noeud* deplacementPlateau(Plateau* p, double x, double y);

#endif
