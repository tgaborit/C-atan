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
    printf("Clic sur bouton n°%d\n", button_clicked);
    switch(button_clicked)
    {
    case CROSSXX0_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, 0, 1, urb_placing);
        break;

    case CROSSXX1_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, 0, 2, urb_placing);
        break;

    case CROSSXX2_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, 0, 3, urb_placing);
        break;

    case CROSSXX3_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, 0, 4, urb_placing);
        break;

    case CROSSXX4_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, 0, 5, urb_placing);
        break;

    case CROSSXX5_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, 0, 0, urb_placing);
        break;

    case CROSSX0X_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, 2, 4, urb_placing);
        break;

    case CROSSX1X_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, 0, 1, urb_placing);
        break;

    case CROSSX2X_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, 0, 4, urb_placing);
        break;

    case CROSSX3X_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, -2, 1, urb_placing);
        break;

    case CROSSX4X_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, 0, 4, urb_placing);
        break;

    case CROSSX5X_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, 0, 1, urb_placing);
        break;

    case CROSS0XX_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, 2, 1, urb_placing);
        break;

    case CROSS1XX_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1.5, 1, 2, urb_placing);
        break;

    case CROSS2XX_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1.5, -1, 3, urb_placing);
        break;

    case CROSS3XX_BUTTON :
        break;
        placeUrbEvent(pplacing_launched/*, the_game,*/, 0, -2, 4, urb_placing);

    case CROSS4XX_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1.5, -1, 5, urb_placing);
        break;

    case CROSS5XX_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1.5, 1, 0, urb_placing);
        break;

    case CROSSNE0_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, 2, 1, urb_placing);
        break;

    case CROSSNE1_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, 2, 2, urb_placing);
        break;

    case CROSSNE2_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, 2, 3, urb_placing);
        break;

    case CROSSNE3_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, 2, 4, urb_placing);
        break;

    case CROSSNE4_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, 2, 5, urb_placing);
        break;

    case CROSSNE5_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, 2, 0, urb_placing);
        break;

    case CROSSEE0_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 2, 0, 1, urb_placing);
        break;

    case CROSSEE1_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 2, 0, 2, urb_placing);
        break;

    case CROSSEE2_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 2, 0, 3, urb_placing);
        break;

    case CROSSEE3_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 2, 0, 4, urb_placing);
        break;

    case CROSSEE4_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 2, 0, 5, urb_placing);
        break;

    case CROSSEE5_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 2, 0, 0, urb_placing);
        break;

    case CROSSSE0_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, -2, 1, urb_placing);
        break;

    case CROSSSE1_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, -2, 2, urb_placing);
        break;

    case CROSSSE2_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, -2, 3, urb_placing);
        break;

    case CROSSSE3_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, -2, 4, urb_placing);
        break;

    case CROSSSE4_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, -2, 5, urb_placing);
        break;

    case CROSSSE5_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, 1, -2, 0, urb_placing);
        break;

    case CROSSSW0_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, -2, 1, urb_placing);
        break;

    case CROSSSW1_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, -2, 2, urb_placing);
        break;

    case CROSSSW2_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, -2, 3, urb_placing);
        break;

    case CROSSSW3_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, -2, 4, urb_placing);
        break;

    case CROSSSW4_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, -2, 5, urb_placing);
        break;

    case CROSSSW5_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, -2, 0, urb_placing);
        break;

    case CROSSWW0_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -2, 0, 1, urb_placing);
        break;

    case CROSSWW1_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -2, 0, 2, urb_placing);
        break;

    case CROSSWW2_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -2, 0, 3, urb_placing);
        break;

    case CROSSWW3_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -2, 0, 4, urb_placing);
        break;

    case CROSSWW4_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -2, 0, 5, urb_placing);
        break;

    case CROSSWW5_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -2, 0, 0, urb_placing);
        break;

    case CROSSNW0_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, 2, 1, urb_placing);
        break;

    case CROSSNW1_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, 2, 2, urb_placing);
        break;

    case CROSSNW2_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, 2, 3, urb_placing);
        break;

    case CROSSNW3_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, 2, 4, urb_placing);
        break;

    case CROSSNW4_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, 2, 5, urb_placing);
        break;

    case CROSSNW5_BUTTON :
        placeUrbEvent(pplacing_launched/*, the_game,*/, -1, 2, 0, urb_placing);
        break;

    default :
        break;
    }
}

void placeUrbEvent(SDL_bool* pplacing_launched/*, Game* the_game,*/, double x, double y, int position, UrbPlacing urb_placing)
{
    printf("Appel de la fonction placeUrbEvent(pplacing_launched, the_game, %f, %f, %d, urb_placing)\n", x, y, position);
    if(urb_placing == SETTLE_PLACING)
    {
        printf("Appel de la fonction du modele setColonie(the_game, %f, %f, %d)\n", x, y, position);
        /*
        if(setColonie(the_game, x, y, position) == 0)
        {
        */
            printf("Hypothese : setColonie(the_game, %f, %f, %d) == 1\n", x, y, position);

            printf("Appel de la fonction quitPlacing(pplacing_launched)\n");
            quitPlacing(pplacing_launched);
        /*
        }
        */
    }
    else
    {
        printf("Appel de la fonction du modele setVille(the_game, %f, %f, %d)\n", x, y, position);
        /*
        if(setVille(the_game, x, y, position) == 0)
        {
        */
            printf("Hypothese : setVille(the_game, %f, %f, %d) == 1\n", x, y, position);

            printf("Appel de la fonction quitPlacing(pplacing_launched)\n");
            quitPlacing(pplacing_launched);
        /*
        }
        */
    }
}
