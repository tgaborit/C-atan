#include "controller_preparation.h"
#include "get_partie.h"
#include "fenetre.h"
#include "controller_crossing.h"
#include "converters.h"
#include "set_plateau.h"
#include "set_partie.h"


void controllerPreparation(SDL_bool* program_launched, SDL_Window* window, Partie* the_game)
{
    int i, j, bool_colonie, bool_route;
    updateFenetre(the_game, window);
    for(i = 0; i < 2; ++i)
    {
        for(j = 0; j < get_nbjoueurs(the_game); ++j)
        {
            CrossButton cross_clicked;
            CrossCoordinates cross_chosen;

            do
            {
                cross_clicked = NO_CROSSBUTTON;
                controllerCrossing(&cross_clicked, window, program_launched);
                if(*program_launched == SDL_FALSE){
                    return;
                }

                cross_chosen = crossButtonToCrossCoordinates(cross_clicked);
                printf("Appel de la fonction du modele setColonie(the_game, %f, %f, %d)\n", cross_chosen.x, cross_chosen.y, cross_chosen.position);
                bool_colonie = setColonieInit(the_game, cross_chosen.x, cross_chosen.y, cross_chosen.position);
            }
            while (bool_colonie != 0);
            updateFenetre(the_game, window);


            PathButton path_clicked;
            PathCoordinates path_chosen;

            do
            {
                path_clicked = NO_PATHBUTTON;
                controllerPath(&path_clicked, window, program_launched);
                if(*program_launched == SDL_FALSE){
                    return;
                }

                path_chosen = pathButtonToPathCoordinates(path_clicked);
                printf("Appel de la fonction du modele setRouteFree(the_game, %f, %f, %d)\n", path_chosen.x, path_chosen.y, path_chosen.position);
                bool_route = setRouteFree(the_game, path_chosen.x, path_chosen.y, path_chosen.position);
            }
            while (bool_route != 0);


            passer_tour(the_game);
            updateFenetre(the_game, window);
        }
    }
}

