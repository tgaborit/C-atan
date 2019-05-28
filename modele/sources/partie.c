
#include "partie.h"



/**
 * \fn static List_joueur* init_list_joueur ()
 * \brief initialisation de la liste des joueurs dans la partie
 *alloue l'espace necessaire et initialise les pointeurs
 *
 * \param aucun
 * \return: aucun
 */
static List_joueur* init_list_joueur ()
{
    List_joueur* list= (List_joueur*) malloc(3*sizeof(Node_joueur));

    list->current=NULL;
    list->first=NULL;
    list->last=NULL;

    return list;
}

/**
 * \fn void init_pile_cartdev(Joueur joueur);
 * \brief Initialisation de la pile de cartes développment de la partie celon les règles du jeu
 *
 *
 * \param : CarteDev carte_dev[4] tableau representant la pile de carte developpement
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
 * \fn void setOnNext_list_joueur(List_joueur* list)
 * \brief passe le joueur courant de la liste sur le joueur suivant
 *
 *
 * \param :List_joueur* liste des joueurs
 * \return: aucun
 */

void setOnNext_list_joueur(List_joueur* list)
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
    partie->valeur_de = 12;
    return partie;
 }

/**
* \fn static void free_node_joueur(Node_joueur* n)
* \brief libère la mémoire allouée pour une structure Node_joueur
*
* \param Node_joueur* le noeud a liberer
* \return aucun
*/
static void free_node_joueur(Node_joueur* n){
    free_joueur(n->joueur);
    free(n);
}

static int get_nbjoueurs(Partie* partie)
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
* \fn static void free_list_joueur(Partie* partie)
* \brief libère la mémoire allouée pour une structure List_joueur
*
* \param Partie* la partie contenant la liste à liberer
* \return aucun
*/
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

/**
* \fn void free_partie(Partie* partie)
* \brief libère la mémoire allouée pour une structure partie
*
* \param
* \return aucun
*/
void free_partie(Partie* partie){
	freePlateau(partie->plateau);
   	free_list_joueur(partie);
	free (partie->cartedev);
	free(partie);

}
