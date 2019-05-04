/**
 * \file partie.h
 * \brief implémentation des geteurs de la structure partie:
 * \author Rémi.F
 * \version 0
 * \date 04 mai 2019
 *
 */

# include "get_partie.h"
# include "plateau.h"

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
