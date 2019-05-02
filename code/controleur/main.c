#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "controller.h"
#include "controller_turn.h"
#include "controller_place_urb.h"
#include "controller_place_road.h"

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
        SDL_ExitWithError("Initialisation SDL impossible");

    //Creation de la fenetre et rendu
    if(SDL_CreateWindowAndRenderer(WINDOWW, WINDOWH, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");

    SDL_SetWindowTitle(window, "Catane");

    SDL_bool program_launched = SDL_TRUE;

    controllerTurn(&program_launched, renderer);
    //controllerPlaceUrb(program_launched, renderer, SETTLE_PLACING);
    //controllerPlaceRoad(program_launched, renderer);
    //Fermeture fenetre avec destruction rendu et fenetre
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}
