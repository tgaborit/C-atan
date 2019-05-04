/**
* \file controller_place_urb_buttons.h
* \brief En-tête des boutons de l'environnement "Placement d'une colonie ou d'une ville"
* \author Titouan Gaborit
* \date 26 avril 2019
*
* En-tête déclarant les fonctions de gestion des boutons du placement d'une colonie/ville ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_PLACE_URB_BUTTONS_H
#define CATANE_CONTROLLER_PLACE_URB_BUTTONS_H

/**
* \enum CrossButton
* Tous les boutons existants dans l'environnement "Placement d'une colonie ou d'une ville" ainsi que le non-bouton.
*/
typedef enum {
        CROSSXX0_BUTTON,
        CROSSXX1_BUTTON,
        CROSSXX2_BUTTON,
        CROSSXX3_BUTTON,
        CROSSXX4_BUTTON,
        CROSSXX5_BUTTON,

        CROSSX0X_BUTTON,
        CROSSX1X_BUTTON,
        CROSSX2X_BUTTON,
        CROSSX3X_BUTTON,
        CROSSX4X_BUTTON,
        CROSSX5X_BUTTON,

        CROSS0XX_BUTTON,
        CROSS1XX_BUTTON,
        CROSS2XX_BUTTON,
        CROSS3XX_BUTTON,
        CROSS4XX_BUTTON,
        CROSS5XX_BUTTON,

        CROSSNE0_BUTTON,
        CROSSNE1_BUTTON,
        CROSSNE2_BUTTON,
        CROSSNE3_BUTTON,
        CROSSNE4_BUTTON,
        CROSSNE5_BUTTON,

        CROSSEE0_BUTTON,
        CROSSEE1_BUTTON,
        CROSSEE2_BUTTON,
        CROSSEE3_BUTTON,
        CROSSEE4_BUTTON,
        CROSSEE5_BUTTON,

        CROSSSE0_BUTTON,
        CROSSSE1_BUTTON,
        CROSSSE2_BUTTON,
        CROSSSE3_BUTTON,
        CROSSSE4_BUTTON,
        CROSSSE5_BUTTON,

        CROSSSW0_BUTTON,
        CROSSSW1_BUTTON,
        CROSSSW2_BUTTON,
        CROSSSW3_BUTTON,
        CROSSSW4_BUTTON,
        CROSSSW5_BUTTON,

        CROSSWW0_BUTTON,
        CROSSWW1_BUTTON,
        CROSSWW2_BUTTON,
        CROSSWW3_BUTTON,
        CROSSWW4_BUTTON,
        CROSSWW5_BUTTON,

        CROSSNW0_BUTTON,
        CROSSNW1_BUTTON,
        CROSSNW2_BUTTON,
        CROSSNW3_BUTTON,
        CROSSNW4_BUTTON,
        CROSSNW5_BUTTON,

        NO_CROSSBUTTON
} CrossButton;

/**
* \def NPLACEURBBUTTON
* Définit le nombre de boutons de l'environnement "Placement d'une colonie ou d'une ville".
*/
#define NPLACEURBBUTTONS 54

/**
* \def CROSSS
* Définit le côté d'un bouton de croisement.
*/
#define CROSSS 40

void drawButtonsPlaceUrb(SDL_Renderer* renderer);

CrossButton whichButtonPlaceUrb(SDL_MouseButtonEvent mouse_button);
    CrossButton whichCrossButton(SDL_MouseButtonEvent mouse_button);

void initButtonsPlaceUrb();

#endif //CATANE_CONTROLLER_PLACE_URB_BUTTONS_H
