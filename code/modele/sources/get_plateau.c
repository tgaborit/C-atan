#include "plateau.h"
#include "ressource.h"
#include "joueur.h"


/**
 * \fn int getProba(Plateau* p, double x, double y)
 * \brief fonction permettant d'obtenir la proba associée à une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile dont on veut la proba.
 * \return la probabilité de la tuile, ou -1 si la tuile n'existe pas ou si p est un pointeur nul.
 */

int getProba(Plateau* p, double x, double y){
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur != NULL){
        return Cur->t->proba;
    }
    return -1;
}


/**
 * \fn int getType(Plateau* p, double x, double y)
 * \brief fonction permettant d'obtenir le type associé à une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile dont on veut le type.
 * \return le type de la tuile (son entier correspondant), ou -1 si la tuile n'existe pas ou si p est un pointeur nul.
 */

int getType(Plateau* p, double x, double y){
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur != NULL){
        return Cur->t->type;
    }
    return -1;
}


/**
 * \fn int getVoleur(Plateau* p, double x, double y)
 * \brief fonction permettant d'obtenir l'information de présence du voleur sur une tuile d'un plateau, via ses coordonnées.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile à inspecter.
 * \return 0 si le voleur n'est pas présent, 1 si il l'est, ou -1 si la tuile n'existe pas ou si p est un pointeur nul.
 */

int getVoleur(Plateau* p, double x, double y){
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur != NULL){
        return Cur->t->brigand;
    }
    return -1;
}


/**
 * \fn int getInfrastructureArrete(Plateau* p, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information de présence d'une route à un endroit de la tuile d'un plateau.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile et position est l'arrête (suivant l'enum Deplacement).
 * \return l'infrastructure (son entier) ou -1 si la tuile n'existe pas, si la postition est incorrecte ou si p est un pointeur nul.
 */

int getInfrastructureArrete(Plateau *p, double x, double y, int position){
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur != NULL && position < 6 && position >= 0){
        return Cur->t->a[position].i;
    }
    return -1;
}


/**
 * \fn Joueur* getJoueurArrete(Plateau* p, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information du possesseur d'une route à un endroit de la tuile d'un plateau.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile et position est l'arrête (suivant l'enum Deplacement).
 * \return un pointeur vers le joueur ou NULL si la tuile n'existe pas, si la postition est incorrecte, si p est un pointeur nul ou si il n'y a pas de route.
 */

Joueur* getJoueurArrete(Plateau* p, double x, double y, int position){
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur != 0 && position < 6 && position >= 0){
        return Cur->t->a[position].owner;
    }
    return NULL;
}


/**
 * \fn int getInfrastructureSommet(Plateau* p, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information de présence d'une construction sur un sommet de la tuile d'un plateau.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile.
 * \param position est le sommet (suivant l'enum Deplacement, sachant que le sommet correspondant à l'arrete de même numéro est le sommet de droite).
 * \return l'infrastructure (son entier) ou -1 si la tuile n'existe pas, si la postition est incorrecte ou si p est un pointeur nul.
 */

int getInfrastructureSommet(Plateau *p, double x, double y, int position){
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur != NULL && position < 6 && position >= 0){
        return Cur->t->s[position].i;
    }
    return -1;
}


/**
 * \fn Joueur* getJoueurSommet(Plateau* p, double x, double y, int position)
 * \brief fonction permettant d'obtenir l'information du possesseur d'une construction sur un sommet de la tuile d'un plateau.
 *
 *
 * \param p est un pointeur vers le plateau, x et y sont les coordonnées de la tuile
 * \param position est l'arrête (suivant l'enum Deplacement, sachant que le sommet correspondant à l'arrete de même numéro est le sommet de droite).
 * \return un pointeur vers le joueur ou NULL si la tuile n'existe pas, si la postition est incorrecte, si p est un pointeur nul ou si il n'y a pas de construction.
 */

Joueur* getJoueurSommet(Plateau* p, double x, double y, int position){
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur != 0 && position < 6 && position >= 0){
        return Cur->t->s[position].owner;
    }
    return NULL;
}

