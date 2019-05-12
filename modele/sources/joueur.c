/**
 * \file joueur.c
 * \brief fonctions associées à la strucutre Joueur
 * \author Rémi.F
 * \version 0
 * \date 11 mars 2019
 *
 *
 */

#include "joueur.h"
#include <string.h>

/**
 * \fn void set_pseudo(Joueur joueur);
 * \brief Initialisaton pseudo joueur
 *
 *
 * \param Char* pseudo choisie par le joueur Joueur: joueurdont on initialise le pseudo
 * \return: aucun
 */
void set_pseudo(Joueur* joueur, char* pseudo)
{
    strncpy(joueur->pseudo, pseudo,TAILLE_MAX_PSEUDO);
}

/**
 * \fn void set_couleur(Joueur joueur, Couleur couleur);
 * \brief Initialisaton couleur joueur
 *
 *
 * \param Couleur: couleur choisie par le joueur Joueur: joueur dont on initialise la couleur
 * \return: aucun
 */
void set_couleur(Joueur* joueur, Couleur couleur)
{
    joueur->couleur=couleur;
}

/**
 * \fn void init_main_ressource(Joueur joueur);
 * \brief Initialisation des cartes en main du joueur
 *
 *
 * \param initialise les carte en main du joueur en trillant le tableau par type dans un ordre précis
 * \return: aucun
 */
void init_main_ressource(Joueur* joueur)
{
    Ressource ble ={BLE,0};
    Ressource bois ={BOIS,0};
    Ressource pierre ={PIERRE,0};
    Ressource argile= {ARGILE,0};
    Ressource mouton= {MOUTON,0};
    joueur->ressource[0]=ble;
    joueur->ressource[1]=bois;
    joueur->ressource[2]=pierre;
    joueur->ressource[3]=argile;
    joueur->ressource[4]=mouton;
}

/**
 * \fn void init_main_cartdev(Joueur joueur);
 * \brief Initialisation des cartes en main du joueur
 *
 *
 * \param initialise les carte en main du joueur en trillant le tableau par type dans un ordre précis
 * \return: aucun
 */
void init_main_cartedev(Joueur* joueur)
{
    CarteDev monopole ={MONOPOLE,0};
    CarteDev chevalier ={CHEVALIER,0};
    CarteDev routes= {ROUTES,0};
    CarteDev point= {POINT,0};
    CarteDev decouverte= {DECOUVERTE,0};
    joueur->carte_dev[0]=monopole;
    joueur->carte_dev[1]=chevalier;
    joueur->carte_dev[2]=routes;
    joueur->carte_dev[3]=point;
    joueur->carte_dev[4]=decouverte;
}

/**
 * \fn void init_joueur(Couleur couleur,char* pseudo)
 * \brief Fonction d'initialisationde la structure joueur
 *
 * fonction qui alloue la mémoire necessaire à la création d'un joueur, lui donne son pseudo et sa couleur et initialise son score à 0 ainsi que le nombre de ses cartes en main
 * \param Couleur: la couleur choisi par le joueur char* le pseudo choisi par le joueur.
 * \return: aucun
 */
Joueur* init_joueur(Couleur couleur,char* pseudo)
{
    Joueur* new_joueur = (Joueur*) malloc(sizeof(Joueur));
    new_joueur->pseudo= (char*) malloc(TAILLE_MAX_PSEUDO*sizeof(char));
    set_pseudo(new_joueur,pseudo);
    set_couleur(new_joueur,couleur);
    new_joueur->score=0;
    new_joueur->ressource= (Ressource*) malloc(5*sizeof(Ressource));
    new_joueur->carte_dev=(CarteDev*) malloc(5*sizeof(CarteDev));
    new_joueur->nbRoute=0;
    new_joueur->nbChevalier=0;
    init_main_ressource(new_joueur);
    init_main_cartedev(new_joueur);
    set_status(new_joueur,ATTEND);
    return new_joueur;
}

/**
 * \fn void free_joueur(Joueur* joueur)
 * \brief Fonction qui libère la mémoire allouer à un joueur
 *
 *
 * \param Joueur : joueur
 * \return aucun
 */
void free_joueur(Joueur* joueur)
{
    free(joueur->carte_dev);
    free(joueur->pseudo);
    free(joueur->ressource);
    free(joueur);
}

/**
 * \fn int get_score(Joueur joueur)
 * \brief Fonction qui retourne le score du joueur
 *
 * fonction renvoillant le score du joueur passé en paramètre
 * \param Joueur : joueur dont on veut connètrele score
 * \return int:la valeur score cotenue dans la structure joueur passé en paramètre
 */
int get_score(Joueur* joueur)
{
    return joueur->score;
}

 /**
 * \fn char* get_pseudo(Joueur* joueur)
 * \brief Fonction qui retourne le pseudo du joueur
 *
 * fonction renvoillant le pseudo du joueur passé en paramètre
 * \param Joueur : joueur dont on veut connaitre le pseudo
 * \return char* :le pseudo du joueur
 */
char* get_pseudo(Joueur* joueur)
{
    return joueur->pseudo;
}

 /**
 * \fn void inc_score(Joueur* joueur, int points)
 * \brief Fonction qui incrémente le score d'un joueur
 *
 * fonction qui incrémente le score d'un joueur de l'entier passé en paramètre
 * \param Joueur : joueur dont on veut augmenter le score, int: points nombres de points gagné par le joueur
 * \return aucun
 */
void inc_score(Joueur* joueur, int points)
{
    joueur->score+=points;
}

 	/**
	 * \fn void dec_score(Joueur* joueur, int points)
	 * \brief Fonction qui décrémente le score d'un joueur
	 *
	 * fonction qui décrémente le score d'un joueur de l'entier passé en paramètre
	 * \param Joueur : joueur dont on veut diminuer le score, int: points nombres de points perdus par le joueur
	 * \return aucun
	 */
	void dec_score(Joueur* joueur, int points){

	    joueur->score-=points;

	}
/**
 * \fn void set_status(Joueur joueur);
 * \brief Initialisaton status du joueur
 *
 *
 * \param Status status Joueur*: joueur dont on initialise le status
 * \return: aucun
 */
void set_status(Joueur* joueur, Status status)
{
    joueur->status=status;
}

/**
 * \fn Status get_status(Joueur* joueur);
 * \brief Renvoie le status du joueur
 *
 *
 * \param Joueur*: joueur dont on initialise le status
 * \return: Status: status du joueur
 */
Status get_status(Joueur* joueur)
{
    return joueur->status;
}
/**
 * \fn void gain_ressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui ajoute une carte ressource dans la main du joueur
 *
 * fait gagner au joueur une ressource spécifique
 * \param  Type_ressource: le type de la ressource gagné, Joueur: la structure joueur qui gagne cette ressource
 * \return aucun
 */
void gain_ressource(TypeRessource type, Joueur* joueur)
{
    joueur->ressource[type].nb_ressource+=1;
}

/**
 * \fn void perte_ressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui fait perdre une carte ressource dans la main du joueur
 *
 * fait perdre au joueur une ressource spécifique
 * \param  Type_ressource: le type de la ressource gagné, Joueur: la structure joueur qui perd cette ressource
 * \return aucun
 */
void perte_ressource(TypeRessource type, Joueur* joueur)
{
    if (joueur->ressource[type].nb_ressource!=0)
        joueur->ressource[type].nb_ressource-=1;
}

/**
 * \fn int  get_nbressource(Type_ressource type, Joueur* joueur)
 * \brief Fonction qui retourne les ressources possédées par le joueur
 *
 * fonction renvoillant le nombre de ressource d'un certain type possédé par un joueur
 * \param Type_ressource: le type de la ressource dont on veut connaitre le nombre, Joueur: le joeur dont on veut connaitre le nombre de ressource
 * \return int:le nombre de la ressource du type passé en paramètre possédé par le joueur ou -1 si le joueur passé en paramètre n'est pas définie
 */
int  get_nbressource(TypeRessource type, Joueur* joueur)
{
    if (joueur==NULL)
        return -1;
    return joueur->ressource[type].nb_ressource;
}

/**
 * \fn int get_nbressource_total(Joueur* joueur)
 * \brief retourne le nombre totale de carte ressource dans la main du jouuer tout type confondu
 * \param Joueur* joueur
 * \return: int: le nombre de carte ressource
 */

int get_nbressource_total(Joueur* joueur)
{
    int i,c=0;
    for (i=0;i<=4;++i)
    {
        c+= joueur->ressource[i].nb_ressource;
    }
    return c;
}


/**
 * \fn void gain_cartedev(TypeCarteDev type, Joueur* joueur)
 * \brief Fonction qui ajoute une carte developpement dans la main du joueur
 *
 * fait gagner au joueur une carte developpement spécifique
 * \param  TypeCarteDev: le type de la carte developpement gagné, Joueur: la structure joueur qui gagne cette carte
 * \return aucun
 */
void gain_cartedev(TypeCarteDev type, Joueur* joueur)
{
    joueur->carte_dev[type].nb_carte+=1;
}

/**
 * \fn void perte_cartedev(TypeCarteDev type, Joueur* joueur)
 * \brief Fonction qui enlève une carte developpement dans la main du joueur
 *
 * fait gagner au joueur une carte developpement spécifique
 * \param  TypeCarteDev: le type de la carte developpement gagné, Joueur: la structure joueur qui gagne cette carte
 * \return aucun
 */
void perte_cartedev(TypeCarteDev type, Joueur* joueur)
{
    if (joueur->carte_dev[type].nb_carte!=0)
        joueur->carte_dev[type].nb_carte-=1;

}

/**
 * \fn int  get_nbcartedev(TypeCarteDev type, Joueur* joueur)
 * \brief Fonction qui retourne les cartes developpemnts possédées par le joueur
 *
 * fonction renvoillant le nombre de carte developpement d'un certain type possédé par un joueur
 * \param TypeCarteDev: le type de la carte developpemnt dont on veut connaitre le nombre, Joueur: le joeur dont on veut connaitre le nombre de carte developpment
 * \return int:le nombre de la carte developpement du type passé en paramètre possédé par le joueur ou -1 si le joueur passé en paramètre n'est pas définie
 */

int  get_cartedev(TypeCarteDev type, Joueur* joueur)
{
    if (joueur==NULL)
        return -1;

    return joueur->carte_dev[type].nb_carte;
}

/**
 * \fn int  get_nbChevalier(Joueur* joueur)
 * \brief Fonction qui retourne le nombre de chevalier activés par un joueur
 *
 * \param Joueur: le joeur dont on veut connaitre le nombre de chevalier activés
 * \return int:le nombre de chevalier activés ou -1 si le joueur passé en paramètre n'est pas définie
 */

int  get_nbChevalier (Joueur* joueur)
{
    if (joueur==NULL)
        return -1;

    return joueur->nbChevalier;
}


/**
 * \fn int achat_route(Joueur* joueur);
 * \brief teste si le joueur à sufisament de ressource pour construire une route
 *consome les ressource si c'est le cas.
 * \param Joueur* joueur
 * \return: int: -1 le joueur n'as pas suffisement de ressource, 0 tout c'est bien passé
 */
int achat_route(Joueur* joueur)
{
    if (get_nbressource(ARGILE,joueur)>=1 && get_nbressource(BOIS,joueur)>=1)
        {
            perte_ressource(ARGILE,joueur);
            perte_ressource(BOIS, joueur);
            return 0;
        }
    return -1;
}


/**
 * \fn int achat_colonie(Joueur* joueur);
 * \brief teste si le joueur à sufisament de ressource pour construire une colonie
 *consome les ressource si c'est le cas.
 * \param Joueur* joueur
 * \return: int: -1 le joueur n'as pas suffisement de ressource, 0 tout c'est bien passé
 */
int achat_colonie(Joueur* joueur)
{
    if (get_nbressource(ARGILE,joueur)>=1 && get_nbressource(BOIS,joueur)>=1 && get_nbressource(MOUTON,joueur)>=1 && get_nbressource(BLE,joueur)>=1)
        {
            perte_ressource(ARGILE,joueur);
            perte_ressource(BOIS, joueur);
            perte_ressource(MOUTON, joueur);
            perte_ressource(BLE, joueur);
            return 0;
        }
    return -1;
}

/**
 * \fn int achat_ville(Joueur* joueur);
 * \brief teste si le joueur à sufisament de ressource pour construire une ville
 *consome les ressource si c'est le cas.
 * \param Joueur* joueur
 * \return: int: -1 le joueur n'as pas suffisement de ressource, 0 tout c'est bien passé
 */
int achat_ville(Joueur* joueur)
{
    if (get_nbressource(PIERRE,joueur)>=3 && get_nbressource(BLE,joueur)>=2)
        {
            perte_ressource(PIERRE,joueur);
            perte_ressource(PIERRE,joueur);
            perte_ressource(PIERRE,joueur);
            perte_ressource(BLE, joueur);
            perte_ressource(BLE, joueur);
            return 0;
        }
    return -1;
}
/**
 * \fn int achat_cartedev(Joueur* joueur);
 * \brief teste si le joueur à sufisament de ressource pour acheter une cartedev
 *consome les ressource si c'est le cas.
 * \param Joueur* joueur
 * \return: int: -1 le joueur n'as pas suffisement de ressource, 0 tout c'est bien passé
 */
int achat_cartedev(Joueur* joueur)
{
    if (get_nbressource(PIERRE,joueur)>=1 && get_nbressource(MOUTON,joueur)>=1 && get_nbressource(BLE,joueur)>=1)
        {
            perte_ressource(PIERRE,joueur);
            perte_ressource(BLE, joueur);
            perte_ressource(MOUTON, joueur);
            return 0;
        }
    return -1;
}

int voleur_perte_ressource(Joueur* joueur){

    int i,nbCartePerdues;
    int proba_ble,proba_bois,proba_pierre,proba_mouton,proba_argile;


    srand(time(NULL));
    int rand_val;
    if(get_nbressource_total(joueur)>7){


        nbCartePerdues=get_nbressource_total(joueur)/2;
        for(i=0;i<nbCartePerdues;++i){


            rand_val=rand()%100;
            proba_ble=(get_nbressource(BLE,joueur)*100)/get_nbressource_total(joueur);
            proba_bois=(get_nbressource(BOIS,joueur)*100)/get_nbressource_total(joueur);
            proba_pierre=(get_nbressource(PIERRE,joueur)*100)/get_nbressource_total(joueur);
            proba_argile=(get_nbressource(ARGILE,joueur)*100)/get_nbressource_total(joueur);
            proba_mouton=(get_nbressource(MOUTON,joueur)*100)/get_nbressource_total(joueur);

            if (rand_val<= proba_ble)
                perte_ressource(BLE,joueur);

            if(proba_ble<rand_val && rand_val<=(proba_ble+proba_bois))
                perte_ressource(BOIS,joueur);

            if((proba_ble+proba_bois)<rand_val && rand_val<=(proba_ble+proba_bois+proba_pierre))
                perte_ressource(PIERRE,joueur);

            if((proba_ble+proba_bois+proba_pierre)<rand_val && rand_val<=(proba_ble+proba_bois+proba_pierre+proba_argile))
                perte_ressource(ARGILE,joueur);

            if ((proba_ble+proba_bois+proba_pierre+proba_argile)<rand_val && rand_val<=(proba_ble+proba_bois+proba_pierre+proba_argile+proba_mouton))
                perte_ressource(MOUTON,joueur);
            }

    return 0;
    }
    return -1;
}

