/**
 * \file partie.h
 * \brief implémentation des fonctions liées à la partie
 * \author Rémi.F
 * \version 0
 * \date 05 mars 2019
 *
 */


#include "modele/headers/set_partie.h"


static Node_joueur* initNode_joueur(Joueur* joueur, Node_joueur* next)
{
    Node_joueur* new= (Node_joueur*) malloc(sizeof(Node_joueur));
    new->joueur = (Joueur*) malloc(sizeof(Joueur));
    new->next= (Node_joueur*) malloc(sizeof(Node_joueur));
    new->joueur=joueur;
    new->next=next;
    return new;
}

static void cherche_infrastructure(Noeud* n){

	    Infrastructure infra;
	    Joueur* j;
	    int i;
	    for(i=0;i<6;++i){
	        infra = n->t->s[i].i;
	        j = n->t->s[i].owner;
	        if(infra == COLONIE){
	            gain_ressource(n->t->type,j);
	        }

	        if(infra == VILLE){
	            gain_ressource(n->t->type,j);
	            gain_ressource(n->t->type,j);
	        }
	    }

	}

static int isempty_list_joueur (List_joueur* list)
{
    if(list->first==NULL)
        return 1;

    return 0;
}


static void setOnNext_list_joueur(List_joueur* list)
{
    if(list->current != NULL){
        list->current=list->current->next;
    }
}


static void setOnFirst_list_joueur(List_joueur* list)
{
    if(list->current != NULL){
        list->current=list->first;
    }
}

static int addfirst_list_joueur (Joueur* joueur, List_joueur* list)
{

    if (isempty_list_joueur(list))
    {
        Node_joueur* newfirstnode = initNode_joueur(joueur, NULL);
        list->last= newfirstnode;
        list->current= newfirstnode;
        list->first= newfirstnode;
        return 1;
    }
    Node_joueur* newfirstnode = initNode_joueur(joueur, list->current);
    if (newfirstnode==NULL)
        return -1;
    list->current->next= newfirstnode;
    list->last=newfirstnode;
    list->last->next=list->first;
    setOnNext_list_joueur(list);
    return 1;
}

static Joueur* joueur_nbRoute_max(Partie* partie){
    int i, boolean_equal = 0;
    Node_joueur* tmp = partie->joueurs->current;
    setOnFirst_list_joueur(partie->joueurs);
    Joueur* j_max = partie->joueurs->current->joueur;
    setOnNext_list_joueur(partie->joueurs);

    for(i=0;i<get_nbjoueurs(partie)-1;++i){                                             // On parcourt les joueurs et on renvoie celui qui possede le plus de routes.
        if(j_max->nbRoute < partie->joueurs->current->joueur->nbRoute){
            j_max = partie->joueurs->current->joueur;
            boolean_equal = 0;
        }
        else if(j_max->nbRoute == partie->joueurs->current->joueur->nbRoute){           // Si deux joueurs ont le même nombre de routes, alors NULL est renvoyé
            partie->joueurs->current = tmp;
            boolean_equal = 1;
        }
        setOnNext_list_joueur(partie->joueurs);
    }
    partie->joueurs->current = tmp;
    if(boolean_equal == 0){
        return j_max;
    }
    return NULL;
}





  /**
* \fn int find_joueur(Partie* partie, Joueur* joueur)
* \brief place le current de la liste sur le joueur passé en paramètre
*
* \param Partie*:partie, Joueur*:joueur
* \return int: -1 si le joueur n'est pas dans la partie, 0 tout s'est bien passé
*/
int find_joueur(Partie* partie, Joueur* joueur)
{

    int c=0;
    Node_joueur* savecurrent= partie->joueurs->current;
    char* current_pseudo= partie->joueurs->current->joueur->pseudo;
    while(strcmp(current_pseudo,joueur->pseudo)!=0)
    {
        setOnNext_list_joueur(partie->joueurs);
        current_pseudo= partie->joueurs->current->joueur->pseudo;
        c++;
        if (c>get_nbjoueurs(partie))
        {
            partie->joueurs->current= savecurrent;
            return -1;
        }

    }
    return 0;
}




  /**
* \fn void add_joueur(Joueur joueur, Partie partie)
* \brief inscrit un nouveau joueur à la partie
*
* ajoute un joueur au tableau de joueur contenue dans la sructure partie
* \param Joueur: joueur à ajouter Patie: partie dans laquelle le joueur est inscrit
* \return aucun
*/
 void add_joueur(Joueur* joueur,Partie* partie)
 {
    addfirst_list_joueur(joueur,partie->joueurs);
 }

 /**
* \fn void passer_tour(Partie partie)
* \brief donne la main au prochain joueur
*
* place le prochun joueur en position JOUE
* \param Partie: partie
* \return aucun
*/
 void passer_tour(Partie* partie)
 {
    partie->joueurs->current->joueur->status=ATTEND;
    setOnNext_list_joueur(partie->joueurs);
    partie->joueurs->current->joueur->status=JOUE;
 }

  /**
* \fn void donner_main(Partie partie, Joueur joueur)
* \brief donne la main au joueur passé en paramètre
*
*
* \param Partie: partie Joueur: joueur
* \return aucun
*/
 void donner_main(Partie* partie, Joueur* joueur)
 {
    partie->joueurs->current->joueur->status=ATTEND;
    find_joueur(partie, joueur);
    partie->joueurs->current->joueur->status=JOUE;

 }

/**
 * \fn void gagne_ressource(int lance_des, Partie partie);
 * \brief distribue les ressources correspondant aux cases du numéro de dés
 *  ajoute les ressources aux joueurs possédant une construction à proximité de ces cases.
 * \param Partie: etat de la partie
 * \return aucun
 */
void gagne_ressource(int lance_des, Partie* partie){
    if(partie != NULL && partie->plateau != NULL){
        Plateau* p = partie->plateau;
        int i=0;
        int ord[6] = {HG,G,HD,BG,D,BD};                                     // Tableau de chiffres en liaison avec un pattern de mouvements.

        for(i=0;i<6;++i){                                               // On cherche les noeuds ou la proba est celle du lancé de dés
            if(p->adjacence[i]->t->proba == lance_des && p->adjacence[i]->t->brigand == 0){
                cherche_infrastructure(p->adjacence[i]);                // On appelle cherche_infrastructure pour distribuer les ressources au constructions voisines
            }
            if(p->adjacence[i]->adjacence[i]->t->proba == lance_des && p->adjacence[i]->adjacence[i]->t->brigand == 0){
                cherche_infrastructure(p->adjacence[i]->adjacence[i]);
            }
            if(p->adjacence[i]->adjacence[ord[i]]->t->proba == lance_des && p->adjacence[i]->adjacence[ord[i]]->t->brigand == 0){
                cherche_infrastructure(p->adjacence[i]->adjacence[ord[i]]);
            }
        }
    }
}

/**
 * \fn void distribution_ressource(List_Noeud)
 * \brief distribu les ressources en début de partie
 *
 *  ajoute les ressources juxtaposant les noeuds ou les joueurs ont placé leurs collonies au début de la partie
 * \param Partie: etat de la partie
 * \return aucun
 */
void distribution_ressource(Partie* partie){
    if(partie != NULL && partie->plateau != NULL){
        Plateau* p = partie->plateau;
        int i=0;
        int ord[6] = {HG,G,HD,BG,D,BD};                                     // Tableau de chiffres en liaison avec un pattern de mouvements.

        for(i=0;i<6;++i){                                               // On parcourt tous les noeuds du plateau
            cherche_infrastructure(p->adjacence[i]);                // On appelle cherche_infrastructure pour distribuer les ressources au constructions voisines
            cherche_infrastructure(p->adjacence[i]->adjacence[i]);
            cherche_infrastructure(p->adjacence[i]->adjacence[ord[i]]);
        }
    }
}

/**
 * \fn void nb_routes_max(Partie* partie)
 * \brief met à jour le point déscerné au détenteur du plus de routes
 *
 *  Enleve un point à l'ancien détenteur et en rajoute un au nouveau (sauf en cas d'égalité)
 * \param Partie: etat de la partie
 * \return aucun retour
 */

void nb_routes_max(Partie* partie){
    if(partie != NULL && partie->plateau != NULL){
        static Joueur* j_old = NULL;
        Joueur* j_new = joueur_nbRoute_max(partie);                                     // Recherche du nouveau possesseur du plus grand nombre de route et gain d'un point (sauf en cas d'égalité).
        if(j_old != NULL){
            dec_score(j_old,1);                                                         // Perte d'un point à l'ancien possesseur du plus grand nombre de route (suaf en cas d'ancienne égalité).
        }
     if(j_new != NULL){
            inc_score(j_new,1);
        }
        j_old = j_new;
    }

}

/**
 * \fn int lancer_des()
 * \brief Simule un lancé de dès
 *
 *  retourne une valeur aléatoire entre 2 et 12 en respectant les probabilité d'un vrai lancé de dès
 * \param aucun
 * \return int: valeur obtenu
 */
int lancer_des()
{
    int i=0;
    int res=0;
    srand(time(NULL));
    for(i=0;i<2;i++)
    {
        res+= rand()%(7-1) + 1 ;
    }
   return res;
}


static int get_nbcartedev_pile(CarteDev cartedev[4],TypeCarteDev type)
{
    return cartedev[type].nb_carte;
}

static int get_nbcartedev_total_pile(CarteDev cartedev[4])
{
    int i,c=0;
    for(i=0;i<=4;++i)
    {
        c+=cartedev[i].nb_carte;
    }
    return c;
}

static void retirer_cartedev_pile(CarteDev cartedev[4], Joueur* joueur, TypeCarteDev type)
{
    cartedev[type].nb_carte-=1;
    joueur->carte_dev[type].nb_carte+=1;
}

/**
 * \fn int obtenir_cartedev (Partie* partie)
 * \brief donne une carte developpement au joueur qui en fait la demande
 *
 * \param Partie*: la partie en cours
 * \return int: 0 si tout c'est bien passé -1 si le joueur ne peut pas acheter de carte
 */
int obtenir_cartedev (Partie* partie)
{
    Joueur* joueur = get_joueur_actif(partie);
    CarteDev* cartedev= partie->cartedev;
    if(get_nbcartedev_total_pile(cartedev) !=0 )
    {
        if (achat_cartedev(joueur)==0)
        {
        int proba_chevalier=(get_nbcartedev_pile(cartedev,CHEVALIER)*100)/get_nbcartedev_total_pile(cartedev);
        int proba_point=(get_nbcartedev_pile(cartedev,POINT)*100)/get_nbcartedev_total_pile(cartedev);
        int proba_route=(get_nbcartedev_pile(cartedev,ROUTES)*100)/get_nbcartedev_total_pile(cartedev);
        int proba_monopole=(get_nbcartedev_pile(cartedev,MONOPOLE)*100)/get_nbcartedev_total_pile(cartedev);
        int proba_decouverte=(get_nbcartedev_pile(cartedev,DECOUVERTE)*100)/get_nbcartedev_total_pile(cartedev);
        srand(time(NULL));
        int rand_val=rand()%100;


        if (rand_val<= proba_chevalier)
            retirer_cartedev_pile(cartedev,joueur,CHEVALIER);

        if(proba_chevalier<rand_val && rand_val<=(proba_chevalier+proba_point))
            retirer_cartedev_pile(cartedev,joueur,POINT);

        if((proba_chevalier+proba_point)<rand_val && rand_val<=(proba_chevalier+proba_point+proba_decouverte))
            retirer_cartedev_pile(cartedev,joueur,DECOUVERTE);

        if((proba_chevalier+proba_point+proba_decouverte)<rand_val && rand_val<=(proba_chevalier+proba_point+proba_decouverte+proba_monopole))
            retirer_cartedev_pile(cartedev,joueur,MONOPOLE);

        if ((proba_chevalier+proba_point+proba_decouverte+proba_monopole)<rand_val && rand_val<=(proba_chevalier+proba_point+proba_decouverte+proba_monopole+proba_route))
            retirer_cartedev_pile(cartedev,joueur,ROUTES);

        return 0;
        }
    }
    return -1;
}

/**
 * \fn int utiliser_monopole (Partie* partie, TypeRessource type)
 * \brief si le joueur courant possède une carte monopole il la défausse et prend les cartes ressources du type passé en paramètre
 *de tout les autre joueurs.
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte monopole
 */
int utiliser_monopole (Partie* partie, TypeRessource type){
    int i,nb=0,tot=0;

    if(get_cartedev(MONOPOLE,get_joueur_actif(partie))<1)
        return -1;
    perte_cartedev(MONOPOLE,get_joueur_actif(partie));

    for(i=0;i<get_nbjoueurs(partie);++i){
        setOnNext_list_joueur(partie->joueurs);
        nb = get_nbressource(type,partie->joueurs->current->joueur);
        tot+=nb;
        partie->joueurs->current->joueur->ressource[type].nb_ressource=0;
    }
    //setOnNext_list_joueur(partie->joueurs);
    partie->joueurs->current->joueur->ressource[type].nb_ressource=tot;
    return 0;
}

/**
 * \fn int utiliser_decouverte (Partie* partie, TypeRessource type)
 * \brief si le joueur courant possède une carte decouverte il la défausse et gagne 2 carte ressource des types passés en paramètre
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte decouverte
 */
int utiliser_decouverte (Partie* partie, TypeRessource type1, TypeRessource type2){
    Joueur* joueur_actif=get_joueur_actif(partie);
    if(get_cartedev(DECOUVERTE, joueur_actif)<1)
        return -1;

    perte_cartedev(DECOUVERTE,joueur_actif);
    joueur_actif->ressource[type1].nb_ressource+=1;
    joueur_actif->ressource[type2].nb_ressource+=1;
    return 0;
}

/**
 * \fn int utiliser_point (Partie* partie)
 * \brief si le joueur courant possède une carte point il la défausse et gagne 1 point de score
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte point
 */
int utiliser_point (Partie* partie){
    Joueur* joueur_actif=get_joueur_actif(partie);
    if(get_cartedev(POINT,joueur_actif)<1){
        return -1;
        }

    perte_cartedev(POINT,joueur_actif);
    inc_score(joueur_actif,1);
    return 0;
}



/**
 * \fn int utiliser_routes(Partie* partie,int x1,int y1,int x2,int y2,int position1,int position2
 * \brief si le joueur courant possede une carte routes il la defausse et pose deux routes.
 *
 * \param Partie*: la partie en cours, puis les parametres des endroits ou poser les deux routes
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte routes ou si la pose a échoué
 */
int utiliser_routes(Partie* partie,double x1,double y1,double x2,double y2,int position1,int position2){
    Joueur* joueur_actif= get_joueur_actif(partie);
    if (get_cartedev(ROUTES,joueur_actif)<1)
        return -1;

    int cond1 = setRouteFree(partie,x1,y1,position1);
    int cond2 = setRouteFree(partie,x2,y2,position2);

    if(cond1 == 0 && cond2 == 0){
        perte_cartedev(ROUTES,joueur_actif);
        return 0;
    }
    if(cond1 == -1 && cond2 == -1){
        return -1;
    }
    int pattern[6] = {0,2,4,5,3,1};
    if(cond1 == 0){
        Noeud* cur = deplacementPlateau(partie->plateau,x1,y1);
        cur->t->a[position1].i = VIDE;
        cur->t->a[position1].owner = NULL;

        int indice = position1+3;
        if(indice > 5){
            indice = indice-6;
        }

        if(cur->adjacence[pattern[position1]] != NULL){
            cur->adjacence[pattern[position1]]->t->a[indice].i = VIDE;
            cur->adjacence[pattern[position1]]->t->a[indice].owner = NULL;
        }
        --get_joueur_actif(partie)->nbRoute;
        return -1;
    }
    Noeud* cur = deplacementPlateau(partie->plateau,x2,y2);
    cur->t->a[position2].i = VIDE;
    cur->t->a[position2].owner = NULL;

    int indice = position2+3;
        if(indice > 5){
            indice = indice-6;
        }

    if(cur->adjacence[pattern[position2]] != NULL){
        cur->adjacence[pattern[position2]]->t->a[indice].i = VIDE;
        cur->adjacence[pattern[position2]]->t->a[indice].owner = NULL;
    }
    --get_joueur_actif(partie)->nbRoute;
    return -1;
}

/**
 * \fn int utiliser_chevalier(Partie* partie, double x, double y,Joueur* joueur)
 * \brief utilise une carte développemnt chevalier, bouge le voleur sur une nouvelle tuile de coordonée passé en paramètre,
 *vole une carte aléatoirement dans la main du joueur passé en paramètre et la donne au joueur qui appelle la carte chevalier.
 * \param Partie: etat de la partie
 * \return 0 si tout c'est bien passé -1 si le joueur passé en paramètre n'a pas d'infrastructuresur un sommet de la tuile de coordonnées (x,y)
 */
int utiliser_chevalier(Partie* partie, double x, double y,Joueur* joueur){
    int i,rand_val;
    Noeud* current = deplacementPlateau(partie->plateau,x,y);
    Joueur* joueur_actif=get_joueur_actif(partie);
    for(i=0;i<=6;++i){
        if(strcmp(joueur->pseudo,current->t->s[i].owner->pseudo) ==0 && current->t->brigand!=0) {
            setVoleur(partie,x,y);
            if (get_nbressource_total(joueur)==0){
                int proba_ble,proba_bois,proba_pierre,proba_mouton,proba_argile;
                rand_val=rand()%100;
                proba_ble=(get_nbressource(BLE,joueur)*100)/get_nbressource_total(joueur);
                proba_bois=(get_nbressource(BOIS,joueur)*100)/get_nbressource_total(joueur);
                proba_pierre=(get_nbressource(PIERRE,joueur)*100)/get_nbressource_total(joueur);
                proba_argile=(get_nbressource(ARGILE,joueur)*100)/get_nbressource_total(joueur);
                proba_mouton=(get_nbressource(MOUTON,joueur)*100)/get_nbressource_total(joueur);

            if (rand_val<= proba_ble){
                perte_ressource(BLE,joueur);
                gain_ressource(BLE,joueur_actif);
                }

            if(proba_ble<rand_val && rand_val<=(proba_ble+proba_bois))
                {
                perte_ressource(BOIS,joueur);
                gain_ressource(BOIS,joueur_actif);
                }

            if((proba_ble+proba_bois)<rand_val && rand_val<=(proba_ble+proba_bois+proba_pierre))
                {
                perte_ressource(PIERRE,joueur);
                gain_ressource(PIERRE,joueur_actif);
                }

            if((proba_ble+proba_bois+proba_pierre)<rand_val && rand_val<=(proba_ble+proba_bois+proba_pierre+proba_argile))
                {
                perte_ressource(ARGILE,joueur);
                gain_ressource(ARGILE,joueur_actif);
                }

            if ((proba_ble+proba_bois+proba_pierre+proba_argile)<rand_val && rand_val<=(proba_ble+proba_bois+proba_pierre+proba_argile+proba_mouton))
                {
                perte_ressource(MOUTON,joueur);
                gain_ressource(MOUTON,joueur_actif);
                }
            }
     joueur_actif->nbChevalier+=1;
     return 0;
            }
        }
    return -1;
    }

    /**
 * \fn int action_voleur(Partie* partie,int des);
 * \brief si le des affiche 7, passe en revu les cartes ressource de tout les joueur et enlève la moitier des ressource des joueur qui ont plus de 7 cartes ressources.
 *
 * \param Partie*: la partie en cours, int: résultat aux des
 * \return int: 0 si tout c'est bien passé -1 si le résultats des des n'est pas 7
 */
int action_voleur(Partie* partie,int des){
    int i;
    Joueur* current_joueur;
    if (des==7){
        for(i=0;i<=get_nbjoueurs(partie);++i){
            current_joueur=partie->joueurs->current->joueur;
            voleur_perte_ressource(current_joueur);
            setOnNext_list_joueur(partie->joueurs);
            }
        return 0;
    }
    return -1;
}
