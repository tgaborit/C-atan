/**
*
*
* \author Titouan Gaborit
* \date 26 avril 2019
*
*
*/
#include <math.h>
#include <SDL.h>

#include "controller.h"
#include "controller_place_urb_buttons.h"

static SDL_Rect crossXX0_area;          /*!< Rectangle correspondant à la zone du croisement 0 de la première couronne*/
static SDL_Rect crossXX1_area;          /*!< Rectangle correspondant à la zone du croisement 1 de la première couronne*/
static SDL_Rect crossXX2_area;          /*!< Rectangle correspondant à la zone du croisement 2 de la première couronne*/
static SDL_Rect crossXX3_area;          /*!< Rectangle correspondant à la zone du croisement 3 de la première couronne*/
static SDL_Rect crossXX4_area;          /*!< Rectangle correspondant à la zone du croisement 4 de la première couronne*/
static SDL_Rect crossXX5_area;          /*!< Rectangle correspondant à la zone du croisement 5 de la première couronne*/

static SDL_Rect crossX0X_area;          /*!< Rectangle correspondant à la zone du croisement 0 de la deuxième couronne*/
static SDL_Rect crossX1X_area;          /*!< Rectangle correspondant à la zone du croisement 1 de la deuxième couronne*/
static SDL_Rect crossX2X_area;          /*!< Rectangle correspondant à la zone du croisement 2 de la deuxième couronne*/
static SDL_Rect crossX3X_area;          /*!< Rectangle correspondant à la zone du croisement 3 de la deuxième couronne*/
static SDL_Rect crossX4X_area;          /*!< Rectangle correspondant à la zone du croisement 4 de la deuxième couronne*/
static SDL_Rect crossX5X_area;          /*!< Rectangle correspondant à la zone du croisement 5 de la deuxième couronne*/

static SDL_Rect cross0XX_area;          /*!< Rectangle correspondant à la zone du croisement 0 de la troisième couronne*/
static SDL_Rect cross1XX_area;          /*!< Rectangle correspondant à la zone du croisement 1 de la troisième couronne*/
static SDL_Rect cross2XX_area;          /*!< Rectangle correspondant à la zone du croisement 2 de la troisième couronne*/
static SDL_Rect cross3XX_area;          /*!< Rectangle correspondant à la zone du croisement 3 de la troisième couronne*/
static SDL_Rect cross4XX_area;          /*!< Rectangle correspondant à la zone du croisement 4 de la troisième couronne*/
static SDL_Rect cross5XX_area;          /*!< Rectangle correspondant à la zone du croisement 5 de la troisième couronne*/

static SDL_Rect crossNE0_area;          /*!< Rectangle correspondant à la zone du croisement 0 de l'hexagone Nord - Est*/
static SDL_Rect crossNE1_area;          /*!< Rectangle correspondant à la zone du croisement 1 de l'hexagone Nord - Est*/
static SDL_Rect crossNE2_area;          /*!< Rectangle correspondant à la zone du croisement 2 de l'hexagone Nord - Est*/
static SDL_Rect crossNE3_area;          /*!< Rectangle correspondant à la zone du croisement 3 de l'hexagone Nord - Est*/
static SDL_Rect crossNE4_area;          /*!< Rectangle correspondant à la zone du croisement 4 de l'hexagone Nord - Est*/
static SDL_Rect crossNE5_area;          /*!< Rectangle correspondant à la zone du croisement 5 de l'hexagone Nord - Est*/

static SDL_Rect crossEE0_area;          /*!< Rectangle correspondant à la zone du croisement 0 de l'hexagone Est*/
static SDL_Rect crossEE1_area;          /*!< Rectangle correspondant à la zone du croisement 1 de l'hexagone Est*/
static SDL_Rect crossEE2_area;          /*!< Rectangle correspondant à la zone du croisement 2 de l'hexagone Est*/
static SDL_Rect crossEE3_area;          /*!< Rectangle correspondant à la zone du croisement 3 de l'hexagone Est*/
static SDL_Rect crossEE4_area;          /*!< Rectangle correspondant à la zone du croisement 4 de l'hexagone Est*/
static SDL_Rect crossEE5_area;          /*!< Rectangle correspondant à la zone du croisement 5 de l'hexagone Est*/


void drawButtonsPlaceUrb(SDL_Renderer* renderer)
{
    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect place_urb_buttons[NPLACEURBBUTTON] = {crossXX0_area, crossXX1_area, crossXX2_area, crossXX3_area, crossXX4_area, crossXX5_area,
                                                   crossX0X_area, crossX1X_area, crossX2X_area, crossX3X_area, crossX4X_area, crossX5X_area,
                                                   cross0XX_area, cross1XX_area, cross2XX_area, cross3XX_area, cross4XX_area, cross5XX_area,
                                                   crossNE0_area, crossNE1_area, crossNE2_area, crossNE3_area, crossNE4_area, crossNE5_area,
                                                   crossEE0_area, crossEE1_area, crossEE2_area, crossEE3_area, crossEE4_area, crossEE5_area};
    if(SDL_RenderDrawRects(renderer, place_urb_buttons, NPLACEURBBUTTON) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

void initButtonsPlaceUrb()
{
    int i, j;

    SDL_Rect* place_urb_buttons[5][6] = {{&crossXX0_area, &crossXX1_area, &crossXX2_area, &crossXX3_area, &crossXX4_area, &crossXX5_area},
                                         {&crossX0X_area, &crossX1X_area, &crossX2X_area, &crossX3X_area, &crossX4X_area, &crossX5X_area},
                                         {&cross0XX_area, &cross1XX_area, &cross2XX_area, &cross3XX_area, &cross4XX_area, &cross5XX_area},
                                         {&crossNE0_area, &crossNE1_area, &crossNE2_area, &crossNE3_area, &crossNE4_area, &crossNE5_area},
                                         {&crossEE0_area, &crossEE1_area, &crossEE2_area, &crossEE3_area, &crossEE4_area, &crossEE5_area}};


    for(i = 0; i < 5; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            place_urb_buttons[i][j]->h = CROSSS;
            place_urb_buttons[i][j]->w = CROSSS;
        }
    }

    initButtonsHex(place_urb_buttons[0], BOARDCENTERX, BOARDCENTERY, HEXAGONS);
    initButtonsHex(place_urb_buttons[1], BOARDCENTERX, BOARDCENTERY, 2*HEXAGONS);
    initButtonsHex(place_urb_buttons[2], BOARDCENTERX, BOARDCENTERY, 4*HEXAGONS);
    initButtonsHex(place_urb_buttons[3], BOARDCENTERX + sqrt(3)*HEXAGONS, BOARDCENTERY - 3*HEXAGONS, HEXAGONS);
    initButtonsHex(place_urb_buttons[4], BOARDCENTERX + 2*sqrt(3)*HEXAGONS, BOARDCENTERY, HEXAGONS);

}

void initButtonsHex(SDL_Rect** hex_buttons, int center_x, int center_y, int hexagon_s)
{
    int hexagon_h = (sqrt(3)/2)*hexagon_s;

    hex_buttons[0]->x = center_x - CROSSS/2;
    hex_buttons[0]->y = center_y - hexagon_s - CROSSS/2;

    hex_buttons[1]->x = center_x + hexagon_h - CROSSS/2;
    hex_buttons[1]->y = center_y - hexagon_s/2 - CROSSS/2;

    hex_buttons[2]->x = center_x + hexagon_h - CROSSS/2;
    hex_buttons[2]->y = center_y + hexagon_s/2 - CROSSS/2;

    hex_buttons[3]->x = center_x - CROSSS/2;
    hex_buttons[3]->y = center_y + hexagon_s - CROSSS/2;

    hex_buttons[4]->x = center_x - hexagon_h - CROSSS/2;
    hex_buttons[4]->y = center_y + hexagon_s/2 - CROSSS/2;

    hex_buttons[5]->x = center_x - hexagon_h - CROSSS/2;
    hex_buttons[5]->y = center_y - hexagon_s/2 - CROSSS/2;
}
