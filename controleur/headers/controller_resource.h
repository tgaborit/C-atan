/**
* \file controller_resource.h
* \brief En-tête du contrôleur du choix d'une ressource
* \author Titouan Gaborit
* \date 4 mai 2019
*
* En-tête déclarant les fonctions du contrôleur du choix d'une ressource ainsi que la définition des macros relatives.
*
*/

#ifndef CATANE_CONTROLLER_RESOURCE_H
#define CATANE_CONTROLLER_RESOURCE_H

#include <SDL.h>

/**
* \enum ResourceButton
* Tous les boutons existants dans l'environnement "Choix d'une ressource" ainsi que le non-bouton.
*/
typedef enum {
        WOOD_BUTTON,
        WHEAT_BUTTON,
        CLAY_BUTTON,
        SHEEPS_BUTTON,
        ROCK_BUTTON,

        NO_RESOURCEBUTTON
} ResourceButton;

/**
* \def NRESOURCEBUTTONS
* Définit le nombre de boutons de l'environnement "Choix d'une ressource".
*/
#define NRESOURCEBUTTONS 5

/**
* \def CARDW
* Définit la largeur d'une carte ressource.
*/
#define CARDW 115

/**
* \def CARDH
* Définit la hauteur d'une carte ressource.
*/
#define CARDH 166

void controllerResource(ResourceButton* resource_chosen, SDL_Window* window, SDL_bool* program_launched);

void drawResourceButtons(SDL_Window* window);

ResourceButton whichResourceButton(SDL_MouseButtonEvent mouse_button);

void initResourceButtons();
    void initWoodCard();
    void initWheatCard();
    void initClayCard();
    void initSheepsCard();
    void initRockCard();

#endif //CATANE_CONTROLLER_RESOURCE_H
