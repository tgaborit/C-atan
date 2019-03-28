#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "controler_turn.h"
#include "controler.h"

#define RED 255
#define GREEN 255
#define BLUE 255

void SDL_ExitWithError(const char *message);

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

    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_bool program_launched = SDL_TRUE;

    controlerTurn(program_launched, renderer);

    //Fermeture fenetre avec destruction rendu et fenetre
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    printf("Test main\n");

    return EXIT_SUCCESS;

}
