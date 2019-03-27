//
// Created by tgaborit on 27/03/19.
//

#include <SDL.h>
#include "controler_turn.h"

void controler_turn(SDL_bool program_launched/*, partie * the_partie*/) /*à appeler avec la structure the_partie*/
{

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
                    program_launched = SDL_FALSE;
                    break;
                default :
                    continue;
                }

            case SDL_QUIT :
                program_launched = SDL_FALSE;
                break;

            default :
                break;
            }
        }
    }
}
