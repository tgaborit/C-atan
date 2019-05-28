/**
 * \file set_plateau.h
 * \brief Définit les fonctions de set_plateau.c
 * \author Emmanuel.D
 * \version 1.0
 * \date 5 mars 2019
 *
 * Définit les fonctions utiles à la modification des données touchant au plateau de jeu.
 */

#include "plateau.h"
#include "get_plateau.h"
#include "get_partie.h"
#include "joueur.h"
#include "ressource.h"
#include "partie.h"
#include <string.h>

#ifndef SETPLT_H
#define SETPLT_H


/**
 * \fn int setRoute(Partie* partie,double x, double y, int position)
 * \brief fonction permettant de placer une route appartenant à un joueur sur l'arrete d'une tuile et payer.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est l'arrête.
 * \return 0 si la route a été posée, -1 si ce n'est pas possible.
 */

int setRoute(Partie* partie, double x, double y, int position);


/**
 * \fn int setRouteFree(Partie* partie,double x, double y, int position)
 * \brief fonction permettant de placer une route appartenant à un joueur sur l'arrete d'une tuile.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est l'arrête.
 * \return 0 si la route a été posée, -1 si ce n'est pas possible.
 */

int setRouteFree(Partie* partie, double x, double y, int position);


/**
 * \fn int setColonieInit(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une colonie appartenant à un joueur sur le sommet d'une tuile, en début de partie (conditions différentes).
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été posée, -1 si ce n'est pas possible.
 */

int setColonieInit(Partie* partie, double x, double y, int position);


/**
 * \fn int setColonie(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une colonie appartenant à un joueur sur le sommet d'une tuile et de payer.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été posée, -1 si ce n'est pas possible.
 */

int setColonie(Partie* partie, double x, double y, int position);


/**
 * \fn int setColonieFree(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une colonie appartenant à un joueur sur le sommet d'une tuile.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été posée, -1 si ce n'est pas possible.
 */

int setColonieFree(Partie* partie, double x, double y, int position);

/**
 * \fn int setVille(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une ville sur la colonie d'un joueur et de payer.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été changée en ville, -1 si ce n'est pas possible.
 */

int setVille(Partie* partie, double x, double y, int position);


/**
 * \fn int setVilleFree(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une ville sur la colonie d'un joueur.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été changée en ville, -1 si ce n'est pas possible.
 */

int setVilleFree(Partie* partie, double x, double y, int position);


/**
 * \fn int setVoleur(Partie* partie, double x, double y)
 * \brief fonction permettant de déplacer le voleur d'une tuile à une autre.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la nouvelle tuile où poser le voleur.
 * \return retourne 0 si tout c est bien passé, -1 sinon.
 */

int setVoleur(Partie* partie, double x, double y);

#endif // SETPLT_H
