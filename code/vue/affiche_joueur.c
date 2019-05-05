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

/**
 * \fn void AffichePseudoJ1(SDL_Renderer* renderer, Joueur* j);
 * \brief Fonction affichant le pseudo et le score du joueur 1.
 *
 *
 * \param renderer, le rendu actuel
 * \param j, le joueur 1
 * \return aucun
 */
void AffichePseudoJ1(SDL_Renderer* renderer, Joueur*j)
{
    TTF_Font* police = TTF_OpenFont("Vogue.ttf", 30);
    TTF_SetFontStyle(police, TTF_STYLE_BOLD);
    char score[20]="";
    SDL_Color couleur;


    SDL_Rect rect;

    rect.x = 5;
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

        SDL_RenderPresent(renderer);

        TTF_CloseFont(police);
}



/**
 * \fn void AffichePseudoJ2(SDL_Renderer* renderer, Joueur* j);
 * \brief Fonction affichant le pseudo et le score du joueur 2.
 *
 *
 * \param renderer, le rendu actuel
 * \param j, le joueur 2
 * \return aucun
 */
void AffichePseudoJ2(SDL_Renderer* renderer, Joueur*j)
{
    TTF_Font* police = TTF_OpenFont("Vogue.ttf", 30);
    TTF_SetFontStyle(police, TTF_STYLE_BOLD);
    char score[20]="";
    SDL_Color couleur;

    SDL_Rect rect;

    rect.x = 468.5;
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

        SDL_RenderPresent(renderer);

        TTF_CloseFont(police);
}



/**
 * \fn void AffichePseudoJ3(SDL_Renderer* renderer, Joueur* j);
 * \brief Fonction affichant le pseudo et le score du joueur 3.
 *
 *
 * \param renderer, le rendu actuel
 * \param j, le joueur 3
 * \return aucun
 */
void AffichePseudoJ3(SDL_Renderer* renderer, Joueur*j)
{
    TTF_Font* police = TTF_OpenFont("Vogue.ttf", 30);
    TTF_SetFontStyle(police, TTF_STYLE_BOLD);
    SDL_Color couleur;
    char score[20]="";

    SDL_Rect rect;

    rect.x = 937;
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

        SDL_RenderPresent(renderer);

        TTF_CloseFont(police);
}


/**
 * \fn void AffichePseudoJ4(SDL_Renderer* renderer, Joueur* j);
 * \brief Fonction affichant le pseudo et le score du joueur 4.
 *
 *
 * \param renderer, le rendu actuel
 * \param j, le joueur 4
 * \return aucun
 */
void AffichePseudoJ4(SDL_Renderer* renderer, Joueur*j)
{
    TTF_Font* police = TTF_OpenFont("Vogue.ttf", 30);
    TTF_SetFontStyle(police, TTF_STYLE_BOLD);
    SDL_Color couleur;
    char score[20] = "";

    SDL_Rect rect;

    rect.x = 1405.5;
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

        SDL_RenderPresent(renderer);

        TTF_CloseFont(police);
}

