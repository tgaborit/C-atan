/**
* \file controller_player.c
* \brief Fonctions du contrôleur du choix d'un joueur
* \author Titouan Gaborit
* \date 9 mai 2019
*
* Programme gérant l'environnement du choix d'un joueur : la détection d'un clic dessus par le joueur
* ou encore le fait de quitter l'environnement ou le programme.
*
*/

#include <stdio.h>
#include <SDL.h>
#include "controller.h"
#include "controller_player.h"
#include "get_partie.h"
#include "SDL_erreur.h"

static SDL_Rect player1_area;           /*!< Rectangle correspondant à la zone de la carte Bois*/
static SDL_Rect player2_area;           /*!< Rectangle correspondant à la zone de la carte Blé*/
static SDL_Rect player3_area;           /*!< Rectangle correspondant à la zone de la carte Argile*/
static SDL_Rect player4_area;           /*!< Rectangle correspondant à la zone de la carte Moutons*/

/**
* \fn void controllerPlayer(PlayerButton* player_chosen, Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
* \brief Fonction principale du contrôleur du choix d'un joueur.
*
* Cette fonction se répète tant que le joueur reste dans l'environnement du choix d'un joueur.
* Elle détecte les actions du joueur et enregistre le joueur cliqué le cas échéant, quitte le programme ou l'environnement.
*
* \param[in,out] player_chosen Pointeur vers le joueur choisi dans lequel sera enregistré le joueur cliqué.
* \param[in] the_partie Etat de la partie en cours qui contient le nombre de joueurs.
* \param[in,out] window Pointeur vers la fenêtre du jeu.
* \param[in,out] program_launched Etat du programme : si devient SDL_False, on quitte le programme.
*/
void controllerPlayer(PlayerButton* player_chosen, Partie* the_game, SDL_Window* window, SDL_bool* program_launched)
{
    SDL_bool choice_launched = SDL_TRUE;
    initPlayerButtons(the_game);
    while(choice_launched)
    {
        drawPlayerButtons(window);
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN :
                switch(whichPlayerButton(event.button))
                {
                case PLAYER1_BUTTON :
                    *player_chosen = PLAYER1_BUTTON;
                    quit(&choice_launched);
                    break;

                case PLAYER2_BUTTON :
                    *player_chosen = PLAYER2_BUTTON;
                    quit(&choice_launched);
                    break;

                case PLAYER3_BUTTON :
                    *player_chosen = PLAYER3_BUTTON;
                    quit(&choice_launched);
                    break;

                case PLAYER4_BUTTON :
                    *player_chosen = PLAYER4_BUTTON;
                    quit(&choice_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_BACKSPACE :
                    quit(&choice_launched);
                    break;

                default :
                    break;
                }
                break;

            case SDL_QUIT :
                *player_chosen = NO_PLAYERBUTTON;
                quit(&choice_launched);
                quit(program_launched);
                break;

            default :
                break;
            }
        }
    }
}

/**
* \fn void drawPlayerButtons(SDL_Window* window)
* \brief Fonction d'affichage des boutons de l'environnement du choix d'un joueur
*
* Regroupe tous les boutons de l'envrionnement du choix d'un joueur dans un tableau, puis les affiche de couleur blanche, par-dessus
* sur le rendu de la fenêtre.
* \param[in,out] window Pointeur vers la fenêtre du jeu.
*/
void drawPlayerButtons(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_GetRenderer(window);


    //Couleur boutons
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect player_buttons[NPLAYERBUTTONS] = {player1_area, player2_area, player3_area, player4_area};
    if(SDL_RenderDrawRects(renderer, player_buttons, NPLAYERBUTTONS) != 0)
        SDL_ExitWithError("Impossible de dessiner les boutons");

    //Met a jour l'ecran
    SDL_RenderPresent(renderer);
}

/**
* \fn PlayerButton whichPlayerButton(SDL_MouseButtonEvent mouse_button)
* \brief Fonction de test sur quel bouton de joueur le joueur a cliqué.
*
* Teste pour chaque bouton de joueur si le clic effectué correspond à la zone de ce bouton.
* Si c'est le cas, communique lequel.
*
* \param[in] mouse_button Clic qui a été effectué par le joueur. Contient notamment les informations sur sa position.
* \return Le bouton de joueur qui a été cliqué, NO_PLAYERBUTTON si aucun.
*/
PlayerButton whichPlayerButton(SDL_MouseButtonEvent mouse_button){
    if(isInArea(mouse_button, player1_area) == SDL_TRUE)
        return PLAYER1_BUTTON;
    if(isInArea(mouse_button, player2_area) == SDL_TRUE)
        return PLAYER2_BUTTON;
    if(isInArea(mouse_button, player3_area) == SDL_TRUE)
        return PLAYER3_BUTTON;
    if(isInArea(mouse_button, player4_area) == SDL_TRUE)
        return PLAYER4_BUTTON;
    return NO_PLAYERBUTTON;
}

/**
* \fn void initPlayerButtons(Partie* the_game)
* \brief Fonction d'initialisation des zones des boutons de l'environnement "Choix d'un joueur".
*
* Initialise les champs des rectangles des zones correspondant aux boutons des joueurs.
* Fait appel aux fonctions d'initialisation de placement pour le bouton du joueur 1, le bouton du joueur 2, le bouton du joueur 3,
* et le bouton du joueur 4.
* Assigne les valeurs de largeur et hauteur d'après les macros correspondant à la largeur et à la hauteur des boutons de joueur.
*/
void initPlayerButtons(Partie* the_game)
{
    SDL_Rect* player_buttons[NPLAYERBUTTONS] = {&player1_area, &player2_area, &player3_area, &player4_area};
    int i;

    for(i = 0; i < get_nbjoueurs(the_game); ++i)
    {
        player_buttons[i]->h = BANNERH;
        player_buttons[i]->w = PLAYERW;
    }

    initPlayer1Placement();
    initPlayer2Placement();
    initPlayer3Placement();
    initPlayer4Placement();
}

/**
* \fn void initPlayer1Placement()
* \brief Fonction d'initialisation de la position de la zone du bouton du joueur 1.
*
* Initialise l'abscisse de la zone du bouton du joueur 1 selon son emplacement dans le bandeau.
*/
void initPlayer1Placement()
{
    player1_area.x = 10;
}

/**
* \fn void initPlayer2Placement()
* \brief Fonction d'initialisation de la position de la zone du bouton du joueur 2.
*
* Initialise l'abscisse de la zone du bouton du joueur 1 selon son emplacement dans le bandeau.
*/
void initPlayer2Placement()
{
    player2_area.x = player1_area.x + player1_area.w + 5;
}

/**
* \fn void initPlayer3Placement()
* \brief Fonction d'initialisation de la position de la zone du bouton du joueur 3.
*
* Initialise l'abscisse de la zone du bouton du joueur 1 selon son emplacement dans le bandeau.
*/
void initPlayer3Placement()
{
    player3_area.x = player2_area.x + player2_area.w + 5;
}

/**
* \fn void initPlayer4Placement()
* \brief Fonction d'initialisation de la position de la zone du bouton du joueur 4.
*
* Initialise l'abscisse de la zone du bouton du joueur 1 selon son emplacement dans le bandeau.
*/
void initPlayer4Placement()
{
    player4_area.x = player3_area.x + player3_area.w + 5;
}
