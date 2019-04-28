/**
* \file controller_place_urb.c
* \brief Fonctions du contrôleur du placement d'une colonie ou d'une ville
* \author Titouan Gaborit
* \date 1 avril 2019
*
* Programme gérant les actions du joueur lors du placement d'une colonie ou d'une ville : le choix du croisement sur lequel elle sera construite.
*
*/

#include <SDL.h>

#include "controller.h"
#include "controller_place_urb.h"
#include "controller_place_urb_buttons.h"

void controllerPlaceUrb(SDL_bool program_launched, SDL_Renderer* renderer/*, Game* the_game*/, UrbPlacing urb_placing)
{
    SDL_bool placing_launched = SDL_TRUE;
    initButtonsPlaceUrb();
    while(program_launched && placing_launched)
    {
        drawButtonsPlaceUrb(renderer);
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN :
                controllerPlaceUrbButton(event.button, &placing_launched/*, the_game,*/, urb_placing);
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_BACKSPACE :
                    printf("Appui sur touche Retour arriere\n");
                    printf("Appel de la fonction quitPlacing(&placing_launched)\n");
                    quitPlacing(&placing_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
                printf("Appel de la fonction quitProgram(&program_launched)\n");
                quitProgram(&program_launched);
                break;

            default :
                break;
            }
        }
    }
}

/**
* \fn void quitPLacing(SDL_bool * pplacing_launched)
* \brief Fonction annulant le placement d'un urb
*
* Donne la valeur SDL_False à l'état du placement, ce qui le fera sortir de la boucle de controlerPlaceUrb
* et revenir à l'environnement Tour du joueur.
*
* \param[in,out] pplacing_launched Pointeur vers l'état du placement
*
*/
void quitPlacing(SDL_bool * pplacing_launched)
{
    *pplacing_launched = SDL_FALSE;
}

void controllerPlaceUrbButton(SDL_MouseButtonEvent button, SDL_bool* pplacing_launched/*, Game* the_game,*/, UrbPlacing urb_placing)
{
    PlaceUrbButton button_clicked  = whichButtonPlaceUrb(button);
    printf("Clic sur croisement n°%d\n", button_clicked);
    switch(button_clicked)
    {
    case CROSSXX0_BUTTON :
        break;
    case CROSSXX1_BUTTON :
        break;
    case CROSSXX2_BUTTON :
        break;
    case CROSSXX3_BUTTON :
        break;
    case CROSSXX4_BUTTON :
        break;
    case CROSSXX5_BUTTON :
        break;
    case CROSSX0X_BUTTON :
        break;
    case CROSSX1X_BUTTON :
        break;
    case CROSSX2X_BUTTON :
        break;
    case CROSSX3X_BUTTON :
        break;
    case CROSSX4X_BUTTON :
        break;
    case CROSSX5X_BUTTON :
        break;
    case CROSS0XX_BUTTON :
        break;
    case CROSS1XX_BUTTON :
        break;
    case CROSS2XX_BUTTON :
        break;
    case CROSS3XX_BUTTON :
        break;
    case CROSS4XX_BUTTON :
        break;
    case CROSS5XX_BUTTON :
        break;
    case CROSSNE0_BUTTON :
        break;
    case CROSSNE1_BUTTON :
        break;
    case CROSSNE2_BUTTON :
        break;
    case CROSSNE3_BUTTON :
        break;
    case CROSSNE4_BUTTON :
        break;
    case CROSSNE5_BUTTON :
        break;
    case CROSSEE0_BUTTON :
        break;
    case CROSSEE1_BUTTON :
        break;
    case CROSSEE2_BUTTON :
        break;
    case CROSSEE3_BUTTON :
        break;
    case CROSSEE4_BUTTON :
        break;
    case CROSSEE5_BUTTON :
        break;
    case CROSSSE0_BUTTON :
        break;
    case CROSSSE1_BUTTON :
        break;
    case CROSSSE2_BUTTON :
        break;
    case CROSSSE3_BUTTON :
        break;
    case CROSSSE4_BUTTON :
        break;
    case CROSSSE5_BUTTON :
        break;
    case CROSSWW0_BUTTON :
        break;
    case CROSSWW1_BUTTON :
        break;
    case CROSSWW2_BUTTON :
        break;
    case CROSSWW3_BUTTON :
        break;
    case CROSSWW4_BUTTON :
        break;
    case CROSSWW5_BUTTON :
        break;
    case CROSSNW0_BUTTON :
        break;
    case CROSSNW1_BUTTON :
        break;
    case CROSSNW2_BUTTON :
        break;
    case CROSSNW3_BUTTON :
        break;
    case CROSSNW4_BUTTON :
        break;
    case CROSSNW5_BUTTON :
        break;
    default :
        break;
    }
}
