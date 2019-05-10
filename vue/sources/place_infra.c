/**
 * \file place_infra.c
 * \brief Implémente les fonctions de place_infra.h
 * \author Emmanuel.D
 * \version 1.0
 * \date 1 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage des probabilites dans le jeu.
 */

#include "vue/headers/place_infra.h"
#include <math.h>
#include "vue/headers/SDL_erreur.h"


static double calcul_offset_x(int position){
    switch(position){
    case 0:;
    case 5: return (-round(cote*sqrt(3)/2));
    case 1:;
    case 4: return 0;
    case 2:;
    case 3: return (round(cote*sqrt(3)/2));
    default: return 0;
    }
}

static double calcul_offset_y(int position){
    switch(position){
    case 0:;
    case 2: return (-cote/2);
    case 1: return (-cote);
    case 3:;
    case 5: return (+cote/2);
    case 4: return (+cote);
    default: return 0;
    }
}

static void print_infra(double x, double y,double angle, char* pathname, SDL_Renderer* renderer){
    SDL_Surface *image = NULL;
	SDL_Texture *infra = NULL;

	image = SDL_LoadBMP(pathname);

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image");

	infra = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	if(infra == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectangle;

	if(SDL_QueryTexture(infra, NULL, NULL, &rectangle.w, &rectangle.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectangle.x = round(x);
	rectangle.y = round(y);

	SDL_Point point ={19,2};

    if(SDL_RenderCopyEx(renderer,infra, NULL, &rectangle, angle, &point, 0) != 0){
		SDL_ExitWithError("Impossible d'afficher la texture");
    }

	SDL_RenderPresent(renderer);
}


static void Affiche_Colonie(double x, double y, int position, Couleur couleur, SDL_Renderer* renderer){
    double posx,posy;

    posx = x_centre+cote*x*sqrt(3);
    posy = y_centre-cote*y*1.5;
    posx += calcul_offset_x(position);
    posy += calcul_offset_y(position);
    posx += -23;
    posy += -34;

    if(couleur == BLANC){
        print_infra(posx,posy,0,"images/colonieblanche.bmp",renderer);
    }
    if(couleur == BLEU){
        print_infra(posx,posy,0,"images/coloniebleu.bmp",renderer);
    }
    if(couleur == ROUGE){
        print_infra(posx,posy,0,"images/colonierouge.bmp",renderer);
    }
    if(couleur == ORANGE){
        print_infra(posx,posy,0,"images/colonieorange.bmp",renderer);
    }
}

static void Affiche_Ville(double x, double y, int position, Couleur couleur, SDL_Renderer* renderer){
    double posx,posy;

    posx = x_centre+cote*x*sqrt(3);
    posy = y_centre-cote*y*1.5;
    posx += calcul_offset_x(position);
    posy += calcul_offset_y(position);
    posx += -29;
    posy += -22;

    if(couleur == BLANC){
        print_infra(posx,posy,0,"images/villeblanc.bmp",renderer);
    }
    if(couleur == BLEU){
        print_infra(posx,posy,0,"images/villebleu.bmp",renderer);
    }
    if(couleur == ROUGE){
        print_infra(posx,posy,0,"images/villerouge.bmp",renderer);
    }
    if(couleur == ORANGE){
        print_infra(posx,posy,0,"images/villeorange.bmp",renderer);
    }
}

static void Affiche_Route(double x, double y, int position, Couleur couleur, SDL_Renderer* renderer){
    double posx,posy,angle = 0;

    posx = x_centre+cote*x*sqrt(3);
    posy = y_centre-cote*y*1.5;
    posx += calcul_offset_x(position);
    posy += calcul_offset_y(position);
    posx += -18;
    posy += -7;

    switch (position){
    case 5: angle += 60;
    case 4: angle += 60;
    case 3: angle += 60;
    case 2: angle += 60;
    case 1: angle += 60;
    case 0: angle += 0;
    default: angle += 0;
    }

    if(couleur == BLANC){
        print_infra(posx,posy,angle,"images/routeblanc.bmp",renderer);
    }
    if(couleur == BLEU){
        print_infra(posx,posy,angle,"images/routebleu.bmp",renderer);
    }
    if(couleur == ROUGE){
        print_infra(posx,posy,angle,"images/routerouge.bmp",renderer);
    }
    if(couleur == ORANGE){
        print_infra(posx,posy,angle,"images/routeorange.bmp",renderer);
    }
}


/**
 * \fn void Affiche_Infrastructures(Partie* partie, SDL_Renderer* renderer)
 * \brief affiche les colonies/villes/routes présentes sur le plateau
 *
 *
 * \param partie un pointeur vers la partie actuelle
 * \param renderer le rendu actuel
 * \return aucun
 */
void Affiche_Infrastructures(Partie* partie, SDL_Renderer* renderer){
    int i,j,j_borne;
    Plateau* p = partie->plateau;
    int ord[6] = {HG,G,HD,BG,D,BD};                                    // Tableau de chiffres en liaison avec un pattern de mouvements.
    int ord2[6] = {3,2,4,1,5,0};


    for(i=0; i<6; ++i){
        for(j=ord2[i]; j<ord2[i]+4; ++j){
            int j_borne = j;
            if(j_borne>5){
                j_borne -= 6;
            }
            if(p->adjacence[i]->t->a[j_borne].i == ROUTE){
                Affiche_Route(p->adjacence[i]->x,p->adjacence[i]->y,j_borne,p->adjacence[i]->t->a[j_borne].owner->couleur,renderer);
            }
            ++j_borne;
            if(j_borne>5){
                j_borne -= 6;
            }
            if(p->adjacence[i]->adjacence[i]->t->a[j_borne].i == ROUTE){
                Affiche_Route(p->adjacence[i]->adjacence[i]->x,p->adjacence[i]->adjacence[i]->y,j_borne,p->adjacence[i]->adjacence[i]->t->a[j_borne].owner->couleur,renderer);
            }
            if(p->adjacence[i]->adjacence[ord[i]]->t->a[j_borne].i == ROUTE){
                Affiche_Route(p->adjacence[i]->adjacence[ord[i]]->x,p->adjacence[i]->adjacence[ord[i]]->y,j_borne,p->adjacence[i]->adjacence[ord[i]]->t->a[j_borne].owner->couleur,renderer);
            }
        }

    }

    for(i=0; i<6; ++i){
        for(j=ord2[i]; j<ord2[i]+3; ++j){
            j_borne = j;
            if(j_borne>5){
                j_borne -= 6;
            }
            if(p->adjacence[i]->t->s[j_borne].i == COLONIE){
                Affiche_Colonie(p->adjacence[i]->x,p->adjacence[i]->y,j_borne,p->adjacence[i]->t->s[j_borne].owner->couleur,renderer);
            }
            if(p->adjacence[i]->t->s[j_borne].i == VILLE){
                Affiche_Ville(p->adjacence[i]->x,p->adjacence[i]->y,j_borne,p->adjacence[i]->t->s[j_borne].owner->couleur,renderer);
            }
            ++j_borne;
            if(j_borne>5){
                j_borne -= 6;
            }
            if(p->adjacence[i]->adjacence[i]->t->s[j_borne].i == COLONIE){
                Affiche_Colonie(p->adjacence[i]->adjacence[i]->x,p->adjacence[i]->adjacence[i]->y,j_borne,p->adjacence[i]->adjacence[i]->t->s[j_borne].owner->couleur,renderer);
            }
            if(p->adjacence[i]->adjacence[i]->t->s[j_borne].i == VILLE){
                Affiche_Ville(p->adjacence[i]->adjacence[i]->x,p->adjacence[i]->adjacence[i]->y,j_borne,p->adjacence[i]->adjacence[i]->t->s[j_borne].owner->couleur,renderer);
            }
            if(p->adjacence[i]->adjacence[ord[i]]->t->s[j_borne].i == COLONIE){
                Affiche_Colonie(p->adjacence[i]->adjacence[ord[i]]->x,p->adjacence[i]->adjacence[ord[i]]->y,j_borne,p->adjacence[i]->adjacence[ord[i]]->t->s[j_borne].owner->couleur,renderer);
            }
            if(p->adjacence[i]->adjacence[ord[i]]->t->s[j_borne].i == VILLE){
                Affiche_Ville(p->adjacence[i]->adjacence[ord[i]]->x,p->adjacence[i]->adjacence[ord[i]]->y,j_borne,p->adjacence[i]->adjacence[ord[i]]->t->s[j_borne].owner->couleur,renderer);
            }
        }
    }
}
