/**
* \file controller_terrain.c
* \brief Fonctions du contrôleur du choix d'un terrain
* \author Titouan Gaborit
* \date 6 mai 2019
*
* Programme gérant l'environnement du choix d'une terrain : la détection d'un clic dessus par le joueur
* ou encore le fait de quitter le programme.
*
*/

#include <stdio.h>
#include <SDL.h>
#include "controller_terrain.h"
#include "controller.h"

/**
* \fn void controllerTerrain(PathButton* path_chosen, SDL_bool* program_launched)
* \brief Fonction principale du contrôleur du choix d'une ressource.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du choix d'un terrain.
* Elle détecte les actions du joueur et enregistre le terrain cliqué le cas échéant.
*
* \param[in,out] terrain_chosen Pointeur vers la ressource choisie dans laquelle sera enregistrée la ressource cliquée.
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on quitte le programme.
*/
void controllerTerrain(/*TerrainButton* terrain_chosen, */SDL_Renderer* renderer, SDL_bool* program_launched)
{
//    initTerrainButtons();
    while(*program_launched)
    {
//        drawTerrainButtons(renderer);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
//            case SDL_MOUSEBUTTONDOWN :
//                switch(whichTerrainButton(event.button))
//                {
//                default :
//                    break;
//                }
//                break;

            case SDL_QUIT :
                printf("Evenement SDL_QUIT\n");
//                *resource_chosen = NO_RESOURCEBUTTON;
                printf("Appel de la fonction quit(program_launched)\n");
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}
