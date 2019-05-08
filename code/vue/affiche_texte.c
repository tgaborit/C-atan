/**
 * \file affiche_texte.c
 * \brief Implémente les fonctions de affiche_texte.h
 * \author Emmanuel.D
 * \version 1.0
 * \date 6 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage de texte dans le jeu.
 */

#include "affiche_texte.h"

static int fill_text(char* frag, char* buffer){

    int i =0;
    while(buffer[i] != '\0' && i<TAILLE_FRAG){
        ++i;
    }
    strncpy(frag,buffer,i);
    if(i<TAILLE_FRAG){
        frag[i] = '\0';
        return 1;
    }
    return 0;
}

static void PrintText(SDL_Renderer* renderer, char* frag, int ligne){
    TTF_Font* police = TTF_OpenFont("DejaVuSansMono.ttf", 14);
    SDL_Color couleur = {255, 255, 255, SDL_ALPHA_OPAQUE};

	if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

    SDL_Rect rect;
    rect.x = 1400;
    rect.y = 783+ligne*16;
    rect.w = 477;
    rect.h = 16;

    if(SDL_RenderFillRect(renderer, &rect) != 0)
        SDL_ExitWithError("Impossible de remplir un rectangle");

    SDL_Surface* surf = TTF_RenderText_Blended(police, frag, couleur);
    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);

    SDL_QueryTexture(text, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, text, NULL, &rect);
    TTF_CloseFont(police);
}

static void AfficheTexte(SDL_Renderer* renderer, char* buffer, int action){
    static char previous_text[10][TAILLE_FRAG+1];
    static int nbLignes = 0;

    char frag[TAILLE_FRAG+1] = "";
    int fin_message = 0;
    int i=0, j=0;
    switch(action){
    case 0:
        while(fin_message != 1){
            fin_message = fill_text(frag, buffer+TAILLE_FRAG*i);
            if(nbLignes < 10){
                PrintText(renderer, frag, nbLignes);
                strcpy(previous_text[nbLignes],frag);
                ++nbLignes;
            }
            else{
                for(j=0;j<9;++j){
                    PrintText(renderer,previous_text[j+1],j);
                    strcpy(previous_text[j],previous_text[j+1]);
                }
                PrintText(renderer, frag, 9);
                strcpy(previous_text[9],frag);
            }
            ++i;
        }
        break;
    case 1:
        for(j=0;j<10;++j){
            PrintText(renderer,previous_text[j],j);
        }
        break;
    default:;
    }
    SDL_RenderPresent(renderer);
}

/**
 * \fn AfficheTexte_Joueur(SDL_Renderer* renderer)
 * \brief affiche un message sur le joueur dont c'est le tour de jeu
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Joueur(SDL_Renderer* renderer){
    AfficheTexte(renderer,"----------------------------------------------------------",0);
    char txt[40] = "Tour du joueur ...";
    AfficheTexte(renderer,txt,0);
    AfficheTexte(renderer,"----------------------------------------------------------",0);
}

/**
 * \fn AfficheTexte_Init(SDL_Renderer* renderer)
 * \brief affiche un message d'accueil en début de partie
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Init(SDL_Renderer* renderer){
    char txt[40] = "Bienvenu dans le jeu Catane !";
    AfficheTexte(renderer,txt,0);
}

/**
 * \fn AfficheTexte_MAJ(SDL_Renderer* renderer)
 * \brief affiche l'état actuel complet de messages (pour un nouveau rendu par exemple)
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_MAJ(SDL_Renderer* renderer){
    AfficheTexte(renderer,"",1);
}

/**
 * \fn AfficheTexte_PosRoute(SDL_Renderer* renderer)
 * \brief affiche un message d'indication pour poser une route
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosRoute(SDL_Renderer* renderer){
    char txt[80] = "Selectionez une arrete ou vous souhaitez poser une route.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_PosRoute_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas assez de ressources pour poser une route
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosRoute_Echec(SDL_Renderer* renderer){
    char txt[110] = "Echec, vous n'avez pas assez de ressources pour poser cette route ou bien l'emplacement est invalide.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_PosRoute_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas assez de ressources pour poser une route
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosRoute_Succes(SDL_Renderer* renderer){
    char txt[80] = "La route a ete posee avec succes !";
    AfficheTexte(renderer,txt,0);
}



/**
 * \fn AfficheTexte_PosColonie(SDL_Renderer* renderer)
 * \brief affiche un message d'indication pour poser une colonie
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosColonie(SDL_Renderer* renderer){
    char txt[80] = "Selectionez un sommet ou vous souhaitez poser une colonie.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_PosColonie_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la colonie n'a pas pu etre posée.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosColonie_Echec(SDL_Renderer* renderer){
    char txt[110] = "Echec, vous n'avez pas assez de ressources pour poser cette colonie ou bien l'emplacement est invalide.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_PosColonie_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la colonie a été posée.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosColonie_Succes(SDL_Renderer* renderer){
    char txt[80] = "La colonie a ete posee avec succes !";
    AfficheTexte(renderer,txt,0);
}

/**
 * \fn AfficheTexte_PosVille(SDL_Renderer* renderer)
 * \brief affiche un message d'indication pour poser une ville
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosVille(SDL_Renderer* renderer){
    char txt[80] = "Selectionez une de vos colonies a changer en ville.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_PosVille_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la ville n'a pas pu etre posee
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosVille_Echec(SDL_Renderer* renderer){
    char txt[110] = "Echec, vous n'avez pas assez de ressources pour poser cette ville ou bien l'emplacement est invalide.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_PosVille_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la ville a ete posee.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_PosVille_Succes(SDL_Renderer* renderer){
    char txt[110] = "La ville a ete posee avec succes !";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_CarteDev_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, une carte developpement a ete choisie.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_CarteDev_Succes(SDL_Renderer* renderer){
    char txt[110] = "Vous venez d'acheter une carte developpement !";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_CarteDev_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, une carte developpement n'a pas pu etre choisie.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_CarteDev_Echec(SDL_Renderer* renderer){
    char txt[110] = "Echec, vous n'avez pas assez de ressources pour acheter une carte developpement.";
    AfficheTexte(renderer,txt,0);
}

/**
 * \fn AfficheTexte_ChoixRessource(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur doit choisir un type de ressource.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_ChoixRessource(SDL_Renderer* renderer){
    char txt[110] = "Veuillez choisir un type de ressource.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_Monopole_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur a utilisé une carte monopole.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Monopole_Succes(SDL_Renderer* renderer){
    char txt[110] = "Utilisation d'une carte Monopole avec succes !";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_Monopole_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas de carte monopole à jouer.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Monopole_Echec(SDL_Renderer* renderer){
    char txt[110] = "Vous n'avez pas de carte Monopole a jouer.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_Decouverte_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur a utilisé une carte decouverte.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Decouverte_Succes(SDL_Renderer* renderer){
    char txt[110] = "Utilisation d'une carte Decouverte avec succes !";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_Decouverte_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas de carte decouverte à jouer.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Decouverte_Echec(SDL_Renderer* renderer){
    char txt[110] = "Vous n'avez pas de carte Decouverte a jouer.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_Point_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur a utilisé une carte point.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Point_Succes(SDL_Renderer* renderer){
    char txt[110] = "Utilisation d'une carte Point avec succes !";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_Point_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas de carte point à jouer.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Point_Echec(SDL_Renderer* renderer){
    char txt[110] = "Vous n'avez pas de carte Point a jouer.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_Routes_Succes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur a utilisé une carte routes.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Routes_Succes(SDL_Renderer* renderer){
    char txt[110] = "Utilisation d'une carte Routes avec succes !";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_Routes_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, le joueur n'a pas de carte routes à jouer ou les emplacements des routes sont invalides.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_Routes_Echec(SDL_Renderer* renderer){
    char txt[110] = "Vous n'avez pas de carte Routes a jouer, ou bien les lieux choisis pour vos routes sont invalides.";
    AfficheTexte(renderer,txt,0);
}


/**
 * \fn AfficheTexte_ChoixRoutes(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, demande au joueur de choisir deux emplacements pour les routes à poser.
 *
 *
 * \param renderer le rendu actuel
 * \return aucun
 */
void AfficheTexte_ChoixRoutes(SDL_Renderer* renderer){
    char txt[110] = "Veuillez choisir deux emplacements ou poser vos routes.";
    AfficheTexte(renderer,txt,0);
}
