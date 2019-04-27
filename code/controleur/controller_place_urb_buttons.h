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
        CROSS001_BUTTON,
        CROSS002_BUTTON,
        CROSS003_BUTTON,
        CROSS004_BUTTON,
        CROSS005_BUTTON,
        CROSS006_BUTTON,

        NO_BUTTON
} PlaceUrbButton;

/**
* \def NPLACEURBBUTTON
* Définit le nombre de boutons de l'environnement "Placement d'une colonie ou d'une ville"
*/
#define NPLACEURBBUTTON 6

/**
* \def CROSSS
* Définit le côté d'un bouton de croisement
*/
#define CROSSS 40

void drawButtonsPlaceUrb(SDL_Renderer* renderer);

void initButtonsPlaceUrb();
void initButtonsHex(SDL_Rect** hex_buttons, int center_x, int center_y, int hexagon_s);

#endif //CATANE_CONTROLLER_PLACE_URB_BUTTONS_H
