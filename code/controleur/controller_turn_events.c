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

#include "controller_path.h"
#include "controller_resource.h"
#include "controller_turn_events.h"

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

TypeRessource resourceButtonToTypeRessource(ResourceButton resource_clicked)
{
    switch(resource_clicked)
    {
    case WOOD_BUTTON :
        return BOIS;

    case WHEAT_BUTTON :
        return BLE;

    case CLAY_BUTTON :
        return ARGILE;

    case SHEEPS_BUTTON :
        return MOUTON;

    case ROCK_BUTTON :
        return PIERRE;

    default :
        return -1;
    }
}

/**
* \fn void controllerPlaceRoadButton(SDL_MouseButtonEvent button, SDL_bool* placing_launched, Game* the_game)
* \brief Sous-fonction de controllerPlaceRoad qui traite le clic effectué.
*
* Détermine le bouton sur lequel le joueur a cliqué puis appelle l'évènement de placement d'une route sur le chemin correspondant,
* si le clic a été effectué sur un chemin.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \param[in,out] placcement Pointeur vers l'état du placement.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
*/
PathCoordinates pathButtonToPathCoordinates(PathButton path_clicked)
{
    PathCoordinates path_coordinates;
    switch(path_clicked)
    {
    case PATHXX0_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 0;
        path_coordinates.position = 2;
        break;

    case PATHXX1_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 0;
        path_coordinates.position = 3;
        break;

    case PATHXX2_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 0;
        path_coordinates.position = 4;
        break;

    case PATHXX3_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 0;
        path_coordinates.position = 5;
        break;

    case PATHXX4_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 0;
        path_coordinates.position = 0;
        break;

    case PATHXX5_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 0;
        path_coordinates.position = 1;
        break;


    case PATHX0X_BUTTON :
        path_coordinates.x = 0.5;
        path_coordinates.y = 1;
        path_coordinates.position = 2;
        break;

    case PATHX1X_BUTTON :
        path_coordinates.x = 1;
        path_coordinates.y = 0;
        path_coordinates.position = 3;
        break;

    case PATHX2X_BUTTON :
        path_coordinates.x = 0.5;
        path_coordinates.y = -1;
        path_coordinates.position = 4;
        break;

    case PATHX3X_BUTTON :
        path_coordinates.x = -0.5;
        path_coordinates.y = -1;
        path_coordinates.position = 5;
        break;

    case PATHX4X_BUTTON :
        path_coordinates.x = -1;
        path_coordinates.y = 0;
        path_coordinates.position = 0;
        break;

    case PATHX5X_BUTTON :
        path_coordinates.x = -0.5;
        path_coordinates.y = 1;
        path_coordinates.position = 1;
        break;


    case PATH0XX_BUTTON :
        path_coordinates.x = 1;
        path_coordinates.y = 2;
        path_coordinates.position = 2;
        break;

    case PATH1XX_BUTTON :
        path_coordinates.x = 2;
        path_coordinates.y = 0;
        path_coordinates.position = 3;
        break;

    case PATH2XX_BUTTON :
        path_coordinates.x = 1;
        path_coordinates.y = -2;
        path_coordinates.position = 4;
        break;

    case PATH3XX_BUTTON :
        path_coordinates.x = -1;
        path_coordinates.y = -2;
        path_coordinates.position = 5;
        break;

    case PATH4XX_BUTTON :
        path_coordinates.x = -2;
        path_coordinates.y = 0;
        path_coordinates.position = 0;
        break;

    case PATH5XX_BUTTON :
        path_coordinates.x = -1;
        path_coordinates.y = 2;
        path_coordinates.position = 1;
        break;


    case PATHNN0_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 2;
        path_coordinates.position = 2;
        break;

    case PATHNN1_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 2;
        path_coordinates.position = 3;
        break;

    case PATHNN2_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 2;
        path_coordinates.position = 4;
        break;

    case PATHNN3_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 2;
        path_coordinates.position = 5;
        break;

    case PATHNN4_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 2;
        path_coordinates.position = 0;
        break;

    case PATHNN5_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = 2;
        path_coordinates.position = 1;
        break;


    case PATHNE0_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 2;
        break;

    case PATHNE1_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 3;
        break;

    case PATHNE2_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 4;
        break;

    case PATHNE3_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 5;
        break;

    case PATHNE4_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 0;
        break;

    case PATHNE5_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 1;
        break;


    case PATHSE0_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 2;
        break;

    case PATHSE1_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 3;
        break;

    case PATHSE2_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 4;
        break;

    case PATHSE3_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 5;
        break;

    case PATHSE4_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 0;
        break;

    case PATHSE5_BUTTON :
        path_coordinates.x = 1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 1;
        break;


    case PATHSS0_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = -2;
        path_coordinates.position = 2;
        break;

    case PATHSS1_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = -2;
        path_coordinates.position = 3;
        break;

    case PATHSS2_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = -2;
        path_coordinates.position = 4;
        break;

    case PATHSS3_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = -2;
        path_coordinates.position = 5;
        break;

    case PATHSS4_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = -2;
        path_coordinates.position = 0;
        break;

    case PATHSS5_BUTTON :
        path_coordinates.x = 0;
        path_coordinates.y = -2;
        path_coordinates.position = 1;
        break;


    case PATHSW0_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 2;
        break;

    case PATHSW1_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 3;
        break;

    case PATHSW2_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 4;
        break;

    case PATHSW3_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 5;
        break;

    case PATHSW4_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 0;
        break;

    case PATHSW5_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = -1;
        path_coordinates.position = 1;
        break;


    case PATHNW0_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 2;
        break;

    case PATHNW1_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 3;
        break;

    case PATHNW2_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 4;
        break;

    case PATHNW3_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 5;
        break;

    case PATHNW4_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 0;
        break;

    case PATHNW5_BUTTON :
        path_coordinates.x = -1.5;
        path_coordinates.y = 1;
        path_coordinates.position = 1;
        break;


    case PATHST0_BUTTON :
        path_coordinates.x = 0.5;
        path_coordinates.y = 1;
        path_coordinates.position = 0;
        break;

    case PATHST1_BUTTON :
        path_coordinates.x = 1;
        path_coordinates.y = 0;
        path_coordinates.position = 1;
        break;

    case PATHST2_BUTTON :
        path_coordinates.x = 0.5;
        path_coordinates.y = 1;
        path_coordinates.position = 2;
        break;

    case PATHST3_BUTTON :
        path_coordinates.x = -0.5;
        path_coordinates.y = 1;
        path_coordinates.position = 3;
        break;

    case PATHST4_BUTTON :
        path_coordinates.x = -1;
        path_coordinates.y = 0;
        path_coordinates.position = 4;
        break;

    case PATHST5_BUTTON :
        path_coordinates.x = -0.5;
        path_coordinates.y = 1;
        path_coordinates.position = 5;
        break;


    case PATHO00_BUTTON :
        path_coordinates.x = -1;
        path_coordinates.y = 2;
        path_coordinates.position = 2;
        break;

    case PATHO01_BUTTON :
        path_coordinates.x = 1;
        path_coordinates.y = 2;
        path_coordinates.position = 1;
        break;

    case PATHO10_BUTTON :
        path_coordinates.x = 1;
        path_coordinates.y = 2;
        path_coordinates.position = 3;
        break;

    case PATHO11_BUTTON :
        path_coordinates.x = 2;
        path_coordinates.y = 0;
        path_coordinates.position = 2;
        break;

    case PATHO20_BUTTON :
        path_coordinates.x = 2;
        path_coordinates.y = 0;
        path_coordinates.position = 4;
        break;

    case PATHO21_BUTTON :
        path_coordinates.x = 1;
        path_coordinates.y = -2;
        path_coordinates.position = 3;
        break;

    case PATHO30_BUTTON :
        path_coordinates.x = 1;
        path_coordinates.y = -2;
        path_coordinates.position = 5;
        break;

    case PATHO31_BUTTON :
        path_coordinates.x = -1;
        path_coordinates.y = -2;
        path_coordinates.position = 4;
        break;

    case PATHO40_BUTTON :
        path_coordinates.x = -1;
        path_coordinates.y = -2;
        path_coordinates.position = 0;
        break;

    case PATHO41_BUTTON :
        path_coordinates.x = -2;
        path_coordinates.y = 0;
        path_coordinates.position = 5;
        break;

    case PATHO50_BUTTON :
        path_coordinates.x = -2;
        path_coordinates.y = 0;
        path_coordinates.position = 1;
        break;

    case PATHO51_BUTTON :
        path_coordinates.x = -1;
        path_coordinates.y = 2;
        path_coordinates.position = 0;
        break;

    default :
        path_coordinates.x = -1;
        path_coordinates.y = -1;
        path_coordinates.position = -1;
        break;
    }
    return path_coordinates;
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
