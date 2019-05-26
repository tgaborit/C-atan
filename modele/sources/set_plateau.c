#include "set_plateau.h"


/**
 * \fn static int constructionVoisineSommet(Partie* partie, double x, double y, int position)
 * \brief fonction indiquant la présence de constructions voisines à un sommet.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 1 si aucune construction n'est à proximité, 0 sinon et -1 si un probleme est détecté.
 */

static int constructionVoisineSommet(Partie* partie, double x, double y, int position){
    Plateau*p = partie->plateau;
    int low = position-1;
    int high = position+1;
    if(low < 0){
        low = 5;
    }
    if(high > 5){
        high = 0;
    }
    if(getInfrastructureSommet(partie,x,y,low) == VIDE && getInfrastructureSommet(partie,x,y,high) == VIDE){
        int pattern[6] = {0,2,4,5,3,1};
        Noeud* Cur = deplacementPlateau(p,x,y);

        if(Cur->adjacence[pattern[high]] == NULL){
            if(Cur->adjacence[pattern[position]] == NULL){
                return 1;
            }
            if(getInfrastructureSommet(partie,Cur->adjacence[pattern[position]]->x,Cur->adjacence[pattern[position]]->y,high) == VIDE){
                return 1;
            }
        }
        if(getInfrastructureSommet(partie,Cur->adjacence[pattern[high]]->x,Cur->adjacence[pattern[high]]->y,low) == VIDE){
            return 1;
        }
    }
    return 0;
}


/**
 * \fn static int routeVoisineSommet(Partie* partie,double x, double y, int position)
 * \brief fonction indiquant la présence de routes voisines à un sommet.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 1 si une route du joueur est à proximité, 0 sinon et -1 si un probleme est détecté.
 */

static int routeVoisineSommet(Partie* partie,double x, double y, int position){
    Plateau* p = partie->plateau;
    Noeud* Cur = deplacementPlateau(p,x,y);
    Joueur* owner = partie->joueurs->current->joueur;

    int pattern[6] = {0,2,4,5,3,1};             // pattern de mouvements suivant le sommet actuel
    int low = position-1,high = position+1, high2 = position+2;
    if(low < 0){
        low = 5;
    }
    if(high > 5){
        high = 0;
    }
    if(high2 > 5){
        high2 = high2 -6;
    }
    int r1 = getInfrastructureArrete(partie,x,y,position);
    int r2 = getInfrastructureArrete(partie,x,y,high);
    int r3;
    Joueur* j3;
    if(Cur->adjacence[pattern[high]] == NULL){
        if(Cur->adjacence[pattern[position]] == NULL){
            r3 = VIDE;
            j3 = NULL;
        }
        else{
            r3 = getInfrastructureArrete(partie,Cur->adjacence[pattern[position]]->x,Cur->adjacence[pattern[position]]->y,high2);
            j3 = getJoueurArrete(partie,Cur->adjacence[pattern[position]]->x,Cur->adjacence[pattern[position]]->y,high2);
        }
    }
    else{
        r3 = getInfrastructureArrete(partie,Cur->adjacence[pattern[high]]->x,Cur->adjacence[pattern[high]]->y,low);
        j3 = getJoueurArrete(partie,Cur->adjacence[pattern[high]]->x,Cur->adjacence[pattern[high]]->y,low);
    }

    Joueur* j1 = getJoueurArrete(partie,x,y,position);
    Joueur* j2 = getJoueurArrete(partie,x,y,high);

    if(r1 != VIDE && strcmp(j1->pseudo, owner->pseudo) == 0){
        return 1;
    }
    if(r2 != VIDE && strcmp(j2->pseudo, owner->pseudo) == 0){
        return 1;
    }
    if(r3 != VIDE && strcmp(j3->pseudo, owner->pseudo) == 0){
        return 1;
    }
    return 0;
}

/**
 * \fn static int constructionVoisineArrete(Partie* partie, double x, double y, int position)
 * \brief fonction cherchant si il y a des infrastructures appartenant au joueur sur les sommets adjacents à une arrete.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est l'arrête.
 * \return -1 si il y a une erreur, 1 s'il n'y a aucune infrastructure voisine et 0 en cas d'echec
 */

static int constructionVoisineArrete(Partie* partie, double x, double y, int position){
    Plateau* p = partie->plateau;
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur == NULL || partie->joueurs->current == NULL || position < 0 || position > 5){
        return -1;
    }
    Joueur* owner = partie->joueurs->current->joueur;

    int low = position-1;
    if(low < 0){
        low = 5;
    }
    // verif si les sommets adjacents contiennent une construction du joueur
    if(getInfrastructureSommet(partie,x,y,position) != VIDE && strcmp(getJoueurSommet(partie,x,y,position)->pseudo, owner->pseudo) == 0){
        return 1;
    }
    if(getInfrastructureSommet(partie,x,y,low) != VIDE && strcmp(getJoueurSommet(partie,x,y,low)->pseudo, owner->pseudo) == 0){
        return 1;
    }
    return 0;
}


/**
 * \fn static int routeVoisineArrete(Partie* partie, double x, double y, int position)
 * \brief fonction cherchant si il y a des routes appartenant au joueur sur les arretes adjacentes à une arrete.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est l'arrête.
 * \return -1 si il y a une erreur, 1 si une route du joueur est présente et 0 sinon.
 */

static int routeVoisineArrete(Partie* partie, double x, double y, int position){
    Plateau* p = partie->plateau;
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(Cur == NULL || partie->joueurs->current == NULL || position < 0 || position > 5){
        return -1;
    }
    Joueur* owner = partie->joueurs->current->joueur;

    int pattern[6] = {0,2,4,5,3,1};             // pattern de mouvements suivant le côté actuel
    int low = position-1,high = position+1;
    if(low < 0){
        low = 5;
    }
    if(high > 5){
        high = 0;
    }
        // Par la suite, on vérifie un a un les quatre arretes adjacentes afin de voir si elles contiennent une route du joueur

    if(getInfrastructureArrete(partie,x,y,low) == ROUTE && strcmp(getJoueurArrete(partie,x,y,low)->pseudo, owner->pseudo) == 0){
        return 1;
    }
    if(getInfrastructureArrete(partie,x,y,high) == ROUTE && strcmp(getJoueurArrete(partie,x,y,high)->pseudo, owner->pseudo) == 0){
        return 1;
    }
    int route1 = position+2;
    if(route1 > 5){
        route1 = route1-6;
    }
    int route2 = position +4;
    if(route2 > 5){
        route2 = route2-6;
    }
    if(Cur->adjacence[pattern[position]] != NULL){
        if(getInfrastructureArrete(partie,Cur->adjacence[pattern[position]]->x,Cur->adjacence[pattern[position]]->y,route1) == ROUTE
           && strcmp(getJoueurArrete(partie,Cur->adjacence[pattern[position]]->x,Cur->adjacence[pattern[position]]->y,route1)->pseudo, owner->pseudo) == 0){
            return 1;
        }
        if(getInfrastructureArrete(partie,Cur->adjacence[pattern[position]]->x,Cur->adjacence[pattern[position]]->y,route2) == ROUTE
           && strcmp(getJoueurArrete(partie,Cur->adjacence[pattern[position]]->x,Cur->adjacence[pattern[position]]->y,route2)->pseudo, owner->pseudo) == 0){
            return 1;
        }
    }
    else{
        if(Cur->adjacence[pattern[low]] != NULL){
            if(getInfrastructureArrete(partie,Cur->adjacence[pattern[low]]->x,Cur->adjacence[pattern[low]]->y,high) == ROUTE
               && strcmp(getJoueurArrete(partie,Cur->adjacence[pattern[low]]->x,Cur->adjacence[pattern[low]]->y,high)->pseudo, owner->pseudo) == 0){
                return 1;
            }
        }
        if(Cur->adjacence[pattern[high]] != NULL){
            if(getInfrastructureArrete(partie,Cur->adjacence[pattern[high]]->x,Cur->adjacence[pattern[high]]->y,low) == ROUTE
               && strcmp(getJoueurArrete(partie,Cur->adjacence[pattern[high]]->x,Cur->adjacence[pattern[high]]->y,low)->pseudo, owner->pseudo) == 0){
                return 1;
            }
        }
    }
    return 0;
}


/**
 * \fn int setRoute(Partie* partie,double x, double y, int position, Infrastructure i)
 * \brief fonction permettant de placer une route appartenant à un joueur sur l'arrete d'une tuile et payer.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est l'arrête.
 * \return 0 si la route a été posée, -1 si ce n'est pas possible.
 */

int setRoute(Partie* partie, double x, double y, int position){
    if(partie == NULL){
        return -1;
    }
    if(get_nbressource_joueuractif(ARGILE,partie)>=1 && get_nbressource_joueuractif(BOIS,partie)>=1){
        if(setRouteFree(partie,x,y,position) == 0){
            achat_route(partie->joueurs->current->joueur);
            return 0;
        }
    }
    return -1;
}




/**
 * \fn int setRouteFree(Partie* partie,double x, double y, int position, Infrastructure i)
 * \brief fonction permettant de placer une route appartenant à un joueur sur l'arrete d'une tuile.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est l'arrête.
 * \return 0 si la route a été posée, -1 si ce n'est pas possible.
 */

int setRouteFree(Partie* partie, double x, double y, int position){
    if(partie == NULL){
        return -1;
    }
    Plateau* p = partie->plateau;
    Noeud* Cur = deplacementPlateau(p,x,y);

    if(p == NULL || deplacementPlateau(p,x,y) == NULL || partie->joueurs->current == NULL){
        return -1;
    }
    Joueur* owner = partie->joueurs->current->joueur;

    if(position < 0 || position >= 6){
        return -1;
    }

    if(getInfrastructureArrete(partie,x,y,position) == ROUTE){       // verif si l'arrete ne contient pas deja une route
        return -1;
    }
    int cond1 = constructionVoisineArrete(partie,x,y,position);      // verif si le joueur possede une construction adjacente
    int cond2 = routeVoisineArrete(partie,x,y,position);             // verif si le joueur possede une route adjacente
    if(cond1 != 1 && cond2 != 1){
        return -1;
    }
    int pattern[6] = {0,2,4,5,3,1};                             // création de la route, sur les deux tuiles la contenant
    int pos2 = position+3;
    if(pos2 > 5){
        pos2 = pos2-6;
    }
    Cur->t->a[position].i = ROUTE;
    Cur->t->a[position].owner = owner;
    if(Cur->adjacence[pattern[position]] != NULL){
        Cur->adjacence[pattern[position]]->t->a[pos2].i = ROUTE;
        Cur->adjacence[pattern[position]]->t->a[pos2].owner = owner;
    }
    ++partie->joueurs->current->joueur->nbRoute;
    return 0;
}


/**
 * \fn int setColonieInit(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une colonie appartenant à un joueur sur le sommet d'une tuile, en début de partie (conditions différentes).
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été posée, -1 si ce n'est pas possible.
 */

int setColonieInit(Partie* partie, double x, double y, int position){
    if(partie == NULL){
        return -1;
    }
    Plateau* p = partie->plateau;
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(p == NULL || Cur == NULL || partie->joueurs->current == NULL){
        return -1;
    }
    Joueur* owner = partie->joueurs->current->joueur;

    if(position < 0 || position >= 6){
        return -1;
    }

    //verification que l'emplacement est vide.
    if(Cur->t->s[position].i != VIDE){
        return -1;
    }
    //verification que il n'y a pas de colonie adjacente.
    if(constructionVoisineSommet(partie,x,y,position) !=1 ){
        return -1;
    }

    int pattern[6] = {0,2,4,5,3,1};
    int low = position-2;
    int high = position+2;
    int position2 = position+1;
    if(position2 > 5){
        position2 = 0;
    }
    if(low < 0){
        low = low+6;
    }
    if(high > 5){
        high = high-6;
    }

    Cur->t->s[position].i = COLONIE;
    Cur->t->s[position].owner = owner;
    if(Cur->adjacence[pattern[position]] != NULL){
        Cur->adjacence[pattern[position]]->t->s[high].i = COLONIE;
        Cur->adjacence[pattern[position]]->t->s[high].owner = owner;
    }
    if(Cur->adjacence[pattern[position2]] != NULL){
        Cur->adjacence[pattern[position2]]->t->s[low].i = COLONIE;
        Cur->adjacence[pattern[position2]]->t->s[low].owner = owner;
    }
    inc_score(get_joueur_actif(partie),1);
    return 0;
}


/**
 * \fn int setColonie(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une colonie appartenant à un joueur sur le sommet d'une tuile et de payer.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été posée, -1 si ce n'est pas possible.
 */

int setColonie(Partie* partie, double x, double y, int position){
    if(partie == NULL){
        return -1;
    }
    if(get_nbressource_joueuractif(ARGILE,partie)>=1 && get_nbressource_joueuractif(BOIS,partie)>=1 && get_nbressource_joueuractif(MOUTON,partie)>=1 && get_nbressource_joueuractif(BLE,partie)>=1){
        if(setColonieFree(partie,x,y,position) == 0){
            achat_colonie(partie->joueurs->current->joueur);
            return 0;
        }
    }
    return -1;
}


/**
 * \fn int setColonieFree(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une colonie appartenant à un joueur sur le sommet d'une tuile.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été posée, -1 si ce n'est pas possible.
 */

int setColonieFree(Partie* partie, double x, double y, int position){
    if(partie == NULL){
        return -1;
    }
    Plateau* p = partie->plateau;
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(p == NULL || Cur == NULL || partie->joueurs->current == NULL){
        return -1;
    }
    Joueur* owner = partie->joueurs->current->joueur;

    if(position < 0 || position >= 6){
        return -1;
    }

    //verification que l'emplacement est vide.
    if(Cur->t->s[position].i != VIDE){
        return -1;
    }
    //verification que il n'y a pas de colonie adjacente.
    if(constructionVoisineSommet(partie,x,y,position) !=1 ){
        return -1;
    }
    //verification que l'emplacement soit relié par au moins une route du joueur.
    if(routeVoisineSommet(partie,x,y,position) != 1){
        return -1;
    }
    int pattern[6] = {0,2,4,5,3,1};
    int low = position-2;
    int high = position+2;
    int position2 = position+1;
    if(position2 > 5){
        position2 = 0;
    }
    if(low < 0){
        low = low+6;
    }
    if(high > 5){
        high = high-6;
    }

    Cur->t->s[position].i = COLONIE;
    Cur->t->s[position].owner = owner;
    if(Cur->adjacence[pattern[position]] != NULL){
        Cur->adjacence[pattern[position]]->t->s[high].i = COLONIE;
        Cur->adjacence[pattern[position]]->t->s[high].owner = owner;
    }
    if(Cur->adjacence[pattern[position2]] != NULL){
        Cur->adjacence[pattern[position2]]->t->s[low].i = COLONIE;
        Cur->adjacence[pattern[position2]]->t->s[low].owner = owner;
    }
    return 0;
}


/**
 * \fn int setVille(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une ville sur la colonie d'un joueur et de payer.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été changée en ville, -1 si ce n'est pas possible.
 */

int setVille(Partie* partie, double x, double y, int position){
    if(partie == NULL){
        return -1;
    }
    if(get_nbressource_joueuractif(PIERRE,partie) >=3 && get_nbressource_joueuractif(BLE,partie) >=2){
        if(setVilleFree(partie,x,y,position)== 0){
            achat_ville(partie->joueurs->current->joueur);
            return 0;
        }
    }
    return -1;
}


/**
 * \fn int setVilleFree(Partie* partie, double x, double y, int position)
 * \brief fonction permettant de placer une ville sur la colonie d'un joueur.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la tuile et position est le sommet.
 * \return 0 si la colonie a été changée en ville, -1 si ce n'est pas possible.
 */

int setVilleFree(Partie* partie, double x, double y, int position){
    if(partie == NULL){
        return -1;
    }

    Plateau* p = partie->plateau;
    Noeud* Cur = deplacementPlateau(p,x,y);
    if(p == NULL || Cur == NULL || partie->joueurs->current == NULL){
        return -1;
    }
    Joueur* owner = partie->joueurs->current->joueur;

    if(position < 0 || position >= 6){
        return -1;
    }

    int pattern[6] = {0,2,4,5,3,1};
    int low = position-2;
    int high = position+2;
    int position2 = position+1;
    if(position2 > 5){
        position2 = 0;
    }
    if(low < 0){
        low = low+6;
    }
    if(high > 5){
        high = high-6;
    }
    //verification que le joueur possede une colonie à la position indiquée.
    if(getInfrastructureSommet(partie,x,y,position) == COLONIE && strcmp(getJoueurSommet(partie,x,y,position)->pseudo,owner->pseudo) == 0){
        Cur->t->s[position].i = VILLE;
        if(Cur->adjacence[pattern[position]] != NULL){
            Cur->adjacence[pattern[position]]->t->s[high].i = VILLE;
        }
        if(Cur->adjacence[pattern[position2]] != NULL){
            Cur->adjacence[pattern[position2]]->t->s[low].i = VILLE;
        }
        return 0;
    }

    return -1;
}


/**
 * \fn int setVoleur(Partie* partie, double x, double y)
 * \brief fonction permettant de déplacer le voleur d'une tuile à une autre.
 *
 *
 * \param partie est un pointeur vers la partie, x et y sont les coordonnées de la nouvelle tuile où poser le voleur.
 * \return retourne 0 si tout c est bien passé, -1 sinon.
 */
int setVoleur(Partie* partie, double x, double y){
    if(partie == NULL){
        return -1;
    }

    Plateau* p = partie->plateau;
    if(p == NULL || deplacementPlateau(p,x,y) == NULL){
        return -1;
    }
    int i=0;
    int ord[6] = {HG,G,HD,BG,D,BD};                                     // Tableau de chiffres en liaison avec un pattern de mouvements.
    for(i=0;i<6;++i){                                               // On cherche le noeud ou se trouve actuellement le voleur afin de l'enlever.
        if(p->t->brigand == 1){
            p->t->brigand = 0;
            break;
        }
        if(p->adjacence[i]->t->brigand == 1){
            p->adjacence[i]->t->brigand = 0;
            break;
        }
        if(p->adjacence[i]->adjacence[i]->t->brigand == 1){
            p->adjacence[i]->adjacence[i]->t->brigand = 0;
            break;
        }
        if(p->adjacence[i]->adjacence[ord[i]]->t->brigand == 1){
            p->adjacence[i]->adjacence[ord[i]]->t->brigand = 0;
            break;
        }
    }
    Noeud* voleur = deplacementPlateau(p, x, y);                    // Le noeud choisi est paramétreé pour acueillir le voleur.
    voleur->t->brigand = 1;
    return 0;
}
