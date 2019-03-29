/**
* \file controler_turn_buttons.c
* \brief Fonctions de gestion des boutons de l'environnement "Tour du joueur"
* \author Titouan Gaborit
* \date 29 mars 2019
*
* Fonctions gérant l'initialisation des boutons cliquables par le joueur lors de son tour de jeu et la détection d'un clic dessus.
*
*/

#include <SDL.h>

#include "controler.h"
#include "controler_turn.h"
#include "controler_turn_buttons.h"

static SDL_Rect wood_card_area;        /*!< Rectangle correspondant à la zone de la carte Bois*/
static SDL_Rect wheat_card_area;       /*!< Rectangle correspondant à la zone de la carte Blé*/
static SDL_Rect clay_card_area;        /*!< Rectangle correspondant à la zone de la carte Argile*/
static SDL_Rect sheeps_card_area;      /*!< Rectangle correspondant à la zone de la carte Moutons*/
static SDL_Rect rock_card_area;        /*!< Rectangle correspondant à la zone de la carte Roche*/

static SDL_Rect end_turn_area;         /*!< Rectangle correspondant à la zone du bouton Fin de tour*/

static SDL_Rect dev_craft_area;
static SDL_Rect road_craft_area;
/**
* \fn void initWoodCard()
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte bois
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Bois sur l'écran du joueur.
*
*/
void initWoodCard()
{
    wood_card_area.w = CARDW;
    wood_card_area.h = CARDH;

    wood_card_area.x = WINDOWW/2 - CARDW/2;/* regler positions par rapport à la vue */
    wood_card_area.y = WINDOWH - CARDH;
}

/**
* \fn void initWheatCard()
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte blé
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Blé sur l'écran du joueur.
*
*/
void initWheatCard()
{
    wheat_card_area.w = CARDW;
    wheat_card_area.h = CARDH;

    wheat_card_area.x = wood_card_area.x - 58 - wheat_card_area.w;
    wheat_card_area.y = WINDOWH - CARDH;
}

/**
* \fn void initClayCard()
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte argile
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Argile sur l'écran du joueur.
*
*/
void initClayCard()
{
    clay_card_area.w = CARDW;
    clay_card_area.h = CARDH;

    clay_card_area.x = wheat_card_area.x - 58 - clay_card_area.w;
    clay_card_area.y = WINDOWH - CARDH;
}

/**
* \fn void initSheepsCard()
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte moutons
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Moutons sur l'écran du joueur.
*
*/
void initSheepsCard()
{
    sheeps_card_area.w = CARDW;
    sheeps_card_area.h = CARDH;

    sheeps_card_area.x = wood_card_area.x + wood_card_area.w + 58;
    sheeps_card_area.y = WINDOWH - CARDH;
}

/**
* \fn void initRockCard()
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte roche
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Roche sur l'écran du joueur.
*
*/
void initRockCard()
{
    rock_card_area.w = CARDW;
    rock_card_area.h = CARDH;

    rock_card_area.x = sheeps_card_area.x + sheeps_card_area.w + 58;
    rock_card_area.y = WINDOWH - CARDH;
}

/**
* \fn void initCardsAreas()
* \brief Fonction d'initialisation des cartes ressources
*
* Initialise les champs des rectangles des zones correspondant aux cartes ressources.
* Fait appel aux fonctions d'initialisation pour la carte Bois, la carte Blé, la carte Argile, la carte Moutons et la carte Roche.
*
*/
void initCardsAreas()
{
    initWoodCard();
    initWheatCard();
    initClayCard();
    initSheepsCard();
    initRockCard();
}

/**
* \fn void initEndTurnArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Fin de tour
*
* Assigne les valeurs de largeur et hauteur d'après la taille souhaitée.
* Assigne les valeurs de position selon le placement souhaité.
*
*/
void initEndTurnArea()
{
    end_turn_area.w = 150;
    end_turn_area.h = 75;

    end_turn_area.x = 300;
    end_turn_area.y = WINDOWH - 55 - end_turn_area.h;
}

void initDevCraftArea()
{
    dev_craft_area.w = CRAFTW;
    dev_craft_area.h = CRAFTH;

    dev_craft_area.x = WINDOWW - 400;
    dev_craft_area.y = 300;
}

void initRoadCraftArea()
{
    road_craft_area.w = CRAFTW;
    road_craft_area.h = CRAFTH;

    road_craft_area.x = dev_craft_area.x;
    road_craft_area.y = dev_craft_area.y + dev_craft_area.h + 50;
}

/**
* \fn ControlerButton whichButtonTurn(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton le jouer a cliqué
*
* Teste pour chaque bouton si le clic efféctué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \return Le bouton de l'environnement "Tour du joueur" qui a été cliqué.
*/
TurnButton whichButtonTurn(SDL_MouseButtonEvent mouse_button){
    if(isInArea(mouse_button, wood_card_area) == SDL_TRUE)
        return WOOD_BUTTON;
    if(isInArea(mouse_button, wheat_card_area) == SDL_TRUE)
        return WHEAT_BUTTON;
    if(isInArea(mouse_button, clay_card_area) == SDL_TRUE)
        return CLAY_BUTTON;
    if(isInArea(mouse_button, sheeps_card_area) == SDL_TRUE)
        return SHEEPS_BUTTON;
    if(isInArea(mouse_button, rock_card_area) == SDL_TRUE)
        return ROCK_BUTTON;
    if(isInArea(mouse_button, end_turn_area) == SDL_TRUE)
        return ENDTURN_BUTTON;
    if(isInArea(mouse_button, dev_craft_area) == SDL_TRUE)
        return DEVCRAFT_BUTTON;
    if(isInArea(mouse_button, road_craft_area) == SDL_TRUE)
        return ROADCRAFT_BUTTON;
    return NO_BUTTON;
}

/**
* \fn void initButtonsTurn()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Tour du joueur"
*
* Initialise les champs des rectangles des zones correspondant aux cartes ressources et au bouton Fin de tour.
* Fait appel aux fonctions d'initialisation correspondantes.
*
*/
void initButtonsTurn()
{
    initCardsAreas();
    initCraftAreas();
    initEndTurnArea();
}

void initCraftAreas(){
    initDevCraftArea();
    initRoadCraftArea();
}

void drawButtons(SDL_Renderer* renderer)
{
    SDL_Rect turn_buttons[NTURNBUTTON] = {wood_card_area, wheat_card_area, clay_card_area, sheeps_card_area, rock_card_area, end_turn_area, dev_craft_area, road_craft_area};
    if(SDL_RenderDrawRects(renderer, turn_buttons, NTURNBUTTON) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");
}
