/**
*
*
* \author Titouan Gaborit
* \date 26 avril 2019
*
*
*/

#ifndef CATANE_CONTROLLER_PLACE_URB_BUTTONS_H
#define CATANE_CONTROLLER_PLACE_URB_BUTTONS_H

/**
* \enum PlaceUrbButton
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

        NO_BUTTON
} PlaceUrbButton;

/**
* \def NPLACEURBBUTTON
* Définit le nombre de boutons de l'environnement "Placement d'une colonie ou d'une ville"
*/
#define NPLACEURBBUTTON 18

/**
* \def CROSSS
* Définit le côté d'un bouton de croisement
*/
#define CROSSS 40

/**
* \def BOARDCENTERX
* Définit l'abscisse du centre du plateau
*/
#define BOARDCENTERX 960

/**
* \def BOARDCENTERY
* Définit l'ordonnée du centre du plateau
*/
#define BOARDCENTERY 431

void drawButtonsPlaceUrb(SDL_Renderer* renderer);

void initButtonsPlaceUrb();
void initButtonsHex(SDL_Rect** hex_buttons, int center_x, int center_y, int hexagon_s);

#endif //CATANE_CONTROLLER_PLACE_URB_BUTTONS_H
