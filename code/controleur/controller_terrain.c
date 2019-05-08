/**
* \file controller_terrain.c
* \brief Fonctions du contrôleur du choix d'un terrain
* \author Titouan Gaborit
* \date 6 mai 2019
*
* Programme gérant l'environnement du choix d'une terrain : la détection d'un clic dessus par le joueur
* ou encore le fait de quitter l'environnement ou le programme.
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

static SDL_Rect terrNN_area;          /*!< Rectangle correspondant à la zone du terrain 0 de l'hexagone debout*/
static SDL_Rect terrNE_area;          /*!< Rectangle correspondant à la zone du terrain 1 de l'hexagone debout*/
static SDL_Rect terrSE_area;          /*!< Rectangle correspondant à la zone du terrain 2 de l'hexagone debout*/
static SDL_Rect terrSS_area;          /*!< Rectangle correspondant à la zone du terrain 3 de l'hexagone debout*/
static SDL_Rect terrSW_area;          /*!< Rectangle correspondant à la zone du terrain 4 de l'hexagone debout*/
static SDL_Rect terrNW_area;          /*!< Rectangle correspondant à la zone du terrain 5 de l'hexagone debout*/

/**
* \fn void controllerTerrain(PathButton* path_chosen, SDL_bool* program_launched)
* \brief Fonction principale du contrôleur du choix d'un terrain.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du choix d'un terrain.
* Elle détecte les actions du joueur et enregistre le terrain cliqué le cas échéant, quitte le programme ou l'environnement.
*
* \param[in,out] terrain_chosen Pointeur vers la ressource choisie dans laquelle sera enregistrée le terrain cliqué.
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on quitte le programme.
*/
void controllerTerrain(TerrButton* terr_chosen, SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_bool choice_launched = SDL_TRUE;
    initTerrButtons();
    while(choice_launched)
    {
        drawTerrButtons(renderer);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            TerrButton terr_clicked;
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN :
                if((terr_clicked = whichTerrButton(event.button)) != NO_TERRBUTTON)
                {
                    printf("Clic sur terrain %d\n", terr_clicked);
                    *terr_chosen = terr_clicked;
                    quit(&choice_launched);
                }
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_BACKSPACE :
                    printf("Appui sur touche Retour arriere\n");
                    printf("Appel de la fonction quit(&choice_launched)\n");
                    quit(&choice_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
//                *resource_chosen = NO_RESOURCEBUTTON;
                printf("Appel de la fonction quit(&choice_launched)\n");
                quit(&choice_launched);
                printf("Appel de la fonction quit(program_launched)\n");
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}

void drawTerrButtons(SDL_Renderer* renderer)
{
    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect terr_buttons[NTERRBUTTONS] = {terrX0_area, terrX1_area, terrX2_area, terrX3_area, terrX4_area, terrX5_area,
                                           terr0X_area, terr1X_area, terr2X_area, terr3X_area, terr4X_area, terr5X_area,
                                           terrNN_area, terrNE_area, terrSE_area, terrSS_area, terrSW_area, terrNW_area};
    if(SDL_RenderDrawRects(renderer, terr_buttons, NTERRBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn TerrButton whichTerrButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton de terrain le joueur a cliqué
*
* Teste pour chaque bouton de terrain si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient notamment les informations sur sa position.
* \return Le bouton de terrain qui a été cliqué, NO_TERRBUTTON si aucun.
*/
TerrButton whichTerrButton(SDL_MouseButtonEvent mouse_button){
    int i;

    SDL_Rect terr_buttons[NTERRBUTTONS] = {terrX0_area, terrX1_area, terrX2_area, terrX3_area, terrX4_area, terrX5_area,
                                           terr0X_area, terr1X_area, terr2X_area, terr3X_area, terr4X_area, terr5X_area,
                                           terrNN_area, terrNE_area, terrSE_area, terrSS_area, terrSW_area, terrNW_area};

    for(i = 0; i < NTERRBUTTONS; ++i)
    {
        if(isInArea(mouse_button, terr_buttons[i]) != SDL_FALSE)
            return i;
    }

    return NO_TERRBUTTON;
}

/**
* \fn void initTerrButtons()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Choix d'un terrain".
*
* Initialise les champs des rectangles des zones correspondant aux terrains du plateau.
* Répartit la totalité des terrains selon la formation de 2 hexagones couchés et 1 hexagone debout
* dans un tableau bidimensionnel, puis utilise une fonction d'initialisation de position pour chaque hexagone, selon la position et le côté
* de cet hexagone.
* De plus, initialise le côté de toutes les zones selon une constante.
*/
void initTerrButtons()
{
    int i, j;
    float hexagonl_s;

    // Répartition des terrains selon la formation de 2 hexagones couchés et 1 hexagone debout
    SDL_Rect* terr_buttons[3][6] = {{&terrX0_area, &terrX1_area, &terrX2_area, &terrX3_area, &terrX4_area, &terrX5_area},
                                       {&terr0X_area, &terr1X_area, &terr2X_area, &terr3X_area, &terr4X_area, &terr5X_area},
                                       {&terrNN_area, &terrNE_area, &terrSE_area, &terrSS_area, &terrSW_area, &terrNW_area}};

    // Initialisation des côtés des zones des boutons des terrains
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            terr_buttons[i][j]->h = TERRAINS;
            terr_buttons[i][j]->w = TERRAINS;
        }
    }

    hexagonl_s = (sqrt(3)/2)*HEXAGONS;

    // Initialisation de la position des zones des boutons des terrains par hexagone, selon leur position et leur côté
    initPosRectHexLying(terr_buttons[0], BOARDCENTERX, BOARDCENTERY, 2*hexagonl_s);
    initPosRectHexLying(terr_buttons[1], BOARDCENTERX, BOARDCENTERY, 4*hexagonl_s);
    initPosRectHex(terr_buttons[2], BOARDCENTERX, BOARDCENTERY, 3*HEXAGONS);
}
