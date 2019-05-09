/**
 * \file partie.h
 * \brief implémentation des geteurs de la structure partie:
 * \author Rémi.F
 * \version 0
 * \date 04 mai 2019
 *
 */

# include "get_partie.h"


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

int get_score_nbChevalier(Partie* partie)
{
    Joueur* joueur= get_joueur_actif(partie);
    return get_nbChevalier(joueur);
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
