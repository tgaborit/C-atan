/**
 * \file place_infra.c
 * \brief Implémente les fonctions de place_infra.h
 * \author Emmanuel.D
 * \version 1.0
 * \date 1 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage des probabilites dans le jeu.
 */

#include "place_infra.h"
#include "math.h"


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

static void print_infra(double x, double y, char* pathname, SDL_Renderer* renderer){
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




	if(SDL_RenderCopy(renderer, infra, NULL, &rectangle) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");

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

    if(couleur == VERT){
        print_infra(posx,posy,"imagecatane/colonieblanche.bmp",renderer);
    }
    if(couleur == BLEU){
        print_infra(posx,posy,"imagecatane/coloniebleu.bmp",renderer);
    }
    if(couleur == ROUGE){
        print_infra(posx,posy,"imagecatane/colonierouge.bmp",renderer);

    }
    if(couleur == ORANGE){
        print_infra(posx,posy,"imagecatane/colonieorange.bmp",renderer);
    }
}

static void Affiche_Ville(double x, double y, int position, Couleur couleur, SDL_Renderer* renderer){
    double posx,posy;

    posx = x_centre+cote*x*sqrt(3);
    posy = y_centre-cote*y*1.5;
    posx += calcul_offset_x(position);
    posy += calcul_offset_y(position);
    posx += -29;
    posy += -20;

    if(couleur == VERT){
        print_infra(posx,posy,"imagecatane/villeblanc.bmp",renderer);
    }
    if(couleur == BLEU){
        print_infra(posx,posy,"imagecatane/villebleu.bmp",renderer);
    }
    if(couleur == ROUGE){
        print_infra(posx,posy,"imagecatane/villerouge.bmp",renderer);

    }
    if(couleur == ORANGE){
        print_infra(posx,posy,"imagecatane/villeorange.bmp",renderer);
    }
}

static void Affiche_Route(double x, double y, int position, Couleur couleur, SDL_Renderer* renderer){

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
    int i,j;
    Plateau* p = partie->plateau;
    int ord[6] = {HG,G,HD,BG,D,BD};                                    // Tableau de chiffres en liaison avec un pattern de mouvements.


    for(i=0; i<6; ++i){
        for(j=0; j<6; ++j){
            if(p->adjacence[i]->t->s[j].i == COLONIE){
                Affiche_Colonie(p->adjacence[i]->x,p->adjacence[i]->y,j,/*p->adjacence[i]->t->s[j].owner->couleur*/1,renderer);
            }
            if(p->adjacence[i]->t->s[j].i == VILLE){
                Affiche_Ville(p->adjacence[i]->x,p->adjacence[i]->y,j,/*p->adjacence[i]->t->s[j].owner->couleur*/1,renderer);
            }
            if(p->adjacence[i]->t->a[j].i == ROUTE){
                Affiche_Route(p->adjacence[i]->x,p->adjacence[i]->y,j,/*p->adjacence[i]->t->s[j].owner->couleur*/2,renderer);
            }
            if(p->adjacence[i]->adjacence[i]->t->s[j].i == COLONIE){
                Affiche_Colonie(p->adjacence[i]->adjacence[i]->x,p->adjacence[i]->adjacence[i]->y,j,/*p->adjacence[i]->adjacence[i]->t->s[j].owner->couleur*/0,renderer);
            }
            if(p->adjacence[i]->adjacence[i]->t->s[j].i == VILLE){
                Affiche_Ville(p->adjacence[i]->adjacence[i]->x,p->adjacence[i]->adjacence[i]->y,j,/*p->adjacence[i]->adjacence[i]->t->s[j].owner->couleur*/1,renderer);
            }
            if(p->adjacence[i]->adjacence[i]->t->a[j].i == ROUTE){
                Affiche_Route(p->adjacence[i]->adjacence[i]->x,p->adjacence[i]->adjacence[i]->y,j,/*p->adjacence[i]->adjacence[i]->t->s[j].owner->couleur*/2,renderer);
            }
            if(p->adjacence[i]->adjacence[ord[i]]->t->s[j].i == COLONIE){
                Affiche_Colonie(p->adjacence[i]->adjacence[ord[i]]->x,p->adjacence[i]->adjacence[ord[i]]->y,j,/*p->adjacence[i]->adjacence[ord[i]]->t->s[j].owner->couleur*/3,renderer);
            }
            if(p->adjacence[i]->adjacence[ord[i]]->t->s[j].i == VILLE){
                Affiche_Ville(p->adjacence[i]->adjacence[ord[i]]->x,p->adjacence[i]->adjacence[ord[i]]->y,j,/*p->adjacence[i]->adjacence[ord[i]]->t->s[j].owner->couleur*/2,renderer);
            }
            if(p->adjacence[i]->adjacence[ord[i]]->t->a[j].i == ROUTE){
                Affiche_Route(p->adjacence[i]->adjacence[ord[i]]->x,p->adjacence[i]->adjacence[ord[i]]->y,j,/*p->adjacence[i]->adjacence[ord[i]]->t->s[j].owner->couleur*/1,renderer);
            }
        }

    }


}
