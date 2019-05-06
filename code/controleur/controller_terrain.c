/**
* \file controller_terrain.c
* \brief Fonctions du contrôleur du choix d'un terrain
* \author Titouan Gaborit
* \date 6 mai 2019
*
* Programme gérant l'environnement du choix d'une terrain : la détection d'un clic dessus par le joueur
* ou encore le fait de quitter le programme.
*
*/

#include <stdio.h>
#include <SDL.h>
#include "controller_terrain.h"
#include "controller.h"

static SDL_Rect terrX0_area;          /*!< Rectangle correspondant à la zone du terrain 0 de la première couronne*/
static SDL_Rect terrX1_area;          /*!< Rectangle correspondant à la zone du terrain 1 de la première couronne*/
static SDL_Rect terrX2_area;          /*!< Rectangle correspondant à la zone du terrain 2 de la première couronne*/
static SDL_Rect terrX3_area;          /*!< Rectangle correspondant à la zone du terrain 3 de la première couronne*/
static SDL_Rect terrX4_area;          /*!< Rectangle correspondant à la zone du terrain 4 de la première couronne*/
static SDL_Rect terrX5_area;          /*!< Rectangle correspondant à la zone du terrain 5 de la première couronne*/

static SDL_Rect terr0X_area;          /*!< Rectangle correspondant à la zone du terrain 0 de la deuxième couronne*/
static SDL_Rect terr1X_area;          /*!< Rectangle correspondant à la zone du terrain 1 de la deuxième couronne*/
static SDL_Rect terr2X_area;          /*!< Rectangle correspondant à la zone du terrain 2 de la deuxième couronne*/
static SDL_Rect terr3X_area;          /*!< Rectangle correspondant à la zone du terrain 3 de la deuxième couronne*/
static SDL_Rect terr4X_area;          /*!< Rectangle correspondant à la zone du terrain 4 de la deuxième couronne*/
static SDL_Rect terr5X_area;          /*!< Rectangle correspondant à la zone du terrain 5 de la deuxième couronne*/

/**
* \fn void controllerTerrain(PathButton* path_chosen, SDL_bool* program_launched)
* \brief Fonction principale du contrôleur du choix d'une ressource.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du choix d'un terrain.
* Elle détecte les actions du joueur et enregistre le terrain cliqué le cas échéant.
*
* \param[in,out] terrain_chosen Pointeur vers la ressource choisie dans laquelle sera enregistrée la ressource cliquée.
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on quitte le programme.
*/
void controllerTerrain(/*TerrainButton* terrain_chosen, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
    initTerrainButtons();
    while(*program_launched)
    {
        drawTerrainButtons(renderer);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
//            case SDL_MOUSEBUTTONDOWN :
//                switch(whichTerrainButton(event.button))
//                {
//                default :
//                    break;
//                }
//                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
//                *resource_chosen = NO_RESOURCEBUTTON;
                printf("Appel de la fonction quit(program_launched)\n");
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}

void drawTerrainButtons(SDL_Renderer* renderer)
{
    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect terrain_buttons[NTERRAINBUTTONS] = {terrX0_area, terrX1_area, terrX2_area, terrX3_area, terrX4_area, terrX5_area,
                                                 terr0X_area, terr1X_area, terr2X_area, terr3X_area, terr4X_area, terr5X_area};
    if(SDL_RenderDrawRects(renderer, terrain_buttons, NTERRAINBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn void initTerrainButton()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Choix d'un terrain".
*
* Initialise les champs des rectangles des zones correspondant aux terrains du plateau.
* Répartit la totalité des terrains selon la formation de 3 hexagones dans un tableau bidimensionnel,
* puis utilise une fonction d'initialisation pour chaque hexagone, selon sa position et son côté.
*/
void initTerrainButtons()
{
    int i, j;
    float hexagonl_s;

    // Répartition des chemins selon la formation de 9 hexagones couchés
    SDL_Rect* terrain_buttons[2][6] = {{&terrX0_area, &terrX1_area, &terrX2_area, &terrX3_area, &terrX4_area, &terrX5_area},
                                      {&terr0X_area, &terr1X_area, &terr2X_area, &terr3X_area, &terr4X_area, &terr5X_area}};

    // Initialisation des côtés des zones des boutons des chemins
    for(i = 0; i < 2; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            terrain_buttons[i][j]->h = TERRAINS;
            terrain_buttons[i][j]->w = TERRAINS;
        }
    }

    hexagonl_s = (sqrt(3)/2)*HEXAGONS;

    // Initialisation de la position des zones des boutons des terrains par hexagone, selon leur position et leur côté
    initPosRectHexLying(terrain_buttons[0], BOARDCENTERX, BOARDCENTERY, 2*hexagonl_s);
    initPosRectHexLying(terrain_buttons[1], BOARDCENTERX, BOARDCENTERY, 4*hexagonl_s);
}
