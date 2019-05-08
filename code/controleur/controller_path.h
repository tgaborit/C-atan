/**
* \file controller_path.h
* \brief En-tête du contrôleur du choix d'un chemin
* \author Titouan Gaborit
* \date 1 mai 2019
*
* En-tête déclarant les fonctions du contrôleur du choix d'un chemin ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_PATH_H
#define CATANE_CONTROLLER_PATH_H

#include <SDL.h>

/**
* \enum PathButton
* Tous les boutons existants dans l'environnement "Choix d'un chemin" ainsi que le non-bouton.
*/
typedef enum {
        PATHXX0_BUTTON,
        PATHXX1_BUTTON,
        PATHXX2_BUTTON,
        PATHXX3_BUTTON,
        PATHXX4_BUTTON,
        PATHXX5_BUTTON,

        PATHX0X_BUTTON,
        PATHX1X_BUTTON,
        PATHX2X_BUTTON,
        PATHX3X_BUTTON,
        PATHX4X_BUTTON,
        PATHX5X_BUTTON,

        PATH0XX_BUTTON,
        PATH1XX_BUTTON,
        PATH2XX_BUTTON,
        PATH3XX_BUTTON,
        PATH4XX_BUTTON,
        PATH5XX_BUTTON,

        PATHNN0_BUTTON,
        PATHNN1_BUTTON,
        PATHNN2_BUTTON,
        PATHNN3_BUTTON,
        PATHNN4_BUTTON,
        PATHNN5_BUTTON,

        PATHNE0_BUTTON,
        PATHNE1_BUTTON,
        PATHNE2_BUTTON,
        PATHNE3_BUTTON,
        PATHNE4_BUTTON,
        PATHNE5_BUTTON,

        PATHSE0_BUTTON,
        PATHSE1_BUTTON,
        PATHSE2_BUTTON,
        PATHSE3_BUTTON,
        PATHSE4_BUTTON,
        PATHSE5_BUTTON,

        PATHSS0_BUTTON,
        PATHSS1_BUTTON,
        PATHSS2_BUTTON,
        PATHSS3_BUTTON,
        PATHSS4_BUTTON,
        PATHSS5_BUTTON,

        PATHSW0_BUTTON,
        PATHSW1_BUTTON,
        PATHSW2_BUTTON,
        PATHSW3_BUTTON,
        PATHSW4_BUTTON,
        PATHSW5_BUTTON,

        PATHNW0_BUTTON,
        PATHNW1_BUTTON,
        PATHNW2_BUTTON,
        PATHNW3_BUTTON,
        PATHNW4_BUTTON,
        PATHNW5_BUTTON,

        PATHST0_BUTTON,
        PATHST1_BUTTON,
        PATHST2_BUTTON,
        PATHST3_BUTTON,
        PATHST4_BUTTON,
        PATHST5_BUTTON,

        PATHO00_BUTTON,
        PATHO01_BUTTON,
        PATHO10_BUTTON,
        PATHO11_BUTTON,
        PATHO20_BUTTON,
        PATHO21_BUTTON,
        PATHO30_BUTTON,
        PATHO31_BUTTON,
        PATHO40_BUTTON,
        PATHO41_BUTTON,
        PATHO50_BUTTON,
        PATHO51_BUTTON,

        NO_PATHBUTTON
} PathButton;

/**
* \def NPATHBUTTONS
* Définit le nombre de boutons de l'environnement "Choix d'un chemin".
*/
#define NPATHBUTTONS 72

/**
* \def PATHS
* Définit le côté d'un bouton de chemin.
*/
#define PATHS 40

void controllerPath(PathButton* path_clicked, SDL_Renderer* renderer, SDL_bool* program_launched);

void drawPathButtons(SDL_Renderer* renderer);

PathButton whichPathButton(SDL_MouseButtonEvent mouse_button);

void initPathButtons();
    void initPosRectOthers();

#endif //CATANE_CONTROLLER_PATH_H
