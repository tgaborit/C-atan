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
#include "converters.h"

/**
* \fn void craftDevEvent(Game* the_game)
* \brief Evénement de craft d'une carte développement.
*
* Fait appel à la fonction du modèle craftDev pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void craftDevEvent(/*Game* the_game*/)
{
    SDL_Event ev;
    printf("Appel de la fonction du modèle craftDev(the_game)\n");
    //craftDev(the_game);
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void craftRoadEvent(Game* the_game, SDL_Renderer* renderer, SDL_bool* program_launched)
* \brief Evénement de craft d'une route.
*
* Demande au joueur de sélectionner un chemin où construire une route, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setRoute pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* Si le placement échoue, on reste dans l'environnement "Choix d'un chemin".
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void craftRoadEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;
    PathButton path_clicked;

    do
    {
        path_clicked = NO_PATHBUTTON;
        controllerPath(&path_clicked, renderer, program_launched);
        if(path_clicked == NO_PATHBUTTON || *program_launched == SDL_FALSE)
            return;

        PathCoordinates path_chosen = pathButtonToPathCoordinates(path_clicked);
        printf("Appel de la fonction du modele setRoute(the_game, %f, %f, %d)\n", path_chosen.x, path_chosen.y, path_chosen.position);
        printf("Hypothese : setRoute(the_game, %f, %f, %d) == 0\n", path_chosen.x, path_chosen.y, path_chosen.position);
    }
    while (/*set_route(the_game, path_chosen.x, path_chosen.y, path_chosen.position)*/0 != 0);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void craftSettleEvent(Game* the_game, SDL_Renderer* renderer, SDL_bool* program_launched)
* \brief Evénement de craft d'une colonie.
*
* Demande au joueur de sélectionner un croisement où construire une colonie, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setColonie pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* Si le placement échoue, on reste dans l'environnement "Choix d'un croisement".
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void craftSettleEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;
    CrossButton cross_clicked;

    do
    {
        cross_clicked = NO_PATHBUTTON;
        controllerCrossing(&cross_clicked, renderer, program_launched);
        if(cross_clicked == NO_CROSSBUTTON || *program_launched == SDL_FALSE)
            return;

        CrossCoordinates cross_chosen = crossButtonToCrossCoordinates(cross_clicked);
        printf("Appel de la fonction du modele setColonie(the_game, %f, %f, %d)\n", cross_chosen.x, cross_chosen.y, cross_chosen.position);
        printf("Hypothese : setColonie(the_game, %f, %f, %d) == 0\n", cross_chosen.x, cross_chosen.y, cross_chosen.position);
    }
    while (/*set_colonie(the_game, cross_chosen.x, cross_chosen.y, cross_chosen.position)*/0 != 0);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void craftCityEvent(Game* the_game, SDL_Renderer* renderer, SDL_bool* program_launched)
* \brief Evénement de craft d'une ville.
*
* Demande au joueur de sélectionner un croisement où construire une ville, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setVille pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* Si le placement échoue, on reste dans l'environnement "Choix d'un croisement".
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void craftCityEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;
    CrossButton cross_clicked;

    do
    {
        cross_clicked = NO_PATHBUTTON;
        controllerCrossing(&cross_clicked, renderer, program_launched);
        if(cross_clicked == NO_CROSSBUTTON || *program_launched == SDL_FALSE)
            return;

        CrossCoordinates cross_chosen = crossButtonToCrossCoordinates(cross_clicked);
        printf("Appel de la fonction du modele setVille(the_game, %f, %f, %d)\n", cross_chosen.x, cross_chosen.y, cross_chosen.position);
        printf("Hypothese : setVille(the_game, %f, %f, %d) == 0\n", cross_chosen.x, cross_chosen.y, cross_chosen.position);
    }
    while (/*set_ville(the_game, cross_chosen.x, cross_chosen.y, cross_chosen.position)*/0 != 0);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useKnightEvent(Game* the_game)
* \brief Evénement d'utilisation de carte développement Chevalier.
*
* Fait appel à la fonction à la fonction activateRobberEvent pour activer le brigand et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void useKnightEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;

    printf("Appel de la fonction activateRobberEvent(the_game, renderer, program_launched)\n");
    activateRobberEvent(/*the_game, */renderer, program_launched);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useMonopEvent(Game* the_game)
* \brief Evénement d'utilisation de carte développement Monopole.
*
* Demande au joueur de sélectionner une ressource pour la carte, convertit ce choix en données du modèle,
* puis fait appel à la fonction du modèle utiliser_monopole pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void useMonopEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;
    ResourceButton resource_clicked = NO_RESOURCEBUTTON;

    do
    {
    controllerResource(&resource_clicked, renderer, program_launched);
    if(*program_launched == SDL_FALSE)
        return;
    }
    while(resource_clicked == NO_RESOURCEBUTTON);

    TypeRessource resource_chosen = resourceButtonToTypeRessource(resource_clicked);
    printf("Appel de la fonction du modele utiliser_monopole(the_game, %d)\n", resource_chosen);
    //utiliser_monopole(the_game, resource_chosen);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useInventEvent(Game* the_game)
* \brief Evénement d'utilisation de carte développement Invention.
*
* Demande au joueur de sélectionner deux ressources pour la carte, convertit ce choix en données du modèle,
* puis fait appel à la fonction du modèle utiliser_decouverte pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void useInventEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;
    ResourceButton resource_clicked1 = NO_RESOURCEBUTTON;
    ResourceButton resource_clicked2 = NO_RESOURCEBUTTON;

    do
    {
        controllerResource(&resource_clicked1, renderer, program_launched);
        if(*program_launched == SDL_FALSE)
            return;
    }
    while(resource_clicked1 == NO_RESOURCEBUTTON);

    do
    {
    controllerResource(&resource_clicked2, renderer, program_launched);
    if(*program_launched == SDL_FALSE)
        return;
    }
    while(resource_clicked2 == NO_RESOURCEBUTTON);

    TypeRessource resource_chosen1 = resourceButtonToTypeRessource(resource_clicked1);
    TypeRessource resource_chosen2 = resourceButtonToTypeRessource(resource_clicked2);
    printf("Appel de la fonction du modele utiliser_decouverte(the_game, %d, %d)\n", resource_chosen1, resource_chosen2);
    //utiliser_decouverte(the_game, resource_chosen1, resource_chosen2);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useRoadsEvent(Game* the_game)
* \brief Evénement d'utilisation de carte développement Routes.
*
* Demande au joueur de sélectionner un chemin où placer une route, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle setRoute pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* Répète l'opération deux fois.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void useRoadsEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;
    PathButton path_clicked;
    int i;

    for(i=0; i<2; ++i)
    {
        do
        {
            path_clicked = NO_PATHBUTTON;
            controllerPath(&path_clicked, renderer, program_launched);
            if(*program_launched == SDL_FALSE)
                return;

            PathCoordinates path_chosen = pathButtonToPathCoordinates(path_clicked);
            printf("Appel de la fonction du modele setRouteGratuite(the_game, %f, %f, %d)\n", path_chosen.x, path_chosen.y, path_chosen.position);
            printf("Hypothese : setRoute(the_game, %f, %f, %d) == 0\n", path_chosen.x, path_chosen.y, path_chosen.position);
        }
        while (/*set_route(the_game, path_chosen.x, path_chosen.y, path_chosen.position)*/0 != 0 || path_clicked == NO_PATHBUTTON);
    }

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void useUnivEvent(Game* the_game)
* \brief Evénement d'utilisation de carte développement Université.
*
* Fait appel à la fonction du modèle utiliser_point pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void useUnivEvent(/*Game* the_game*/)
{
    SDL_Event ev;
    printf("Appel de la fonction du modèle utiliser_point(the_game)\n");
    //utiliser_point(the_game);
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void rollDiceEvent(Game* the_game)
* \brief Evénement de lancer des dés.
*
* Fait appel à la fonction du modèle rollDice pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void rollDiceEvent(/*Game* the_game*/)
{
    SDL_Event ev;
    printf("Appel de la fonction du modèle rollDice(the_game)\n");
    //rollDice(the_game);
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void endTurnEvent(Game* the_game)
* \brief Evénement de fin de tour du joueur.
*
* Fait appel à la fonction du modèle endTurn pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void endTurnEvent(/*Game* the_game*/)
{
    SDL_Event ev;
    printf("Appel de la fonction du modèle endTurn(the_game)\n");
    //endTurn(the_game);
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}

/**
* \fn void activateRobberEvent(Game* the_game, SDL_Renderer* renderer, SDL_bool* program_launched)
* \brief Evénement d'activation du brigand.
*
* Demande au joueur de sélectionner un terrain où déplacer le brigand, convertit cet emplacement en données du modèle,
* puis fait appel à la fonction du modèle set_voleur pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
*/
void activateRobberEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;
    TerrButton terr_clicked = NO_TERRBUTTON;

    do
    {
        controllerTerrain(&terr_clicked, renderer, program_launched);
        if(*program_launched == SDL_FALSE)
            return;
    }
    while(terr_clicked == NO_TERRBUTTON);

    TerrCoordinates terr_chosen = terrButtonToTerrCoordinates(terr_clicked);
    printf("Appel de la fonction du modele set_voleur(the_game, %f, %f)\n", terr_chosen.x, terr_chosen.y);
    //set_voleur(the_game, terr_chosen.x, terr_chosen.y);

    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
}
