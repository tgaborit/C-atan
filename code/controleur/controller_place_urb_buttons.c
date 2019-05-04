/**
* \file controller_place_urb_buttons.c
* \brief Fonctions de gestion des boutons de l'environnement "Placement d'une colonie ou d'une ville"
* \author Titouan Gaborit
* \date 26 avril 2019
*
* Fonctions gérant l'initialisation des boutons cliquables par le joueur lors du placement d'une colonie/ville et la détection d'un clic dessus.
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

static SDL_Rect crossSE0_area;          /*!< Rectangle correspondant à la zone du croisement 0 de l'hexagone Sud - Est*/
static SDL_Rect crossSE1_area;          /*!< Rectangle correspondant à la zone du croisement 1 de l'hexagone Sud - Est*/
static SDL_Rect crossSE2_area;          /*!< Rectangle correspondant à la zone du croisement 2 de l'hexagone Sud - Est*/
static SDL_Rect crossSE3_area;          /*!< Rectangle correspondant à la zone du croisement 3 de l'hexagone Sud - Est*/
static SDL_Rect crossSE4_area;          /*!< Rectangle correspondant à la zone du croisement 4 de l'hexagone Sud - Est*/
static SDL_Rect crossSE5_area;          /*!< Rectangle correspondant à la zone du croisement 5 de l'hexagone Sud - Est*/

static SDL_Rect crossSW0_area;          /*!< Rectangle correspondant à la zone du croisement 0 de l'hexagone Sud - Ouest*/
static SDL_Rect crossSW1_area;          /*!< Rectangle correspondant à la zone du croisement 1 de l'hexagone Sud - Ouest*/
static SDL_Rect crossSW2_area;          /*!< Rectangle correspondant à la zone du croisement 2 de l'hexagone Sud - Ouest*/
static SDL_Rect crossSW3_area;          /*!< Rectangle correspondant à la zone du croisement 3 de l'hexagone Sud - Ouest*/
static SDL_Rect crossSW4_area;          /*!< Rectangle correspondant à la zone du croisement 4 de l'hexagone Sud - Ouest*/
static SDL_Rect crossSW5_area;          /*!< Rectangle correspondant à la zone du croisement 5 de l'hexagone Sud - Ouest*/

static SDL_Rect crossWW0_area;          /*!< Rectangle correspondant à la zone du croisement 0 de l'hexagone Ouest*/
static SDL_Rect crossWW1_area;          /*!< Rectangle correspondant à la zone du croisement 1 de l'hexagone Ouest*/
static SDL_Rect crossWW2_area;          /*!< Rectangle correspondant à la zone du croisement 2 de l'hexagone Ouest*/
static SDL_Rect crossWW3_area;          /*!< Rectangle correspondant à la zone du croisement 3 de l'hexagone Ouest*/
static SDL_Rect crossWW4_area;          /*!< Rectangle correspondant à la zone du croisement 4 de l'hexagone Ouest*/
static SDL_Rect crossWW5_area;          /*!< Rectangle correspondant à la zone du croisement 5 de l'hexagone Ouest*/

static SDL_Rect crossNW0_area;          /*!< Rectangle correspondant à la zone du croisement 0 de l'hexagone Nord - Ouest*/
static SDL_Rect crossNW1_area;          /*!< Rectangle correspondant à la zone du croisement 1 de l'hexagone Nord - Ouest*/
static SDL_Rect crossNW2_area;          /*!< Rectangle correspondant à la zone du croisement 2 de l'hexagone Nord - Ouest*/
static SDL_Rect crossNW3_area;          /*!< Rectangle correspondant à la zone du croisement 3 de l'hexagone Nord - Ouest*/
static SDL_Rect crossNW4_area;          /*!< Rectangle correspondant à la zone du croisement 4 de l'hexagone Nord - Ouest*/
static SDL_Rect crossNW5_area;          /*!< Rectangle correspondant à la zone du croisement 5 de l'hexagone Nord - Ouest*/

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

    SDL_Rect place_urb_buttons[NPLACEURBBUTTONS] = {crossXX0_area, crossXX1_area, crossXX2_area, crossXX3_area, crossXX4_area, crossXX5_area,
                                                    crossX0X_area, crossX1X_area, crossX2X_area, crossX3X_area, crossX4X_area, crossX5X_area,
                                                    cross0XX_area, cross1XX_area, cross2XX_area, cross3XX_area, cross4XX_area, cross5XX_area,
                                                    crossNE0_area, crossNE1_area, crossNE2_area, crossNE3_area, crossNE4_area, crossNE5_area,
                                                    crossEE0_area, crossEE1_area, crossEE2_area, crossEE3_area, crossEE4_area, crossEE5_area,
                                                    crossSE0_area, crossSE1_area, crossSE2_area, crossSE3_area, crossSE4_area, crossSE5_area,
                                                    crossSW0_area, crossSW1_area, crossSW2_area, crossSW3_area, crossSW4_area, crossSW5_area,
                                                    crossWW0_area, crossWW1_area, crossWW2_area, crossWW3_area, crossWW4_area, crossWW5_area,
                                                    crossNW0_area, crossNW1_area, crossNW2_area, crossNW3_area, crossNW4_area, crossNW5_area};
    if(SDL_RenderDrawRects(renderer, place_urb_buttons, NPLACEURBBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn CrossButton whichButtonPlaceUrb(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton le joueur a cliqué.
*
* Teste pour chaque bouton si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \return Le bouton de l'environnement "Placement d'une colonie ou d'une ville" qui a été cliqué, NO_CROSSBUTTON si aucun.
*/
CrossButton whichButtonPlaceUrb(SDL_MouseButtonEvent mouse_button){
    CrossButton button_clicked;
    if((button_clicked = whichCrossButton(mouse_button)) != NO_CROSSBUTTON)
        return button_clicked;
    return NO_CROSSBUTTON;
}

/**
* \fn CrossButton whichCrossButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton de croisement le joueur a cliqué
*
* Teste pour chaque bouton de croisement si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient notamment les informations sur sa position.
* \return Le bouton de croisement qui a été cliqué, NO_CROSSBUTTON si aucun.
*/
CrossButton whichCrossButton(SDL_MouseButtonEvent mouse_button){
    int i;
    SDL_Rect place_urb_buttons[NPLACEURBBUTTONS] = {crossXX0_area, crossXX1_area, crossXX2_area, crossXX3_area, crossXX4_area, crossXX5_area,
                                                    crossX0X_area, crossX1X_area, crossX2X_area, crossX3X_area, crossX4X_area, crossX5X_area,
                                                    cross0XX_area, cross1XX_area, cross2XX_area, cross3XX_area, cross4XX_area, cross5XX_area,
                                                    crossNE0_area, crossNE1_area, crossNE2_area, crossNE3_area, crossNE4_area, crossNE5_area,
                                                    crossEE0_area, crossEE1_area, crossEE2_area, crossEE3_area, crossEE4_area, crossEE5_area,
                                                    crossSE0_area, crossSE1_area, crossSE2_area, crossSE3_area, crossSE4_area, crossSE5_area,
                                                    crossSW0_area, crossSW1_area, crossSW2_area, crossSW3_area, crossSW4_area, crossSW5_area,
                                                    crossWW0_area, crossWW1_area, crossWW2_area, crossWW3_area, crossWW4_area, crossWW5_area,
                                                    crossNW0_area, crossNW1_area, crossNW2_area, crossNW3_area, crossNW4_area, crossNW5_area};
    for(i = 0; i<NPLACEURBBUTTONS; ++i)
    {
        if(isInArea(mouse_button, place_urb_buttons[i]) != SDL_FALSE)
            return i;
    }
    return NO_CROSSBUTTON;
}

/**
* \fn void initButtonsPlaceUrb()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Placement d'une colonie ou d'une ville".
*
* Initialise les champs des rectangles des zones correspondant aux croisements du plateau.
* Répartit la totalité des croisements selon la formation de 9 hexagones dans un tableau bidimensionnel,
* puis utilise une fonction d'initialisation pour chaque hexagone, selon sa position et son côté.
*/
void initButtonsPlaceUrb()
{
    int i, j;
    // Répartition des croisements selon la formation de 9 hexagones
    SDL_Rect* place_urb_buttons[9][6] = {{&crossXX0_area, &crossXX1_area, &crossXX2_area, &crossXX3_area, &crossXX4_area, &crossXX5_area},
                                         {&crossX0X_area, &crossX1X_area, &crossX2X_area, &crossX3X_area, &crossX4X_area, &crossX5X_area},
                                         {&cross0XX_area, &cross1XX_area, &cross2XX_area, &cross3XX_area, &cross4XX_area, &cross5XX_area},
                                         {&crossNE0_area, &crossNE1_area, &crossNE2_area, &crossNE3_area, &crossNE4_area, &crossNE5_area},
                                         {&crossEE0_area, &crossEE1_area, &crossEE2_area, &crossEE3_area, &crossEE4_area, &crossEE5_area},
                                         {&crossSE0_area, &crossSE1_area, &crossSE2_area, &crossSE3_area, &crossSE4_area, &crossSE5_area},
                                         {&crossSW0_area, &crossSW1_area, &crossSW2_area, &crossSW3_area, &crossSW4_area, &crossSW5_area},
                                         {&crossWW0_area, &crossWW1_area, &crossWW2_area, &crossWW3_area, &crossWW4_area, &crossWW5_area},
                                         {&crossNW0_area, &crossNW1_area, &crossNW2_area, &crossNW3_area, &crossNW4_area, &crossNW5_area}};
    // Initialisation des côtés des zones des boutons des croisements
    for(i = 0; i < 9; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            place_urb_buttons[i][j]->h = CROSSS;
            place_urb_buttons[i][j]->w = CROSSS;
        }
    }
    // Initialisation de la position des zones des boutons des croisements par hexagone, selon leur position et leur côté
    initPosRectHex(place_urb_buttons[0], BOARDCENTERX, BOARDCENTERY, HEXAGONS);                                 // Boutons de la première couronne
    initPosRectHex(place_urb_buttons[1], BOARDCENTERX, BOARDCENTERY, 2*HEXAGONS);                               // Boutons de la deuxième couronne
    initPosRectHex(place_urb_buttons[2], BOARDCENTERX, BOARDCENTERY, 4*HEXAGONS);                               // Boutons de la troisième couronne
    initPosRectHex(place_urb_buttons[3], round(BOARDCENTERX + sqrt(3)*HEXAGONS), BOARDCENTERY - 3*HEXAGONS, HEXAGONS); // Boutons de l'hexagone Nord - Est
    initPosRectHex(place_urb_buttons[4], round(BOARDCENTERX + 2*sqrt(3)*HEXAGONS), BOARDCENTERY, HEXAGONS);            // Boutons de l'hexagone Est
    initPosRectHex(place_urb_buttons[5], round(BOARDCENTERX + sqrt(3)*HEXAGONS), BOARDCENTERY + 3*HEXAGONS, HEXAGONS); // Boutons de l'hexagone Sud - Est
    initPosRectHex(place_urb_buttons[6], round(BOARDCENTERX - sqrt(3)*HEXAGONS), BOARDCENTERY + 3*HEXAGONS, HEXAGONS); // Boutons de l'hexagone Sud - Ouest
    initPosRectHex(place_urb_buttons[7], round(BOARDCENTERX - 2*sqrt(3)*HEXAGONS), BOARDCENTERY, HEXAGONS);            // Boutons de l'hexagone Ouest
    initPosRectHex(place_urb_buttons[8], round(BOARDCENTERX - sqrt(3)*HEXAGONS), BOARDCENTERY - 3*HEXAGONS, HEXAGONS); // Boutons de l'hexagone Nord - Ouest

}
