/**
* \file controller_turn.c
* \brief Fonctions du contrôleur du tour du joueur
* \author Titouan Gaborit
* \date 27 mars 2019
*
* Programme gérant les actions du joueur lors de son tour de jeu : les interactions avec les cartes ressources ainsi que le bouton de fin de tour.
*
*/

#include <stdio.h>
#include <SDL.h>
#include "controller.h"
#include "controller_turn.h"
#include "controller_turn_events.h"
//#include "partie.h"
//#include "fenetre.h"

static SDL_Rect dev_craft_area;         /*!< Rectangle correspondant à la zone du bouton Craft d'une Carte développement*/
static SDL_Rect road_craft_area;        /*!< Rectangle correspondant à la zone du bouton Craft d'une Route*/
static SDL_Rect settle_craft_area;      /*!< Rectangle correspondant à la zone du bouton Craft d'une Colonie*/
static SDL_Rect city_craft_area;        /*!< Rectangle correspondant à la zone du bouton Craft d'une Ville*/

static SDL_Rect knight_dev_area;        /*!< Rectangle correspondant à la zone du bouton de la carte développement Chevalier*/
static SDL_Rect monop_dev_area;         /*!< Rectangle correspondant à la zone du bouton de la carte développement Monopole*/
static SDL_Rect invent_dev_area;        /*!< Rectangle correspondant à la zone du bouton de la carte développement Invention*/
static SDL_Rect roads_dev_area;         /*!< Rectangle correspondant à la zone du bouton de la carte développement Routes*/
static SDL_Rect univ_dev_area;          /*!< Rectangle correspondant à la zone du bouton de la carte développement Université*/

static SDL_Rect dice_area;              /*!< Rectangle correspondant à la zone du bouton Lancer les dés*/
static SDL_Rect end_turn_area;          /*!< Rectangle correspondant à la zone du bouton Fin de tour*/

static SDL_Rect help_area;              /*!< Rectangle correspondant à la zone du bouton Aide*/


/**
* \fn void controllerTurn(SDL_bool* program_launched, Partie* the_game)
* \brief Fonction principale du contrôleur du tour du joueur.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement de son tour de jeu.
* Elle détecte les actions du joueur et fait appel aux fonctions de callback de craft, de carte développement, de lancer de dé, de fin de tour,
* d'aide ou de fin du programme en fonction de ces actions.
*
* \param[in,out] program_launched Pointeur vers l'état du programme : si devient SDL_False, on sort de la fonction et on quitte le programme.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
*/
void controllerTurn(SDL_bool* program_launched, SDL_Window* window/*, Partie* the_game*/)
{
    initTurnButtons();
    while(*program_launched)
    {
        drawTurnButtons(window);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_USEREVENT:
                printf("Appel de la fonction de la vue updateFenetre(the_game, window)\n");
                //updateFenetre(the_game, window);
                break;

            case SDL_MOUSEBUTTONDOWN :
                switch(whichTurnButton(event.button))
                {
                case DEVCRAFT_BUTTON :
                    printf("Clic sur bouton Craft developpement\n");
                    printf("Appel de la fonction craftDevEvent(the_game)\n");
                    craftDevEvent(/*the_game*/);
                    break;

                case ROADCRAFT_BUTTON :
                    printf("Clic sur bouton Craft route\n");
                    printf("Appel de la fonction craftRoadEvent(the_game, window, program_launched)\n");
                    craftRoadEvent(/*the_game, */window, program_launched);
                    break;

                case SETTLECRAFT_BUTTON :
                    printf("Clic sur bouton Craft colonie\n");
                    printf("Appel de la fonction craftSettleEvent(the_game, window, program_launched)\n");
                    craftSettleEvent(/*the_game, */window, program_launched);
                    break;

                case CITYCRAFT_BUTTON :
                    printf("Clic sur bouton Craft ville\n");
                    printf("Appel de la fonction craftCityEvent(the_game, window, program_launched)\n");
                    craftCityEvent(/*the_game, */window, program_launched);
                    break;


                case KNIGHTDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Chevalier\n");
                    printf("Appel de la fonction useKnightEvent(the_game, window, program_launched)\n");
                    useKnightEvent(/*the_game, */window, program_launched);
                    break;

                case MONOPDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Monopole\n");
                    printf("Appel de la fonction useMonopEvent(the_game, window, program_launched)\n");
                    useMonopEvent(/*the_game, */window, program_launched);
                    break;

                case INVENTDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Invention\n");
                    printf("Appel de la fonction useInventEvent(the_game, window, program_launched)\n");
                    useInventEvent(/*the_game, */window, program_launched);
                    break;

                case ROADSDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Routes\n");
                    printf("Appel de la fonction useRoadsEvent(the_game, window, program_launched)\n");
                    useRoadsEvent(/*the_game, */window, program_launched);
                    break;

                case UNIVDEV_BUTTON :
                    printf("Clic sur bouton de carte développement Universite\n");
                    printf("Appel de la fonction useUnivEvent(the_game)\n");
                    useUnivEvent(/*the_game*/);
                    break;


                case ENDTURN_BUTTON :
                    printf("Clic sur bouton Fin de tour\n");
                    printf("Appel de la fonction endTurnEvent(the_game)\n");
                    endTurnEvent(/*the_game*/);
                    break;

                case DICE_BUTTON :
                    printf("Clic sur bouton Lancer les des\n");
                    printf("Appel de la fonction rollDiceEvent(the_game)\n");
                    rollDiceEvent(/*the_game*/window, program_launched);
                    break;

                case HELP_BUTTON :
                    printf("Clic sur bouton Aide\n");
                    break;


                default :
                    break;
                }
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_q :
                    printf("Appui sur touche Q\n");
                    printf("Appel de la fonction quit(program_launched)\n");
                    quit(program_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
                printf("Appel de la fonction quit(program_launched)\n");
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}

void drawTurnButtons(SDL_Window* window)
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

    SDL_Rect turn_buttons[NTURNBUTTONS] = {dev_craft_area, road_craft_area, settle_craft_area, city_craft_area,
    knight_dev_area, monop_dev_area, invent_dev_area, roads_dev_area, univ_dev_area, dice_area, end_turn_area, help_area};
    if(SDL_RenderDrawRects(renderer, turn_buttons, NTURNBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn TurnButton whichTurnButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton le joueur a cliqué.
*
* Teste pour chaque bouton si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \return Le bouton de l'environnement "Tour du joueur" qui a été cliqué, NO_TURNBUTTON si aucun.
*/
TurnButton whichTurnButton(SDL_MouseButtonEvent mouse_button){
    TurnButton button_clicked;
    if((button_clicked = whichCraftButton(mouse_button)) != NO_TURNBUTTON)
        return button_clicked;
    if((button_clicked = whichDevButton(mouse_button)) != NO_TURNBUTTON)
        return button_clicked;
    if(isInArea(mouse_button, end_turn_area) == SDL_TRUE)
        return ENDTURN_BUTTON;
    if(isInArea(mouse_button, dice_area) == SDL_TRUE)
        return DICE_BUTTON;
    if(isInArea(mouse_button, help_area) == SDL_TRUE)
        return HELP_BUTTON;
    return NO_TURNBUTTON;
}

/**
* \fn TurnButton whichCraftButton(SDL_MouseButtonEvent mouse_button)
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
    return NO_TURNBUTTON;
}

/**
* \fn TurnButton whichDevButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton de carte développement le joueur a cliqué.
*
* Teste pour chaque bouton de carte développement si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient notamment les informations sur sa position.
* \return Le bouton de carte développement qui a été cliqué, NO_BUTTON si aucun.
*/
TurnButton whichDevButton(SDL_MouseButtonEvent mouse_button){
    if(isInArea(mouse_button, knight_dev_area) == SDL_TRUE)
        return KNIGHTDEV_BUTTON;
    if(isInArea(mouse_button, monop_dev_area) == SDL_TRUE)
        return MONOPDEV_BUTTON;
    if(isInArea(mouse_button, invent_dev_area) == SDL_TRUE)
        return INVENTDEV_BUTTON;
    if(isInArea(mouse_button, roads_dev_area) == SDL_TRUE)
        return ROADSDEV_BUTTON;
    if(isInArea(mouse_button, univ_dev_area) == SDL_TRUE)
        return UNIVDEV_BUTTON;
    return NO_TURNBUTTON;
}

/**
* \fn void initTurnButtons()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Tour du joueur"
*
* Initialise les champs des rectangles des zones correspondant aux cartes ressources, au bouton Lancer les dés et au bouton Fin de tour.
* Fait appel aux fonctions d'initialisation correspondantes.
*/
void initTurnButtons()
{
    initCraftAreas();
    initDevCardsAreas();
    initDiceArea();
    initEndTurnArea();
    initHelpArea();
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
* \fn void initDevCardsAreas()
* \brief Fonction d'initialisation des boutons des cartes développement.
*
* Initialise les champs des rectangles des zones correspondant aux boutons des cartes développement.
* Fait appel aux fonctions d'initialisation pour la carte Chevalier, la carte Monopole, la carte Invention, la carte Routes et la carte Université.
*/
void initDevCardsAreas()
{
    initKnightDevArea();
    initMonopDevArea();
    initInventDevArea();
    initRoadsDevArea();
    initUnivDevArea();
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

    dev_craft_area.x = WINDOWW - 150 - dev_craft_area.w;
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
* \fn void initKnightDevArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton de la carte développement Chevalier.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de carte développement.
* Assigne les valeurs de position selon le placement du bouton Chevalier sur l'écran du joueur.
*/
void initKnightDevArea()
{
    knight_dev_area.w = DEVW;
    knight_dev_area.h = DEVH;

    knight_dev_area.x = 100;
    knight_dev_area.y = 240;
}

/**
* \fn void initMonopDevArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton de la carte développement Monopole.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de carte développement.
* Assigne les valeurs de position selon le placement du bouton Monopole sur l'écran du joueur.
*/
void initMonopDevArea()
{
    monop_dev_area.w = DEVW;
    monop_dev_area.h = DEVH;

    monop_dev_area.x = knight_dev_area.x;
    monop_dev_area.y = knight_dev_area.y + 25 + monop_dev_area.h;
}

/**
* \fn void initInventDevArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton de la carte développement Invention.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de carte développement.
* Assigne les valeurs de position selon le placement du bouton Invention sur l'écran du joueur.
*/
void initInventDevArea()
{
    invent_dev_area.w = DEVW;
    invent_dev_area.h = DEVH;

    invent_dev_area.x = knight_dev_area.x;
    invent_dev_area.y = monop_dev_area.y + 25 + invent_dev_area.h;
}

/**
* \fn void initRoadsDevArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton de la carte développement Routes.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de carte développement.
* Assigne les valeurs de position selon le placement du bouton Routes sur l'écran du joueur.
*/
void initRoadsDevArea()
{
    roads_dev_area.w = DEVW;
    roads_dev_area.h = DEVH;

    roads_dev_area.x = knight_dev_area.x;
    roads_dev_area.y = invent_dev_area.y + 25 + roads_dev_area.h;
}

/**
* \fn void initUnivDevArea()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton de la carte développement Université.
*
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de carte développement.
* Assigne les valeurs de position selon le placement du bouton Université sur l'écran du joueur.
*/
void initUnivDevArea()
{
    univ_dev_area.w = DEVW;
    univ_dev_area.h = DEVH;

    univ_dev_area.x = knight_dev_area.x;
    univ_dev_area.y = roads_dev_area.y + 25 + univ_dev_area.h;
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
