/**
 * \file fenetre.c
 * \brief Implémente les fonctions de fenetre.h
 * \author Pauline.M
 * \version 1.0
 * \date 01 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage du jeu.
 */

#include "fenetre.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "developpement.h"
#include "partie.h"
#include "get_plateau.h"
#include "architecture.h"
#include "tuile.h"
#include "carte.h"
#include "developpement.h"
#include "probabilite.h"
#include "place_infra.h"
#include "affiche_joueur.h"
#include "SDL_erreur.h"
#include "affiche_texte.h"
#include "set_partie.h"

#define WINDOWW 1920
#define WINDOWH 950
#define RED 64
#define GREEN 159
#define BLUE 255

/**
 * \fn SDL_Window* InitFenetre()
 * \brief Fonction créant une fenêtre.
 *
 *
 * \param aucun
 * \return Affiche une fenêtre
 */
SDL_Window* InitFenetre(){
    SDL_Window *window = NULL;

    if(TTF_Init()!=0){
        fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError());
    }

	if(SDL_Init(SDL_INIT_VIDEO)!=0)
		SDL_ExitWithError("Initialisation SDL impossible");

	//Creation de la fenetre en fullscreen et rendu
	if((window = SDL_CreateWindow("Catane",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOWW, WINDOWH, SDL_WINDOW_FULLSCREEN_DESKTOP)) == NULL)
		SDL_ExitWithError("Impossible de creer la fenetre");

    return window;
}


/**
 * \fn SDL_Renderer* updateFenetre(Partie* p, SDL_Window* window)
 * \brief Fonction mettant à jour le plateau de jeu en fonction de la partie
 *
 *
 * \param p, la partie de jeu
 * \param window, la fenêtre du jeu
 * \return le nouveau renderer
 */
void updateFenetre(Partie* p, SDL_Window* window){
    SDL_DestroyRenderer(SDL_GetRenderer(window));

    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    //Couleur fond
	if(SDL_SetRenderDrawColor(renderer, RED, GREEN, BLUE, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = WINDOWW;
	rectangle.h = WINDOWH;

	if(SDL_RenderFillRect(renderer, &rectangle) != 0)
		SDL_ExitWithError("Impossible de remplir un rectangle");



	if(renderer == NULL)
		SDL_ExitWithError("Creation rendu echouée");

    AfficheDe(window, p);
	AfficheChevalier(renderer);
	AfficheMonopole(renderer);
	AfficheInvention(renderer);
	AfficheRouteDev(renderer);
	AfficheUniversite(renderer);
	AfficheGrandeArmee(renderer);
	AfficheGrandeRoute(renderer);
	AfficheTuilePlateau(p,renderer);
	AfficheRandomProbaPlateau(p,renderer);
	AfficheTuile(renderer);
	AfficheCarteArgile(renderer);
	AfficheCarteBle(renderer);
	AfficheCarteBois(renderer);
	AfficheCarteMouton(renderer);
	AfficheCarteRoche(renderer);
	AfficheVoleur(p, renderer);
	AfficheJoueur(renderer);
	AfficheListeJoueurs(p,renderer);

	AfficheSkip(renderer);
	AfficheHelp(renderer);
	AfficheBoutonDev(renderer);
	AfficheBoutonRoute(renderer);
	AfficheBoutonColonie(renderer);
	AfficheBoutonVille(renderer);
	Affiche_Infrastructures(p,renderer);
	AfficheNbCarte(p, renderer);
	AfficheNbReussiteChevalier(p, renderer);
	AfficheNbReussiteRoute(p, renderer);
    SDL_RenderPresent(renderer);

	AfficheTexte_MAJ(window);
}

/**
 * \fn void destroyFenetre(SDL_Window* window)
 * \brief Fonction détruisant la fenêtre et le renderer, et permettant de quitter SDL.
 *
 *
 * \param window, la fenêtre du jeu
 * \return aucun
 */
void destroyFenetre(SDL_Window* window){

    TTF_Quit();
    SDL_DestroyRenderer(SDL_GetRenderer(window));
	SDL_DestroyWindow(window);
	SDL_Quit();
}


/**
 * \fn void AfficheSkip(SDL_Renderer* renderer)
 * \brief Fonction affichant le bouton pour passer son tour
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */


void AfficheSkip(SDL_Renderer* renderer)
{

	SDL_Surface *image = NULL;
	SDL_Texture *skip = NULL;

	image = SDL_LoadBMP("../images/skip.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image skip.bmp");

	skip = SDL_CreateTextureFromSurface(renderer, image);

	SDL_FreeSurface(image);


	if(skip == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectskip;

	if(SDL_QueryTexture(skip, NULL, NULL, &rectskip.w, &rectskip.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectskip.x = 300;
	rectskip.y = 820;


	if(SDL_RenderCopy(renderer, skip, NULL, &rectskip) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);
}

/**
 * \fn void AfficheDe(SDL_Renderer* renderer)
 * \brief Fonction affichant le dé
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheDe(SDL_Window* window, Partie* partie)
{
    SDL_Renderer* renderer = SDL_GetRenderer(window);
    TTF_Font* police = TTF_OpenFont("../fonts/Vogue.ttf", 100);

    if(police == NULL)
		SDL_ExitWithError("Echec du chargement de la police Vogue.ttf");

    SDL_Color couleur = {255, 255, 255, SDL_ALPHA_OPAQUE};
    int lancer = get_des(partie);
    char de[20] = "";
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");


	SDL_Rect rectde;
	rectde.x = 1570;
	rectde.y = 110;
	rectde.w = 100;
	rectde.h = 100;

	SDL_Rect rect;
	rect.x = 1596;
	rect.y = 125;
	rect.w = 100;
	rect.h = 100;

	if(SDL_RenderFillRect(renderer, &rectde) != 0)
		SDL_ExitWithError("Impossible de remplir un rectangle");

    if((lancer == 10) | (lancer == 11) | (lancer == 12)){
        rect.x = 1572;
    }
    sprintf(de, "%d", lancer);


    SDL_Surface* surfde = TTF_RenderText_Blended(police, de, couleur);
    if(surfde == NULL)
        SDL_ExitWithError("Echec de la creation de la surface du de");

    SDL_Texture* textde = SDL_CreateTextureFromSurface(renderer, surfde);
    if(textde == NULL)
        SDL_ExitWithError("Echec de la creation de la texture du de");

    SDL_QueryTexture(textde, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, textde, NULL, &rect);

    TTF_CloseFont(police);
}

/**
 * \fn void AfficheHelp(SDL_Renderer* renderer)
 * \brief Fonction affichant le bouton "?" (help)
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheHelp(SDL_Renderer* renderer)
{
	SDL_Surface *image = NULL;
	SDL_Texture *help = NULL;

	image = SDL_LoadBMP("../images/help.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image help.bmp");

	help = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(help == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect recthelp;

	if(SDL_QueryTexture(help, NULL, NULL, &recthelp.w, &recthelp.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	recthelp.x = 1875;
	recthelp.y = 0;


	if(SDL_RenderCopy(renderer, help, NULL, &recthelp) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn void Help(SDL_Renderer* renderer)
 * \brief Fonction affichant l'aide du jeu
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void Help(SDL_Window* w)
{
    SDL_Renderer* renderer = SDL_GetRenderer(w);
	SDL_Surface *image = NULL;
	SDL_Texture *help = NULL;

	image = SDL_LoadBMP("../images/aide.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image aide.bmp");

	help = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(help == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect recthelp;

	if(SDL_QueryTexture(help, NULL, NULL, &recthelp.w, &recthelp.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	recthelp.x = 0;
	recthelp.y = 0;


	if(SDL_RenderCopy(renderer, help, NULL, &recthelp) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

	SDL_RenderPresent(renderer);

}


/**
 * \fn void AfficheJetonVoleur(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy)
 * \brief Fonction affichant le jeton du voleur
 *
 *
 * \param p, la partie de jeu actuel
 * \param x et y les coordonnées du noeud recherché
 * \param renderer, le rendu actuel
 * \param posimx et posimy les position en pixel dans la fenetre
 * \return aucun
 */
void AfficheJetonVoleur(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy)
{
	int v = getVoleur(p, x, y);

	if (v!= 1) return;

	else {

		SDL_Surface *image = NULL;
		SDL_Texture *voleur = NULL;

		image = SDL_LoadBMP("../images/voleur.bmp");

		if(image == NULL)
			SDL_ExitWithError("Impossible de charger l'image voleur.bmp");

		voleur = SDL_CreateTextureFromSurface(renderer, image);
		SDL_FreeSurface(image);

		if(voleur == NULL)
			SDL_ExitWithError("impossible de creer la texture");

		SDL_Rect rectvoleur;

		if(SDL_QueryTexture(voleur, NULL, NULL, &rectvoleur.w, &rectvoleur.h) != 0)
			SDL_ExitWithError("Impossible de charger la texture");

		rectvoleur.x = posimx;
		rectvoleur.y = posimy;


		if(SDL_RenderCopy(renderer, voleur, NULL, &rectvoleur) !=0)
			SDL_ExitWithError("Impossible d'afficher la texture");
	}
}

/**
 * \fn void AfficheVoleur(Partie* p, SDL_Renderer* renderer)
 * \brief Fonction affichant le voleur
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheVoleur(Partie* p, SDL_Renderer* renderer)
{
	AfficheJetonVoleur(p, -1, 2, renderer, 792, 152);
	AfficheJetonVoleur(p, 0, 2, renderer, 928, 152);
	AfficheJetonVoleur(p, 1, 2, renderer, 1063, 152);

	AfficheJetonVoleur(p, -1.5, 1, renderer, 724, 270);
	AfficheJetonVoleur(p, -0.5, 1, renderer, 860, 270);
	AfficheJetonVoleur(p, 0.5, 1, renderer, 996, 270);
	AfficheJetonVoleur(p, 1.5, 1, renderer, 1130, 270);

	AfficheJetonVoleur(p, -2, 0, renderer, 656, 388);
	AfficheJetonVoleur(p, -1, 0, renderer, 792, 388);
	AfficheJetonVoleur(p, 0, 0, renderer, 928, 388);
	AfficheJetonVoleur(p, 1, 0, renderer, 1063, 388);
	AfficheJetonVoleur(p, 2, 0, renderer, 1198, 388);

	AfficheJetonVoleur(p, -1.5, -1, renderer, 724, 506);
	AfficheJetonVoleur(p, -0.5, -1, renderer, 860, 506);
	AfficheJetonVoleur(p, 0.5, -1, renderer, 996, 506);
	AfficheJetonVoleur(p, 1.5, -1, renderer, 1130, 506);

	AfficheJetonVoleur(p, -1, -2, renderer, 792, 624);
	AfficheJetonVoleur(p, 0, -2, renderer, 928, 624);
	AfficheJetonVoleur(p, 1, -2, renderer, 1063, 624);

}
