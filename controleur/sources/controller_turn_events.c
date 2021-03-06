/**
* \file controller_turn_events.c
* \brief
* \author Titouan Gaborit
* \date 4 mai 2019
*
* Programme gérant les fonctions de callback appelées lors d'un évènement particulier. Ces fonctions agissent sur le modèle.
*
*/

#include <stdio.h>
#include <SDL.h>
#include "controller_turn_events.h"
#include "controller_path.h"
#include "controller_crossing.h"
#include "controller_terrain.h"
#include "controller_resource.h"
#include "controller_player.h"
#include "converters.h"
#include "partie.h"
#include "set_plateau.h"
#include "set_partie.h"
#include "ressource.h"
#include "affiche_texte.h"
#include "fenetre.h"


/**
* \fn void craftDevEvent(Partie* the_game)
* \brief Evénement de craft d'une carte développement.
*
* Fait appel à la fonction du modèle obtenir_cartedev pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void craftDevEvent(SDL_Window* window, Partie* the_game)
{
    if(get_nbressource_joueuractif(PIERRE,the_game) < 1 || get_nbressource_joueuractif(MOUTON,the_game) < 1 || get_nbressource_joueuractif(BLE,the_game) < 1){
        AfficheTexte_NoRessource(window);
        return;
    }
    SDL_Event ev;
    if(obtenir_cartedev(the_game) == 0){
        AfficheTexte_CarteDev_Succes(window);
    }
    else{
        AfficheTexte_CarteDev_Echec(window);
    }
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void craftRoadEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
* \brief Evénement de craft d'une route.
*
* Demande au joueur de sélectionner un chemin où construire une route, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setRoute pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* Si le placement échoue, on reste dans l'environnement "Choix d'un chemin".
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void craftRoadEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    if(get_nbressource_joueuractif(ARGILE,the_game) < 1 || get_nbressource_joueuractif(BOIS,the_game) < 1){
        AfficheTexte_NoRessource(window);
        return;
    }
    SDL_Event ev;
    PathButton path_clicked;
    PathCoordinates path_chosen;
    int bool_route =0;

    do
    {
        if(bool_route == 0){
            AfficheTexte_PosRoute(window);
        }
        else{
            AfficheTexte_PosRoute_Echec(window);
        }
        path_clicked = NO_PATHBUTTON;
        controllerPath(&path_clicked, window, program_launched);
        if(path_clicked == NO_PATHBUTTON || *program_launched == SDL_FALSE){
            AfficheTexte_StopAction(window);
            break;
        }

        path_chosen = pathButtonToPathCoordinates(path_clicked);
        bool_route = setRoute(the_game, path_chosen.x, path_chosen.y, path_chosen.position);
        if(bool_route == 0){
            AfficheTexte_PosRoute_Succes(window);
        }
    }
    while (bool_route != 0);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void craftSettleEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
* \brief Evénement de craft d'une colonie.
*
* Demande au joueur de sélectionner un croisement où construire une colonie, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setColonie pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* Si le placement échoue, on reste dans l'environnement "Choix d'un croisement".
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void craftSettleEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    if(get_nbressource_joueuractif(ARGILE,the_game) < 1 || get_nbressource_joueuractif(BOIS,the_game) < 1 ||
        get_nbressource_joueuractif(MOUTON,the_game) < 1 || get_nbressource_joueuractif(BLE,the_game) < 1){
        AfficheTexte_NoRessource(window);
        return;
    }
    SDL_Event ev;
    CrossButton cross_clicked;
    CrossCoordinates cross_chosen;
    int bool_colonie = 0;

    do
    {
        if(bool_colonie == 0){
        AfficheTexte_PosColonie(window);
        }
        else{
            AfficheTexte_PosColonie_Echec(window);
        }
        cross_clicked = NO_CROSSBUTTON;
        controllerCrossing(&cross_clicked, window, program_launched);
        if(cross_clicked == NO_CROSSBUTTON || *program_launched == SDL_FALSE){
            AfficheTexte_StopAction(window);
            break;
        }

        cross_chosen = crossButtonToCrossCoordinates(cross_clicked);
        bool_colonie = setColonie(the_game, cross_chosen.x, cross_chosen.y, cross_chosen.position);
        if(bool_colonie == 0){
            AfficheTexte_PosColonie_Succes(window);
        }
    }
    while (bool_colonie != 0);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void craftCityEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
* \brief Evénement de craft d'une ville.
*
* Demande au joueur de sélectionner un croisement où construire une ville, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setVille pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* Si le placement échoue, on reste dans l'environnement "Choix d'un croisement".
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void craftCityEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    if(get_nbressource_joueuractif(PIERRE,the_game) < 3 || get_nbressource_joueuractif(BLE,the_game) < 2){
        AfficheTexte_NoRessource(window);
        return;
    }
    SDL_Event ev;
    CrossButton cross_clicked;
    CrossCoordinates cross_chosen;
    int bool_ville = 0;

    do
    {
        if(bool_ville == 0){
            AfficheTexte_PosVille(window);
        }
        else{
            AfficheTexte_PosVille_Echec(window);
        }
        cross_clicked = NO_CROSSBUTTON;
        controllerCrossing(&cross_clicked, window, program_launched);
        if(cross_clicked == NO_CROSSBUTTON || *program_launched == SDL_FALSE){
            AfficheTexte_StopAction(window);
            break;
        }

        cross_chosen = crossButtonToCrossCoordinates(cross_clicked);
        bool_ville = setVille(the_game, cross_chosen.x, cross_chosen.y, cross_chosen.position);
        if(bool_ville == 0){
            AfficheTexte_PosVille_Succes(window);
        }
    }
    while (bool_ville != 0);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useKnightEvent(Partie* the_game)
* \brief Evénement d'utilisation de carte développement Chevalier.
*
* Fait appel à la fonction à la fonction activateRobberEvent pour activer le brigand et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void useKnightEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_Event ev;

    if(get_nbcartedev_joueuractif(CHEVALIER, the_game) == 0){
        AfficheTexte_NoCarte(window);
        return;
    }

    activateRobberEvent(the_game, window, program_launched, 1);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useMonopEvent(Partie* the_game)
* \brief Evénement d'utilisation de carte développement Monopole.
*
* Demande au joueur de sélectionner une ressource pour la carte, convertit ce choix en données du modèle,
* puis fait appel à la fonction du modèle utiliser_monopole pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void useMonopEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_Event ev;

    if(get_nbcartedev_joueuractif(MONOPOLE, the_game) == 0){
        AfficheTexte_NoCarte(window);
        return;
    }

    ResourceButton resource_clicked = NO_RESOURCEBUTTON;
    AfficheTexte_ChoixRessource(window);
    do
    {
    controllerResource(&resource_clicked, window, program_launched);
    if(*program_launched == SDL_FALSE){
        AfficheTexte_StopAction(window);
        return;
    }
    }
    while(resource_clicked == NO_RESOURCEBUTTON);

    TypeRessource resource_chosen = resourceButtonToTypeRessource(resource_clicked);
    int resource_init = get_nbressource_joueuractif(resource_chosen,the_game);
    int vol = utiliser_monopole(the_game, resource_chosen);
    if(vol-resource_init > 0){
        AfficheTexte_Monopole_Succes(window, vol-resource_init);
    }
    else{
        AfficheTexte_Monopole_Echec(window);
    }

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useInventEvent(Partie* the_game)
* \brief Evénement d'utilisation de carte développement Invention.
*
* Demande au joueur de sélectionner deux ressources pour la carte, convertit ce choix en données du modèle,
* puis fait appel à la fonction du modèle utiliser_decouverte pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void useInventEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_Event ev;

    if(get_nbcartedev_joueuractif(DECOUVERTE, the_game) == 0){
        AfficheTexte_NoCarte(window);
        return;
    }

    ResourceButton resource_clicked1 = NO_RESOURCEBUTTON;
    ResourceButton resource_clicked2 = NO_RESOURCEBUTTON;
    AfficheTexte_ChoixRessource(window);

    do
    {
        controllerResource(&resource_clicked1, window, program_launched);
        if(*program_launched == SDL_FALSE){
            AfficheTexte_StopAction(window);
            return;
        }
    }
    while(resource_clicked1 == NO_RESOURCEBUTTON);

    AfficheTexte_ChoixRessource(window);

    do
    {
        controllerResource(&resource_clicked2, window, program_launched);
        if(*program_launched == SDL_FALSE){
            AfficheTexte_StopAction(window);
            return;
        }
    }
    while(resource_clicked2 == NO_RESOURCEBUTTON);

    TypeRessource resource_chosen1 = resourceButtonToTypeRessource(resource_clicked1);
    TypeRessource resource_chosen2 = resourceButtonToTypeRessource(resource_clicked2);
    utiliser_decouverte(the_game, resource_chosen1, resource_chosen2);
    AfficheTexte_Decouverte_Succes(window);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useRoadsEvent(Partie* the_game)
* \brief Evénement d'utilisation de carte développement Routes.
*
* Demande au joueur de sélectionner un chemin où placer une route, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setRoute pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* Répète l'opération deux fois.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void useRoadsEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_Event ev;
    int bool_routes = 0;

    if(get_nbcartedev_joueuractif(ROUTES, the_game) == 0){
        AfficheTexte_NoCarte(window);
        return;
    }

    PathCoordinates path_chosen1;
    PathCoordinates path_chosen2;

    do
    {
        if(bool_routes != 0){
            AfficheTexte_Routes_Echec(window);
        }
        PathButton path_clicked1 = NO_PATHBUTTON;
        PathButton path_clicked2 = NO_PATHBUTTON;

        do
        {
            AfficheTexte_PosRoute(window);

            controllerPath(&path_clicked1, window, program_launched);
            if(*program_launched == SDL_FALSE){
                AfficheTexte_StopAction(window);
                return;
            }
        }
        while(path_clicked1 == NO_PATHBUTTON);

        AfficheTexte_PosRoute(window);

        do
        {
            controllerPath(&path_clicked2, window, program_launched);
            if(*program_launched == SDL_FALSE){
                AfficheTexte_StopAction(window);
                return;
            }
        }
        while(path_clicked2 == NO_PATHBUTTON);

        path_chosen1 = pathButtonToPathCoordinates(path_clicked1);
        path_chosen2 = pathButtonToPathCoordinates(path_clicked2);

        bool_routes = utiliser_routes(the_game, path_chosen1.x, path_chosen1.y, path_chosen2.x, path_chosen2.y,path_chosen1.position, path_chosen2.position);
    }
    while (bool_routes != 0);

    AfficheTexte_Routes_Succes(window);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useUnivEvent(Partie* the_game)
* \brief Evénement d'utilisation de carte développement Université.
*
* Fait appel à la fonction du modèle utiliser_point pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void useUnivEvent(Partie* the_game, SDL_Window* window)
{
    SDL_Event ev;

    if(get_nbcartedev_joueuractif(POINT, the_game) == 0){
        AfficheTexte_NoCarte(window);
        return;
    }

    utiliser_point(the_game);
    AfficheTexte_Point_Succes(window);
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void rollDiceEvent(Partie* the_game)
* \brief Evénement de lancer des dés.
*
* Fait appel à la fonction du modèle lancer_des pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void rollDiceEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_Event ev;

    int des = lancer_des(the_game);
    if(des == 7)
    {
        activateRobberEvent(the_game, window, program_launched, 0);
        int nb_vol = action_voleur(the_game);
        AfficheTexte_nbVol(window,nb_vol);
    }
    gagne_ressource(des, the_game);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void activateRobberEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched, int bool_knight)
* \brief Evénement d'activation du brigand.
*
* Demande au joueur de sélectionner un terrain où déplacer le brigand, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setVoleur pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] bool_knight un entier, 1 si l'action est déclenchée par le chevalier, 0 sinon.
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du placement.
*/
void activateRobberEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched, int bool_knight)
{

    SDL_Event ev;
    TerrButton terr_clicked = NO_TERRBUTTON;
    PlayerButton player_clicked = NO_PLAYERBUTTON;
    AfficheTexte_ChoixTuileVoleur(window);

    updateFenetre(the_game, window);

    do
    {
        controllerTerrain(&terr_clicked, window, program_launched);
        if(*program_launched == SDL_FALSE){
            AfficheTexte_StopAction(window);
            return;
        }
    }
    while(terr_clicked == NO_TERRBUTTON);

    TerrCoordinates terr_chosen = terrButtonToTerrCoordinates(terr_clicked);
    AfficheTexte_ChoixJoueurVoler(window);

    do
    {
        controllerPlayer(&player_clicked, the_game, window, program_launched);
        if(*program_launched == SDL_FALSE){
            AfficheTexte_StopAction(window);
            return;
        }
    }
    while(player_clicked == NO_PLAYERBUTTON);

    int i;
    int player_chosen = playerButtonToInteger(player_clicked);
    Joueur* cur = get_joueur_actif(the_game);
    setOnFirst_joueur(the_game);
    for(i=1;i<player_chosen;++i){
        passer_tour(the_game);
    }
    Joueur* victime = get_joueur_actif(the_game);
    while(get_joueur_actif(the_game) != cur){
        passer_tour(the_game);
    }
    if(bool_knight == 1){
        if(utiliser_chevalier(the_game,terr_chosen.x, terr_chosen.y, victime) == 0){
            AfficheTexte_Chevalier_Succes(window);
        }
        else{
            AfficheTexte_Chevalier_Echec(window);
        }
    }
    else{
        setVoleur(the_game, terr_chosen.x, terr_chosen.y);
        if(vole_carte(the_game,terr_chosen.x,terr_chosen.y,victime) == 0){
            AfficheTexte_Chevalier_Succes(window);
        }
        else{
            AfficheTexte_Chevalier_Echec(window);
        }
    }

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}
