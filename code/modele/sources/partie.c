/**
 * \file partie.h
 * \brief implémentation des fonctions liées à la partie
 * \author Rémi.F
 * \version 0
 * \date 05 mars 2019
 *
 */

# include "partie.h"
# include "plateau.h"



static Node_joueur* initNode_joueur(Joueur* joueur, Node_joueur* next)
{
    Node_joueur* new= (Node_joueur*) malloc(sizeof(Node_joueur));
    new->joueur=joueur;
    new->next=next;
    return new;
}

static List_joueur* init_list_joueur ()
{
    List_joueur* list= (List_joueur*) malloc(3*sizeof(Node_joueur));

    list->current=NULL;
    list->first=NULL;
    list->last=NULL;

    return list;
}

static int isempty_list_joueur (List_joueur* list)
{
    if(list->first==NULL)
        return 1;

    return 0;
}

static void setOnNext_list_joueur(List_joueur* list)
{
    list->current=list->current->next;
}

static void setOnFirst_list_joueur(List_joueur* list)
{
    list->current=list->first;
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
 * \fn void init_pile_cartdev(Joueur joueur);
 * \brief Initialisation des cartes en main du joueur
 *
 *
 * \param initialise les carte en main du joueur en trillant le tableau par type dans un ordre précis
 * \return: aucun
 */
static void init_pile_cartedev(CarteDev carte_dev[4])
{
    CarteDev monopole ={MONOPOLE,2};
    CarteDev chevalier ={CHEVALIER,14};
    CarteDev routes= {ROUTES,2};
    CarteDev point= {POINT,5};
    CarteDev decouverte= {DECOUVERTE,2};
    carte_dev[0]=monopole;
    carte_dev[1]=chevalier;
    carte_dev[2]=routes;
    carte_dev[3]=point;
    carte_dev[4]=decouverte;
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
    partie->cartedev= (CarteDev*) malloc(4* sizeof(CarteDev));
    init_pile_cartedev(partie->cartedev);
    return partie;
 }

   /**
* \fn void free_partie(Partie* partie)
* \brief libère la mémoire allouée pour une structure partie
*
* \param
* \return aucun
*/
void free_partie(Partie* partie){
    int i;
    Joueur* current_joueur;
    for (i=1;i<=get_nbjoueurs(partie);++i){
    current_joueur=get_joueur_actif(partie);
    setOnNext_list_joueur(partie->joueurs);
    free_joueur(current_joueur);
    }
    freePlateau(partie->plateau);
    free(partie->cartedev);
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
    Node_joueur* savecurrent= partie->joueurs->current;
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
    partie->joueurs->current=savecurrent;
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
 * \brief si le joueur courant possède une carte decouverte il la défausse et gagne 2 carte ressource du type passé en paramètre
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte decouverte
 */
int utiliser_decouverte (Partie* partie, TypeRessource type){
    Joueur* joueur_actif=get_joueur_actif(partie);
    if(get_cartedev(DECOUVERTE, joueur_actif)<1)
        return -1;

    perte_cartedev(DECOUVERTE,joueur_actif);
    joueur_actif->ressource[type].nb_ressource+=2;
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
 * \fn int utiliser_routes (Partie* partie)
 * \brief si le joueur courant possède une carte point il la défausse et gagne 1 point de score
 *
 * \param Partie*: la partie en cours, TypeRessource: type de ressource demandé.
 * \return int: 0 si tout c'est bien passé -1 si le joueur n'as pas de carte point
 */
//int utiliser_routes (Partie* partie,){
