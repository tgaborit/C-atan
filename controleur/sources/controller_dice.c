/**
* \file controller_dice.c
* \brief Fonctions du contrôleur du tour du joueur
* \author Titouan Gaborit
* \date 25 mai 2019
*
* Programme gérant les actions du joueur lors de son lancer de dés.
*
*/

#include <stdio.h>
#include "controller_dice.h"
#include "controller.h"
#include "controller_turn_events.h"
#include "partie.h"
#include "fenetre.h"
#include "SDL_erreur.h"

static SDL_Rect dice_area;              /*!< Rectangle correspondant à la zone du bouton Lancer les dés*/

void controllerDice(SDL_bool* program_launched, SDL_Window* window, Partie* the_game)
{
    updateFenetre(the_game, window);
    initDiceButton();
    SDL_bool throw_launched = SDL_TRUE;
    while(throw_launched == SDL_TRUE)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN :
                switch(whichDiceButton(event.button))
                {
                case DICE_BUTTON :
                    printf("Clic sur bouton Lancer les des\n");
                    printf("Appel de la fonction rollDiceEvent(the_game)\n");
                    rollDiceEvent(the_game, window, program_launched);
                    printf("Appel de la fonction quit(&throw_launched)\n");
                    quit(&throw_launched);
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
                    printf("Appel de la fonction quit(&throw_launched)\n");
                    quit(&throw_launched);
                    printf("Appel de la fonction quit(program_launched)\n");
                    quit(program_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
                printf("Appel de la fonction quit(&throw_launched)\n");
                quit(&throw_launched);
                printf("Appel de la fonction quit(program_launched)\n");
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}

void drawDiceButton(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_GetRenderer(window);

//    //Nettoyage du rendu
//    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
//        SDL_ExitWithError("Impossible de changer la couleur du rendu");
//
//    if(SDL_RenderClear(renderer) != 0)
//        SDL_ExitWithError("Impossible de nettoyer le rendu");

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect dice_button[1] = {dice_area};
    if(SDL_RenderDrawRects(renderer, dice_button, 1) != 0)
        SDL_ExitWithError("Impossible de dessiner le bouton");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn DiceButton whichDiceButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton le joueur a cliqué.
*
* Teste pour chaque bouton si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient les informations sur sa position notamment.
* \return Le bouton de l'environnement "Tour du joueur" qui a été cliqué, NO_TDICEBUTTON si aucun.
*/
DiceButton whichDiceButton(SDL_MouseButtonEvent mouse_button){
    if(isInArea(mouse_button, dice_area) == SDL_TRUE)
        return DICE_BUTTON;
    return NO_DICEBUTTON;
}

/**
* \fn void initDiceButton()
* \brief Fonction d'initialisation des champs du rectangle de la zone du bouton Lancer les dés.
*
* Assigne les valeurs de largeur et hauteur d'après la taille souhaitée.
* Assigne les valeurs de position selon le placement souhaité.
*/
void initDiceButton()
{
    dice_area.w = 100;
    dice_area.h = 100;

    dice_area.x = WINDOWW - 250 - dice_area.w;
    dice_area.y = 75;
}
