/**
* \file controller_turn_events.c
* \brief
* \author Titouan Gaborit
* \date 4 mai 2019
*
*
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

/**
* \fn void craftDevEvent(Partie* the_game)
* \brief Evénement de craft d'une carte développement.
*
* Fait appel à la fonction du modèle obtenir_cartedev pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void craftDevEvent(Partie* the_game)
{
    SDL_Event ev;
    printf("Appel de la fonction du modèle obtenir_cartedev(the_game)\n");
    obtenir_cartedev(the_game);
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
    SDL_Event ev;
    PathButton path_clicked;
    PathCoordinates path_chosen;

    do
    {
        path_clicked = NO_PATHBUTTON;
        controllerPath(&path_clicked, window, program_launched);
        if(path_clicked == NO_PATHBUTTON || *program_launched == SDL_FALSE)
            break;

        path_chosen = pathButtonToPathCoordinates(path_clicked);
        printf("Appel de la fonction du modele setRoute(the_game, %f, %f, %d)\n", path_chosen.x, path_chosen.y, path_chosen.position);
    }
    while (setRoute(the_game, path_chosen.x, path_chosen.y, path_chosen.position) != 0);

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
    SDL_Event ev;
    CrossButton cross_clicked;
    CrossCoordinates cross_chosen;

    do
    {
        cross_clicked = NO_CROSSBUTTON;
        controllerCrossing(&cross_clicked, window, program_launched);
        if(cross_clicked == NO_CROSSBUTTON || *program_launched == SDL_FALSE)
            break;

        cross_chosen = crossButtonToCrossCoordinates(cross_clicked);
        printf("Appel de la fonction du modele setColonie(the_game, %f, %f, %d)\n", cross_chosen.x, cross_chosen.y, cross_chosen.position);
    }
    while (setColonie(the_game, cross_chosen.x, cross_chosen.y, cross_chosen.position) != 0);

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
    SDL_Event ev;
    CrossButton cross_clicked;
    CrossCoordinates cross_chosen;

    do
    {
        cross_clicked = NO_CROSSBUTTON;
        controllerCrossing(&cross_clicked, window, program_launched);
        if(cross_clicked == NO_CROSSBUTTON || *program_launched == SDL_FALSE)
            break;

        cross_chosen = crossButtonToCrossCoordinates(cross_clicked);
        printf("Appel de la fonction du modele setVille(the_game, %f, %f, %d)\n", cross_chosen.x, cross_chosen.y, cross_chosen.position);
    }
    while (setVille(the_game, cross_chosen.x, cross_chosen.y, cross_chosen.position) != 0);

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

    if(get_nbcartedev_joueuractif(CHEVALIER, the_game) == 0)
        return;

    printf("Appel de la fonction activateRobberEvent(the_game, renderer, program_launched)\n");
    activateRobberEvent(the_game, window, program_launched);

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

    if(get_nbcartedev_joueuractif(MONOPOLE, the_game) == 0)
        return;

    ResourceButton resource_clicked = NO_RESOURCEBUTTON;
    do
    {
    controllerResource(&resource_clicked, window, program_launched);
    if(*program_launched == SDL_FALSE)
        return;
    }
    while(resource_clicked == NO_RESOURCEBUTTON);

    TypeRessource resource_chosen = resourceButtonToTypeRessource(resource_clicked);
    printf("Appel de la fonction du modele utiliser_monopole(the_game, %d)\n", resource_chosen);
    utiliser_monopole(the_game, resource_chosen);

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

    if(get_nbcartedev_joueuractif(DECOUVERTE, the_game) == 0)
        return;

    ResourceButton resource_clicked1 = NO_RESOURCEBUTTON;
    ResourceButton resource_clicked2 = NO_RESOURCEBUTTON;

    do
    {
        controllerResource(&resource_clicked1, window, program_launched);
        if(*program_launched == SDL_FALSE)
            return;
    }
    while(resource_clicked1 == NO_RESOURCEBUTTON);

    do
    {
        controllerResource(&resource_clicked2, window, program_launched);
        if(*program_launched == SDL_FALSE)
            return;
    }
    while(resource_clicked2 == NO_RESOURCEBUTTON);

    TypeRessource resource_chosen1 = resourceButtonToTypeRessource(resource_clicked1);
    TypeRessource resource_chosen2 = resourceButtonToTypeRessource(resource_clicked2);
    printf("Appel de la fonction du modele utiliser_decouverte(the_game, %d, %d)\n", resource_chosen1, resource_chosen2);
    utiliser_decouverte(the_game, resource_chosen1, resource_chosen2);

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

    if(get_nbcartedev_joueuractif(ROUTES, the_game) == 0)
        return;

    PathCoordinates path_chosen1;
    PathCoordinates path_chosen2;

    do
    {
        PathButton path_clicked1 = NO_PATHBUTTON;
        PathButton path_clicked2 = NO_PATHBUTTON;

        do
        {
            controllerPath(&path_clicked1, window, program_launched);
            if(*program_launched == SDL_FALSE)
                return;
        }
        while(path_clicked1 == NO_PATHBUTTON);

        do
        {
            controllerPath(&path_clicked2, window, program_launched);
            if(*program_launched == SDL_FALSE)
                return;
        }
        while(path_clicked2 == NO_PATHBUTTON);

        path_chosen1 = pathButtonToPathCoordinates(path_clicked1);
        path_chosen2 = pathButtonToPathCoordinates(path_clicked2);

        printf("Appel de la fonction du modele utiliserRoutes(the_game, %f, %f, %f, %f, %d, %d)\n", path_chosen1.x, path_chosen1.y,
        path_chosen2.x, path_chosen2.y,path_chosen1.position, path_chosen2.position);
    }
    while (utiliser_routes(the_game, path_chosen1.x, path_chosen1.y, path_chosen2.x, path_chosen2.y,path_chosen1.position, path_chosen2.position) != 0);

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
void useUnivEvent(Partie* the_game)
{
    SDL_Event ev;

    if(get_nbcartedev_joueuractif(POINT, the_game) == 0)
        return;

    printf("Appel de la fonction du modèle utiliser_point(the_game)\n");
    utiliser_point(the_game);
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

    printf("Appel de la fonction du modèle lancer_des()\n");
    int des = lancer_des();
    if(des == 7)
    {
        printf("Appel de la fonction activateRobberEvent(the_game, renderer, program_launched)\n");
        activateRobberEvent(the_game, window, program_launched);
    }
    gagne_ressource(des, the_game);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void endTurnEvent(Partie* the_game)
* \brief Evénement de fin de tour du joueur.
*
* Fait appel à la fonction du modèle passer_tour pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void endTurnEvent(Partie* the_game)
{
    SDL_Event ev;
    printf("Appel de la fonction du modèle passer_tour(the_game)\n");
    //passer_tour(the_game);
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void activateRobberEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
* \brief Evénement d'activation du brigand.
*
* Demande au joueur de sélectionner un terrain où déplacer le brigand, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setVoleur pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void activateRobberEvent(Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_Event ev;
    TerrButton terr_clicked = NO_TERRBUTTON;
    PlayerButton player_clicked = NO_PLAYERBUTTON;

    do
    {
        controllerTerrain(&terr_clicked, window, program_launched);
        if(*program_launched == SDL_FALSE)
            return;
    }
    while(terr_clicked == NO_TERRBUTTON);

    TerrCoordinates terr_chosen = terrButtonToTerrCoordinates(terr_clicked);
    printf("Appel de la fonction du modele setVoleur(the_game, %f, %f)\n", terr_chosen.x, terr_chosen.y);
    setVoleur(the_game, terr_chosen.x, terr_chosen.y);

    do
    {
        controllerPlayer(&player_clicked, the_game, window, program_launched);
        if(*program_launched == SDL_FALSE)
            return;
    }
    while(player_clicked == NO_PLAYERBUTTON);

    int player_chosen = playerButtonToInteger(player_clicked);
    printf("Appel de la fonction du modele volVoleur(the_game, %d)\n", player_chosen);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}
