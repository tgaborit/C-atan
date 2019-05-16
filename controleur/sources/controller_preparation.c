#include "controller_preparation.h"
#include "get_partie.h"
#include "fenetre.h"
#include "controller_crossing.h"
#include "converters.h"
#include "set_plateau.h"


void controllerPreparation(SDL_bool* program_launched, SDL_Window* window, Partie* the_game)
{
    int j, bool_colonie;
    updateFenetre(the_game, window);
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
        passer_tour(the_game);
        updateFenetre(the_game, window);
    }
}

