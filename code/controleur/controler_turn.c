//
// Created by tgaborit on 27/03/19.
//

#include <SDL.h>
#include "controler.h"
#include "controler_turn.h"

SDL_Rect wood_card_area;

void controlerTurn(SDL_bool program_launched/*, partie * the_partie*/) /*à appeler avec la structure the_partie*/
{
    //printf("Doit afficher 115 : %d\n", CARDW);
    initWoodCard();

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

    wood_card_area.x = BANNERW/2 - CARDW/2;
    wood_card_area.y = WINDOWH - CARDH;
}
