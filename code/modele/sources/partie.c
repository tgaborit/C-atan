#include "partie.h"

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

static Node_joueur* initNode_joueur(Joueur* joueur, Node_joueur* next)
{
    Node_joueur* new= (Node_joueur*) malloc(sizeof(Node_joueur));
    new->joueur=joueur;
    new->next=next;
    return new;
}

static void free_node_joueur(Node_joueur* n){
    free(n);
}

static List_joueur* init_list_joueur ()
{
    List_joueur* list= (List_joueur*) malloc(3*sizeof(Node_joueur));

    list->current=NULL;
    list->first=NULL;
    list->last=NULL;

    return list;
}

static void free_list_joueur(Partie* partie){
    int i;
    setOnFirst_list_joueur(partie->joueurs);
    setOnNext_list_joueur(partie->joueurs);

    for(i=0;i<get_nbjoueurs(partie)-1;++i){
        Node_joueur* n = partie->joueurs->current;
        setOnNext_list_joueur(partie->joueurs);
        free_node_joueur(n);
    }
    free_node_joueur(partie->joueurs->current);
    free(partie->joueurs);
}

static int isempty_list_joueur (List_joueur* list)
{
    if(list->first==NULL)
        return 1;

    return 0;
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



  /**
* \fn int find_joueur(Partie* partie, Joueur* joueur)
* \brief place le current de la liste sur le joueur passé en paramètre
*
* \param Partie*:partie, Joueur*:joueur
* \return int: -1 si le joueur n'est pas dans la partie, 0 tout s'est bien passé
*/
int find_joueur(Partie* partie, Joueur* joueur)
{
    setOnFirst_list_joueur(partie->joueurs);
    int c=0;
    char* current_pseudo= partie->joueurs->current->joueur->pseudo;
    while(strcmp(current_pseudo,joueur->pseudo)!=0)
    {
        setOnNext_list_joueur(partie->joueurs);
        current_pseudo= partie->joueurs->current->joueur->pseudo;
        c++;
        if (c>get_nbjoueurs(partie))
        return -1;
    }
    return 0;
}

  /**
* \fn int get_nbjoueurs(Partie* partie)
* \brief renvoie le nombre de joueurs dans la partie
*
* \param Partie*:partie
* \return int: nombre de joueurs.
*/
int get_nbjoueurs(Partie* partie)
{
    if (partie->joueurs==NULL)
        return -1;
    Node_joueur* save_current= partie->joueurs->current;

    setOnFirst_list_joueur(partie->joueurs);
    int c=1;

    while(partie->joueurs->current != partie->joueurs->last)
    {
        setOnNext_list_joueur(partie->joueurs);
        c+=1;
    }
    partie->joueurs->current=save_current;
    return c;
}
  /**
* \fn void init_partie (Partie partie)
* \brief initialise la strucure partie qui contient toute les information relatives à la partie
*
* alloue la mémoire necessaire à la structure partie,
*initialise le pateau aléatoirement et initialise le tableau de joueur à null
* \param
* \return aucun
*/
 Partie* init_partie()
 {
    Partie* partie = (Partie*) malloc(sizeof(Partie));
    partie->joueurs= init_list_joueur();
    partie->plateau= initPlateau();
    return partie;
 }

 void free_partie(Partie* partie){
    freePlateau(partie->plateau);
    free_list_joueur(partie);
    free(partie);
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
* \fn Joueur get_joueur_actif(Partie partie);
* \brief renvoie le Joueur qui a la main
*
* \param Partie: partie en cour
* \return Joueur: joueur qui a la main
*/
Joueur* get_joueur_actif(Partie* partie)
{
    return partie->joueurs->current->joueur;
}

/**
* \fn Joueur* get_score_max
* \brief retourne un pointeur sur le joueur qui a le score le plus fort
*
* renvoie le joueur ayant le plus de point si plusieurs joueur sont a égalité renvoie le joeur qui a joué le plus tot au premier tour
* exemple: si tout les score sont à 2 renvoie le joueur qui a jouer en premier
*
* \param Partie: partie en cours
* \return Joueur*: joueur ayant le plus haut score
*/
Joueur* get_joueur_score_max(Partie* partie)
{
    setOnFirst_list_joueur(partie->joueurs);
    Joueur* joueurmaxscore = NULL;
    int maxscore=0;

    while(partie->joueurs->current!=partie->joueurs->last)
    {
        if(partie->joueurs->current->joueur->score>maxscore)
        {
            maxscore=partie->joueurs->current->joueur->score;
            joueurmaxscore=partie->joueurs->current->joueur;
        }
        setOnNext_list_joueur(partie->joueurs);
    }
    if (maxscore==0)
        return partie->joueurs->current->joueur;

    return joueurmaxscore;

}


/**
* \fn int get_score_max
* \brief retourne le score du joueur le plus fort
*
* renvoie le score du joueur ayant le plus de point si plusieurs joueur sont a égalité renvoie
 * le score le plus fort
* \param Partie: partie en cours
* \return int: score max dans la partie
*/
int get_score_max(Partie* partie)
{
    return get_joueur_score_max(partie)->score;
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


/**
 * \fn void gagne_ressource(int lance_des, Partie partie);
 * \brief distribue les ressources correspondant aux cases du numéro de dés
 *
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
            if(p->adjacence[i]->t->proba == lance_des){
                cherche_infrastructure(p->adjacence[i]);                // On appelle cherche_infrastructure pour distribuer les ressources au constructions voisines
            }
            if(p->adjacence[i]->adjacence[i]->t->proba == lance_des){
                cherche_infrastructure(p->adjacence[i]->adjacence[i]);
            }
            if(p->adjacence[i]->adjacence[ord[i]]->t->proba == lance_des){
                cherche_infrastructure(p->adjacence[i]->adjacence[ord[i]]);
            }
        }
    }
}


/**
 * \fn void distribution_ressource(List_Noeud)
 * \brief distribue les ressources en début de partie
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
