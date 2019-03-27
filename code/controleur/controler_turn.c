//
// Created by tgaborit on 27/03/19.
//

#include <SDL.h>
#include "controler.h"
#include "controler_turn.h"

SDL_Rect wood_card_area;        /* rectangles correspondant aux zones des cartes ressources*/
SDL_Rect wheat_card_area;       /* initialisés une seule fois dans les fonctions init*Card*/

void controlerTurn(SDL_bool program_launched/*, partie * the_partie*/) /*à appeler avec la structure the_partie*/
{
    //printf("Doit afficher 115 : %d\n", CARDW);
    initCardsAreas();

    while(program_launched)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_USEREVENT:
                /*AffichePlateau(the_partie);*/
                printf("Appel de la fonction AffichePlateau(the_partie)\n");
                break;

            case SDL_MOUSEBUTTONDOWN :
                if(isInArea(event.button, wood_card_area)==SDL_TRUE)
                    printf("Clic sur carte bois\n");
                if(isInArea(event.button, wheat_card_area)==SDL_TRUE)
                    printf("Clic sur carte ble\n");
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_q :
                    //program_launched = SDL_FALSE;
                    quit(&program_launched);
                    break;

                default :
                    continue;
                }

            case SDL_QUIT :
                //program_launched = SDL_FALSE;
                quit(&program_launched);
                break;

            default :
                break;
            }
        }
    }
}

void quit(SDL_bool * program_launched)
{
    *program_launched = SDL_FALSE;
    printf("execution fonction quit()\n");
}

void initWoodCard()
{
    wood_card_area.w = CARDW;
    wood_card_area.h = CARDH;

    wood_card_area.x = WINDOWW/2 - CARDW/2;
    wood_card_area.y = WINDOWH - CARDH;
}

void initWheatCard()
{
    wheat_card_area.w = CARDW;
    wheat_card_area.h = CARDH;

    wheat_card_area.x = wood_card_area.x-58-wood_card_area.w;
    wheat_card_area.y = WINDOWH - CARDH;
}

void initCardsAreas(){
    initWoodCard();
    initWheatCard();
    }

SDL_bool isInArea(SDL_MouseButtonEvent mouse_button, SDL_Rect area)
{
    if ((mouse_button.x>=area.x)&&(mouse_button.x<=area.x+area.w))
    {
        if ((mouse_button.y>=area.y)&&(mouse_button.y<=area.y+area.h))
            return SDL_TRUE;
    }
    return SDL_FALSE;
}
