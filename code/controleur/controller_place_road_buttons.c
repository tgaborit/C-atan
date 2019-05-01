/**
* \file controller_place_road_buttons.c
* \brief Fonctions de gestion des boutons de l'environnement "Placement d'une route"
* \author Titouan Gaborit
* \date 1 mai 2019
*
* Fonctions gérant l'initialisation des boutons cliquables par le joueur lors du placement d'une route et la détection d'un clic dessus.
*
*/
#include <math.h>
#include <SDL.h>

#include "controller.h"
#include "controller_place_road_buttons.h"

static SDL_Rect pathXX0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de la première couronne*/
static SDL_Rect pathXX1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de la première couronne*/
static SDL_Rect pathXX2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de la première couronne*/
static SDL_Rect pathXX3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de la première couronne*/
static SDL_Rect pathXX4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de la première couronne*/
static SDL_Rect pathXX5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de la première couronne*/

static SDL_Rect pathX0X_area;          /*!< Rectangle correspondant à la zone du chemin 0 de la deuxième couronne*/
static SDL_Rect pathX1X_area;          /*!< Rectangle correspondant à la zone du chemin 1 de la deuxième couronne*/
static SDL_Rect pathX2X_area;          /*!< Rectangle correspondant à la zone du chemin 2 de la deuxième couronne*/
static SDL_Rect pathX3X_area;          /*!< Rectangle correspondant à la zone du chemin 3 de la deuxième couronne*/
static SDL_Rect pathX4X_area;          /*!< Rectangle correspondant à la zone du chemin 4 de la deuxième couronne*/
static SDL_Rect pathX5X_area;          /*!< Rectangle correspondant à la zone du chemin 5 de la deuxième couronne*/

static SDL_Rect path0XX_area;          /*!< Rectangle correspondant à la zone du chemin 0 de la troisième couronne*/
static SDL_Rect path1XX_area;          /*!< Rectangle correspondant à la zone du chemin 1 de la troisième couronne*/
static SDL_Rect path2XX_area;          /*!< Rectangle correspondant à la zone du chemin 2 de la troisième couronne*/
static SDL_Rect path3XX_area;          /*!< Rectangle correspondant à la zone du chemin 3 de la troisième couronne*/
static SDL_Rect path4XX_area;          /*!< Rectangle correspondant à la zone du chemin 4 de la troisième couronne*/
static SDL_Rect path5XX_area;          /*!< Rectangle correspondant à la zone du chemin 5 de la troisième couronne*/

static SDL_Rect pathNE0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Nord - Est*/
static SDL_Rect pathNE1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Nord - Est*/
static SDL_Rect pathNE2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Nord - Est*/
static SDL_Rect pathNE3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Nord - Est*/
static SDL_Rect pathNE4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Nord - Est*/
static SDL_Rect pathNE5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Nord - Est*/

static SDL_Rect pathEE0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Est*/
static SDL_Rect pathEE1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Est*/
static SDL_Rect pathEE2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Est*/
static SDL_Rect pathEE3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Est*/
static SDL_Rect pathEE4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Est*/
static SDL_Rect pathEE5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Est*/

static SDL_Rect pathSE0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Sud - Est*/
static SDL_Rect pathSE1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Sud - Est*/
static SDL_Rect pathSE2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Sud - Est*/
static SDL_Rect pathSE3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Sud - Est*/
static SDL_Rect pathSE4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Sud - Est*/
static SDL_Rect pathSE5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Sud - Est*/

static SDL_Rect pathSW0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Sud - Ouest*/

static SDL_Rect pathWW0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Ouest*/
static SDL_Rect pathWW1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Ouest*/
static SDL_Rect pathWW2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Ouest*/
static SDL_Rect pathWW3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Ouest*/
static SDL_Rect pathWW4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Ouest*/
static SDL_Rect pathWW5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Ouest*/

static SDL_Rect pathNW0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Nord - Ouest*/

void drawButtonsPlaceRoad(SDL_Renderer* renderer)
{
    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect place_road_buttons[NPLACEROADBUTTONS] = {pathXX0_area, pathXX1_area, pathXX2_area, pathXX3_area, pathXX4_area, pathXX5_area,
                                                     pathX0X_area, pathX1X_area, pathX2X_area, pathX3X_area, pathX4X_area, pathX5X_area,
                                                     path0XX_area, path1XX_area, path2XX_area, path3XX_area, path4XX_area, path5XX_area/*,
                                                     pathNE0_area, pathNE1_area, pathNE2_area, pathNE3_area, pathNE4_area, pathNE5_area,
                                                     pathEE0_area, pathEE1_area, pathEE2_area, pathEE3_area, pathEE4_area, pathEE5_area,
                                                     pathSE0_area, pathSE1_area, pathSE2_area, pathSE3_area, pathSE4_area, pathSE5_area,
                                                     pathSW0_area, pathSW1_area, pathSW2_area, pathSW3_area, pathSW4_area, pathSW5_area,
                                                     pathWW0_area, pathWW1_area, pathWW2_area, pathWW3_area, pathWW4_area, pathWW5_area,
                                                     pathNW0_area, pathNW1_area, pathNW2_area, pathNW3_area, pathNW4_area, pathNW5_area*/};
    if(SDL_RenderDrawRects(renderer, place_road_buttons, NPLACEROADBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn void initButtonsPlaceRoad()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Placement d'une route".
*
* Initialise les champs des rectangles des zones correspondant aux chemin du plateau.
* Répartit la totalité des chemins selon la formation de 9 hexagones couchés dans un tableau bidimensionnel,
* puis utilise une fonction d'initialisation pour chaque hexagone, selon sa position et son côté.
*/
void initButtonsPlaceRoad()
{
    int i, j;
    int hexagonl_s;
    // Répartition des chemins selon la formation de 9 hexagones couchés
    SDL_Rect* place_road_buttons[3][6] = {{&pathXX0_area, &pathXX1_area, &pathXX2_area, &pathXX3_area, &pathXX4_area, &pathXX5_area},
                                          {&pathX0X_area, &pathX1X_area, &pathX2X_area, &pathX3X_area, &pathX4X_area, &pathX5X_area},
                                          {&path0XX_area, &path1XX_area, &path2XX_area, &path3XX_area, &path4XX_area, &path5XX_area}/*,
                                          {&pathNE0_area, &pathNE1_area, &pathNE2_area, &pathNE3_area, &pathNE4_area, &pathNE5_area},
                                          {&pathEE0_area, &pathEE1_area, &pathEE2_area, &pathEE3_area, &pathEE4_area, &pathEE5_area},
                                          {&pathSE0_area, &pathSE1_area, &pathSE2_area, &pathSE3_area, &pathSE4_area, &pathSE5_area},
                                          {&pathSW0_area, &pathSW1_area, &pathSW2_area, &pathSW3_area, &pathSW4_area, &pathSW5_area},
                                          {&pathWW0_area, &pathWW1_area, &pathWW2_area, &pathWW3_area, &pathWW4_area, &pathWW5_area},
                                          {&pathNW0_area, &pathNW1_area, &pathNW2_area, &pathNW3_area, &pathNW4_area, &pathNW5_area}*/};
    // Initialisation des côtés des zones des boutons des chemins
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            place_road_buttons[i][j]->h = PATHS;
            place_road_buttons[i][j]->w = PATHS;
        }
    }

    hexagonl_s = (sqrt(3)/2)*HEXAGONS;

    // Initialisation de la position des zones des boutons des chemins par hexagone, selon leur position et leur côté
    initPosRectHexLying(place_road_buttons[0], BOARDCENTERX, BOARDCENTERY, hexagonl_s);                                 // Boutons de la première couronne
    initPosRectHexLying(place_road_buttons[1], BOARDCENTERX, BOARDCENTERY, 3*hexagonl_s);                               // Boutons de la deuxième couronne
    initPosRectHexLying(place_road_buttons[2], BOARDCENTERX, BOARDCENTERY, 5*hexagonl_s);                               // Boutons de la troisième couronne
    /*
    initPosRectHexLying(place_road_buttons[3], BOARDCENTERX + sqrt(3)*HEXAGONS, BOARDCENTERY - 3*HEXAGONS, HEXAGONS); // Boutons de l'hexagone Nord - Est
    initPosRectHexLying(place_road_buttons[4], BOARDCENTERX + 2*sqrt(3)*HEXAGONS, BOARDCENTERY, HEXAGONS);            // Boutons de l'hexagone Est
    initPosRectHexLying(place_road_buttons[5], BOARDCENTERX + sqrt(3)*HEXAGONS, BOARDCENTERY + 3*HEXAGONS, HEXAGONS); // Boutons de l'hexagone Sud - Est
    initPosRectHexLying(place_road_buttons[6], BOARDCENTERX - sqrt(3)*HEXAGONS, BOARDCENTERY + 3*HEXAGONS, HEXAGONS); // Boutons de l'hexagone Sud - Ouest
    initPosRectHexLying(place_road_buttons[7], BOARDCENTERX - 2*sqrt(3)*HEXAGONS, BOARDCENTERY, HEXAGONS);            // Boutons de l'hexagone Ouest
    initPosRectHexLying(place_road_buttons[8], BOARDCENTERX - sqrt(3)*HEXAGONS, BOARDCENTERY - 3*HEXAGONS, HEXAGONS); // Boutons de l'hexagone Nord - Ouest
*/
}

/**
* \fn void initPosRectHexLying(SDL_Rect** hex_buttons, int center_x, int center_y, int hexagon_s)
* \brief Fonction d'initialisation des positions de 6 rectangles selon la formation d'un hexagone couché.
*
* Initialise les positions des 6 rectangles d'un tableau en formant un hexagone couché centré selon l'abscisse et l'ordonnée passées en paramètre,
* et de côté passé en paramètre.
* \param[in] hex_buttons Tableau de pointeurs sur les rectangles à initialiser.
* \param[in] center_x Abscisse du centre de l'hexagone formé par les 6 rectangles.
* \param[in] center_y Ordonnée du centre de l'hexagone formé par les 6 rectangles.
* \param[in] hexagon_s Côté de l'hexagone formé par les 6 rectangles.
*/
void initPosRectHexLying(SDL_Rect** hex_buttons, int center_x, int center_y, int hexagon_s)
{
    int hexagon_h = (sqrt(3)/2)*hexagon_s;

    hex_buttons[0]->x = center_x + hexagon_s/2 - hex_buttons[0]->w/2;
    hex_buttons[0]->y = center_y - hexagon_h - hex_buttons[0]->h/2;

    hex_buttons[1]->x = center_x + hexagon_s - hex_buttons[0]->w/2;
    hex_buttons[1]->y = center_y - hex_buttons[0]->h/2;

    hex_buttons[2]->x = center_x + hexagon_s/2 - hex_buttons[0]->w/2;
    hex_buttons[2]->y = center_y + hexagon_h - hex_buttons[0]->h/2;

    hex_buttons[3]->x = center_x - hexagon_s/2 - hex_buttons[0]->w/2;
    hex_buttons[3]->y = center_y + hexagon_h - hex_buttons[0]->h/2;

    hex_buttons[4]->x = center_x - hexagon_s - hex_buttons[0]->w/2;
    hex_buttons[4]->y = center_y - hex_buttons[0]->h/2;

    hex_buttons[5]->x = center_x - hexagon_s/2 - hex_buttons[0]->w/2;
    hex_buttons[5]->y = center_y - hexagon_h - hex_buttons[0]->h/2;
}
