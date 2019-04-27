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

static SDL_Rect crossXX0_area;          /*!< Rectangle correspondant à la zone du croisement 1 de la première couronne*/
static SDL_Rect crossXX1_area;          /*!< Rectangle correspondant à la zone du croisement 2 de la première couronne*/
static SDL_Rect crossXX2_area;          /*!< Rectangle correspondant à la zone du croisement 3 de la première couronne*/
static SDL_Rect crossXX3_area;          /*!< Rectangle correspondant à la zone du croisement 4 de la première couronne*/
static SDL_Rect crossXX4_area;          /*!< Rectangle correspondant à la zone du croisement 5 de la première couronne*/
static SDL_Rect crossXX5_area;          /*!< Rectangle correspondant à la zone du croisement 6 de la première couronne*/

//SDL_Rect crown1_buttons[6]  = {cross001_area, cross002_area, cross003_area, cross004_area, cross005_area, cross006_area};

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

    SDL_Rect place_urb_buttons[NPLACEURBBUTTON] = {crossXX0_area, crossXX1_area, crossXX2_area, crossXX3_area, crossXX4_area, crossXX5_area};
    if(SDL_RenderDrawRects(renderer, place_urb_buttons, NPLACEURBBUTTON) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

void initButtonsPlaceUrb()
{
    int i = 0;

    SDL_Rect* place_urb_buttons[6] = {&crossXX0_area, &crossXX1_area, &crossXX2_area, &crossXX3_area, &crossXX4_area, &crossXX5_area};

    for(i = 0; i < 6; ++i)
    {
        place_urb_buttons[i]->h = CROSSS;
        place_urb_buttons[i]->w = CROSSS;
    }

    initButtonsHex(place_urb_buttons, 960, 431, HEXAGONS);

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
