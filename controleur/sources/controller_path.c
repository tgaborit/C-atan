/**
* \file controller_path.c
* \brief Fonctions du contrôleur du choix d'un chemin
* \author Titouan Gaborit
* \date 1 mai 2019
*
* Programme gérant l'environnement du choix d'un chemin : la détection d'un clic dessus par le joueur
* ou encore le fait de quitter l'environnement ou le programme.
*
*/

#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "controller.h"
#include "controller_path.h"
#include "SDL_erreur.h"


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

static SDL_Rect pathNN0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Nord*/
static SDL_Rect pathNN1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Nord*/
static SDL_Rect pathNN2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Nord*/
static SDL_Rect pathNN3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Nord*/
static SDL_Rect pathNN4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Nord*/
static SDL_Rect pathNN5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Nord*/

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

static SDL_Rect pathSE0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Sud - Est*/
static SDL_Rect pathSE1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Sud - Est*/
static SDL_Rect pathSE2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Sud - Est*/
static SDL_Rect pathSE3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Sud - Est*/
static SDL_Rect pathSE4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Sud - Est*/
static SDL_Rect pathSE5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Sud - Est*/

static SDL_Rect pathSS0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Sud*/
static SDL_Rect pathSS1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Sud*/
static SDL_Rect pathSS2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Sud*/
static SDL_Rect pathSS3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Sud*/
static SDL_Rect pathSS4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Sud*/
static SDL_Rect pathSS5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Sud*/

static SDL_Rect pathSW0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Sud - Ouest*/
static SDL_Rect pathSW5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Sud - Ouest*/

static SDL_Rect pathNW0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone Nord - Ouest*/
static SDL_Rect pathNW5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone Nord - Ouest*/

static SDL_Rect pathST0_area;          /*!< Rectangle correspondant à la zone du chemin 0 de l'hexagone debout*/
static SDL_Rect pathST1_area;          /*!< Rectangle correspondant à la zone du chemin 1 de l'hexagone debout*/
static SDL_Rect pathST2_area;          /*!< Rectangle correspondant à la zone du chemin 2 de l'hexagone debout*/
static SDL_Rect pathST3_area;          /*!< Rectangle correspondant à la zone du chemin 3 de l'hexagone debout*/
static SDL_Rect pathST4_area;          /*!< Rectangle correspondant à la zone du chemin 4 de l'hexagone debout*/
static SDL_Rect pathST5_area;          /*!< Rectangle correspondant à la zone du chemin 5 de l'hexagone debout*/

static SDL_Rect pathO00_area;          /*!< Rectangle correspondant à la zone du chemin 00 des chemins orphelins*/
static SDL_Rect pathO01_area;          /*!< Rectangle correspondant à la zone du chemin 01 des chemins orphelins*/
static SDL_Rect pathO10_area;          /*!< Rectangle correspondant à la zone du chemin 10 des chemins orphelins*/
static SDL_Rect pathO11_area;          /*!< Rectangle correspondant à la zone du chemin 11 des chemins orphelins*/
static SDL_Rect pathO20_area;          /*!< Rectangle correspondant à la zone du chemin 20 des chemins orphelins*/
static SDL_Rect pathO21_area;          /*!< Rectangle correspondant à la zone du chemin 21 des chemins orphelins*/
static SDL_Rect pathO30_area;          /*!< Rectangle correspondant à la zone du chemin 30 des chemins orphelins*/
static SDL_Rect pathO31_area;          /*!< Rectangle correspondant à la zone du chemin 31 des chemins orphelins*/
static SDL_Rect pathO40_area;          /*!< Rectangle correspondant à la zone du chemin 40 des chemins orphelins*/
static SDL_Rect pathO41_area;          /*!< Rectangle correspondant à la zone du chemin 41 des chemins orphelins*/
static SDL_Rect pathO50_area;          /*!< Rectangle correspondant à la zone du chemin 50 des chemins orphelins*/
static SDL_Rect pathO51_area;          /*!< Rectangle correspondant à la zone du chemin 51 des chemins orphelins*/

/**
* \fn void controllerPath(PathButton* path_chosen, SDL_bool* program_launched)
* \brief Fonction principale du contrôleur du choix d'un chemin.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du choix d'un chemin.
* Elle détecte les actions du joueur et enregistre le chemin cliqué le cas échéant, quitte le programme ou l'environnement.
*
* \param[in,out] path_chosen Pointeur vers le chemin choisi dans lequel sera enregistré le chemin cliqué.
* \param[in] window Pointeur vers la fenêtre du jeu.
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on quitte le programme.
*/
void controllerPath(PathButton* path_chosen, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_bool choice_launched = SDL_TRUE;
    initPathButtons();
    while(choice_launched)
    {
        drawPathButtons(window);
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            PathButton path_clicked;
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN :
                if((path_clicked = whichPathButton(event.button)) != NO_PATHBUTTON)
                {
                    *path_chosen = path_clicked;
                    quit(&choice_launched);
                }
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_BACKSPACE :
                    quit(&choice_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                quit(&choice_launched);
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}

/**
* \fn void drawPathButtons(SDL_Window* window)
* \brief Fonction d'affichage des boutons de l'environnement du choix d'un chemin
*
* Regroupe tous les boutons de l'envrionnement du choix d'un chemin dans un tableau, puis les affiche de couleur blanche, par-dessus
* sur le rendu de la fenêtre.
* \param[in,out] window Pointeur vers la fenêtre du jeu.
*/
void drawPathButtons(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_GetRenderer(window);

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect path_buttons[NPATHBUTTONS] = {pathXX0_area, pathXX1_area, pathXX2_area, pathXX3_area, pathXX4_area, pathXX5_area,
                                           pathX0X_area, pathX1X_area, pathX2X_area, pathX3X_area, pathX4X_area, pathX5X_area,
                                           path0XX_area, path1XX_area, path2XX_area, path3XX_area, path4XX_area, path5XX_area,
                                           pathNN0_area, pathNN1_area, pathNN2_area, pathNN3_area, pathNN4_area, pathNN5_area,
                                           pathNE0_area, pathNE1_area, pathNE2_area, pathNE3_area, pathNE4_area, pathNE5_area,
                                           pathSE0_area, pathSE1_area, pathSE2_area, pathSE3_area, pathSE4_area, pathSE5_area,
                                           pathSS0_area, pathSS1_area, pathSS2_area, pathSS3_area, pathSS4_area, pathSS5_area,
                                           pathSW0_area, pathSW1_area, pathSW2_area, pathSW3_area, pathSW4_area, pathSW5_area,
                                           pathNW0_area, pathNW1_area, pathNW2_area, pathNW3_area, pathNW4_area, pathNW5_area,
                                           pathST0_area, pathST1_area, pathST2_area, pathST3_area, pathST4_area, pathST5_area,
                                           pathO00_area, pathO01_area, pathO10_area, pathO11_area, pathO20_area, pathO21_area,
                                           pathO30_area, pathO31_area, pathO40_area, pathO41_area, pathO50_area, pathO51_area};
    if(SDL_RenderDrawRects(renderer, path_buttons, NPATHBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn PathButton whichPathButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton de chemin le joueur a cliqué.
*
* Teste pour chaque bouton de chemin si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient notamment les informations sur sa position.
* \return Le bouton de chemin qui a été cliqué, NO_PATHBUTTON si aucun.
*/
PathButton whichPathButton(SDL_MouseButtonEvent mouse_button){
    int i;

    SDL_Rect path_buttons[NPATHBUTTONS] = {pathXX0_area, pathXX1_area, pathXX2_area, pathXX3_area, pathXX4_area, pathXX5_area,
                                           pathX0X_area, pathX1X_area, pathX2X_area, pathX3X_area, pathX4X_area, pathX5X_area,
                                           path0XX_area, path1XX_area, path2XX_area, path3XX_area, path4XX_area, path5XX_area,
                                           pathNN0_area, pathNN1_area, pathNN2_area, pathNN3_area, pathNN4_area, pathNN5_area,
                                           pathNE0_area, pathNE1_area, pathNE2_area, pathNE3_area, pathNE4_area, pathNE5_area,
                                           pathSE0_area, pathSE1_area, pathSE2_area, pathSE3_area, pathSE4_area, pathSE5_area,
                                           pathSS0_area, pathSS1_area, pathSS2_area, pathSS3_area, pathSS4_area, pathSS5_area,
                                           pathSW0_area, pathSW1_area, pathSW2_area, pathSW3_area, pathSW4_area, pathSW5_area,
                                           pathNW0_area, pathNW1_area, pathNW2_area, pathNW3_area, pathNW4_area, pathNW5_area,
                                           pathST0_area, pathST1_area, pathST2_area, pathST3_area, pathST4_area, pathST5_area,
                                           pathO00_area, pathO01_area, pathO10_area, pathO11_area, pathO20_area, pathO21_area,
                                           pathO30_area, pathO31_area, pathO40_area, pathO41_area, pathO50_area, pathO51_area};

    for(i = 0; i<NPATHBUTTONS; ++i)
    {
        if(isInArea(mouse_button, path_buttons[i]) != SDL_FALSE)
            return i;
    }

    return NO_PATHBUTTON;
}

/**
* \fn void initPathButton()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Choix d'un chemin".
*
* Initialise les champs des rectangles des zones correspondant aux chemins du plateau.
* Répartit la totalité des chemins selon la formation de 9 hexagones couchés, 1 hexagone debout, et 12 chemins orphelins
* dans un tableau bidimensionnel, puis utilise une fonction d'initialisation de position pour chaque hexagone, selon la position et le côté
* de cet hexagone, ainsi qu'une fonction d'initialisation pour les chemisn orphelins.
* De plus, initialise le côté de toutes les zones selon une constante.
*/
void initPathButtons()
{
    int i, j;
    float hexagonl_s;

    // Répartition des chemins selon la formation de 9 hexagones couchés, 1 hexagone debout et 2x6 chemins orphelins
    SDL_Rect* path_buttons[12][6] = {{&pathXX0_area, &pathXX1_area, &pathXX2_area, &pathXX3_area, &pathXX4_area, &pathXX5_area},
                                     {&pathX0X_area, &pathX1X_area, &pathX2X_area, &pathX3X_area, &pathX4X_area, &pathX5X_area},
                                     {&path0XX_area, &path1XX_area, &path2XX_area, &path3XX_area, &path4XX_area, &path5XX_area},
                                     {&pathNN0_area, &pathNN1_area, &pathNN2_area, &pathNN3_area, &pathNN4_area, &pathNN5_area},
                                     {&pathNE0_area, &pathNE1_area, &pathNE2_area, &pathNE3_area, &pathNE4_area, &pathNE5_area},
                                     {&pathSE0_area, &pathSE1_area, &pathSE2_area, &pathSE3_area, &pathSE4_area, &pathSE5_area},
                                     {&pathSS0_area, &pathSS1_area, &pathSS2_area, &pathSS3_area, &pathSS4_area, &pathSS5_area},
                                     {&pathSW0_area, &pathSW1_area, &pathSW2_area, &pathSW3_area, &pathSW4_area, &pathSW5_area},
                                     {&pathNW0_area, &pathNW1_area, &pathNW2_area, &pathNW3_area, &pathNW4_area, &pathNW5_area},
                                     {&pathST0_area, &pathST1_area, &pathST2_area, &pathST3_area, &pathST4_area, &pathST5_area},
                                     {&pathO00_area, &pathO01_area, &pathO10_area, &pathO11_area, &pathO20_area, &pathO21_area},
                                     {&pathO30_area, &pathO31_area, &pathO40_area, &pathO41_area, &pathO50_area, &pathO51_area}};

    // Initialisation des côtés des zones des boutons des chemins
    for(i = 0; i < 12; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            path_buttons[i][j]->h = PATHS;
            path_buttons[i][j]->w = PATHS;
        }
    }

    hexagonl_s = (sqrt(3)/2)*HEXAGONS;

    // Initialisation de la position des zones des boutons des chemins par hexagone, selon leur position et leur côté
    initPosRectHexLying(path_buttons[0], BOARDCENTERX, BOARDCENTERY, hexagonl_s);                                           // Boutons de la première couronne
    initPosRectHexLying(path_buttons[1], BOARDCENTERX, BOARDCENTERY, 3*hexagonl_s);                                         // Boutons de la deuxième couronne
    initPosRectHexLying(path_buttons[2], BOARDCENTERX, BOARDCENTERY, 5*hexagonl_s);                                         // Boutons de la troisième couronne
    initPosRectHexLying(path_buttons[3], BOARDCENTERX, BOARDCENTERY - 3*HEXAGONS, hexagonl_s);                              // Boutons de l'hexagone Nord
    initPosRectHexLying(path_buttons[4], BOARDCENTERX + 3*hexagonl_s, BOARDCENTERY - HEXAGONS - (float)HEXAGONS/2, hexagonl_s);    // Boutons de l'hexagone Est
    initPosRectHexLying(path_buttons[5], BOARDCENTERX + 3*hexagonl_s, BOARDCENTERY + HEXAGONS + (float)HEXAGONS/2, hexagonl_s);    // Boutons de l'hexagone Sud - Est
    initPosRectHexLying(path_buttons[6], BOARDCENTERX, BOARDCENTERY + 3*HEXAGONS, hexagonl_s);                              // Boutons de l'hexagone Sud
    initPosRectHexLying(path_buttons[7], BOARDCENTERX - 3*hexagonl_s, BOARDCENTERY + HEXAGONS + (float)HEXAGONS/2, hexagonl_s);    // Boutons de l'hexagone Sud - Ouest
    initPosRectHexLying(path_buttons[8], BOARDCENTERX - 3*hexagonl_s, BOARDCENTERY - HEXAGONS - (float)HEXAGONS/2, hexagonl_s);    // Boutons de l'hexagone Nord - Ouest
    initPosRectHex(path_buttons[9], BOARDCENTERX, BOARDCENTERY, HEXAGONS + (float)HEXAGONS/2);                                     // Boutons de l'hexagone debout
    initPosRectOthers();                                                                                                    // Boutons des 12 chemins orphelins
}

/**
* \fn void initPosRectOthers()
* \brief Fonction d'initialisation de la position des rectangles chemins orphelins.
*
* Assigne les valeurs de position selon le placement souhaité.
*/
void initPosRectOthers(){

    float hexagonl_s, hexagonl_h;

    hexagonl_s = (sqrt(3)/2)*HEXAGONS;
    hexagonl_h = (sqrt(3)/2)*hexagonl_s;

    pathO00_area.x = pathO31_area.x = (int)round((double)(BOARDCENTERX - hexagonl_s - hexagonl_s/2 - (float)pathO00_area.w/2));
    pathO00_area.y = pathO01_area.y = (int)round((double)(BOARDCENTERY - 3*HEXAGONS - hexagonl_h - (float)pathO00_area.h/2));
    pathO01_area.x = pathO30_area.x = (int)round((double)(BOARDCENTERX + hexagonl_s + hexagonl_s/2 - (float)pathO01_area.w/2));
    pathO30_area.y = pathO31_area.y = (int)round((double)(BOARDCENTERY + 3*HEXAGONS + hexagonl_h - (float)pathO20_area.h/2));

    pathO11_area.x = pathO20_area.x = (int)round((double)(BOARDCENTERX + 4*hexagonl_s + hexagonl_s/2 - (float)pathO10_area.w/2));
    pathO11_area.y = pathO50_area.y = (int)round((double)(BOARDCENTERY - hexagonl_h - (float)pathO11_area.h/2));
    pathO41_area.x = pathO50_area.x = (int)round((double)(BOARDCENTERX - 4*hexagonl_s - hexagonl_s/2 - (float)pathO41_area.w/2));
    pathO20_area.y = pathO41_area.y = (int)round((double)(BOARDCENTERY + hexagonl_h - (float)pathO11_area.h/2));

    pathO10_area.x = pathO21_area.x = (int)round((double)(BOARDCENTERX + 3*hexagonl_s - (float)pathO10_area.w/2));
    pathO10_area.y = pathO51_area.y = (int)round((double)(BOARDCENTERY - 3*HEXAGONS - (float)pathO10_area.h/2));
    pathO21_area.y = pathO40_area.y = (int)round((double)(BOARDCENTERY + 3*HEXAGONS - (float)pathO21_area.h/2));
    pathO40_area.x = pathO51_area.x = (int)round((double)(BOARDCENTERX - 3*hexagonl_s - (float)pathO40_area.w/2));
}
