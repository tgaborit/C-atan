/**
 * \file probabilite.c
 * \brief Implémente les fonctions de probabilite.h
 * \author Pauline.M
 * \version 1.0
 * \date 1 mai 2019
 *
 * Implémente les fonctions utiles à l'affichage des probabilites dans le jeu.
 */

#include "probabilite.h"


/**
 * \fn Affiche2(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 2 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche2(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p2 = NULL;

	image = SDL_LoadBMP("../images/2.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 2.bmp");

	p2 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p2 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp2;

	if(SDL_QueryTexture(p2, NULL, NULL, &rectp2.w, &rectp2.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp2.x = posx;
	rectp2.y = posy;


	if(SDL_RenderCopy(renderer, p2, NULL, &rectp2) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn Affiche3(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 3 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche3(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p3 = NULL;

	image = SDL_LoadBMP("../images/3.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 3.bmp");

	p3 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p3 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp3;

	if(SDL_QueryTexture(p3, NULL, NULL, &rectp3.w, &rectp3.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp3.x = posx;
	rectp3.y = posy;


	if(SDL_RenderCopy(renderer, p3, NULL, &rectp3) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn Affiche4(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 4 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche4(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p4 = NULL;

	image = SDL_LoadBMP("../images/4.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 4.bmp");

	p4 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p4 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp4;

	if(SDL_QueryTexture(p4, NULL, NULL, &rectp4.w, &rectp4.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp4.x = posx;
	rectp4.y = posy;


	if(SDL_RenderCopy(renderer, p4, NULL, &rectp4) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn Affiche5(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 5 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche5(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p5 = NULL;

	image = SDL_LoadBMP("../images/5.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 5.bmp");

	p5 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p5 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp5;

	if(SDL_QueryTexture(p5, NULL, NULL, &rectp5.w, &rectp5.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp5.x = posx;
	rectp5.y = posy;


	if(SDL_RenderCopy(renderer, p5, NULL, &rectp5) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}


/**
 * \fn Affiche6(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 6 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche6(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p6 = NULL;

	image = SDL_LoadBMP("../images/6.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 6.bmp");

	p6 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p6 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp6;

	if(SDL_QueryTexture(p6, NULL, NULL, &rectp6.w, &rectp6.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp6.x = posx;
	rectp6.y = posy;


	if(SDL_RenderCopy(renderer, p6, NULL, &rectp6) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}




/**
 * \fn Affiche7(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 7 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche7(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p7 = NULL;

	image = SDL_LoadBMP("../images/7.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 7.bmp");

	p7 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p7 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp7;

	if(SDL_QueryTexture(p7, NULL, NULL, &rectp7.w, &rectp7.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp7.x = posx;
	rectp7.y = posy;


	if(SDL_RenderCopy(renderer, p7, NULL, &rectp7) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}



/**
 * \fn Affiche8(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 8 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche8(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p8 = NULL;

	image = SDL_LoadBMP("../images/8.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 8.bmp");

	p8 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p8 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp8;

	if(SDL_QueryTexture(p8, NULL, NULL, &rectp8.w, &rectp8.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp8.x = posx;
	rectp8.y = posy;


	if(SDL_RenderCopy(renderer, p8, NULL, &rectp8) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn Affiche9(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 9 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche9(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p9 = NULL;

	image = SDL_LoadBMP("../images/9.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 9.bmp");

	p9 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p9 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp9;

	if(SDL_QueryTexture(p9, NULL, NULL, &rectp9.w, &rectp9.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp9.x = posx;
	rectp9.y = posy;


	if(SDL_RenderCopy(renderer, p9, NULL, &rectp9) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn Affiche10(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 10 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche10(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p10 = NULL;

	image = SDL_LoadBMP("../images/10.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 10.bmp");

	p10 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p10 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp10;

	if(SDL_QueryTexture(p10, NULL, NULL, &rectp10.w, &rectp10.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp10.x = posx;
	rectp10.y = posy;


	if(SDL_RenderCopy(renderer, p10, NULL, &rectp10) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn Affiche11(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 11 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche11(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p11 = NULL;

	image = SDL_LoadBMP("../images/11.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 11.bmp");

	p11 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p11 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp11;

	if(SDL_QueryTexture(p11, NULL, NULL, &rectp11.w, &rectp11.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp11.x = posx;
	rectp11.y = posy;


	if(SDL_RenderCopy(renderer, p11, NULL, &rectp11) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn Affiche12(SDL_Renderer *renderer,double posx, double posy)
 * \brief Fonction affichant l'image de la probabilité 12 en posx et posy
 *
 *
 * \param renderer, le rendu actuel
 * \param posx et posy, la position de l'image en pixel
 * \return aucun
 */
void Affiche12(SDL_Renderer* renderer, double posx, double posy)
{
	SDL_Surface *image = NULL;
	SDL_Texture *p12 = NULL;

	image = SDL_LoadBMP("../images/12.bmp");

	if(image == NULL)
		SDL_ExitWithError("Impossible de charger l'image 12.bmp");

	p12 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	if(p12 == NULL)
		SDL_ExitWithError("impossible de creer la texture");

	SDL_Rect rectp12;

	if(SDL_QueryTexture(p12, NULL, NULL, &rectp12.w, &rectp12.h) != 0)
		SDL_ExitWithError("Impossible de charger la texture");

	rectp12.x = posx;
	rectp12.y = posy;


	if(SDL_RenderCopy(renderer, p12, NULL, &rectp12) !=0)
		SDL_ExitWithError("Impossible d'afficher la texture");
}

/**
 * \fn AfficheProbaNormal(SDL_Renderer *renderer)
 * \brief Fonction affichant les probabiltés tel que c'est décrit dans les règles du jeu classique
 *
 *
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheProbaNormal(SDL_Renderer* renderer)
{
	Affiche6(renderer, 814, 135);
	Affiche3(renderer, 949, 135);
	Affiche8(renderer, 1084, 135);

	Affiche2(renderer, 746.5, 251);
	Affiche4(renderer, 881.5, 251);
	Affiche5(renderer, 1016.5, 251);
	Affiche10(renderer, 1151.5, 251);

	Affiche5(renderer, 679, 368);
	Affiche9(renderer, 814, 368);
	Affiche6(renderer, 1084, 368);
	Affiche9(renderer, 1219, 368);

	Affiche10(renderer, 746.5, 484);
	Affiche11(renderer, 881.5, 484);
	Affiche3(renderer, 1016.5, 484);
	Affiche12(renderer, 1151.5, 484);

	Affiche8(renderer, 814, 605);
	Affiche4(renderer, 949, 605);
	Affiche11(renderer, 1084, 605);
}

/**
 * \fn AfficheRandomProba(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy)
 * \brief Fonction affichant les probabiltés de manière aléatoire
 *
 *
 * \param p, la partie actuelle
 * \param x et y les coordonnées du noeud recherché
 * \param renderer, le rendu actuel
 * \param posimx et posimy les coordonnées en pixel de l'image à afficher
 * \return aucun
 */
void AfficheRandomProba(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy)
{
	int proba = getProba(p, x, y);

	switch(proba)
	{
		case 2 :
			Affiche2(renderer, posimx, posimy);
			break;
		case 3 :
			Affiche3(renderer, posimx, posimy);
			break;
		case 4 :
			Affiche4(renderer, posimx, posimy);
			break;

		case 5 :
			Affiche5(renderer, posimx, posimy);
			break;

		case 6 :
			Affiche6(renderer, posimx, posimy);
			break;

		case 7 :
			Affiche7(renderer, posimx, posimy);
			break;

		case 8 :
			Affiche8(renderer, posimx, posimy);
			break;

		case 9 :
			Affiche9(renderer, posimx, posimy);
			break;

		case 10 :
			Affiche10(renderer, posimx, posimy);
			break;

		case 11 :
			Affiche11(renderer, posimx, posimy);
			break;

		case 12 :
			Affiche12(renderer, posimx, posimy);
			break;

		default :
			break;
	}
}


/**
 * \fn AfficheRandomProbaPlateau(Partie* p, SDL_Renderer* renderer)
 * \brief Fonction affichant les probabiltés de manière aléatoire sur le plateau
 *
 *
 * \param p, la partie actuelle
 * \param renderer, le rendu actuel
 * \return aucun
 */
void AfficheRandomProbaPlateau(Partie *p, SDL_Renderer *renderer)
{
	AfficheRandomProba(p, -1, 2, renderer, 814, 135);
	AfficheRandomProba(p, 0, 2, renderer, 949, 135);
	AfficheRandomProba(p, 1, 2, renderer, 1084, 135);

	AfficheRandomProba(p, -1.5, 1, renderer, 746.5, 251);
	AfficheRandomProba(p, -0.5, 1, renderer, 881.5, 251);
	AfficheRandomProba(p, 0.5, 1, renderer, 1016.5, 251);
	AfficheRandomProba(p, 1.5, 1, renderer, 1151.5, 251);

	AfficheRandomProba(p, -2, 0, renderer, 679, 368);
	AfficheRandomProba(p, -1, 0, renderer, 814, 368);
	AfficheRandomProba(p, 1, 0, renderer, 1084, 368);
	AfficheRandomProba(p, 2, 0, renderer, 1219, 368);

	AfficheRandomProba(p, -1.5, -1, renderer, 746.5, 484);
	AfficheRandomProba(p, -0.5, -1, renderer, 881.5, 484);
	AfficheRandomProba(p, 0.5, -1, renderer, 1016.5, 484);
	AfficheRandomProba(p, 1.5, -1, renderer, 1151.5, 484);

	AfficheRandomProba(p, -1, -2, renderer, 814, 605);
	AfficheRandomProba(p, 0, -2, renderer, 949, 605);
	AfficheRandomProba(p, 1, -2, renderer, 1084, 605);
}
