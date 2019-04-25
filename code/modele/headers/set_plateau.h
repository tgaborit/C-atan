#include "plateau.h"
#include "get_plateau.h"
#include "joueur.h"
#include "ressource.h"

#ifndef SETPLT_H
#define SETPLT_H


/**
 * \fn int setRoute(Plateau* p,double x, double y, int position, Infrastructure i, Joueur* owner)
 * \brief fonction permettant de placer une route appartenant à un joueur sur l'arrete d'une tuile.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile et position est l'arrête.
 * \param owner est un pointeur sur la structure du joueur désirant placer sa route.
 * \return 0 si la route a été posée, -1 si ce n'est pas possible.
 */

int setRoute(Plateau* p, double x, double y, int position, Joueur* owner);


/**
 * \fn int setColonie(Plateau* p,double x, double y, int position, Joueur* owner)
 * \brief fonction permettant de placer une colonie appartenant à un joueur sur le sommet d'une tuile.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile et position est le sommet.
 * \param owner est un pointeur sur la structure du joueur désirant placer sa colonie.
 * \return 0 si la route a été posée, -1 si ce n'est pas possible.
 */

int setColonie(Plateau* p,double x, double y, int position, Joueur* owner);


/**
 * \fn int setVille(Plateau* p,double x, double y, int position, Joueur* owner)
 * \brief fonction permettant de placer une ville sur la colonie d'un joueur.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile et position est le sommet.
 * \param owner est un pointeur sur la structure du joueur désirant placer sa ville.
 * \return 0 si la route a été posée, -1 si ce n'est pas possible.
 */

int setVille(Plateau* p,double x, double y, int position, Joueur* owner);


/**
 * \fn int setVoleur(double x, double y)
 * \brief fonction permettant de déplacer le voleur d'une tuile à une autre.
 *
 *
 * \param x et y sont les coordonnées de la nouvelle tuile où poser le voleur.
 * \return 0 si tout c est bien passé, -1 sinon.
 */

int setVoleur(Plateau* p, double x, double y);

#endif // SETPLT_H
