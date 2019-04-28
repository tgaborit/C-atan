/**
* \file controller_turn_buttons.c
* \brief Fonctions de gestion des boutons de l'environnement "Tour du joueur"
* \author Titouan Gaborit
* \date 29 mars 2019
*
* Fonctions gérant l'initialisation des boutons cliquables par le joueur lors de son tour de jeu et la détection d'un clic dessus.
*
*/

#include <SDL.h>

#include "controller.h"
#include "controller_turn_buttons.h"


static SDL_Rect wood_card_area;         /*!< Rectangle correspondant à la zone de la carte Bois*/
static SDL_Rect wheat_card_area;        /*!< Rectangle correspondant à la zone de la carte Blé*/
static SDL_Rect clay_card_area;         /*!< Rectangle correspondant à la zone de la carte Argile*/
static SDL_Rect sheeps_card_area;       /*!< Rectangle correspondant à la zone de la carte Moutons*/
static SDL_Rect rock_card_area;         /*!< Rectangle correspondant à la zone de la carte Roche*/

static SDL_Rect dev_craft_area;         /*!< Rectangle correspondant à la zone du bouton Craft d'une Carte développement*/
static SDL_Rect road_craft_area;        /*!< Rectangle correspondant à la zone du bouton Craft d'une Route*/
static SDL_Rect settle_craft_area;      /*!< Rectangle correspondant à la zone du bouton Craft d'une Colonie*/
static SDL_Rect city_craft_area;        /*!< Rectangle correspondant à la zone du bouton Craft d'une Ville*/

static SDL_Rect dice_area;              /*!< Rectangle correspondant à la zone du bouton Lancer les dés*/
static SDL_Rect end_turn_area;          /*!< Rectangle correspondant à la zone du bouton Fin de tour*/

static SDL_Rect help_area;              /*!< Rectangle correspondant à la zone du bouton Aide*/


void drawButtonsTurn(SDL_Renderer* renderer)
{
    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect turn_buttons[NTURNBUTTONS] = {wood_card_area, wheat_card_area, clay_card_area, sheeps_card_area, rock_card_area,
    dev_craft_area, road_craft_area, settle_craft_area, city_craft_area, dice_area, end_turn_area, help_area};
    if(SDL_RenderDrawRects(renderer, turn_buttons, NTURNBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn TurnButton whichButtonTurn(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton le jouer a cliqué.
*
* Teste pour chaque bouton si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \return Le bouton de l'environnement "Tour du joueur" qui a été cliqué, NO_BUTTON si aucun.
*/
TurnButton whichButtonTurn(SDL_MouseButtonEvent mouse_button){
    TurnButton button_clicked;
    if((button_clicked = whichCardButton(mouse_button)) != NO_BUTTON)
        return button_clicked;
    if((button_clicked = whichCraftButton(mouse_button)) != NO_BUTTON)
        return button_clicked;
    if(isInArea(mouse_button, end_turn_area) == SDL_TRUE)
        return ENDTURN_BUTTON;
    if(isInArea(mouse_button, dice_area) == SDL_TRUE)
        return DICE_BUTTON;
    if(isInArea(mouse_button, help_area) == SDL_TRUE)
        return HELP_BUTTON;
    return NO_BUTTON;
}

/**
* \fn TurnButton whichCardButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton de carte ressource le joueur a cliqué.
*
* Teste pour chaque bouton de carte ressource si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient notamment les informations sur sa position.
* \return Le bouton de carte ressource qui a été cliqué, NO_BUTTON si aucun.
*/
TurnButton whichCardButton(SDL_MouseButtonEvent mouse_button){
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
    return NO_BUTTON;
}

/**
* \fn ControlerButton whichCraftButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton de craft le joueur a cliqué.
*
* Teste pour chaque bouton de craft si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient notamment les informations sur sa position.
* \return Le bouton de craft qui a été cliqué, NO_BUTTON si aucun.
*/
TurnButton whichCraftButton(SDL_MouseButtonEvent mouse_button){
    if(isInArea(mouse_button, dev_craft_area) == SDL_TRUE)
        return DEVCRAFT_BUTTON;
    if(isInArea(mouse_button, road_craft_area) == SDL_TRUE)
        return ROADCRAFT_BUTTON;
    if(isInArea(mouse_button, settle_craft_area) == SDL_TRUE)
        return SETTLECRAFT_BUTTON;
    if(isInArea(mouse_button, city_craft_area) == SDL_TRUE)
        return CITYCRAFT_BUTTON;
    return NO_BUTTON;
}

/**
* \fn void initButtonsTurn()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Tour du joueur"
*
* Initialise les champs des rectangles des zones correspondant aux cartes ressources, au bouton Lancer les dés et au bouton Fin de tour.
* Fait appel aux fonctions d'initialisation correspondantes.
*/
void initButtonsTurn()
{
    initCardsAreas();
    initCraftAreas();
    initDiceArea();
    initEndTurnArea();
    initHelpArea();
}

/**
* \fn void initCardsAreas()
* \brief Fonction d'initialisation des cartes ressources.
*
* Initialise les champs des rectangles des zones correspondant aux cartes ressources.
* Fait appel aux fonctions d'initialisation pour la carte Bois, la carte Blé, la carte Argile, la carte Moutons et la carte Roche.
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
* \fn void initCraftAreas()
* \brief Fonction d'initialisation des boutons de craft.
*
* Initialise les champs des rectangles des zones correspondant aux boutons de craft.
* Fait appel aux fonctions d'initialisation pour le bouton Craft d'une Carte développement, le bouton Craft d'une Route,
* le bouton de Craft d'une Colonie et le bouton de Craft d'une Ville.
*/
void initCraftAreas(){
    initDevCraftArea();
    initRoadCraftArea();
    initSettleCraftArea();
    initCityCraftArea();
}

/**
* \fn void initWoodCard()
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte bois.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Bois sur l'écran du joueur.
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
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte blé.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Blé sur l'écran du joueur.
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
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte argile.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Argile sur l'écran du joueur.
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
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte moutons.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Moutons sur l'écran du joueur.
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
* \brief Fonction d'initialisation des champs du rectangle de la zone de la carte roche.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des cartes ressources.
* Assigne les valeurs de position selon le placement de la carte Roche sur l'écran du joueur.
*/
void initRockCard()
{
    rock_card_area.w = CARDW;
    rock_card_area.h = CARDH;

    rock_card_area.x = sheeps_card_area.x + sheeps_card_area.w + 58;
    rock_card_area.y = WINDOWH - CARDH;
}

/**
* \fn void initDevCraftArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Craft d'une Carte développement.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de craft.
* Assigne les valeurs de position selon le placement du bouton Craft d'une Carte développement sur l'écran du joueur.
*/
void initDevCraftArea()
{
    dev_craft_area.w = CRAFTW;
    dev_craft_area.h = CRAFTH;

    dev_craft_area.x = WINDOWW - 200 - dev_craft_area.w;
    dev_craft_area.y = 300;
}

/**
* \fn void initRoadCraftArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Craft d'une Route.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de craft.
* Assigne les valeurs de position selon le placement du bouton Craft d'une Route sur l'écran du joueur.
*/
void initRoadCraftArea()
{
    road_craft_area.w = CRAFTW;
    road_craft_area.h = CRAFTH;

    road_craft_area.x = dev_craft_area.x;
    road_craft_area.y = dev_craft_area.y + dev_craft_area.h + 50;
}

/**
* \fn void initSettleCraftArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Craft d'une Colonie.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de craft.
* Assigne les valeurs de position selon le placement du bouton Craft d'une Colonie sur l'écran du joueur.
*/
void initSettleCraftArea()
{
    settle_craft_area.w = CRAFTW;
    settle_craft_area.h = CRAFTH;

    settle_craft_area.x = road_craft_area.x;
    settle_craft_area.y = road_craft_area.y + road_craft_area.h + 50;
}

/**
* \fn void initCityCraftArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Craft d'une Ville.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de craft.
* Assigne les valeurs de position selon le placement du bouton Craft d'une Ville sur l'écran du joueur.
*/
void initCityCraftArea()
{
    city_craft_area.w = CRAFTW;
    city_craft_area.h = CRAFTH;

    city_craft_area.x = settle_craft_area.x;
    city_craft_area.y = settle_craft_area.y + settle_craft_area.h + 50;
}

/**
* \fn void initDiesArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Lancer les dés.
*
* Assigne les valeurs de largeur et hauteur d'après la taille souhaitée.
* Assigne les valeurs de position selon le placement souhaité.
*/
void initDiceArea()
{
    dice_area.w = 100;
    dice_area.h = 100;

    dice_area.x = dev_craft_area.x + dev_craft_area.w/2 - dice_area.w/2;
    dice_area.y = 75;
}

/**
* \fn void initEndTurnArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Fin de tour.
*
* Assigne les valeurs de largeur et hauteur d'après la taille souhaitée.
* Assigne les valeurs de position selon le placement souhaité.
*/
void initEndTurnArea()
{
    end_turn_area.w = 150;
    end_turn_area.h = 75;

    end_turn_area.x = 300;
    end_turn_area.y = WINDOWH - 55 - end_turn_area.h;
}

/**
* \fn void initHelpArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Aide.
*
* Assigne les valeurs de largeur et hauteur d'après la taille souhaitée.
* Assigne les valeurs de position selon le placement souhaité.
*/
void initHelpArea()
{
    help_area.w = 35;
    help_area.h = 35;

    help_area.x = WINDOWW - 10 - help_area.w;
    help_area.y = 0;
}
