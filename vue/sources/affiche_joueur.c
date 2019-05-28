/**
 * \file affiche_joueur.c
 * \brief Implémente les fonctions de affiche_joueur.h
 * \author Pauline.M
 * \version 1.0
 * \date 05 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage des informations des joueurs.
 */

#include "affiche_joueur.h"
#include "get_partie.h"


/**
 * \fn void AfficheJoueur(SDL_Renderer* renderer)
 * \brief Fonction affichant les noms et les scores des joueurs
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheJoueur(SDL_Renderer* renderer)
{
	//Creation de la barre avec les noms des joueurs et le score
	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

	SDL_Rect barrejoueurs;
	barrejoueurs.x = 0;
	barrejoueurs.y = 0;
	barrejoueurs.w = 1920;
	barrejoueurs.h = 35;

	if(SDL_RenderFillRect(renderer, &barrejoueurs) != 0)
		SDL_ExitWithError("Impossible de remplir un rectangle");
}


/**
 * \fn void AfficheInfoJoueurs(Joueur* j, SDL_Renderer* renderer, int x);
 * \brief Fonction affichant le pseudo et le score d'un joueur.
 *
 *
 * \param j, le joueur
 * \param renderer, le rendu actuel
 * \param x, la coordonnée x du rectangle d'affichage des informations
 * \return aucun
 */
void AfficheInfoJoueurs(Joueur* j, SDL_Renderer* renderer, int x)
{

    TTF_Font* police = TTF_OpenFont("../fonts/Vogue.ttf", 30);
    if (police == NULL)
        SDL_ExitWithError("Echec du chargement de la police Vogue.ttf");

    TTF_SetFontStyle(police, TTF_STYLE_BOLD);
    char score[20]="";
    SDL_Color couleur;

    SDL_Rect rect;
    rect.x = x;
    rect.y = 8.5;
    rect.w = 1920;
    rect.h = 35;

    SDL_Rect rectscore;
    rectscore.x = rect.x + 210;
    rectscore.y = 8.5;
    rectscore.w = 1920;
    rectscore.h = 35;

    switch(j->couleur)
    {
        case ROUGE :
            couleur.r = 255;
            couleur.g = 18;
            couleur.b = 0;
            couleur.a = SDL_ALPHA_OPAQUE;
            break;

        case BLANC:
            couleur.r = 255;
            couleur.g = 255;
            couleur.b = 255;
            couleur.a = SDL_ALPHA_OPAQUE;
            break;

        case ORANGE:
            couleur.r = 255;
            couleur.g = 138;
            couleur.b = 0;
            couleur.a = SDL_ALPHA_OPAQUE;
            break;

        case BLEU:
            couleur.r = 0;
            couleur.g = 0;
            couleur.b = 255;
            couleur.a = SDL_ALPHA_OPAQUE;
            break;

        default:
            break;
    }

    SDL_Surface* surfpseudo = TTF_RenderText_Blended(police, j->pseudo, couleur);
    SDL_Texture* textpseudo = SDL_CreateTextureFromSurface(renderer, surfpseudo);

    SDL_QueryTexture(textpseudo, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, textpseudo, NULL, &rect);

    sprintf(score, "Points : %d", j->score);
    SDL_Surface* surfscore = TTF_RenderText_Blended(police, score, couleur);
    SDL_Texture* textscore = SDL_CreateTextureFromSurface(renderer, surfscore);

    SDL_QueryTexture(textscore, NULL, NULL, &rectscore.w, &rectscore.h);

    SDL_RenderCopy(renderer, textscore, NULL, &rectscore);

    TTF_CloseFont(police);
}



/**
 * \fn void AfficheListeJoueurs(Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant le pseudo et le score tous les joueurs participant à la partie.
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheListeJoueurs(Partie* p, SDL_Renderer* renderer)
{
    if(p->joueurs->first->next != p->joueurs->last){

        AfficheInfoJoueurs(p->joueurs->first->joueur, renderer, 5);
        AfficheInfoJoueurs(p->joueurs->first->next->joueur,renderer, 468.5);

        if(p->joueurs->first->next->next == p->joueurs->last){
            AfficheInfoJoueurs(p->joueurs->last->joueur, renderer, 937);
        }else{
            AfficheInfoJoueurs(p->joueurs->first->next->next->joueur, renderer, 937);
            AfficheInfoJoueurs(p->joueurs->last->joueur, renderer, 1405.5);
        }

    }else{

    AfficheInfoJoueurs(p->joueurs->first->joueur, renderer, 5);
    AfficheInfoJoueurs(p->joueurs->first->next->joueur,renderer, 468.5);

    }
}




/**
 * \fn void AfficheNombreRessources(TypeRessource type, Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant le nombre de chaque ressource pour le joueur courant
 *
 *
 * \param type, le type de ressource
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNombreRessources(TypeRessource type, Partie* p, SDL_Renderer* renderer)
{
    TTF_Font* police = TTF_OpenFont("../fonts/Vogue.ttf", 20);
    if (police == NULL)
        SDL_ExitWithError("Echec du chargement de la police Vogue.ttf");

    SDL_Color couleur = {0, 0, 0, SDL_ALPHA_OPAQUE};
    char nb[20] = "";

	SDL_Rect rect;
	rect.y = 788;
	rect.w = 100;
	rect.h = 100;

	int n = get_nbressource_joueuractif(type, p);

	switch(type){
        case ARGILE:
            rect.x = 565;
            break;
        case BLE:
            rect.x = 738.5;
            break;
        case BOIS:
            rect.x = 910.5;
            break;
        case MOUTON:
            rect.x = 1084.5;
            break;
        case PIERRE:
            rect.x = 1259.5;
            break;
    }

    sprintf(nb, "%d", n);
    SDL_Surface* surfnb = TTF_RenderText_Blended(police, nb, couleur);
    SDL_Texture* textnb = SDL_CreateTextureFromSurface(renderer, surfnb);

    SDL_QueryTexture(textnb, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, textnb, NULL, &rect);

    TTF_CloseFont(police);
}

/**
 * \fn void AfficheNombreDev(TypeCarteDev type, Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant le nombre de chaque carte développement pour le joueur courant
 *
 *
 * \param type, le type de développement
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNombreDev(TypeCarteDev type, Partie* p, SDL_Renderer* renderer)
{
    TTF_Font* police = TTF_OpenFont("../fonts/Vogue.ttf", 20);
    if (police == NULL)
        SDL_ExitWithError("Echec du chargement de la police Vogue.ttf");

    SDL_Color couleur = {255, 255, 255, SDL_ALPHA_OPAQUE};
    char nb[20] = "";

	SDL_Rect rect;
	rect.x = 102;
	rect.w = 100;
	rect.h = 100;

	int n = get_nbcartedev_joueuractif(type, p);

	switch(type){
        case CHEVALIER:
            rect.y = 277;
            break;
        case MONOPOLE:
            rect.y = 377;
            break;
        case DECOUVERTE:
            rect.y = 477;
            break;
        case ROUTES:
            rect.y = 577;
            break;
        case POINT:
            rect.y = 677;
            break;
    }

    sprintf(nb, "%d", n);
    SDL_Surface* surfnb = TTF_RenderText_Blended(police, nb, couleur);
    SDL_Texture* textnb = SDL_CreateTextureFromSurface(renderer, surfnb);

    SDL_QueryTexture(textnb, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, textnb, NULL, &rect);

    TTF_CloseFont(police);
}

/**
 * \fn void AfficheNbCarte(Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant le nombre de toutes les cartes pour le joueur courant
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNbCarte(Partie* p, SDL_Renderer* renderer)
{
    AfficheNombreRessources(ARGILE, p, renderer);
	AfficheNombreRessources(BLE, p, renderer);
	AfficheNombreRessources(BOIS, p, renderer);
	AfficheNombreRessources(MOUTON, p, renderer);
	AfficheNombreRessources(PIERRE, p, renderer);
	AfficheNombreDev(CHEVALIER, p, renderer);
	AfficheNombreDev(MONOPOLE, p, renderer);
	AfficheNombreDev(DECOUVERTE, p, renderer);
	AfficheNombreDev(ROUTES, p, renderer);
	AfficheNombreDev(POINT, p, renderer);
}


/**
 * \fn void AfficheNbReussiteChevalier(Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant 1 si la carte réussite est en possession du joueur, sinon 0
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNbReussiteChevalier(Partie*p, SDL_Renderer* renderer)
{
    TTF_Font* police = TTF_OpenFont("../fonts/Vogue.ttf", 15);
    if (police == NULL)
        SDL_ExitWithError("Echec du chargement de la police Vogue.ttf");

    SDL_Color couleur = {255, 255, 255, SDL_ALPHA_OPAQUE};

	SDL_Rect rect;
	rect.x = 155;
	rect.y = 235;
	rect.w = 100;
	rect.h = 100;

    SDL_Surface* surfnb = NULL;
    if(p->joueurs->current->joueur == get_joueur_chevaliers(p) && p->joueurs->current->joueur->nbChevalier > 2){
         surfnb = TTF_RenderText_Blended(police, "1", couleur);

    }else{
        surfnb = TTF_RenderText_Blended(police, "0", couleur);
    }

    SDL_Texture* textnb = SDL_CreateTextureFromSurface(renderer, surfnb);

    SDL_QueryTexture(textnb, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, textnb, NULL, &rect);

    TTF_CloseFont(police);
}


/**
 * \fn void AfficheNbReussiteRoute(Partie* p, SDL_Renderer* renderer);
 * \brief Fonction affichant 1 si la carte réussite est en possession du joueur, sinon 0
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheNbReussiteRoute(Partie* p, SDL_Renderer* renderer)
{
    TTF_Font* police = TTF_OpenFont("../fonts/Vogue.ttf", 15);
    if (police == NULL)
        SDL_ExitWithError("Echec du chargement de la police Vogue.ttf");

    SDL_Color couleur = {255, 255, 255, SDL_ALPHA_OPAQUE};

	SDL_Rect rect;
	rect.x = 330;
	rect.y = 235;
	rect.w = 100;
	rect.h = 100;

	 SDL_Surface* surfnb = NULL;

    if(p->joueurs->current->joueur == get_joueur_routes(p) && p->joueurs->current->joueur->nbRoute > 4){
        surfnb = TTF_RenderText_Blended(police, "1", couleur);

    }else{
        surfnb = TTF_RenderText_Blended(police, "0", couleur);
    }

    SDL_Texture* textnb = SDL_CreateTextureFromSurface(renderer, surfnb);

    SDL_QueryTexture(textnb, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, textnb, NULL, &rect);

    TTF_CloseFont(police);
}
