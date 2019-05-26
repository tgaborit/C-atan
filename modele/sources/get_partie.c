/**
 * \file partie.h
 * \brief implémentation des geteurs de la structure partie:
 * \author Rémi.F
 * \version 0
 * \date 04 mai 2019
 *
 */

#include "get_partie.h"




static void setOnFirst_list_joueur(List_joueur* list)
{
    if(list->current != NULL){
        list->current=list->first;
    }
}


/**
 * \fn int get_des(Partie* partie)
 * \brief Simule un lancé de dès
 *
 *  retourne la valeur du lancé de des le plus récent de la partie.
 * \param partie un pointeur vers la partie.
 * \return int: valeur obtenu
 */
int get_des(Partie* partie){
    return partie->valeur_de;
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
 * \fn int  get_nbcartedev_joueuractif(TypeCarteDev type,Partie* partie)
 * \brief Fonction qui retourne les cartes developpemnts possédées par le joueur
 *
 * fonction renvoillant le nombre de carte developpement d'un certain type possédé par le joueur actif
 * \param TypeCarteDev: le type de la carte developpemnt dont on veut connaitre le nombre, Partie* partie en cours
 * \return int:le nombre de la carte developpement du type passé en paramètre possédé par le joueur actif
 */
int  get_nbcartedev_joueuractif(TypeCarteDev type,Partie* partie){
    Joueur* joueur= get_joueur_actif(partie);
    return get_cartedev(type,joueur);
}


/**
 * \fn int  get_nbressource_joueuractif(TypeRessource type, Partie* partie)
 * \brief Fonction qui retourne les ressources possédées par le joueur actif
 *fonction renvoillant le nombre de ressource d'un certain type possédé le joueur actif
 * \param Type_ressource: le type de la ressource dont on veut connaitre le nombre, Partie* partie en cours
 * \return int:le nombre de la ressource du type passé en paramètre possédé par le joueur
 */
int  get_nbressource_joueuractif(TypeRessource type, Partie* partie){
    Joueur* joueur= get_joueur_actif(partie);
    return get_nbressource(type,joueur);
}

/**
 * \fn int get_score_joueuractif(Partie* partie)
 * \brief Fonction qui retourne le score du joueur actif
 *
 * \param Partie* partie en cours
 * \return int:le score du joueur actif.
 */

int get_score_joueuractif(Partie* partie)
{
    Joueur* joueur= get_joueur_actif(partie);
    return get_score(joueur);
}

/**
 * \fn int get_nbChevalier_joueuractif(Partie* partie)
 * \brief Fonction qui retourne le nombre de chevaliers activés par le joueur actif
 *
 * \param Partie* partie en cours
 * \return int:le nombre de chevaliers activés par le joueur actif
 */

int get_nbChevalier_joueuractif(Partie* partie)
{
    Joueur* joueur= get_joueur_actif(partie);
    return get_nbChevalier(joueur);
}


/**
 * \fn Joueur* get_joueur_chevaliers(Partie* partie)
 * \brief Fonction qui retourne le joueur possédant le plus d'activations de chevaliers.
 *
 * \param Partie* partie en cours
 * \return retourne le joueur en question, ou NULL en cas d'égalité ou si personne n'a activé plus de trois chevaliers.
 */

Joueur* get_joueur_chevaliers(Partie* partie){
    int i, boolean_equal = 0;
    Node_joueur* tmp = partie->joueurs->current;
    setOnFirst_list_joueur(partie->joueurs);
    Joueur* j_max = partie->joueurs->current->joueur;
    setOnNext_list_joueur(partie->joueurs);

    for(i=0;i<get_nbjoueurs(partie)-1;++i){                                             // On parcourt les joueurs et on renvoie celui qui possede le plus d'activations de chevaliers.
        if(j_max->nbChevalier < partie->joueurs->current->joueur->nbChevalier){
            j_max = partie->joueurs->current->joueur;
            boolean_equal = 0;
        }
        else if(j_max->nbChevalier == partie->joueurs->current->joueur->nbChevalier){           // Si deux joueurs ont le même nombre de chevaliers, alors NULL est renvoyé
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
 * \fn Joueur* get_joueur_routes(Partie* partie)
 * \brief Fonction qui retourne le joueur possédant le plus d'activations de chevaliers.
 *
 * \param Partie* partie en cours
 * \return retourne le joueur en question, ou NULL en cas d'égalité ou si personne n'a posé plus de cinq routes.
 */

Joueur* get_joueur_routes(Partie* partie){
    int i,nbRoutes, boolean_equal = 0;
    Node_joueur* tmp = partie->joueurs->current;
    setOnFirst_list_joueur(partie->joueurs);
    Joueur* j_max = partie->joueurs->current->joueur;
    setOnNext_list_joueur(partie->joueurs);

    for(i=0;i<get_nbjoueurs(partie)-1;++i){                                             // On parcourt les joueurs et on renvoie celui qui possede le plus de routes.
        nbRoutes = partie->joueurs->current->joueur->nbRoute;
        if(j_max->nbRoute < nbRoutes){
            j_max = partie->joueurs->current->joueur;
            boolean_equal = 0;
        }
        else if(j_max->nbRoute == nbRoutes){                                            // Si deux joueurs ont le même nombre de routes, alors NULL est renvoyé
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
 * \fn char* get_pseudo_joueuractif(Partie* partie)
 * \brief Fonction qui retourne le pseudo du joueur actif
 *
 * \param Partie* partie en cours
 * \return char*:le pseudo du joueur actif
 */

 char* get_pseudo_joueuractif(Partie* partie)
{
    Joueur* joueur= get_joueur_actif(partie);
    return get_pseudo(joueur);
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
    if (partie==NULL)
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
* \fn int test_pseudo(char* pseudo, Partie* partie)
* \brief retourne un flag qui indique l'unité ou non du pseudo choisi.
*retourne 0 si le pseudo n'est pas encore utiliser dans la partie, -1 sinon
*
* \param char*:pseudo à vérifier,Partie: partie en cours
* \return int:retourne 0 si le pseudo n'est pas encore utiliser dans la partie, -1 sinon
*/
int test_pseudo(char* pseudo, Partie* partie){
    int i;
    Node_joueur* current_node= partie->joueurs->current;
    setOnFirst_list_joueur(partie->joueurs);
    for(i=0;i<get_nbjoueurs(partie);++i){
        if(strcmp(pseudo,partie->joueurs->current->joueur->pseudo)==0){
            partie->joueurs->current= current_node;
            return -1;
        }
        setOnNext_list_joueur(partie->joueurs);

    }
    partie->joueurs->current= current_node;
    return 0;
    }
