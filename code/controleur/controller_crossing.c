/**
* \file controller_terrain.c
* \brief Fonctions du contrôleur du choix d'un croisement
* \author Titouan Gaborit
* \date 1 avril 2019
*
* Programme gérant l'environnement du choix d'un croisement : la détection d'un clic dessus par le joueur
* ou encore le fait de quitter l'environnement ou le programme.
*
*/

#include <stdio.h>
#include <SDL.h>
#include "controller.h"
#include "controller_crossing.h"

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

/**
* \fn void controllerCrossing(SDL_bool* program_launched, SDL_Window* window, Game* the_game, UrbPlacing urb_placing)
* \brief Fonction principale du contrôleur du choix d'un croisement.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du choix d'un croisement.
* Elle détecte les actions du joueur et enregistre le croisement cliqué le cas échéant, quitte le programme ou l'environnement.
*
* \param[in,out] path_chosen Pointeur vers le croisement choisi dans lequel sera enregistré le croisement cliqué.
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on quitte le programme.
*/
void controllerCrossing(CrossButton* cross_chosen, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_bool choice_launched = SDL_TRUE;
    initCrossButtons();
    while(choice_launched)
    {
        drawCrossButtons(window);
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            CrossButton cross_clicked;
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN :
                if((cross_clicked = whichCrossButton(event.button)) != NO_CROSSBUTTON)
                {
                    printf("Clic sur croisement %d\n", cross_clicked);
                    *cross_chosen = cross_clicked;
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

void drawCrossButtons(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_GetRenderer(window);

    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect cross_buttons[NCROSSBUTTONS] = {crossXX0_area, crossXX1_area, crossXX2_area, crossXX3_area, crossXX4_area, crossXX5_area,
                                             crossX0X_area, crossX1X_area, crossX2X_area, crossX3X_area, crossX4X_area, crossX5X_area,
                                             cross0XX_area, cross1XX_area, cross2XX_area, cross3XX_area, cross4XX_area, cross5XX_area,
                                             crossNE0_area, crossNE1_area, crossNE2_area, crossNE3_area, crossNE4_area, crossNE5_area,
                                             crossEE0_area, crossEE1_area, crossEE2_area, crossEE3_area, crossEE4_area, crossEE5_area,
                                             crossSE0_area, crossSE1_area, crossSE2_area, crossSE3_area, crossSE4_area, crossSE5_area,
                                             crossSW0_area, crossSW1_area, crossSW2_area, crossSW3_area, crossSW4_area, crossSW5_area,
                                             crossWW0_area, crossWW1_area, crossWW2_area, crossWW3_area, crossWW4_area, crossWW5_area,
                                             crossNW0_area, crossNW1_area, crossNW2_area, crossNW3_area, crossNW4_area, crossNW5_area};
    if(SDL_RenderDrawRects(renderer, cross_buttons, NCROSSBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
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

    SDL_Rect cross_buttons[NCROSSBUTTONS] = {crossXX0_area, crossXX1_area, crossXX2_area, crossXX3_area, crossXX4_area, crossXX5_area,
                                             crossX0X_area, crossX1X_area, crossX2X_area, crossX3X_area, crossX4X_area, crossX5X_area,
                                             cross0XX_area, cross1XX_area, cross2XX_area, cross3XX_area, cross4XX_area, cross5XX_area,
                                             crossNE0_area, crossNE1_area, crossNE2_area, crossNE3_area, crossNE4_area, crossNE5_area,
                                             crossEE0_area, crossEE1_area, crossEE2_area, crossEE3_area, crossEE4_area, crossEE5_area,
                                             crossSE0_area, crossSE1_area, crossSE2_area, crossSE3_area, crossSE4_area, crossSE5_area,
                                             crossSW0_area, crossSW1_area, crossSW2_area, crossSW3_area, crossSW4_area, crossSW5_area,
                                             crossWW0_area, crossWW1_area, crossWW2_area, crossWW3_area, crossWW4_area, crossWW5_area,
                                             crossNW0_area, crossNW1_area, crossNW2_area, crossNW3_area, crossNW4_area, crossNW5_area};

    for(i = 0; i < NCROSSBUTTONS; ++i)
    {
        if(isInArea(mouse_button, cross_buttons[i]) != SDL_FALSE)
            return i;
    }

    return NO_CROSSBUTTON;
}

/**
* \fn void initCrossButtons()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Choix d'un croisement".
*
* Initialise les champs des rectangles des zones correspondant aux croisements du plateau.
* Répartit la totalité des croisements selon la formation de 9 hexagones
* dans un tableau bidimensionnel, puis utilise une fonction d'initialisation de position pour chaque hexagone, selon la position et le côté
* de cet hexagone.
* De plus, initialise le côté de toutes les zones selon une constante.
*/
void initCrossButtons()
{
    int i, j;
    float hexagon_h;

    // Répartition des croisements selon la formation de 9 hexagones
    SDL_Rect* cross_buttons[9][6] = {{&crossXX0_area, &crossXX1_area, &crossXX2_area, &crossXX3_area, &crossXX4_area, &crossXX5_area},
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
            cross_buttons[i][j]->h = CROSSS;
            cross_buttons[i][j]->w = CROSSS;
        }
    }

    hexagon_h = (sqrt(3)/2)*HEXAGONS;

    // Initialisation de la position des zones des boutons des croisements par hexagone, selon leur position et leur côté
    initPosRectHex(cross_buttons[0], BOARDCENTERX, BOARDCENTERY, HEXAGONS);                                         // Boutons de la première couronne
    initPosRectHex(cross_buttons[1], BOARDCENTERX, BOARDCENTERY, 2*HEXAGONS);                                       // Boutons de la deuxième couronne
    initPosRectHex(cross_buttons[2], BOARDCENTERX, BOARDCENTERY, 4*HEXAGONS);                                       // Boutons de la troisième couronne
    initPosRectHex(cross_buttons[3], round(BOARDCENTERX + 2*hexagon_h), BOARDCENTERY - 3*HEXAGONS, HEXAGONS);  // Boutons de l'hexagone Nord - Est
    initPosRectHex(cross_buttons[4], round(BOARDCENTERX + 4*hexagon_h), BOARDCENTERY, HEXAGONS);             // Boutons de l'hexagone Est
    initPosRectHex(cross_buttons[5], round(BOARDCENTERX + 2*hexagon_h), BOARDCENTERY + 3*HEXAGONS, HEXAGONS);  // Boutons de l'hexagone Sud - Est
    initPosRectHex(cross_buttons[6], round(BOARDCENTERX - 2*hexagon_h), BOARDCENTERY + 3*HEXAGONS, HEXAGONS);  // Boutons de l'hexagone Sud - Ouest
    initPosRectHex(cross_buttons[7], round(BOARDCENTERX - 4*hexagon_h), BOARDCENTERY, HEXAGONS);             // Boutons de l'hexagone Ouest
    initPosRectHex(cross_buttons[8], round(BOARDCENTERX - 2*hexagon_h), BOARDCENTERY - 3*HEXAGONS, HEXAGONS);  // Boutons de l'hexagone Nord - Ouest
}
