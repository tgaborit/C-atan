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

/**
* \fn PathCoordinates pathButtonToPathCoordinates(PathButton path_clicked)
* \brief Fonction de conversion de bouton de chemin vers les coordonnées du modèle.
*
* Remplit les champs d'une structure de coordonnées de chemin en fonction du bouton de chemin passé en paramètre.
*
* \param[in] path_clicked Bouton de chemin qui a été cliqué par le joueur.
* \return Une structure PathCoordinates contenant les coordonnées du modèle corrsepondant au bouton de chemin cliqué.
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
* \fn void controllerPlaceUrbButton(SDL_MouseButtonEvent button, SDL_bool* placing_launched, Game* the_game, UrbPlacing urb_placing)
* \brief Sous-fonction de controllerPlaceUrb qui traite le clic effectué.
*
* Détermine le bouton sur lequel le joueur a cliqué puis appelle l'évènement de placement d'une colonie/ville sur le croisement correspondant,
* si le clic a été effectué sur un croisement.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \param[in,out] placcement Pointeur vers l'état du placement.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
* \param[in] urb_placing Placement d'une colonie ou d'une ville.
*/
/**
* \fn CrossCoordinates crossButtonToCrossCoordinates(CrossButton cross_clicked)
* \brief Fonction de conversion de bouton de croisement vers les coordonnées du modèle.
*
* Remplit les champs d'une structure de coordonnées de croisement en fonction du bouton de croisement passé en paramètre.
*
* \param[in] cross_clicked Bouton de croisement qui a été cliqué par le joueur.
* \return Une structure CrossCoordinates contenant les coordonnées du modèle corrsepondant au bouton de croisement cliqué.
*/
CrossCoordinates crossButtonToCrossCoordinates(CrossButton cross_clicked)
{
    CrossCoordinates cross_coordinates;
    switch(cross_clicked)
    {
    case CROSSXX0_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = 0;
        cross_coordinates.position = 1;
        break;

    case CROSSXX1_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = 0;
        cross_coordinates.position = 2;
        break;

    case CROSSXX2_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = 0;
        cross_coordinates.position = 3;
        break;

    case CROSSXX3_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = 0;
        cross_coordinates.position = 4;
        break;

    case CROSSXX4_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = 0;
        cross_coordinates.position = 5;
        break;

    case CROSSXX5_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = 0;
        cross_coordinates.position = 0;
        break;


    case CROSSX0X_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = 2;
        cross_coordinates.position = 4;
        break;

    case CROSSX1X_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = 0;
        cross_coordinates.position = 1;
        break;

    case CROSSX2X_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = 0;
        cross_coordinates.position = 4;
        break;

    case CROSSX3X_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = -2;
        cross_coordinates.position = 1;
        break;

    case CROSSX4X_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = 0;
        cross_coordinates.position = 4;
        break;

    case CROSSX5X_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = 0;
        cross_coordinates.position = 1;
        break;


    case CROSS0XX_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = 2;
        cross_coordinates.position = 1;
        break;

    case CROSS1XX_BUTTON :
        cross_coordinates.x = 1.5;
        cross_coordinates.y = 1;
        cross_coordinates.position = 2;
        break;

    case CROSS2XX_BUTTON :
        cross_coordinates.x = 1.5;
        cross_coordinates.y = -1;
        cross_coordinates.position = 3;
        break;

    case CROSS3XX_BUTTON :
        cross_coordinates.x = 0;
        cross_coordinates.y = -2;
        cross_coordinates.position = 4;
        break;

    case CROSS4XX_BUTTON :
        cross_coordinates.x = -1.5;
        cross_coordinates.y = -1;
        cross_coordinates.position = 5;
        break;

    case CROSS5XX_BUTTON :
        cross_coordinates.x = -1.5;
        cross_coordinates.y = 1;
        cross_coordinates.position = 0;
        break;


    case CROSSNE0_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 1;
        break;

    case CROSSNE1_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 2;
        break;

    case CROSSNE2_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 3;
        break;

    case CROSSNE3_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 4;
        break;

    case CROSSNE4_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 5;
        break;

    case CROSSNE5_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 0;
        break;


    case CROSSEE0_BUTTON :
        cross_coordinates.x = 2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 1;
        break;

    case CROSSEE1_BUTTON :
        cross_coordinates.x = 2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 2;
        break;

    case CROSSEE2_BUTTON :
        cross_coordinates.x = 2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 3;
        break;

    case CROSSEE3_BUTTON :
        cross_coordinates.x = 2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 4;
        break;

    case CROSSEE4_BUTTON :
        cross_coordinates.x = 2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 5;
        break;

    case CROSSEE5_BUTTON :
        cross_coordinates.x = 2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 0;
        break;


    case CROSSSE0_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 1;
        break;

    case CROSSSE1_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 2;
        break;

    case CROSSSE2_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 3;
        break;

    case CROSSSE3_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 4;
        break;

    case CROSSSE4_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 5;
        break;

    case CROSSSE5_BUTTON :
        cross_coordinates.x = 1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 0;
        break;


    case CROSSSW0_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 1;
        break;

    case CROSSSW1_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 2;
        break;

    case CROSSSW2_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 3;
        break;

    case CROSSSW3_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 4;
        break;

    case CROSSSW4_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 5;
        break;

    case CROSSSW5_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = -2;
        cross_coordinates.position = 0;
        break;


    case CROSSWW0_BUTTON :
        cross_coordinates.x = -2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 1;
        break;

    case CROSSWW1_BUTTON :
        cross_coordinates.x = -2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 2;
        break;

    case CROSSWW2_BUTTON :
        cross_coordinates.x = -2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 3;
        break;

    case CROSSWW3_BUTTON :
        cross_coordinates.x = -2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 4;
        break;

    case CROSSWW4_BUTTON :
        cross_coordinates.x = -2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 5;
        break;

    case CROSSWW5_BUTTON :
        cross_coordinates.x = -2;
        cross_coordinates.y = 0;
        cross_coordinates.position = 0;
        break;


    case CROSSNW0_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 1;
        break;

    case CROSSNW1_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 2;
        break;

    case CROSSNW2_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 3;
        break;

    case CROSSNW3_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 4;
        break;

    case CROSSNW4_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 5;
        break;

    case CROSSNW5_BUTTON :
        cross_coordinates.x = -1;
        cross_coordinates.y = 2;
        cross_coordinates.position = 0;
        break;


    default :
        cross_coordinates.x = -1;
        cross_coordinates.y = -1;
        cross_coordinates.position = -1;
        break;
    }
    return cross_coordinates;
}

TerrCoordinates terrButtonToTerrCoordinates(TerrButton terr_clicked)
{
    TerrCoordinates terr_coordinates;
    switch(terr_clicked)
    {
    case TERRX0_BUTTON :
        terr_coordinates.x = 0.5;
        terr_coordinates.y = 1;
        break;

    case TERRX1_BUTTON :
        terr_coordinates.x = 1;
        terr_coordinates.y = 0;
        break;

    case TERRX2_BUTTON :
        terr_coordinates.x = 0.5;
        terr_coordinates.y = -1;
        break;

    case TERRX3_BUTTON :
        terr_coordinates.x = -0.5;
        terr_coordinates.y = -1;
        break;

    case TERRX4_BUTTON :
        terr_coordinates.x = -1;
        terr_coordinates.y = 0;
        break;

    case TERRX5_BUTTON :
        terr_coordinates.x = -0.5;
        terr_coordinates.y = 1;
        break;


    case TERR0X_BUTTON :
        terr_coordinates.x = 1;
        terr_coordinates.y = 2;
        break;

    case TERR1X_BUTTON :
        terr_coordinates.x = 2;
        terr_coordinates.y = 0;
        break;

    case TERR2X_BUTTON :
        terr_coordinates.x = 1;
        terr_coordinates.y = -2;
        break;

    case TERR3X_BUTTON :
        terr_coordinates.x = -1;
        terr_coordinates.y = -2;
        break;

    case TERR4X_BUTTON :
        terr_coordinates.x = -2;
        terr_coordinates.y = 0;
        break;

    case TERR5X_BUTTON :
        terr_coordinates.x = -1;
        terr_coordinates.y = 2;
        break;


    case TERRNN_BUTTON :
        terr_coordinates.x = 0;
        terr_coordinates.y = 2;
        break;

    case TERRNE_BUTTON :
        terr_coordinates.x = 1.5;
        terr_coordinates.y = 1;
        break;

    case TERRSE_BUTTON :
        terr_coordinates.x = 1.5;
        terr_coordinates.y = -1;
        break;

    case TERRSS_BUTTON :
        terr_coordinates.x = 0;
        terr_coordinates.y = -2;
        break;

    case TERRSW_BUTTON :
        terr_coordinates.x = -1.5;
        terr_coordinates.y = -1;
        break;

    case TERRNW_BUTTON :
        terr_coordinates.x = -1.5;
        terr_coordinates.y = 1;
        break;


    default :
        terr_coordinates.x = -1;
        terr_coordinates.y = -1;
        break;
    }
    return terr_coordinates;
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
