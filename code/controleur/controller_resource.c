/**
* \file controller_resource.c
* \brief Fonctions du contrôleur du choix d'une ressource
* \author Titouan Gaborit
* \date 4 mai 2019
*
* Programme gérant l'environnement du choix d'une ressource : la détection d'un clic dessus par le joueur
* ou encore le fait de quitter le programme.
*
*/

#include <stdio.h>
#include <SDL.h>

#include "controller.h"
#include "controller_resource.h"

static SDL_Rect wood_card_area;         /*!< Rectangle correspondant à la zone de la carte Bois*/
static SDL_Rect wheat_card_area;        /*!< Rectangle correspondant à la zone de la carte Blé*/
static SDL_Rect clay_card_area;         /*!< Rectangle correspondant à la zone de la carte Argile*/
static SDL_Rect sheeps_card_area;       /*!< Rectangle correspondant à la zone de la carte Moutons*/
static SDL_Rect rock_card_area;         /*!< Rectangle correspondant à la zone de la carte Roche*/

/**
* \fn void controllerResource(PathButton* path_chosen, SDL_bool* program_launched)
* \brief Fonction principale du contrôleur du choix d'une ressource.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du choix d'une ressource.
* Elle détecte les actions du joueur et enregistre la ressource cliquée le cas échéant.
*
* \param[in,out] path_chosen Pointeur vers la ressource choisie dans laquelle sera enregistrée la ressource cliquée.
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on quitte le programme.
*/
void controllerResource(ResourceButton* resource_chosen, SDL_Renderer* renderer, SDL_bool* program_launched)
{
    SDL_bool choice_launched = SDL_TRUE;
    initResourceButtons();
    while(choice_launched)
    {
        drawResourceButtons(renderer);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN :
                switch(whichResourceButton(event.button))
                {
                case WOOD_BUTTON :
                    printf("Clic sur carte bois\n");
                    *resource_chosen = WOOD_BUTTON;
                    quit(&choice_launched);
                    break;

                case WHEAT_BUTTON :
                    printf("Clic sur carte ble\n");
                    *resource_chosen = WHEAT_BUTTON;
                    quit(&choice_launched);
                    break;

                case CLAY_BUTTON :
                    printf("Clic sur carte argile\n");
                    *resource_chosen = CLAY_BUTTON;
                    quit(&choice_launched);
                    break;

                case SHEEPS_BUTTON :
                    printf("Clic sur carte moutons\n");
                    *resource_chosen = SHEEPS_BUTTON;
                    quit(&choice_launched);
                    break;

                case ROCK_BUTTON :
                    printf("Clic sur carte roche\n");
                    *resource_chosen = ROCK_BUTTON;
                    quit(&choice_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
                *resource_chosen = NO_RESOURCEBUTTON;
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

void drawResourceButtons(SDL_Renderer* renderer)
{
    //Nettoyage du rendu
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect resource_buttons[NRESOURCEBUTTONS] = {wood_card_area, wheat_card_area, clay_card_area, sheeps_card_area, rock_card_area};
    if(SDL_RenderDrawRects(renderer, resource_buttons, NRESOURCEBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn TurnButton whichResourceButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton de carte ressource le joueur a cliqué.
*
* Teste pour chaque bouton de carte ressource si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient notamment les informations sur sa position.
* \return Le bouton de carte ressource qui a été cliqué, NO_RESOURCEBUTTON si aucun.
*/
ResourceButton whichResourceButton(SDL_MouseButtonEvent mouse_button){
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
    return NO_RESOURCEBUTTON;
}

/**
* \fn void initResourceButtons()
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Choix d'une ressource".
*
* Initialise les champs des rectangles des zones correspondant aux boutons des cartes ressources.
* Fait appel aux fonctions d'initialisation pour la carte Bois, la carte Blé, la carte Argile, la carte Moutons et la carte Roche.
*/
void initResourceButtons()
{
    initWoodCard();
    initWheatCard();
    initClayCard();
    initSheepsCard();
    initRockCard();
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
