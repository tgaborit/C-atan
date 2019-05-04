/**
* \file controller_place_road.c
* \brief Fonctions du contrôleur du placement d'une route
* \author Titouan Gaborit
* \date 1 mai 2019
*
* Programme gérant les actions du joueur lors du placement d'une route : le choix du chemin sur lequel elle sera construite.
*
*/

#include <SDL.h>

#include "controller.h"
#include "controller_place_road.h"
#include "controller_place_road_buttons.h"

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
void controllerPlaceRoad(SDL_bool* program_launched, SDL_Renderer* renderer/*, Game* the_game*/)
{
    SDL_bool placing_launched = SDL_TRUE;
    SDL_Event ev;
    initButtonsPlaceRoad();
    while(*program_launched && placing_launched)
    {
        drawButtonsPlaceRoad(renderer);
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN :
                controllerPlaceRoadButton(event.button, &placing_launched/*, the_game*/);
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_BACKSPACE :
                    printf("Appui sur touche Retour arriere\n");
                    printf("Appel de la fonction quit(&placing_launched)\n");
                    quit(&placing_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
                printf("Appel de la fonction quit(program_launched)\n");
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
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
void controllerPlaceRoadButton(SDL_MouseButtonEvent mouse_button, SDL_bool* placing_launched/*, Game* the_game*/)
{
    PathButton button_clicked  = whichButtonPlaceRoad(mouse_button);
    printf("Clic sur bouton n°%d\n", button_clicked);
    switch(button_clicked)
    {
    case PATHXX0_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 0, 2);
        break;

    case PATHXX1_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 0, 3);
        break;

    case PATHXX2_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 0, 4);
        break;

    case PATHXX3_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 0, 5);
        break;

    case PATHXX4_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 0, 0);
        break;

    case PATHXX5_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 0, 1);
        break;


    case PATHX0X_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0.5, 1, 2);
        break;

    case PATHX1X_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1, 0, 3);
        break;

    case PATHX2X_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0.5, -1, 4);
        break;

    case PATHX3X_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -0.5, -1, 5);
        break;

    case PATHX4X_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1, 0, 0);
        break;

    case PATHX5X_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -0.5, 1, 1);
        break;


    case PATH0XX_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1, 2, 2);
        break;

    case PATH1XX_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 2, 0, 3);
        break;

    case PATH2XX_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1, -2, 4);
        break;

    case PATH3XX_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1, -2, 5);
        break;

    case PATH4XX_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -2, 0, 0);
        break;

    case PATH5XX_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1, 2, 1);
        break;


    case PATHNN0_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 2, 2);
        break;

    case PATHNN1_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 2, 3);
        break;

    case PATHNN2_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 2, 4);
        break;

    case PATHNN3_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 2, 5);
        break;

    case PATHNN4_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 2, 0);
        break;

    case PATHNN5_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, 2, 1);
        break;


    case PATHNE0_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, 1, 2);
        break;

    case PATHNE1_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, 1, 3);
        break;

    case PATHNE2_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, 1, 4);
        break;

    case PATHNE3_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, 1, 5);
        break;

    case PATHNE4_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, 1, 0);
        break;

    case PATHNE5_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, 1, 1);
        break;


    case PATHSE0_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, -1, 2);
        break;

    case PATHSE1_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, -1, 3);
        break;

    case PATHSE2_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, -1, 4);
        break;

    case PATHSE3_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, -1, 5);
        break;

    case PATHSE4_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, -1, 0);
        break;

    case PATHSE5_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1.5, -1, 1);
        break;


    case PATHSS0_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, -2, 2);
        break;

    case PATHSS1_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, -2, 3);
        break;

    case PATHSS2_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, -2, 4);
        break;

    case PATHSS3_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, -2, 5);
        break;

    case PATHSS4_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, -2, 0);
        break;

    case PATHSS5_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0, -2, 1);
        break;


    case PATHSW0_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, -1, 2);
        break;

    case PATHSW1_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, -1, 3);
        break;

    case PATHSW2_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, -1, 4);
        break;

    case PATHSW3_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, -1, 5);
        break;

    case PATHSW4_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, -1, 0);
        break;

    case PATHSW5_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, -1, 1);
        break;


    case PATHNW0_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, 1, 2);
        break;

    case PATHNW1_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, 1, 3);
        break;

    case PATHNW2_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, 1, 4);
        break;

    case PATHNW3_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, 1, 5);
        break;

    case PATHNW4_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, 1, 0);
        break;

    case PATHNW5_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1.5, 1, 1);
        break;


    case PATHST0_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0.5, 1, 0);
        break;

    case PATHST1_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1, 0, 1);
        break;

    case PATHST2_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 0.5, 1, 2);
        break;

    case PATHST3_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -0.5, 1, 3);
        break;

    case PATHST4_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1, 0, 4);
        break;

    case PATHST5_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -0.5, 1, 5);
        break;


    case PATHO00_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1, 2, 2);
        break;

    case PATHO01_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1, 2, 1);
        break;

    case PATHO10_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1, 2, 3);
        break;

    case PATHO11_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 2, 0, 2);
        break;

    case PATHO20_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 2, 0, 4);
        break;

    case PATHO21_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1, -2, 3);
        break;

    case PATHO30_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, 1, -2, 5);
        break;

    case PATHO31_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1, -2, 4);
        break;

    case PATHO40_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1, -2, 0);
        break;

    case PATHO41_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -2, 0, 5);
        break;

    case PATHO50_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -2, 0, 1);
        break;

    case PATHO51_BUTTON :
        placeRoadEvent(placing_launched/*, the_game,*/, -1, 2, 0);
        break;


    default :
        break;
    }
}

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
void placeRoadEvent(SDL_bool* placing_launched/*, Game* the_game,*/, double x, double y, int position)
{
    printf("Appel de la fonction placeRoadEvent(pplacing_launched, the_game, %f, %f, %d)\n", x, y, position);

    printf("Appel de la fonction du modele setRoute(the_game, %f, %f, %d)\n", x, y, position);
    /*
    if(setColonie(the_game, x, y, position) == 0)
    {
    */
        printf("Hypothese : setRoute(the_game, %f, %f, %d) == 1\n", x, y, position);
        printf("Appel de la fonction quit(pplacing_launched)\n");
        quit(placing_launched);
    /*
    }
    */
}
