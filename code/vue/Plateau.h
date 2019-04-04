#ifndef PLATEAU_H
#define PLATEAU_H

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"



void SDL_ExitWithError(const char *message);

void AfficheFenetre();



void AfficheTuile(SDL_Renderer* renderer);

void AfficheTuileArgile(SDL_Renderer* renderer, double x, double y);

void AfficheTuileBle(SDL_Renderer* renderer, double x, double y);

void AfficheTuileBois(SDL_Renderer* renderer, double x, double y);

void AfficheTuileMouton(SDL_Renderer* renderer, double x, double y);

void AfficheTuileRoche(SDL_Renderer* renderer, double x, double y);

void AfficheRandomTuile(Plateau* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

void AfficheTuilePlateau(Plateau *p, SDL_Renderer *renderer);

void AfficheJoueur(SDL_Renderer *renderer);



void AfficheCarteArgile(SDL_Renderer *renderer);

void AfficheCarteBle(SDL_Renderer *renderer);

void AfficheCarteBois(SDL_Renderer *renderer);

void AfficheCarteMouton(SDL_Renderer *renderer);

void AfficheCarteArgile(SDL_Renderer *renderer);
	


//void AfficheCartesDev(SDL_Renderer *renderer);

void AfficheChevalier(SDL_Renderer *renderer);

void AfficheMonopole(SDL_Renderer *renderer);

void AfficheInvention(SDL_Renderer *renderer);

void AfficheRouteDev(SDL_Renderer *renderer);

void AfficheUniversite(SDL_Renderer *renderer);

void AfficheGrandeArmee(SDL_Renderer *renderer);

void AfficheGrandeRoute(SDL_Renderer *renderer);



void AfficheBouttonDev(SDL_Renderer *renderer);

void AfficheBouttonRoute(SDL_Renderer *renderer);

void AfficheBouttonColonie(SDL_Renderer *renderer);

void AfficheBouttonVille(SDL_Renderer *renderer);


/*void AfficheConstructions(SDL_Renderer *renderer);	

void AfficheProbas(SDL_Renderer *renderer);

void AfficheReussite(SDL_Renderer *renderer);	//fonction modele*/



void Affiche2(SDL_Renderer* renderer, double posx, double posy);

void Affiche3(SDL_Renderer* renderer, double posx, double posy);

void Affiche4(SDL_Renderer* renderer, double posx, double posy);

void Affiche5(SDL_Renderer* renderer, double posx, double posy);

void Affiche6(SDL_Renderer* renderer, double posx, double posy);

void Affiche7(SDL_Renderer* renderer, double posx, double posy);

void Affiche8(SDL_Renderer* renderer, double posx, double posy);

void Affiche9(SDL_Renderer* renderer, double posx, double posy);

void Affiche10(SDL_Renderer* renderer, double posx, double posy);

void Affiche11(SDL_Renderer* renderer, double posx, double posy);

void Affiche12(SDL_Renderer* renderer, double posx, double posy);

void AfficheProbaNormal(SDL_Renderer* renderer);

void AfficheRandomProba(Plateau* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

void AfficheRandomProbaPlateau(Plateau *p, SDL_Renderer *renderer);


void AfficheHelp(SDL_Renderer *renderer);

void AfficheDe(SDL_Renderer *renderer);

void AfficheSkip(SDL_Renderer *renderer);

void AfficheJetonVoleur(Plateau* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

void AfficheVoleur(Plateau* p, SDL_Renderer* renderer);

#endif
