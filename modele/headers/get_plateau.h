/**
 * \file get_plateau.h
 * \brief Définit les fonctions de get_plateau.c
 * \author Emmanuel.D
 * \version 1.0
 * \date 5 mars 2019
 *
 * Définit les fonctions utiles à l'obtention de données touchant au plateau de jeu.
 */

#include "plateau.h"
#include "ressource.h"
#include "joueur.h"
#include "partie.h"

#ifndef GETPLATEAU_H
#define GETPLATEAU_H


/**
 * \fn int getProba(Partie* partie, double x, double y)
 * \brief fonction permettant d'obtenir la proba associée à une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile dont on veut la proba.
 * \return la probabilité de la tuile, ou -1 si la tuile n'existe pas ou si partie est un pointeur nul.
 */

int getProba(Partie* partie, double x, double y);


/**
 * \fn int getType(Partie* partie, double x, double y)
 * \brief fonction permettant d'obtenir le type associé à une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile dont on veut le type.
 * \return le type de la tuile (son entier correspondant), ou -1 si la tuile n'existe pas ou si partie est un pointeur nul.
 */

int getType(Partie* partie, double x, double y);


/**
 * \fn int getVoleur(Partie* partie, double x, double y)
 * \brief fonction permettant d'obtenir l'information de présence du voleur sur une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile à inspecter.
 * \return 0 si le voleur n'est pas présent, 1 si il l'est, ou -1 si la tuile n'existe pas ou si partie est un pointeur nul.
 */

int getVoleur(Partie* partie, double x, double y);


/**
 * \fn int getInfrastructureArrete(Partie* partie, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information de présence d'une route à un endroit de la tuile d'un plateau.
 * \brief
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est l'arrête (suivant l'enum Deplacement).
 * \return l'infrastructure (son entier) ou -1 si la tuile n'existe pas, si la postition est incorrecte ou si partie est un pointeur nul.
 */

int getInfrastructureArrete(Partie* partie, double x, double y, int position);


/**
 * \fn Joueur* getJoueurArrete(Partie* partie, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information du possesseur d'une route à un endroit de la tuile d'un plateau.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est l'arrête (suivant l'enum Deplacement).
 * \return un pointeur vers le joueur ou NULL si la tuile n'existe pas, si la postition est incorrecte, si partie est un pointeur nul ou si il n'y a pas de route.
 */

Joueur* getJoueurArrete(Partie* partie, double x, double y, int position);


/**
 * \fn int getInfrastructureSommet(Partie* partie, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information de présence d'une construction sur un sommet de la tuile d'un plateau.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile.
 * \param position est le sommet (suivant l'enum Deplacement, sachant que le sommet correspondant à l'arrete de même numéro est le sommet de droite).
 * \return l'infrastructure (son entier) ou -1 si la tuile n'existe pas, si la postition est incorrecte ou si partie est un pointeur nul.
 */
int getInfrastructureSommet(Partie* partie, double x, double y, int position);


/**
 * \fn Joueur* getJoueurSommet(Partie* partie, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information du possesseur d'une construction sur un sommet de la tuile d'un plateau.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile
 * \param position est l'arrête (suivant l'enum Deplacement, sachant que le sommet correspondant à l'arrete de même numéro est le sommet de droite).
 * \return un pointeur vers le joueur ou NULL si la tuile n'existe pas, si la postition est incorrecte, si partie est un pointeur nul ou si il n'y a pas de construction.
 */

Joueur* getJoueurSommet(Partie* partie, double x, double y, int position);

#endif // GETPLATEAU_H
