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
#include <string.h>
#include <SDL.h>

#include "controller_turn_events.h"
#include "controller_path.h"
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
* \fn void controllerPlaceUrb(SDL_bool program_launched, SDL_Renderer* renderer, Game* the_game)
* \brief Fonction principale du contrôleur du placement d'une route.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du placement d'une route.
* Elle détecte les actions du joueur et fait appel aux fonctions de callback en fonction de ces actions.
*
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on sort de la fonction et on quitte le programme.
* \param[in,out] placing_launched Etat du placement : si devient SDL_False, on sort de la fonction.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
*/
/**
* \fn void placeRoadEvent(SDL_bool* placing_launched, Game* the_game, double x, double y, int position)
* \brief Evénement de placement d'une route.
*
* Fait appel à la fonction du modèle setRoute pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* L'emplacement est un chemin dont les coordonnées sont passées en paramètre.
* Si le placement réussit, quitte l'environnement "Placement d'une route".
*
* \param[in,out] program_launched Ponteur vers l'état du pplacement.
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in] x Abscisse de l'hexagone où placer la route.
* \param[in] y Ordonnée de l'hexagone où placer la route.
* \param[in] position Position du chemin dans l'hexagone où placer la route.
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
* \fn void controllerPlaceUrb(SDL_bool* program_launched, SDL_Renderer* renderer, Game* the_game, UrbPlacing urb_placing)
* \brief Fonction principale du contrôleur du placement d'une colonie/ville.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du placement d'une colonie ou d'une ville.
* Elle détecte les actions du joueur et fait appel aux fonctions de callback en fonction de ces actions.
*
* \param[in,out] program_launched Pointeur vers l'état du programme : si devient SDL_False, on sort de la fonction et on quitte le programme.
* \param[in,out] placing_launched Etat du placement : si devient SDL_False, on sort de la fonction.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
* \param[in] urb_placing Placement d'une colonie ou d'une ville.
*/
/**
* \fn void placeUrbEvent(SDL_bool* placing_launched, Game* the_game, double x, double y, int position, UrbPlacing urb_placing)
* \brief Evénement de placement d'une colonie ou d'une ville.
*
* Fait appel à la fonction du modèle setColonie ou setVille en fonction du type de craft passé en paramètre
* pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
* L'emplacement est un croisement dont les coordonnées sont passées en paramètre.
* Si le placement réussit, quitte l'environnement "Placement d'une colonie ou d'une ville".
*
* \param[in,out] placing_launched Ponteur vers l'état du pplacement.
* \param[in,out] the_game Pointeur vers l'état de la partie.
* \param[in] x Abscisse de l'hexagone où placer la colonie/ville.
* \param[in] y Ordonnée de l'hexagone où placer la colonie/ville.
* \param[in] position Position du croisement dans l'hexagone où placer la colonie/ville.
* \param[in] urb_placing Placement d'une colonie ou d'une ville.
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
* \fn void controllerPlaceUrb(SDL_bool* program_launched, SDL_Renderer* renderer, Game* the_game, UrbPlacing urb_placing)
* \brief Fonction principale du contrôleur du placement d'une colonie/ville.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du placement d'une colonie ou d'une ville.
* Elle détecte les actions du joueur et fait appel aux fonctions de callback en fonction de ces actions.
*
* \param[in,out] program_launched Pointeur vers l'état du programme : si devient SDL_False, on sort de la fonction et on quitte le programme.
* \param[in,out] placing_launched Etat du placement : si devient SDL_False, on sort de la fonction.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
* \param[in] urb_placing Placement d'une colonie ou d'une ville.
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
* \fn void useMonopEvent(Game* the_game)
* \brief Evénement d'utilisation de carte développement Monopole.
*
* Fait appel à la fonction du modèle utiliser_monopole pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void useMonopEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;

    ResourceButton resource_clicked = NO_RESOURCEBUTTON;

    controllerResource(&resource_clicked, renderer, program_launched);
    if(*program_launched == SDL_FALSE)
        return;

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
* Fait appel à la fonction du modèle utiliser_decouverte pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
*/
void useInventEvent(/*Game* the_game, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_Event ev;
    ResourceButton resource_clicked1 = NO_RESOURCEBUTTON;
    ResourceButton resource_clicked2 = NO_RESOURCEBUTTON;

    controllerResource(&resource_clicked1, renderer, program_launched);
    if(*program_launched == SDL_FALSE)
        return;

    controllerResource(&resource_clicked2, renderer, program_launched);
    if(*program_launched == SDL_FALSE)
        return;

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
* Fait appel à la fonction du modèle  pour modifier l'état du jeu et crée un événement pour mettre à jour la vue.
*
* \param[in,out] the_game Pointeur vers l'état de la partie.
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
