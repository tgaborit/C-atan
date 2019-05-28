/**
* \file controller_preparation.c
* \brief Fonction du contrôleur de la préparation du jeu
* \author Titouan Gaborit
* \date 16 mai 2019
*
* Programme gérant la préparation du jeu : le placement de deux colonies et de deux routes par chaque joueur, selon l'ordre
* stipulé par les règles du jeu.
*
*/

#include "controller_preparation.h"
#include "get_partie.h"
#include "fenetre.h"
#include "controller_crossing.h"
#include "converters.h"
#include "set_plateau.h"
#include "set_partie.h"
#include "affiche_texte.h"

/**
* \fn void controllerPreparation(SDL_bool* program_launched, SDL_Window* window, Partie* the_game)
* \brief Fonction principale du contrôleur de la préparation du jeu
*
* Cette fonction corrrespond à la préparation de la partie : les joueurs placent chacun deux colonies et deux routes.
* Elle appelle donc des fonctions de contrôleur pour détecter le choix du placement des joueurs, des fonctions du modèle pour modifier
* l'état de la partie, et des fonctions de la vue pour mettre à jour ce que voit le joueur.
*
* \param[in,out] program_launched Pointeur vers l'état du programme : si devient SDL_False, on sort de la fonction et on quitte le programme.
* \param[in,out] window Pointeur vers la fenêtre du jeu.
* \param[in,out] the_partie Etat de la partie en cours qui sera modifié en fonction des actions du joueur.
*/
void controllerPreparation(SDL_bool* program_launched, SDL_Window* window, Partie* the_game)
{
    int i, j, k, bool_colonie = 0, bool_route = 0;
    updateFenetre(the_game, window);
    AfficheTexte_Init(window);
    for(i = 0; i < 2; ++i)
    {
        for(j = 0; j < get_nbjoueurs(the_game); ++j)
        {

            if(i == 0){
                passer_tour(the_game);
            }
            CrossButton cross_clicked;
            CrossCoordinates cross_chosen;

            AfficheTexte_Joueur(window,the_game);

            do
            {
                if(bool_colonie == 0){
                    AfficheTexte_PosColonie(window);
                }
                else{
                    AfficheTexte_PosColonie_Echec(window);
                }

                cross_clicked = NO_CROSSBUTTON;
                controllerCrossing(&cross_clicked, window, program_launched);
                if(*program_launched == SDL_FALSE){
                    return;
                }

                cross_chosen = crossButtonToCrossCoordinates(cross_clicked);
                bool_colonie = setColonieInit(the_game, cross_chosen.x, cross_chosen.y, cross_chosen.position);
                if(bool_colonie == 0){
                    AfficheTexte_PosColonie_Succes(window);
                }
            }
            while (bool_colonie != 0);
            updateFenetre(the_game, window);


            PathButton path_clicked;
            PathCoordinates path_chosen;

            do
            {

                if(bool_route == 0){
                    AfficheTexte_PosRoute(window);
                }
                else{
                    AfficheTexte_PosRoute_Echec(window);
                }

                path_clicked = NO_PATHBUTTON;
                controllerPath(&path_clicked, window, program_launched);
                if(*program_launched == SDL_FALSE){
                    return;
                }

                path_chosen = pathButtonToPathCoordinates(path_clicked);
                bool_route = setRouteFree(the_game, path_chosen.x, path_chosen.y, path_chosen.position);
                if(bool_route == 0){
                    AfficheTexte_PosRoute_Succes(window);
                }
            }
            while (bool_route != 0);
            updateFenetre(the_game, window);

            if(i ==1){
                for(k = 0; k < get_nbjoueurs(the_game)-1; ++k){
                    passer_tour(the_game);
                }
            }
        }
    }
}

