/**
 * \file plateau.c
 * \brief Implémente les fonctions de plateau.h
 * \author Emmanuel.D
 * \version 1.0
 * \date 5 mars 2019
 *
 * Implémente les fonctions utiles à la création et la gestion d'un plateau du jeu.
 */

#include "plateau.h"
#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * \fn static int rechercheNoeud(Noeud* tabNoeud, double x, double y)
 * \brief Fonction recherchant un noeud dans un tableau de noeuds en fonction de ses coordonnées (interne à l'initialisation d'un plateau).
 *
 *
 * \param tabNoeud, un pointeur vers le premier élément du tableau contenant les noeuds des tuiles du plateau
 * \param x et y les coordonnées du noeud recherché
 * \return -1 si le noeud n'existe pas, et son indice dans le tableau sinon.
 */

static int rechercheNoeud(Noeud** tabNoeud, double x, double y){
    int i=0;
    while(i<19){
        if(tabNoeud[i]->x == x && tabNoeud[i]->y == y){
            return i;
        }
        ++i;
    }
    return -1;
}

/**
 * \fn static void fillAdjacence(Noeud* tabNoeud)
 * \brief Fonction remplissant les tableaux de pointeurs noeuds adjacents de chaque noeud du plateau (interne à l'initialisation du plateau).
 *
 *
 * \param tabNoeud, un pointeur vers un tableau de pointeurs de noeuds des tuiles du plateau
 * \return Aucun retour
 */

static void fillAdjacence(Noeud** tabNoeud){
    int i,j,indice;
    double xCur,yCur;

    for(i=0;i<19;++i){                                                              //On boucle sur tous les noeuds du plateau
        xCur = tabNoeud[i]->x;
        yCur = tabNoeud[i]->y;
        double xval[6] = {xCur-1, xCur-0.5, xCur-0.5, xCur+0.5, xCur+0.5, xCur+1};
        double yval[6] = {yCur, yCur-1, yCur+1, yCur-1, yCur+1, yCur};
        for(j = 0; j < 6; ++j){                                                     //Pour chaque noeud, on regarde s'il existe des noeuds adjacents
            indice = rechercheNoeud(tabNoeud, xval[j], yval[j]);
            if(indice != -1){                                                       // Si oui : on fait un pointage vers chaque noeud adjacent dans le tableau d'adjacence
                tabNoeud[i]->adjacence[j] = tabNoeud[indice];
            }
            else{                                                                   // Si non : on pointe à null dans le tableau d'adjacence
                tabNoeud[i]->adjacence[j] = NULL;
            }
        }
    }
}


/**
 * \fn static void generationProba(Noeud* tabNoeud)
 * \brief Génération des probabilités (nombres) associées à chaque tuile du plateau (fonction interne à l'initialisation d'un plateau).
 *
 *
 * \param tabNoeud, un pointeur vers le premier élément du tableau contenant les noeuds des tuiles du plateau
 * \return Aucun retour
 */

static void generationProba(Noeud** tabNoeud){
    int proba[18];
    int i,j=3;
    proba[0]=2;
    proba[1]=12;
    for(i=2; i<18; i+=2){            // boucle de remplissage d'un tableau contenant les probas à distribuer
        proba[i] = j;
        proba[i+1] = j;
        ++j;
        if(j==7){++j;}
    }
    srand(time(NULL));               // Initialisation de la fonction rand en prenant comme référence le temps actuel (pour éviter le "pseudo-aléatoire")

    int nb = 18;
    for(i=0;i<18;++i){                                          // tirage et affectation des probas pour chaque tuile
        if(tabNoeud[i]->x != 0 && tabNoeud[j]->y != 0){
            j = rand()%nb;
            tabNoeud[i]->t->proba = proba[j];
            proba[j] = proba[nb-1];
            --nb;
        }
        else{
            tabNoeud[i]->t->proba = 0;
        }
    }

}


/**
 * \fn static int generationType(Noeud* tabNoeud)
 * \brief Génération des types de ressources pour les tuiles (fonction interne à l'initialisation d'un plateau)
 *
 *
 * \param tabNoeud, un pointeur vers le premier élément du tableau contenant les noeuds des tuiles du plateau
 * \return Aucun retour
 */

static void generationType(Noeud** tabNoeud){
    TypeRessource type[18];
    int i,j;
    for(i=0; i<3; ++i){type[i]= PIERRE;}               // Remplissage d'un tableau avec les types de terrains à distribuer
    for(i=3; i<6; ++i){type[i]= ARGILE;}
    for(i=6; i<10; ++i){type[i]= BLE;}
    for(i=10; i<14; ++i){type[i]= MOUTON;}
    for(i=14; i<18; ++i){type[i]= BOIS;}

    srand(time(NULL));                                     // Initialisation de la fonction rand en prenant comme référence le temps actuel (pour éviter le "pseudo-aléatoire")

    int nb = 18;
    for(i=0;i<18;++i){                                     // Boucle d'affectation aléatoire d'un type de terrain à chaque tuile.
        if(tabNoeud[i]->x != 0 || tabNoeud[i]->y != 0){
            j = rand()%nb;
            tabNoeud[i]->t->type = type[j];
            type[j] = type[nb-1];
            --nb;
        }
        else{
            tabNoeud[i]->t->type = PIERRE;                  // Par défaut, la tuile centrale est de type pierre.
        }
    }
}


/**
 * \fn static Tuile* initTuile()
 * \brief Initialisation d'une tuile, (son contenu est vide)
 *
 *
 * \param aucun paramètre
 * \return un pointeur vers l'instance de type Tuile créée.
 */

static Tuile* initTuile(){
    Tuile* t = (Tuile*) malloc(sizeof(Tuile));             // Allocation mémoire d'une tuile.
    if(t == NULL){
        fprintf(stderr,"probleme d'allocation mémoire !\n");
        return NULL;
    }
    t->brigand = 0;

    int i;
    for(i=0; i<6; ++i){                                     // Initialisation de ses paramètres.
        t->a[i].i = VIDE;
        t->a[i].owner = NULL;
        t->s[i].i = VIDE;
        t->s[i].owner = NULL;
    }
    return t;
}


/**
 * \fn static void freeTuile(Tuile* t)
 * \brief Libération de la mémoire allouée à une tuile.
 *
 *
 * \param t un pointeur vers la tuile à libérer.
 * \return Aucun retour
 */

static void freeTuile(Tuile* t){
    free(t);
}


/**
 * \fn static Noeud* initNoeud(double x, double y)
 * \brief Initialisation d'un noeud
 *
 *
 * \param positions x et y du nouveau noeud
 * \return un pointeur vers l'instance de type Noeud créée.
 */

static Noeud* initNoeud(double x, double y){
    Noeud* n = (Noeud*) malloc(sizeof(Noeud));      // Allocation mémoire d'un noeud.
    if(n == NULL){
        fprintf(stderr,"probleme d'allocation mémoire !\n");
        return NULL;
    }
    Noeud** adj = (Noeud**) malloc(6*sizeof(Noeud*));     //Allocation mémoire des pointeurs de noeuds voisins
    n->adjacence = adj;
    n->t = initTuile();
    n->x = x;
    n->y = y;
    return n;
}


/**
 * \fn static void freeNoeud(Noeud* n)
 * \brief Libération de la mémoire allouée à un noeud, à son tableau d'adjacence et à sa tuile correspondante.
 *
 *
 * \param n un pointeur vers le noeud correspondant.
 * \return Aucun retour
 */

static void freeNoeud(Noeud* n){
    freeTuile(n->t);
    free(n->adjacence);
    free(n);
}


/**
 * \fn Plateau* initPlateau()
 * \brief Initialisation du Plateau, c'est à dire de tous ses Noeuds et Tuiles.
 *
 *
 * \param aucun paramètre
 * \return un pointeur vers une instance de type Plateau.
 */

Plateau* initPlateau(){
    Plateau* p;
    double i,j;
    double coordX[5] = {-1,-1.5,-2,-1.5,-1};
    int compteurNoeud = 0,z=0;
    Noeud* tabNoeud[19];

    for(j=-2;j <= 2;++j){                                       // Création de 19 noeuds pour le plateau.
        for(i = coordX[z];i <= -coordX[z];++i){
            tabNoeud[compteurNoeud] = initNoeud(i,j);           // Chaque noeud est créé avec ses paramètres x et y.
            if(tabNoeud[compteurNoeud] == NULL){
                return NULL;
            }
            if(i==0 && j==0){                                   // si on a affaire au noeud central (x et y =0), alors on fait pointer le plateau vers lui.
                p = tabNoeud[compteurNoeud];
                p->t->brigand = 1;
            }
            ++compteurNoeud;
        }
        ++z;
    }
    fillAdjacence(tabNoeud);                                  // Fonctions de remplissage des noeuds du plateau (probas, types et noeuds adjacents).
    generationProba(tabNoeud);
    generationType(tabNoeud);
    return p;
}


/**
 * \fn int freePlateau(Plateau* p)
 * \brief Libération de la mémoire allouée à un plateau et son contenu.
 *
 *
 * \param p un pointeur vers le Plateau à libérer.
 * \return 0 si tout c'est bien passé, -1 sinon.
 */

int freePlateau(Plateau* p){
    if(p == NULL){
        return -1;
    }
    int i=0;
    int ord[6] = {1,3,0,5,2,4};                                     // Tableau de chiffres en liaison avec un pattern de mouvements.
    for(i=0;i<6;++i){                                               // On parcourt tous les noeuds pour les libérer un par un.
        freeNoeud(p->adjacence[i]->adjacence[i]);
        freeNoeud(p->adjacence[i]->adjacence[ord[i]]);
        freeNoeud(p->adjacence[i]);
    }
    freeNoeud(p);
    return 0;
}


/**
 * \fn Noeud* deplacementPlateau(Plateau* p, double x, double y)
 * \brief Fonction permettant de se déplacer à un endroit du plateau.
 *
 *
 * \param p est un pointeur vers le plateau et x et y sont les coordonnées du noeud recherché.
 * \return un pointeur vers le noeud cherché.
 */

Noeud* deplacementPlateau(Plateau* p, double x, double y){
    Noeud* Cur = p;
    int stop_infinite_while = 0;                                                    // Le noeud central est défini comme noeud de départ (noeud courant.
    if(Cur == NULL){return NULL;}
    while((Cur->x != x) || (Cur->y != y)){                                  // déplacement choisi en fonction des paramètres x et y par rapport au noeud courant.
        ++stop_infinite_while;
        if(stop_infinite_while > 10){
            return NULL;
        }
        if(Cur->x < x){
            if(Cur->y == y){Cur = Cur->adjacence[D];}
            else if(Cur->y < y){Cur = Cur->adjacence[HD];}
            else if(Cur->y > y){Cur = Cur->adjacence[BD];}
        }
        if(Cur == NULL){return NULL;}
        if(Cur->x == x){
            if(Cur->y < y){Cur = Cur->adjacence[HD]->adjacence[HG];}
            else if(Cur->y > y){Cur = Cur->adjacence[BD]->adjacence[BG];}
        }
        if(Cur == NULL){return NULL;}
        if(Cur->x > x){
            if(Cur->y == y){Cur = Cur->adjacence[G];}
            else if(Cur->y < y){Cur = Cur->adjacence[HG];}
            else if(Cur->y > y){Cur = Cur->adjacence[BG];}
        }
        if(Cur == NULL){return NULL;}
    }                                                                       // On continue les déplacements tant que le noeud courant n'est pas le noeud recherché.
    return Cur;
}

