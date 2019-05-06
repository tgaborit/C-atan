/**
* \file converters.c
* \brief
* \author Titouan Gaborit
* \date 6 mai 2019
*
*
*
*/

#include "converters.h"
#include "controller_resource.h"
#include "controller_path.h"

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
