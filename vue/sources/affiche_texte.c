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
#include "SDL_erreur.h"

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

static void PrintText(SDL_Window* window, char* frag, int ligne){
    SDL_Renderer* renderer = SDL_GetRenderer(window);
    TTF_Font* police = TTF_OpenFont("fonts/DejaVuSansMono.ttf", 14);
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

static void AfficheTexte(SDL_Window* window, char* buffer, int action){
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
                PrintText(window, frag, nbLignes);
                strcpy(previous_text[nbLignes],frag);
                ++nbLignes;
            }
            else{
                for(j=0;j<9;++j){
                    PrintText(window,previous_text[j+1],j);
                    strcpy(previous_text[j],previous_text[j+1]);
                }
                PrintText(window, frag, 9);
                strcpy(previous_text[9],frag);
            }
            ++i;
        }
        break;
    case 1:
        for(j=0;j<10;++j){
            PrintText(window,previous_text[j],j);
        }
        break;
    default:;
    }
    SDL_RenderPresent(SDL_GetRenderer(window));
}

/**
 * \fn AfficheTexte_Joueur(SDL_Window* window)
 * \brief affiche un message sur le joueur dont c'est le tour de jeu
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Joueur(SDL_Window* window){
    AfficheTexte(window,"----------------------------------------------------------",0);
    char txt[40] = "Tour du joueur ...";
    AfficheTexte(window,txt,0);
    AfficheTexte(window,"----------------------------------------------------------",0);
}

/**
 * \fn AfficheTexte_NoRessource(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas assez de ressources pour l'action demandée.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_NoRessource(SDL_Window* window){
    char txt[80] = "Echec, vous manquez de ressources cette action";
    AfficheTexte(window,txt,0);
}

/**
 * \fn AfficheTexte_NoCarte(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas assez de cartes pour l'action demandée.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_NoCarte(SDL_Window* window){
    char txt[80] = "Echec, vous manquez de cartes pour realiser cette l'action";
    AfficheTexte(window,txt,0);
}

/**
 * \fn AfficheTexte_StopAction(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a annulé une action.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_StopAction(SDL_Window* window){
    char txt[80] = "Action annulée.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_Init(SDL_Window* window)
 * \brief affiche un message d'accueil en début de partie
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Init(SDL_Window* window){
    char txt[40] = "Bienvenu dans le jeu Catane !";
    AfficheTexte(window,txt,0);
}

/**
 * \fn AfficheTexte_MAJ(SDL_Window* window)
 * \brief affiche l'état actuel complet de messages (pour un nouveau rendu par exemple)
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_MAJ(SDL_Window* window){
    AfficheTexte(window,"",1);
}

/**
 * \fn AfficheTexte_PosRoute(SDL_Window* window)
 * \brief affiche un message d'indication pour poser une route
 *
 *
* \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosRoute(SDL_Window* window){
    char txt[80] = "Selectionez une arrete ou vous souhaitez poser une route.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_PosRoute_Echec(SDL_Renderer* renderer)
 * \brief affiche un message d'indication, la route n'a pas pu etre posée
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosRoute_Echec(SDL_Window* window){
    char txt[110] = "L'emplacement est invalide ! choisissez en un autre.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_PosRoute_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, la route a été posée
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosRoute_Succes(SDL_Window* window){
    char txt[80] = "La route a ete posee avec succes !";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_PosColonie(SDL_Window* window)
 * \brief affiche un message d'indication pour poser une colonie
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosColonie(SDL_Window* window){
    char txt[80] = "Selectionez un sommet ou vous souhaitez poser une colonie.";
    AfficheTexte(window,txt,0);
}


 /**
 * \fn AfficheTexte_PosColonie_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, la colonie n'a pas pu etre posée.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosColonie_Echec(SDL_Window* window){
    char txt[110] = "L'emplacement est invalide ! choisissez en un autre.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_PosColonie_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, la colonie a été posée.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosColonie_Succes(SDL_Window* window){
    char txt[80] = "La colonie a ete posee avec succes !";
    AfficheTexte(window,txt,0);
}

/**
 * \fn AfficheTexte_PosVille(SDL_Window* window)
 * \brief affiche un message d'indication pour poser une ville
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosVille(SDL_Window* window){
    char txt[80] = "Selectionez une de vos colonies a changer en ville.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_PosVille_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, la ville n'a pas pu etre posee
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosVille_Echec(SDL_Window* window){
    char txt[110] = "L'emplacement est invalide ! choisissez en un autre.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_PosVille_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, la ville a ete posee.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_PosVille_Succes(SDL_Window* window){
    char txt[110] = "La ville a ete posee avec succes !";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_CarteDev_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, une carte developpement a ete choisie.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_CarteDev_Succes(SDL_Window* window){
    char txt[110] = "Vous venez d'acheter une carte developpement !";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_CarteDev_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, une carte developpement n'a pas pu etre choisie.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_CarteDev_Echec(SDL_Window* window){
    char txt[110] = "Echec, vous n'avez pas assez de ressources pour acheter une carte developpement ou il n'y en a plus.";
    AfficheTexte(window,txt,0);
}

/**
 * \fn AfficheTexte_ChoixRessource(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur doit choisir un type de ressource.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_ChoixRessource(SDL_Window* window){
    char txt[110] = "Veuillez choisir un type de ressource.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_Monopole_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a utilisé une carte monopole.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Monopole_Succes(SDL_Window* window, int vol){
    char number[10] = "";
    char txt[110] = "Utilisation d'une carte Monopole avec succes, ";
    sprintf(number, "%d", vol);
    char txt2[20] = " ressources volees !";
    strcat(txt,number);
    strcat(txt,txt2);
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_Monopole_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas de carte monopole à jouer.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Monopole_Echec(SDL_Window* window){
    char txt[110] = "Aucune ressource n'a ete volee.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_Decouverte_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a utilisé une carte decouverte.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Decouverte_Succes(SDL_Window* window){
    char txt[110] = "Utilisation d'une carte Invention avec succes !";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_Point_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a utilisé une carte point.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Point_Succes(SDL_Window* window){
    char txt[110] = "Utilisation d'une carte Point avec succes !";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_nbVol(SDL_Window* window, int nb_vol)
 * \brief affiche un message d'indication sur des eventuels joueurs volés.
 *
 *
 * \param window la fenetre de jeu, nb_vol le nombre de joueurs volés.
 * \return aucun
 */
void AfficheTexte_nbVol(SDL_Window* window,int nb_vol){
    char txt[110] = "";
    if(nb_vol <= 0){
        return;
    }
    sprintf(txt, "%d", nb_vol);
    if(nb_vol == 1){
        strcat(txt," personne avait plus de 7 cartes !");
    }
    else{
        strcat(txt," personnes avaient plus de 7 cartes !");
    }
    AfficheTexte(window,txt,0);

}

/**
 * \fn AfficheTexte_Routes_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur a utilisé une carte routes.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Routes_Succes(SDL_Window* window){
    char txt[110] = "Utilisation d'une carte Routes avec succes !";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_Routes_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas de carte routes à jouer ou les emplacements des routes sont invalides.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Routes_Echec(SDL_Window* window){
    char txt[110] = "Les lieux choisis pour vos routes sont invalides, veuillez recommencer.";
    AfficheTexte(window,txt,0);
}



/**
 * \fn AfficheTexte_Chevalier_Succes(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas de carte routes à jouer ou les emplacements des routes sont invalides.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Chevalier_Succes(SDL_Window* window){
    char txt[110] = "Utilisation d'une carte Chevalier avec succes, une carte a ete volee !";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_Chevalier_Echec(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur n'a pas de carte Chevalier a jouer ou bien les parametres sont invalides.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_Chevalier_Echec(SDL_Window* window){
    char txt[130] = "Aucune carte n'a ete volee ...";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_ChoixTuileVoleur(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur doit choisir une tuile ou il souhaite poser le voleur.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_ChoixTuileVoleur(SDL_Window* window){
    char txt[130] = "Veuillez choisir une tuile ou vous voulez poser le voleur.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_ChoixJoueurVoler(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur doit choisir un autre joueur a voler.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_ChoixJoueurVoler(SDL_Window* window){
    char txt[130] = "Veuillez choisir un joueur a voler possedant une colonie ou une ville sur cette tuile.";
    AfficheTexte(window,txt,0);
}


/**
 * \fn AfficheTexte_LancerDe(SDL_Window* window)
 * \brief affiche un message d'indication, le joueur doit lancer le de.
 *
 *
 * \param window la fenetre de jeu
 * \return aucun
 */
void AfficheTexte_LancerDe(SDL_Window* window){
    char txt[60] = "C'est a votre tour, lancez le de.";
    AfficheTexte(window,txt,0);
}


