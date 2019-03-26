#include "plateau.h"
#include "ressource.h"
#include "joueur.h"

#ifndef GETPLATEAU_H
#define GETPLATEAU_H


/**
 * \fn int getProba(Plateau* p, double x, double y)
 * \brief fonction permettant d'obtenir la proba associée à une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile dont on veut la proba.
 * \return: retourne la probabilité de la tuile, ou -1 si la tuile n'existe pas ou si p est un pointeur nul.
 */

int getProba(Plateau* p, double x, double y);


/**
 * \fn int getType(Plateau* p, double x, double y)
 * \brief fonction permettant d'obtenir le type associé à une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile dont on veut le type.
 * \return: retourne le type de la tuile (son entier correspondant), ou -1 si la tuile n'existe pas ou si p est un pointeur nul.
 */

int getType(Plateau* p, double x, double y);


/**
 * \fn int getVoleur(Plateau* p, double x, double y)
 * \brief fonction permettant d'obtenir l'information de présence du voleur sur une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile à inspecter.
 * \return: retourne 0 si le voleur n'est pas présent, 1 si il l'est, ou -1 si la tuile n'existe pas ou si p est un pointeur nul.
 */

int getVoleur(Plateau* p, double x, double y);


/**
 * \fn int getInfrastructureArrete(Plateau* p, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information de présence d'une route à un endroit de la tuile d'un plateau.
 * \brief
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile et position est l'arrête (suivant l'enum Deplacement).
 * \return: retourne l'infrastructure (son entier) ou -1 si la tuile n'existe pas, si la postition est incorrecte ou si p est un pointeur nul.
 */

int getInfrastructureArrete(Plateau *p, double x, double y, int position);


/**
 * \fn Joueur* getJoueurArrete(Plateau* p, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information du possesseur d'une route à un endroit de la tuile d'un plateau.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile et position est l'arrête (suivant l'enum Deplacement).
 * \return: retourne un pointeur vers le joueur ou NULL si la tuile n'existe pas, si la postition est incorrecte, si p est un pointeur nul ou si il n'y a pas de route.
 */

Joueur* getJoueurArrete(Plateau* p, double x, double y, int position);


/**
 * \fn int getInfrastructureSommet(Plateau* p, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information de présence d'une construction sur un sommet de la tuile d'un plateau.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile.
 * \param position est le sommet (suivant l'enum Deplacement, sachant que le sommet correspondant à l'arrete de même numéro est le sommet de droite).
 * \return: retourne l'infrastructure (son entier) ou -1 si la tuile n'existe pas, si la postition est incorrecte ou si p est un pointeur nul.
 */

int getInfrastructureSommet(Plateau *p, double x, double y, int position);


/**
 * \fn Joueur* getJoueurSommet(Plateau* p, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information du possesseur d'une construction sur un sommet de la tuile d'un plateau.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile
 * \param position est l'arrête (suivant l'enum Deplacement, sachant que le sommet correspondant à l'arrete de même numéro est le sommet de droite).
 * \return: retourne un pointeur vers le joueur ou NULL si la tuile n'existe pas, si la postition est incorrecte, si p est un pointeur nul ou si il n'y a pas de construction.
 */

Joueur* getJoueurSommet(Plateau* p, double x, double y, int position);

#endif // GETPLATEAU_H
