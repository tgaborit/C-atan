/**
* \file controller.c
* \brief Fonctions générales du contrôleur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* Fonctions utilisées par le contrôleur pour plusieurs environnements.
*
*/

#include <math.h>
#include <SDL.h>
#include "controleur/headers/controller.h"
#include "vue/headers/SDL_erreur.h"

/**
* \fn SDL_bool isInArea(SDL_MouseButtonEvent mouse_button, SDL_Rect area)
* \brief Détecte si un clic a été fait dans une zone précise ou non.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \param[in] area Zone dans laquelle le clic a été fait ou non.
*
* \return SDL_TRUE si le clic a été fait dans la zone, SDL_FALSE sinon.
*/
SDL_bool isInArea(SDL_MouseButtonEvent mouse_button, SDL_Rect area)
{
    if ((mouse_button.x>=area.x)&&(mouse_button.x<=area.x+area.w))
    {
        if ((mouse_button.y>=area.y)&&(mouse_button.y<=area.y+area.h))
            return SDL_TRUE;
    }
    return SDL_FALSE;
}

/**
* \fn void quit(SDL_bool * paction_launched)
* \brief Fonction activant la fin d'une action.
*
* Donne la valeur SDL_False à l'état de l'action, ce qui le fera sortir de la boucle de controler* et quitter cette action.
*
* \param[in,out] paction_launched Pointeur vers l'état d'une action.
*/
void quit(SDL_bool * paction_launched)
{
    *paction_launched = SDL_FALSE;
}

/**
* \fn void initPosRectHex(SDL_Rect** hex_rect, int center_x, int center_y, float hexagon_s)
* \brief Fonction d'initialisation des positions de 6 rectangles selon la formation d'un hexagone.
*
* Initialise les positions des 6 rectangles d'un tableau en formant un hexagone centré selon l'abscisse et l'ordonnée passées en paramètre,
* et de côté passé en paramètre.
* \param[in] hex_rect Tableau de pointeurs sur les rectangles à initialiser.
* \param[in] center_x Abscisse du centre de l'hexagone formé par les 6 rectangles.
* \param[in] center_y Ordonnée du centre de l'hexagone formé par les 6 rectangles.
* \param[in] hexagon_s Côté de l'hexagone formé par les 6 rectangles.
*/
void initPosRectHex(SDL_Rect** hex_rect, float center_x, float center_y, float hexagon_s)
{
    float hexagon_h = (sqrt(3)/2)*hexagon_s;

    hex_rect[0]->x = round(center_x - hex_rect[0]->w/2);
    hex_rect[0]->y = round(center_y - hexagon_s - hex_rect[0]->h/2);

    hex_rect[1]->x = round(center_x + hexagon_h - hex_rect[0]->w/2);
    hex_rect[1]->y = round(center_y - hexagon_s/2 - hex_rect[0]->h/2);

    hex_rect[2]->x = round(center_x + hexagon_h - hex_rect[0]->w/2);
    hex_rect[2]->y = round(center_y + hexagon_s/2 - hex_rect[0]->h/2);

    hex_rect[3]->x = round(center_x - hex_rect[0]->w/2);
    hex_rect[3]->y = round(center_y + hexagon_s - hex_rect[0]->h/2);

    hex_rect[4]->x = round(center_x - hexagon_h - hex_rect[0]->w/2);
    hex_rect[4]->y = round(center_y + hexagon_s/2 - hex_rect[0]->h/2);

    hex_rect[5]->x = round(center_x - hexagon_h - hex_rect[0]->w/2);
    hex_rect[5]->y = round(center_y - hexagon_s/2 - hex_rect[0]->h/2);
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
void initPosRectHexLying(SDL_Rect** hex_buttons, float center_x, float center_y, float hexagon_s)
{
    float hexagon_h = (sqrt(3)/2)*hexagon_s;

    hex_buttons[0]->x = round(center_x + hexagon_s/2 - hex_buttons[0]->w/2);
    hex_buttons[0]->y = round(center_y - hexagon_h - hex_buttons[0]->h/2);

    hex_buttons[1]->x = round(center_x + hexagon_s - hex_buttons[0]->w/2);
    hex_buttons[1]->y = round(center_y - hex_buttons[0]->h/2);

    hex_buttons[2]->x = round(center_x + hexagon_s/2 - hex_buttons[0]->w/2);
    hex_buttons[2]->y = round(center_y + hexagon_h - hex_buttons[0]->h/2);

    hex_buttons[3]->x = round(center_x - hexagon_s/2 - hex_buttons[0]->w/2);
    hex_buttons[3]->y = round(center_y + hexagon_h - hex_buttons[0]->h/2);

    hex_buttons[4]->x = round(center_x - hexagon_s - hex_buttons[0]->w/2);
    hex_buttons[4]->y = round(center_y - hex_buttons[0]->h/2);

    hex_buttons[5]->x = round(center_x - hexagon_s/2 - hex_buttons[0]->w/2);
    hex_buttons[5]->y = round(center_y - hexagon_h - hex_buttons[0]->h/2);
}

//void SDL_ExitWithError(const char *message)
//{
//    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
//    SDL_Quit();
//    exit(EXIT_FAILURE);
//}
